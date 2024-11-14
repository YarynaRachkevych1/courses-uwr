module.exports = (app, users, db) => {
  app.get('/admin/all_users', (req, res) => {
    users.getAllUsers(db, (err, allUsers) => {
      if (err) {
        console.error('Error getting users:', err);
        res.status(500).json({ error: 'Internal Server Error' });
        return;
      }

      res.render('all_users', { allUsers });
    });
  });
};