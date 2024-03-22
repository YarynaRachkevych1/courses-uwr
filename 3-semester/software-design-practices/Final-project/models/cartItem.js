// cartItem.js

class CartItem {
    constructor(id, user_id, product_id, amount) {
        this.id = id;
        this.user_id = user_id;
        this.product_id = product_id;
        this.amount = amount;
    }

    getById(db, id, callback) {
        db.get("SELECT * FROM cart_items WHERE id = ?", [id], (err, row) => {
        if (err) {
            callback(err, null);
            return;
        }

        if (!row) {
            callback(null, null);
            return;
        }

        const cartItem = new CartItem(row.id, row.user_id, row.product_id, row.amount);
        callback(null, cartItem);
        });
    }

    create(db, user_id, product_id, amount, callback) {
        const stmt = db.prepare("INSERT INTO cart_items (user_id, product_id, amount) VALUES (?, ?, ?)");
        stmt.run(user_id, product_id, amount, function(err) {
        if (err) {
            callback(err, null);
            return;
        }

        const cartItem = new CartItem(this.lastID, user_id, product_id, amount);
        callback(null, cartItem);
        });
        stmt.finalize();
    }

    getAllCartItems(db, user_id, callback) {
        db.all(`
            SELECT products.name, products.description, products.price, cart_items.amount, cart_items.product_id
            FROM cart_items 
            JOIN products ON cart_items.product_id = products.id
            WHERE user_id = ?`, [user_id], (err, rows) => {
                if (err) {
                    callback(err, null);
                    return;
                }
    
                if (!rows || rows.length === 0) {
                    callback(null, []);
                    return;
                }
    
                callback(null, rows);
            });
    }    

    getAllItemIdsByUserId(db, user_id, callback) {
        db.all("SELECT id FROM cart_items WHERE user_id = ?", [user_id], (err, rows) => {
            if (err) {
                callback(err, null);
                return;
            }

            const itemIds = rows.map(row => row.id);
            callback(null, itemIds);
        });
    }

    deleteById(db, id, callback) {
        const stmt = db.prepare("DELETE FROM cart_items WHERE id = ?");
        stmt.run(id, function(err) {
            if (err) {
                callback(err);
                return;
            }

            if (this.changes === 0) {
                callback(null, false);
                return;
            }

            callback(null, true); 
        });
        stmt.finalize();
    }

    deleteByUserId(db, user_id, callback) {
        const stmt = db.prepare("DELETE FROM cart_items WHERE user_id = ?");
        stmt.run(user_id, function(err) {
            if (err) {
                callback(err);
                return;
            }

            if (this.changes === 0) {
                callback(null, false);
                return;
            }

            callback(null, true);
        });
        stmt.finalize();
    }
}

module.exports = CartItem;
