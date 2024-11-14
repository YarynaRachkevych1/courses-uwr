// orderItem.js

class OrderItem {
    constructor(id, order_id, product_id, amount) {
      this.id = id;
      this.order_id = order_id;
      this.product_id = product_id;
      this.amount = amount;
    }

    getByOrderId(db, orderId, callback) {
      db.all("SELECT * FROM order_items WHERE order_id = ?", [orderId], (err, rows) => {
        if (err) {
          callback(err, null);
          return;
        }
  
        const orderItems = rows.map(row => new OrderItem(row.id, row.order_id, row.product_id, row.amount));
        callback(null, orderItems);
      });
    }
  
    getById(db, id, callback) {
      db.get("SELECT * FROM order_items WHERE id = ?", [id], (err, row) => {
        if (err) {
          callback(err, null);
          return;
        }
  
        if (!row) {
          callback(null, null);
          return;
        }
  
        const orderItem = new OrderItem(row.id, row.order_id, row.product_id, row.amount);
        callback(null, orderItem);
      });
    }
  
    create(db, order_id, product_id, amount, callback) {
      const stmt = db.prepare("INSERT INTO order_items (order_id, product_id, amount) VALUES (?, ?, ?)");
      stmt.run(order_id, product_id, amount, function(err) {
        if (err) {
          callback(err, null);
          return;
        }

        callback(null, {order_id, product_id, amount});
      });
      stmt.finalize();
    }
}

module.exports = OrderItem;  