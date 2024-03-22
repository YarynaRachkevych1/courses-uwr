// register.js

module.exports = (app, users, db) => {
  app.get('/register', (req, res) => {
    res.render('register');
  });

  app.post('/register', (req, res) => {
    const email = req.body.e_mail;
    const password = req.body.password;
    const password2 = req.body.password2;

    users.checkIfEmailExists(db, email, (err, emailExists) => {
      if (err) {
        console.error('Error checking if email exists:', err);
        return;
      }
    
      if (emailExists) {
        console.log('User whith that email already exists.');
        const message = 'User whith that email already exists.';
        res.render('passw_fail', {message});
        
      } else {
        if (password === password2) {
          users.create(db, email, password, (err, newUser) => {
            if (err) {
              console.error('Error creating user:', err);
              const message = 'Error creating user:' + err;
              res.render('passw_fail', {message});
              return;
            }
    
            console.log('User successfully created:', newUser);
            res.redirect('home_aut');
          });
        } else {
          const message = 'Passwords are not the same!';
          res.render('passw_fail', {message});
        }
      }
    });
  });
};