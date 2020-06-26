//ECMAScript 8
//Khai báo biến: const, var: biến toàn cục ngoài block, let: biến cục bộ trg khối block

const express = require('express')
const app = express()//tạo server
const port = 3000

//GET: localhost:3000/ -->www.abc.com
app.get('/', (req, res) => res.send('Hello World!'))

app.get('/plus/:a/:b',(req, res)=>{
    let a = parseInt(req.params['a']);
    let b = parseInt(req.params['b']);
    let c = parseInt(a) + parseInt(b);
    res.send(JSON.stringify(c))
})
//POST: localhost/product/999
app.post('/product/:id',(req, res)=>{
    let pid = req.params['id'];
    console.log(pid)
    res.send('Product ID = ' + pid)
})

var express = require('express')
var app = express()
app.get('/', function (req, res) {
  res.send('hello world')
})

app.get('/', function (req, res) {
    res.send('GET request to the homepage')
  })

app.post('/', function (req, res) {
    res.send('POST request to the homepage')
  })
  
app.all('/secret', function (req, res, next) {
    console.log('Accessing the secret section ...')
    next() 
  })

app.get('/', function (req, res) {
    res.send('root')
  })
app.get('/about', function (req, res) {
    res.send('about')
  })
app.get('/random.text', function (req, res) {
    res.send('random.text')
  })
app.get('/ab?cd', function (req, res) {
    res.send('ab?cd')
  })
app.get('/ab+cd', function (req, res) {
    res.send('ab+cd')
  })
app.get('/ab*cd', function (req, res) {
    res.send('ab*cd')
  })
app.get('/ab(cd)?e', function (req, res) {
    res.send('ab(cd)?e')
  })
app.get(/a/, function (req, res) {
    res.send('/a/')
  })
app.get(/.*fly$/, function (req, res) {
    res.send('/.*fly$/')
  })
app.get('/users/:userId/books/:bookId', function (req, res) {
    res.send(req.params)
  })
app.get('/example/a', function (req, res) {
    res.send('Hello from A!')
  })
app.get('/example/b', function (req, res, next) {
    console.log('the response will be sent by the next function ...')
    next()
  }, function (req, res) {
    res.send('Hello from B!')
  })
var cb0 = function (req, res, next) {
    console.log('CB0')
    next()
  }
var cb1 = function (req, res, next) {
    console.log('CB1')
    next()
  }
var cb2 = function (req, res) {
    res.send('Hello from C!')
  }
  
app.get('/example/c', [cb0, cb1, cb2])
var cb0 = function (req, res, next) {
    console.log('CB0')
    next()
  }
  
var cb1 = function (req, res, next) {
    console.log('CB1')
    next()
  }
  
app.get('/example/d', [cb0, cb1], function (req, res, next) {
    console.log('the response will be sent by the next function ...')
    next()
  }, function (req, res) {
    res.send('Hello from D!')
  })
app.route('/book')
  .get(function (req, res) {
    res.send('Get a random book')
  })
  .post(function (req, res) {
    res.send('Add a book')
  })
  .put(function (req, res) {
    res.send('Update the book')
  })

var express = require('express')
var router = express.Router()

router.use(function timeLog (req, res, next) {
  console.log('Time: ', Date.now())
  next()

router.get('/', function (req, res) {
  res.send('Birds home page')
})

router.get('/about', function (req, res) {
  res.send('About birds')
})

module.exports = router
var birds = require('./birds')

app.use('/birds', birds)
app.listen(port, () => console.log(`Example app listening on port ${port}!`))