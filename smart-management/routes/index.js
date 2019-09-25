var express = require('express');
var router = express.Router();
var firebase = require('firebase');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('signup', { title: 'Cadastro' });
});
router.get('/login', function(req, res, next) {
  res.render('index', { title: 'Login' });
});
router.post('/login', function(req, res, next) {
  const user=req.body.user;
  firebase.auth().signInWithEmailAndPassword(user.username, user.password).then((userF)=>{
console.log("deu certoooooooooooooooooooooooooooooooooooooooooooooooo");
res.redirect('/login')

}).catch((error)=>{
  console.log(error);
  res.redirect('/error')
})




});

module.exports = router;
