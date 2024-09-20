#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Ivo";
const char* pass = "0886575995@";

const int pusher = D1;

ESP8266WebServer server(80);


void handleRoot() {
  String index = "<!DOCTYPE html>";
index+="<html>";
index+="<head>";
    index+="<title>Roomba</title>";
    index+="<style>";
        index+=".emoji {";
            index+="font-size: 100px;";
            index+="text-align: center;";
            index+="color: red;";
        index+="}";
    index+="</style>";
    index+="<script>";

        index+="function updateDigitalInput() {";
            index+="var xhttp = new XMLHttpRequest();";
            index+="xhttp.onreadystatechange = function() {";
                index+="if (this.readyState == 4 && this.status == 200) {";
                  index+="if (this.responseText == 'true'){";
                    index+="document.getElementById('audioPlayer').play();";
                  index+="}";
                index+="}";
            index+="};";
            index+="xhttp.open('GET', 'http://"+WiFi.localIP().toString()+":80/digitalInput', true);";
            index+="xhttp.send();";
        index+="}";

        index+="setInterval(updateDigitalInput, 300);";

    index+="</script>";
index+="</head>";
index+="<body>";
    index+="<div id='emoji' class='emoji'>&#9786;</div>";
    index+="<audio id='audioPlayer' src='http://192.168.1.105:3000' type='audio/mp3'></audio>";

    index+="<script>";
        index+="var audio = document.getElementById('audioPlayer');";
        index+="audio.onended = function () {";
            index+="document.getElementById('emoji').innerHTML='&#9786;';";
            index+="location.reload();";
        index+="};";
        index+="audio.onplay = function () {";
            index+="document.getElementById('emoji').innerHTML='&#128561;';";
        index+="};";
    index+="</script>";
index+="</body>";
index+="</html>";
  server.send(200, "text/html", index);
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(1000);
WiFi.begin(ssid, pass);
while(WiFi.status() != WL_CONNECTED){
  delay(1000);
  Serial.print("Connecting...");
}

Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP().toString());
  
  server.on("/", handleRoot);
  server.on("/digitalInput", HTTP_GET, []() {
    String digitalInputStatus = "false";
    if(digitalRead(pusher) == 0){
      digitalInputStatus = "true";
      Serial.println("test");
    }
    server.send(200, "text/plain", digitalInputStatus);
  });
  server.begin();

pinMode(pusher, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
