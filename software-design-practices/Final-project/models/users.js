class User {
  constructor(id, email, password) {
    this.id = id;
    this.email = email;
    this.password = password;
  }

  getAllUsers(db, callback) {
    console.log('jestem tu');
    db.all("SELECT * FROM users", (err, rows) => {
      if (err) {
        callback(err, null);
        return;
      }

      const users = rows.map(row => new User(row.id, row.email, row.password));
      callback(null, users);
    });
  }


  getById(db, userId, callback) {
    db.get("SELECT * FROM users WHERE id = ?", [userId], (err, row) => {
      if (err) {
        callback(err, null);
        return;
      }

      if (!row) {
        callback(null, null);
        return;
      }

      const user = new User(row.id, row.email, row.password);
      callback(null, user);
    });
  }

  getByEmail(db, email, callback) {
    db.get("SELECT id FROM users WHERE email = ?", [email], (err, row) => {
        if (err) {
            callback(err, null);
            return;
        }

        if (!row) {
            callback(null, null);
            return;
        }

        callback(null, row.id);
    });
  }

  create(db, email, password, callback) {
    const stmt = db.prepare("INSERT INTO users (email, password) VALUES (?, ?)");
    stmt.run(email, password, function(err) {
      if (err) {
        callback(err, null);
        return;
      }

      const user = new User(this.lastID, email, password);
      callback(null, user);
    });
    stmt.finalize();
  }

  authenticate(db, email, password, callback) {
    db.get("SELECT * FROM users WHERE email = ?", [email], (err, row) => {
      if (err) {
        callback(err, null, 'Error during authentication');
        return;
      }
  
      if (!row) {
        callback(null, null, 'User not found');
        return;
      }
  
      if (row.password === password) {
        const user = new User(row.id, row.email, row.password);
        callback(null, user, 'Authentication successful');
      } else {
        callback(null, null, 'Incorrect password');
      }
    });
  }
  

  checkIfEmailExists(db, email, callback) {
    db.get("SELECT id FROM users WHERE email = ?", [email], (err, row) => {
      if (err) {
        callback(err, null);
        return;
      }

      const emailExists = row ? true : false;
      callback(null, emailExists);
    });
  }

  static deleteById(db, userId, callback) {
    const stmt = db.prepare("DELETE FROM users WHERE id = ?");
    stmt.run(userId, function(err) {
      if (err) {
        callback(err, null);
        return;
      }

      callback(null, { id: userId });
    });
    stmt.finalize();
  }
}

module.exports = User;