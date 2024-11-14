module.exports = (app, product, db) => {
  app.get('/admin/modify_pr', (req, res) => {
    res.render('modify_pr.ejs')
  });
  app.post('/admin/modify_pr', (req, res) => {
    const productId = req.body.pr_id;
    const newName = req.body.pr_name;
    const newPrice = req.body.pr_price;
    const newDescription = req.body.pr_description;

    product.updateById(db, productId, newName, newPrice, newDescription, (err, updatedProduct) => {
      if (err) {
        console.error('Error updating product:', err);
        const message = 'Error updating product:' + err;
        res.render('product_fail', {message});
        return;
      }
  
      if (!updatedProduct) {
        console.log('Product with ID ' + productId + ' not found.');
        const message = 'Product with ID ' + productId + ' not found.';
        res.render('product_fail', {message});
        return;
      }
  
      console.log('Product successfully updated:', updatedProduct);
      res.render('success.ejs');
    });
  })
};