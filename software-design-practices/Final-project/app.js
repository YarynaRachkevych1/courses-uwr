const express = require('express');
const app = express();
const sqlite3 = require('sqlite3').verbose();
const cookieParser = require("cookie-parser");  

app.set('view engine', 'ejs');
app.set('views', './views');

app.use(express.urlencoded({ extended: true }));
app.use(express.static('public'));
app.use(cookieParser());
app.use((req, res, next) => {
        const pages = ['/log_in', '/register', '/home'];
        if (!pages.includes(req.path)){
                if (req.path === '/admin/') {
                        
                        if (req.cookies.token == 4444) {
                                next();
                        }
                        else {
                                res.redirect('/log_in');
                        }
                }
                else {
                        if (req.cookies.token && (req.cookies.token == 1234 || req.cookies.token == 4444)) {
                                next();
                        }
                        else{
                                res.redirect('/log_in');
                        }
                }
        } else {
                next();
        }
      });

const db = new sqlite3.Database('shop.db');

db.serialize(() => {
    db.run(`CREATE TABLE IF NOT EXISTS products 
            (id INTEGER PRIMARY KEY, 
            name TEXT, 
            price REAL, 
            description TEXT)`);
    db.run(`CREATE TABLE IF NOT EXISTS users 
            (id INTEGER PRIMARY KEY, 
            email TEXT, 
            password TEXT)`);
    db.run(`CREATE TABLE IF NOT EXISTS orders 
            (id INTEGER PRIMARY KEY, 
            status TEXT,
            user_id INTEGER, 
            FOREIGN KEY (user_id) REFERENCES users(id))`);
    db.run(`CREATE TABLE IF NOT EXISTS order_items 
            (id INTEGER PRIMARY KEY, 
            order_id INTEGER,
            product_id INTEGER,
            amount INTEGER,
            FOREIGN KEY (order_id) REFERENCES orders(id), 
            FOREIGN KEY (product_id) REFERENCES products(id))`);
    db.run(`CREATE TABLE IF NOT EXISTS cart_items 
            (id INTEGER PRIMARY KEY,  
            user_id INTEGER, 
            product_id INTEGER,
            amount INTEGER,
            FOREIGN KEY (user_id) REFERENCES users(id),
            FOREIGN KEY (product_id) REFERENCES products(id))`)
  });

const productsModel = require('./models/products');
const usersModel = require('./models/users');
const ordersModel = require('./models/orders');
const orderItemModel = require('./models/orderItem');
const cartItemModel = require('./models/cartItem');

// Inicjalizuj modele z połączeniem do bazy danych
const products = new productsModel(db);
const users = new usersModel(db);
const orders = new ordersModel(db);
const order_items = new orderItemModel(db);
const cart_items = new cartItemModel(db);

const homeRoute = require('./routes/home')(app, products, db);
const homeAutRoute = require('./routes/home_aut')(app, products, users, cart_items, db);
const logInRoute = require('./routes/log_in')(app, users, db);
const registerRoute = require('./routes/register')(app, users, db);

const myAccRoute = require('./routes/my_account/my_acc')(app);
const cartRoute = require('./routes/my_account/cart')(app, cart_items, db);
const ordersRoute = require('./routes/my_account/orders')(app, products, orders, order_items, cart_items, db);

const adminPRoute = require('./routes/admin/admin_p')(app);
const allUsersRoute = require('./routes/admin/all_users')(app, users, db);
const addPrRoute = require('./routes/admin/add_pr')(app, products, db);
const modifyPrRoute = require('./routes/admin/modify_pr')(app, products, db);
const deletePrRoute = require('./routes/admin/delete_pr')(app, products, db);
const processORoute = require('./routes/admin/process_o')(app);
const finishedORoute = require('./routes/admin/finished_o')(app);


// Nasłuchuj na określonym porcie
const port = process.env.PORT || 3000;
app.listen(port, () => {
    console.log(`Serwer nasłuchuje na porcie ${port}`);
});