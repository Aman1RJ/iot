const express=require("express");
const bodyParser=require("body-parser");
const app=express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(function (req, res, next) {

    // Website you wish to allow to connect
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:3000');

    // Request methods you wish to allow
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');

    // Request headers you wish to allow
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');

    // Set to true if you need the website to include cookies in the requests sent
    // to the API (e.g. in case you use sessions)
    res.setHeader('Access-Control-Allow-Credentials', true);

    // Pass to next layer of middleware
    next();
});
var db=['0','0','0','0','0','0','0'];


app.get("/", (req,res)=>{
  res.json(db);
});

app.get("/add/:id", (req,res)=>{
  id=parseInt(req.params.id);

  if(db[id]=='0'){
  db[id]='1';
}
  else {
     db[id]='0';
   }
console.log(db[id]);
res.json(db[id]);


});
app.get("/bmi", function(req,res){
  res.sendFile(__dirname+"/index.html")

});




app.listen(3000);
