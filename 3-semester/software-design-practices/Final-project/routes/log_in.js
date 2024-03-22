module.exports = (app, users, db, cart_items) => {
  app.get('/log_in', (req, res) => {
    res.render('log_in');
  });

  app.post('/log_in', (req, res) => {
    const email = req.body.e_mail;
    const password = req.body.password;

    if (email === 'yaryna_r' && password === 'rachkevych') {
      res.cookie('token', 4444);

      res.redirect('/admin');
    } else {
      users.authenticate(db, email, password, (err, authenticatedUser, message) => {
        if (err) {
          console.error('Error during authentication:', err);
          const message = 'Error during authentication:' + err;
          res.render('login_fail', message);
          return;
        }

        if (!authenticatedUser) {
          console.log('Authentication failed. User not found or invalid credentials.');
          const message = 'Authentication failed. User not found or invalid credentials.';
          res.render('login_fail', {message});
          return;
        }

        if (message === 'Incorrect password') {
          const message = 'Incorrect password';
          res.render('login_fail', {message});
        } else {
          res.cookie('userId', authenticatedUser.id);
          res.cookie('token', 1234);
          res.cookie('userEmail', email);

          res.redirect('home_aut');
          console.log('Authentication successful:', authenticatedUser);
        }
      });
    }
  });
};
