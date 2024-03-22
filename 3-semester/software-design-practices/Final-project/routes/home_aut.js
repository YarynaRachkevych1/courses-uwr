module.exports = (app, products, users, cart_items, db) => {
  app.get('/home_aut', (req, res) => {
    products.getAll(db, (err, allProducts) => {
      if (err) {
        console.error('Error getting products:', err);
        res.render('home_aut.ejs', {products: []});
        return;
      }

      res.render('home_aut.ejs', { products: allProducts });
    });
  });

  app.post('/home/add_cart', (req, res) => {
    const userId = req.cookies.userId;
    const productName = req.body.product_name;

    products.getIdByName(db, productName, (err, productId) => {
        if (err) {
            console.error(err);
            res.status(500).send('Internal Server Error');
            return;
        }

        if (!productId) {
            res.status(404).send('Product not found');
            return;
        }
        const amount = 1;
        cart_items.create(db, userId, productId, amount, (err, cartItem) => {
            if (err) {
                console.error(err);
                res.status(500).send('Internal Server Error');
                return;
            }

            res.cookie('cartItemId', cartItem.id);
            const message = 'Product added to cart';
            res.render('success_h', { message });
        });
    });
  });
};
