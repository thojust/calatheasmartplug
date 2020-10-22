

/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com
*********/

// Load Wi-Fi library
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
/////////////////////////// BUTTON STUFFFF/////////////////////////
#include <SPI.h>
#include <Button2.h>

#define BUTTON_A_PIN  5
#define BUTTON_B_PIN  4

Button2 buttonA = Button2(BUTTON_A_PIN);
Button2 buttonB = Button2(BUTTON_B_PIN);

/////////////////////////END BUTTON STUFF //////////////////////////

// Replace with your network credentials
const char* ssid     = "PlantBasedWifi";
const char* password = "Pothos!3";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state

String output1State = "off";
String output2State = "off";

// Assign output variables to GPIO pins
const int output1 = 13;
const int output2 = 14;


// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(9600);
  WiFi.hostname("calathea");

  // Initialize the output variables as outputs
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);


  /// Setup for Button 
  buttonA.setClickHandler(click);
  buttonB.setClickHandler(click);

 ///// ////////////////////////////////////////
  
  // Set outputs to LOW
  digitalWrite(output1, HIGH);
  digitalWrite(output2, HIGH);



  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  buttonA.loop();
  buttonB.loop();
  
WiFiClient client = server.available();   // Listen for incoming clients

  if (client) { 
     int OffMode13 = (digitalRead(13) == HIGH);
     int OffMode14 = (digitalRead(14) == HIGH);
     int OnMode13 = (digitalRead(13) == LOW);
     int OnMode14 = (digitalRead(14) == LOW);
     
     // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("GPIO 1 on");
              output1State = "on";
              digitalWrite(output1, LOW);
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("GPIO 1 off");
              output1State = "off";
              digitalWrite(output1, HIGH);
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(output2, LOW);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(output2, HIGH);
            }
            
             
            // Display the HTML web page
              client.println("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">");
              client.println("<html xmlns=\"http://www.w3.org/1999/xhtml\">");
              client.println("<head>");
              client.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />");
              client.println("<title>Calathea Smart Plug</title> ");
              client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=0.50\" /> ");
              client.println("<style>");
              client.println("");
              client.println("");
              client.println("");
              client.println("");
              client.println("body{");
              client.println("");
              client.println(" background: repeating-radial-gradient(circle at bottom left, #fedc00 0, #fedc00 5.5555555556%, #fcb712 0, #fcb712 11.1111111111%, #f7921e 0, #f7921e 16.6666666667%, #e87f24 0, #e87f24 22.2222222222%, #dd6227 0, #dd6227 27.7777777778%, #dc4c27 0, #dc4c27 33.3333333333%, #ca3435 0, #ca3435 38.8888888889%, #b82841 0, #b82841 44.4444444444%, #953751 0, #953751 50%, #364c88 0, #364c88 55.5555555556%, #16599d 0, #16599d 61.1111111111%, #02609e 0, #02609e 66.6666666667%, #0073a9 0, #0073a9 72.2222222222%, #008aa4 0, #008aa4 77.7777777778%, #239a87 0, #239a87 83.3333333333%, #7cba6d 0, #7cba6d 88.8888888889%, #becc2f 0, #becc2f 94.4444444444%, #e0d81d 0, #e0d81d 100%), repeating-radial-gradient(circle at bottom right, #fedc00 0, #fedc00 5.5555555556%, #fcb712 0, #fcb712 11.1111111111%, #f7921e 0, #f7921e 16.6666666667%, #e87f24 0, #e87f24 22.2222222222%, #dd6227 0, #dd6227 27.7777777778%, #dc4c27 0, #dc4c27 33.3333333333%, #ca3435 0, #ca3435 38.8888888889%, #b82841 0, #b82841 44.4444444444%, #953751 0, #953751 50%, #364c88 0, #364c88 55.5555555556%, #16599d 0, #16599d 61.1111111111%, #02609e 0, #02609e 66.6666666667%, #0073a9 0, #0073a9 72.2222222222%, #008aa4 0, #008aa4 77.7777777778%, #239a87 0, #239a87 83.3333333333%, #7cba6d 0, #7cba6d 88.8888888889%, #becc2f 0, #becc2f 94.4444444444%, #e0d81d 0, #e0d81d 100%);");
              client.println(" background-blend-mode: overlay;");
              client.println(" height: 100vh;");
              client.println(" text-align:center;");
              client.println(" padding:10%;");
              client.println(" font-family:\"Lucida Console\", Monaco, monospace;");
              client.println(" ");
              client.println(" ");
              client.println("}");
              client.println("");
              client.println("");
              client.println("#plugwrap {");
              client.println(" border-radius: 100px;");
              client.println(" background: #FFF;");
              client.println(" padding: 20px;");
              client.println(" width: 600px;");
              client.println(" height: 100px; ");
              client.println(" box-shadow: 5px 5px 10px 1px #030;");
              client.println(" margin-left:auto;");
              client.println(" margin-right:auto;");
              client.println("");
              client.println("}");
              client.println(".box {");
              client.println(" display:block;");
              client.println(" border-radius: 100px;");
              client.println(" width:200px;");
              client.println(" height:80px;");
              client.println(" text-align:center;");
              client.println(" padding:10px;");
              client.println(" background-color:#CFF0C3;");
              client.println(" ");
              client.println("}");
              client.println(".right {");
              client.println(" float: right;");
              client.println(" ");
              client.println("}");
              client.println(".left{ ");
              client.println(" float: left;");
              client.println("}");
              client.println("");
              client.println(".button { border: none; color: white; padding: 20px; border-radius:50px; height:40px; display:block; font-size:35px; cursor:pointer;} ");
              client.println("");
              client.println(".round {");
              client.println(" border-radius:45px;");
              client.println(" height:45px;");
              client.println(" width:45px;");
              client.println(" background-color:#CFF0C3;");
              client.println("}");
              client.println(".off{");
              client.println(" background-color:#005493;}");
              client.println(".on{");
              client.println(" background-color:#0096FF;}");
              client.println("h1{");
              client.println(" font-size: 4vw;");
              client.println(" text-shadow: 1px 1px 2px #fff, 1px 1px 2px #ccc;");
              client.println("}");
              client.println("");
              client.println(".button55 {");
              client.println(" text-decoration: none; ");
              client.println(" font-size:15px;");
              client.println(" border-radius:20px;");
              client.println(" height:20px;");
              client.println(" width:20px;");
              client.println(" background-color:#FFF;");
              client.println(" text-align:center;");
              client.println(" float:left;");
              client.println(" padding:10px;");
              client.println(" cursor:pointer;");
              client.println(" display:block;");
              client.println("}");
              client.println(".status{");
              client.println(" display:block;");
              client.println(" float: left;");
              client.println(" margin-right:10px;");
              client.println(" margin-top:10px;");
              client.println(" width:290px;");
              client.println("}");
              client.println("");
              client.println("input {");
              client.println(" display:block;");
              client.println(" margin:10px;");
              client.println(" float: left;");
              client.println(" border-radius:10px;");
              client.println(" font-size:16px;");
              client.println(" background-color:white;");
              client.println(" border:none;");
              client.println(" padding:5px;");
              client.println("");
              client.println("}");
              client.println("#advanced {");
              client.println(" margin-top:50px;");
              client.println(" padding:10px;");
              client.println(" width:600px;");
              client.println(" margin-left:auto;");
              client.println(" margin-right:auto;");
              client.println(" background-color:#CCC;");
              client.println(" height:190px;");
              client.println(" border-radius:25px;");
              client.println(" opacity:70%;");
              client.println("");
              client.println(" ");
              client.println("}");
              client.println(".pad{");
              client.println(" padding-top: 5px;");
              client.println(" padding-right: 5px;");
              client.println(" padding-bottom: 0px;");
              client.println(" padding-left: 15px;");
              client.println("}");
              client.println("table,td, th{");
              client.println(" border-collapse: collapse;");
              client.println(" border:none;");
              client.println(" padding:0px;");
              client.println("}");
              client.println("#gear{");
              client.println(" display:block;");
              client.println(" float:left;");
              client.println(" width:160px;");
              client.println(" font-size:50px;");
              client.println(" cursor:pointer;");
              client.println("}");
              client.println("#gear:hover{");
              client.println(" color:#909;}");
              client.println(".hide{visibility:hidden;}");
              client.println(".show{visibility:visible;}");
              client.println(".small{font-size:10px;}");
              client.println("</style>");
              client.println("</head>");
              client.println("");
              client.println("<body>");
              client.println("<h1> Calathea Smart Plug Status </h1>");
              client.println("<div id=\"plugwrap\">");

            // Web Page Heading

            // Display current state, and ON/OFF buttons for GPIO 1
            //if (OnMode13 || output1State == "on"){client.println("<p>GPIO 13 - State ON </p>");}
            //else if (OffMode13 || output1State == "off"){client.println("<p>GPIO 13 - State OFF </p>");}
            // If the output5State is off, it displays the ON button
            if (OnMode13) {
              client.println("<div class=\"box left\" ><div onclick=\"OffButton1()\" class=\"button on\" id=\"button1\"> ON<div id=\"round1\" class=\"round right\"></div> </div></div><div onclick=\"gearButt()\" id=\"gear\">⚙</div>");
            } else if (OffMode13) {
              client.println("<div class=\"box left\" ><div onclick=\"OnButton1()\" class=\"button off\" id=\"button1\"> OFF<div id=\"round1\" class=\"round left\"></div> </div></div><div onclick=\"gearButt()\" id=\"gear\">⚙</div>");
            }

               // Display current state, and ON/OFF buttons for GPIO 1
            //if (OnMode14 || output2State == "on"){client.println("<p>GPIO 13 - State ON </p>");}
            //else if (OffMode14 || output2State == "off"){client.println("<p>GPIO 13 - State OFF </p>");}
            // If the output5State is off, it displays the ON button
            if (OnMode14) {
              client.println("<div class=\"box right\" ><div onclick=\"OffButton2()\" class=\"button on\" id=\"button2\"> ON<div id=\"round2\" class=\"round right\"></div> </div></div>");
            } else if (OffMode14) {
              client.println("<div class=\"box right\" ><div onclick=\"OnButton2()\" class=\"button off\" id=\"button2\"> OFF<div id=\"round2\" class=\"round left\"></div> </div></div>");
            }

                client.println("</div>");
                client.println("<div class=\"hide\" id=\"advanced\">");
                client.println("<table width=\"322\" height=\"169\" border=\"1\">");
                client.println(" <tr>");
                client.println(" <td><div class=\"status\" id=\"status1\"><input type=\"text\" value=\"http://192.168.0.107/1/on\" id=\"myInput1\"><div class=\"button55\" onClick=\"On1()\"> 🔗 </div></div>");
                client.println("</td>");
                client.println(" <td><div class=\"status\" id=\"status2\"><input type=\"text\" value=\"http://192.168.0.107/2/on\" id=\"myInput2\"><div class=\"button55\" onClick=\"On2()\"> 🔗 </div></div>");
                client.println("</td>");
                client.println(" </tr>");
                client.println(" <tr>");
                client.println(" <td><div class=\"status\" id=\"status3\"><input type=\"text\" value=\"http://192.168.0.107/1/off\" id=\"myInput3\"><div class=\"button55\" onClick=\"Off1()\"> 🔗 </div></div>");
                client.println("</td>");
                client.println(" <td><div class=\"status\" id=\"status4\"><input type=\"text\" value=\"http://192.168.0.107/2/off\" id=\"myInput4\"><div class=\"button55\" onClick=\"Off2()\"> 🔗 </div></div>");
                client.println("</td>");
                client.println(" </tr>");
                client.println(" </table>");
                client.println("<p class=\"small\"> compiled by <a href=\"https://github.com/thojust/\">justin thomas </a> 2020</p>");
                client.println("</div>");
                client.println("");
                client.println("<script>");
                client.println("const button1=document.getElementById(\"button1\");");
                client.println("const button2=document.getElementById(\"button2\");");
                client.println("function OnButton1() { ");
                client.println("fetch(\"http://192.168.0.107/1/on\"); ");
                client.println(" button1.classList.remove('off');");
                client.println(" button1.classList.add('on');");
                client.println(" button1.innerHTML = 'ON<div class=\"round right\"></div>';");
                client.println(" setTimeout(function(){ location.reload(true); }, 1000);");
                client.println(" ");
                client.println("};");
                client.println("");
                client.println("function OffButton1() { ");
                client.println("fetch(\"http://192.168.0.107/1/off\"); ");
                client.println(" button1.classList.remove('on');");
                client.println(" button1.classList.add('off');");
                client.println(" button1.innerHTML = 'OFF<div class=\"round left\"></div>';");
                client.println(" setTimeout(function(){ location.reload(true); }, 1000);");
                client.println(" ");
                client.println("};");
                client.println("function OnButton2() { ");
                client.println("fetch(\"http://192.168.0.107/2/on\"); ");
                client.println(" button2.classList.remove('off');");
                client.println(" button2.classList.add('on');");
                client.println(" button2.innerHTML = 'ON<div class=\"round right\"></div>';");
                client.println(" setTimeout(function(){ location.reload(true); }, 1000);");
                client.println(" ");
                client.println("};");
                client.println("");
                client.println("function OffButton2() { ");
                client.println("fetch(\"http://192.168.0.107/2/off\"); ");
                client.println(" button2.classList.remove('on');");
                client.println(" button2.classList.add('off');");
                client.println(" button2.innerHTML = 'OFF<div class=\"round left\"></div>';");
                client.println(" setTimeout(function(){ location.reload(true); }, 1000);");
                client.println(" ");
                client.println("};");
                client.println("//// SHow and hide settings /////");
                client.println("const advn=document.getElementById(\"advanced\");");
                client.println("function gearButt() { ");
                client.println(" advn.classList.remove('hide');");
                client.println(" advn.classList.add('show');");
                client.println("}");
                client.println("");
                client.println("");
                client.println("");
                client.println("///// FOr copying URLS /////");
                client.println(" const statusB1=document.getElementById(\"status1\");");
                client.println(" const statusB2=document.getElementById(\"status2\");");
                client.println(" const statusB3=document.getElementById(\"status3\");");
                client.println(" const statusB4=document.getElementById(\"status4\");");
                client.println(" function On1() {");
                client.println(" /* Get the text field */");
                client.println(" var copyText = document.getElementById(\"myInput1\");");
                client.println("");
                client.println(" /* Select the text field */");
                client.println(" copyText.select();");
                client.println(" copyText.setSelectionRange(0, 99999); /*For mobile devices*/");
                client.println("");
                client.println(" /* Copy the text inside the text field */");
                client.println(" document.execCommand(\"copy\");");
                client.println("");
                client.println(" /* Alert the copied text */");
                client.println("statusB1.innerHTML = '<div class=\"pad\">Copied Link to clipboard </div></div>';");
                client.println("");
                client.println("");
                client.println("} ");
                client.println("");
                client.println(" function On2() {");
                client.println(" /* Get the text field */");
                client.println(" var copyText = document.getElementById(\"myInput2\");");
                client.println("");
                client.println(" /* Select the text field */");
                client.println(" copyText.select();");
                client.println(" copyText.setSelectionRange(0, 99999); /*For mobile devices*/");
                client.println("");
                client.println(" /* Copy the text inside the text field */");
                client.println(" document.execCommand(\"copy\");");
                client.println("");
                client.println(" /* Alert the copied text */");
                client.println("statusB2.innerHTML = '<div class=\"pad\">Copied Link to clipboard </div></div>';");
                client.println("");
                client.println("");
                client.println("} ");
                client.println("");
                client.println(" function Off1() {");
                client.println(" /* Get the text field */");
                client.println(" var copyText = document.getElementById(\"myInput3\");");
                client.println("");
                client.println(" /* Select the text field */");
                client.println(" copyText.select();");
                client.println(" copyText.setSelectionRange(0, 99999); /*For mobile devices*/");
                client.println("");
                client.println(" /* Copy the text inside the text field */");
                client.println(" document.execCommand(\"copy\");");
                client.println("");
                client.println(" /* Alert the copied text */");
                client.println("statusB3.innerHTML = '<div class=\"pad\">Copied Link to clipboard </div></div>';");
                client.println("");
                client.println("");
                client.println("} ");
                client.println("");
                client.println(" function Off2() {");
                client.println(" /* Get the text field */");
                client.println(" var copyText = document.getElementById(\"myInput4\");");
                client.println("");
                client.println(" /* Select the text field */");
                client.println(" copyText.select();");
                client.println(" copyText.setSelectionRange(0, 99999); /*For mobile devices*/");
                client.println("");
                client.println(" /* Copy the text inside the text field */");
                client.println(" document.execCommand(\"copy\");");
                client.println("");
                client.println(" /* Alert the copied text */");
                client.println("statusB4.innerHTML = '<div class=\"pad\">Copied Link to clipboard </div></div>';");
                client.println("");
                client.println("");
                client.println("} ");
                client.println("");
                client.println("</script>");
                client.println("");
                client.println("</body>");
                client.println("</html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
////// BUTTON LOOP ///////////
void click(Button2& btn) {
  int OffMode13 = (digitalRead(13) == HIGH);
  int OffMode14 = (digitalRead(14) == HIGH);
  int OnMode13 = (digitalRead(13) == LOW);
  int OnMode14 = (digitalRead(14) == LOW);
  
    if (btn == buttonA) {
      if (OnMode13) { digitalWrite(output1, HIGH);
        Serial.println("Turning 13 OFF");
      }
       else if (OffMode13) { digitalWrite(output1, LOW);
        Serial.println("Turning 13 ON");
      }
      
    } else if (btn == buttonB) {
     
    if (OnMode14) { digitalWrite(output2, HIGH);
        Serial.println("Turning 14 OFF");
      }
       else if (OffMode14) { digitalWrite(output2, LOW);
        Serial.println("Turning 14 ON");
      }
    }
}
