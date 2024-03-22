module.exports = (app, product, db) => {
  app.get('/admin/add_pr', (req, res) => {
    res.render('add_pr.ejs')
  });
  app.post('/admin/add_pr', (req, res) => {
    const productName = req.body.pr_name;
    const productPrice = req.body.pr_price;
    const productDescription = req.body.pr_description;

    product.create(db, productName, productPrice, productDescription, (err, newProduct) => {
      if (err) {
        console.error('Error creating product:', err);
        const message = 'Error creating product:' + err;
        res.render('product_fail', {message});
        return;
      }
  
      console.log('Product successfully created:', newProduct);
      res.render('success.ejs');
    });
  });
};