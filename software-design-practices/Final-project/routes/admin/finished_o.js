module.exports = (app) => {
  app.get('/admin/finished_o', (req, res) => {
    res.render('finished_o')
  });
  app.post('/admin/finished_o', (req, res) => {

  })
};