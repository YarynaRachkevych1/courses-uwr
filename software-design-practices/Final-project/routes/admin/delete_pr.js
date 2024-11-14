module.exports = (app, product, db) => {
  app.get('/admin/delete_pr', (req, res) => {
    res.render('delete_pr.ejs');
  });

  app.post('/admin/delete_pr', (req, res) => {
    const productId = req.body.pr_id;

    product.deleteById(db, productId, (err, deletedProduct) => {
      if (err) {
        console.error('Error deleting product:', err);
        const message = 'Error deleting product:' + err;
        res.render('product_fail', {message});
        return;
      }
  
      if (!deletedProduct) {
        console.log('Product with ID ' + productId + ' not found.');
        const message = 'Product with ID ' + productId + ' not found.';
        res.render('product_fail', {message});
        return;
      }
  
      console.log('Product successfully deleted:', deletedProduct);
      res.render('success.ejs');
    });
  });
};
