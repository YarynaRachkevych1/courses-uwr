module.exports = (app, products, orders, order_items, cart_items, db) => {
  app.get('/my_acc/orders', (req, res) => {
    const userId = req.cookies.userId;
    console.log('User id: ', userId);

    orders.getByUserId(db, userId, (err, allOrders) => {
      if (err) {
        console.error(err);
        res.status(500).send('Internal Server Error');
        return;
      }
      res.render('orders', {orders : allOrders});
    })
  });

  app.post('/my_acc/make_order', (req, res) => {
    const userId = req.cookies.userId;
    orders.create(db, userId, 'new', (err, newOdrer) => {
      if (err) {
          console.error(err);
          res.status(500).send('Internal Server Error');
          return;
      }

      cart_items.getAllCartItems(db, userId, (err, products) => {
        if (err) {
          console.error(err);
          res.status(500).send('Internal Server Error');
          return;
        } else {
          products.forEach(product => {
            order_items.create(db, newOdrer.id, product.product_id, product.amount, (err, orderItem) => {
              if (err) {
                console.error(err);
                res.status(500).send('Internal Server Error');
                return;
              }
            })
          });
          cart_items.deleteByUserId(db, userId, (err, result) => {
            if (err) {
              console.error(err);
              res.status(500).send('Internal Server Error');
              return;
            }
          })
        }
      })
      res.redirect('/my_acc/orders');
    });
  });

  app.get('/my_acc/see_order', (req, res) => {
    const orderId = req.query.orderId;
  
    order_items.getByOrderId(db, orderId, (err, orderItems) => {
      if (err) {
        console.error(`Error retrieving items for order_id ${orderId}:`, err);
        return;
      }
  
      const productIds = orderItems.map(item => item.product_id);
  
      products.getAll(db, (productErr, products) => {
        if (productErr) {
          console.error("Error retrieving products:", productErr);
          return;
        }
  
        const orderProducts = products.filter(product => productIds.includes(product.id));
        res.render('order_pr', { products: orderProducts });
      });
    });
  });
  
  app.post('/my_acc/orders', (req, res) => {

  })
};