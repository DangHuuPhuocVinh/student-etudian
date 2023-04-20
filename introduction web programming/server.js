

const MongoClient = require('mongodb').MongoClient;
const DATABASE_NAME = 'engine-dict';
const MONGO_URL = 'mongodb://localhost:27017/${DATABASE_NAME}';
let db = null;

MongoClient.connect(MONGO_URL, {useNewUrlParser: true}, function(err, database){
    db = database;
    console.log('Connecting to mongo DB')
})

async function findUser(req, res){
    const routeParams = req.params;
    const user = routeParams.user;
    const query = {
        first_name:user
    };
    const doc = await collection.findOne(query);
    res.json({first:doc.first_name, last:doc.last_name})
}
// async function main(){
//     db = await MongoClient.connect(MONGO_URL);
//     collections = db.collection('vinh');
// }

// async function insertWord(word, definition){
//     const doc = {
//         word:word,
//         definition:definition
//     };
//     collection.insertOne(doc, function(err, result){
//         console.log('Document id: ${result.insertId');
//     });
// }

async function main(){
    const client = await MongoClient.connect(MONGO_URL, {useNewUrlParse})
    db = await client.db(DATABASE_NAME);
    collection = await db.collection('users');
    console.log(collection);
}

main();