// home.js

module.exports = (app, products, db) => {
  app.get('/home', (req, res) => {
    products.getAll(db, (err, allProducts) => {
      if (err) {
        console.error('Error getting products:', err);
        res.render('home.ejs', {products: []});
        return;
      }

      res.render('home.ejs', { products: allProducts });
    });
  });

  app.post('/home', (req, res) => {
    // Tutaj obsługa POST request, jeśli potrzebna
  });
};
