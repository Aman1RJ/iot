#include <ESP8266HTTPClient.h>


#include <ESP8266WiFi.h>




#include <ArduinoJson.h>;

int rel1=16;
int rel2=5;
int rel3=4;
int rel4=0;
int rel5=14;
int rel6=12;
int rel7=13;

const char* ssid = "aman"; //Enter SSID
const char* password = "Aman@1234";

void setup() {
  Serial.begin(9600);
  pinMode(rel1, OUTPUT);
  pinMode(rel2, OUTPUT);
  pinMode(rel3, OUTPUT);
  pinMode(rel4, OUTPUT);
  pinMode(rel5, OUTPUT);
  pinMode(rel6, OUTPUT);
  pinMode(rel7, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while(WiFi.status() !=WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.print("\nConnected");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
  }

void loop() {
 if((WiFi.status()== WL_CONNECTED))
 {
  HTTPClient client;
  client.begin("http://192.168.43.85:3000/");
  int httpCode= client.GET();
  String payload= client.getString();
  Serial.println(payload);
  Serial.println();
  char val='0' ;
   if((payload[2]) == val)
    digitalWrite(rel1, HIGH);
   
   else
    digitalWrite(rel1, LOW);

    if((payload[6]) == val)
    digitalWrite(rel2, HIGH);
   
   else
    digitalWrite(rel2, LOW);

    if((payload[10]) == val)
    digitalWrite(rel3, HIGH);
   
   else
    digitalWrite(rel3, LOW);
    
  if((payload[14]) == val)
    digitalWrite(rel4, HIGH);
   
   else
    digitalWrite(rel4, LOW);
    
    if((payload[18]) == val)
    digitalWrite(rel5, HIGH);
   
   else
    digitalWrite(rel5, LOW);

    if((payload[22]) == val)
    digitalWrite(rel6, HIGH);
   
   else
    digitalWrite(rel6, LOW);
    if((payload[26]) == val)
    digitalWrite(rel7, HIGH);
   
   else
    digitalWrite(rel7, LOW);


  
  
    
 }
 else{
  Serial.print("Connection Nai Hua h");
 }
 delay(200);
 
 }
