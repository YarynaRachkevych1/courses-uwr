// products.js

class Product {
    constructor(id, name, price, description) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.description = description;
    }

    create(db, name, price, description, callback) {
        const stmt = db.prepare("INSERT INTO products (name, price, description) VALUES (?, ?, ?)");
        stmt.run(name, price, description, function(err) {
        if (err) {
            callback(err, null);
            return;
        }

        const product = new Product(this.lastID, name, price, description);
        callback(null, product);
        });
        stmt.finalize();
    }

    updateById(db, productId, newName, newPrice, newDescription, callback) {
        const stmt = db.prepare("UPDATE products SET name = ?, price = ?, description = ? WHERE id = ?");
        stmt.run(newName, newPrice, newDescription, productId, function(err) {
        if (err) {
            callback(err, null);
            return;
        }

        if (this.changes === 0) {
            callback(null, null);
            return;
        }

        const updatedProduct = new Product(productId, newName, newPrice, newDescription);
        callback(null, updatedProduct);
        });
        stmt.finalize();
    }

    deleteById(db, productId, callback) {
        const stmt = db.prepare("DELETE FROM products WHERE id = ?");
        stmt.run(productId, function(err) {
            if (err) {
            callback(err, null);
            return;
            }

            if (this.changes === 0) {
            callback(null, null);
            return;
            }

            callback(null, { id: productId });
        });
        stmt.finalize();
        }
    
    getAll(db, callback) {
        db.all("SELECT * FROM products", (err, rows) => {
            if (err) {
            callback(err, null);
            return;
            }
    
            const products = rows.map(row => new Product(row.id, row.name, row.price, row.description));
            callback(null, products);
        });
        }
    
    getIdByName(db, productName, callback) {
        const stmt = db.prepare("SELECT id FROM products WHERE name = ?");
        stmt.get(productName, (err, row) => {
            if (err) {
                callback(err, null);
                return;
            }

            if (!row) {
                // Brak produktu o podanej nazwie
                callback(null, null);
                return;
            }

            const productId = row.id;
            callback(null, productId);
        });
        stmt.finalize();
    }
}

module.exports = Product;