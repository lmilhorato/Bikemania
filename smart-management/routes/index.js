var express = require('express');
var router = express.Router();
var firebase = require('firebase');
const mongo = require('../models/user');
const Client = require('../models/client');

/* GET home page. */
router.get('/home', function(req, res, next) {
  res.render('home', { title: 'Home' });
});
router.get('/signup', function(req, res, next) {
  res.render('signup', { title: 'Cadastro' });
});
/*POST signup*/
router.post('/signup',(req,res) => {
  const  client  = req.body.client;
    Client.create(client).then((client_id) => {
      console.log("entrou");
      console.log(client_id);
      console.log(client);
      res.redirect(`/`);
    }).catch((error) => {
      console.log(error);
      res.redirect('error');
    });

});

router.get('/login', function(req, res, next) {
  res.render('index', { title: 'Login' });
});
router.get('/novoaluguel', function(req, res, next) {
  res.render('novoaluguel', { title: 'Novo Aluguel' });
});
router.post('/novoaluguel', function(req, res, next) {
  if(tipo==1){
      res.redirect('/acompmaster');
}
  else{
    res.redirect('/acompanhamento')
  }
});
var tipo;
router.post('/login', function(req, res, next) {
  const user=req.body.user;
  firebase.auth().signInWithEmailAndPassword(user.username, user.password).then((userF)=>{
    mongo.getByUid(userF.user.uid).then((result)=> {
      if(result.type=='Master'){
      tipo=1;
        res.redirect('/acompmaster');
      }
      else{
        tipo=0;
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
