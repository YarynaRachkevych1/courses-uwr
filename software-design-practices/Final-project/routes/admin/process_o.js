module.exports = (app) => {
  app.get('/admin/process_o', (req, res) => {
    console.log('process_o');
    res.render('process_o')
  });
  app.post('/admin/process_o', (req, res) => {

  })
};