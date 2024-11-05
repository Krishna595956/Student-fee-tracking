#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Act";
const char* password = "Madhumakeskilled";
const char* apiRoute="https://makeskilled.com/hackathond/api/sim800";

String getDataFromAPI(){
  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    http.begin(apiRoute);
    int responseCode=http.GET();
    if(responseCode>0){
      String response=http.getString();
      Serial.println(response);
      http.end();
    return response;
    }
  }
}

void setup() {
  // ... other setup code
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  getDataFromAPI();
}


void loop() {
//    if (Serial.available()) {    // Check if data is available from the RFID reader
//    String rfidData = "";
//    while (Serial.available()) {
//      char c = Serial.read();  // Read a character from UART0
//      rfidData += c;           // Add it to the string
//    }
//    Serial. println(rfidData);
//    int result=getDataFromAPI(rfidData);
//    Serial.println(result);
//  }
//  delay(100);
}
