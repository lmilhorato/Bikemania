var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/home', function(req, res, next) {
  res.render('home', { title: 'Home' });
});
router.get('/signup', function(req, res, next) {
  res.render('signup', { title: 'Cadastro' });
});

module.exports = router;
