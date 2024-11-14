// orders.js
class Order {
  constructor(id, status, user_id) {
    this.id = id;
    this.status = status;
    this.user_id = user_id; 
  }

  getByUserId(db, userId, callback) {
    db.all("SELECT * FROM orders WHERE user_id = ?", [userId], (err, rows) => {
      if (err) {
        callback(err, null);
        return;
      }

      const orders = rows.map(row => new Order(row.id, row.status, row.user_id));
      callback(null, orders);
    });
  }

  getById(db, orderId, callback) {
    db.get("SELECT * FROM orders WHERE id = ?", [orderId], (err, row) => {
      if (err) {
        callback(err, null);
        return;
      }

      if (!row) {
        callback(null, null);
        return;
      }

      const order = new Order(row.id, row.status, row.user_id); 
      callback(null, order);
    });
  }

  create(db, user_id, status, callback) {
    const stmt = db.prepare("INSERT INTO orders (user_id, status) VALUES (?, ?)");
    stmt.run(user_id, status, function(err) {
      if (err) {
        callback(err, null);
        return;
      }

      const order = new Order(this.lastID, status, user_id); 
      callback(null, order);
    });
    stmt.finalize();
  }
}

module.exports = Order;