const express=require("express");
const bodyParser=require("body-parser");
const app=express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
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
