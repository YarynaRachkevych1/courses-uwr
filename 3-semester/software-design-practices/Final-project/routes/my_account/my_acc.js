module.exports = (app, user) => {
  app.get('/my_acc', (req, res) => {
    res.render('my_acc')
  });
  app.post('/my_acc', (req, res) => {

  })
};