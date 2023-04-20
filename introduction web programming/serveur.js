const http=require('http');
const server=http.createServer();
server.on('request',function(req,res){

res.statusCode =200;
res.setHeader('Content-Type','text/plain');
res.end('Hello world from node\n');

});
server.on('listening', function(){
console.log('server is running');

});
server.listen(3000);