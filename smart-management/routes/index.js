var express = require('express');
var router = express.Router();
var firebase = require('firebase');
const mongo = require('../models/user');

/* GET home page. */
router.get('/home', function(req, res, next) {
  res.render('home', { title: 'Home' });
});
router.get('/signup', function(req, res, next) {
  res.render('signup', { title: 'Cadastro' });
});
router.get('/login', function(req, res, next) {
  res.render('index', { title: 'Login' });
});
router.post('/login', function(req, res, next) {
  const user=req.body.user;
  firebase.auth().signInWithEmailAndPassword(user.username, user.password).then((userF)=>{
    mongo.getByUid(userF.user.uid).then((result)=> {
      if(result.type=='Master'){
        res.redirect('/acompmaster');
      }
      else{
        res.redirect('/acompanhamento');
      }
    }).catch((error)=>{
      console.log(error);
      res.redirect('/error')
      });
    }).catch((error)=>{
      console.log(error);
      res.redirect('/error')
      });
  });


router.get('/acompanhamento', function(req, res, next) {
  res.render('acompanhamento', { title: 'Acompanhamento',layout: 'layout' });
});
router.get('/acompmaster', function(req, res, next) {
  res.render('acompmaster', { title: 'Acompanhamento' });
});



module.exports = router;
