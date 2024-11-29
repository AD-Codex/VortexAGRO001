
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "Eng-Student"
#define WIFI_PASSWORD "3nG5tuDt"

#define API_KEY "AIzaSyBTqEoi6MTNq_EwN3yyg3lWdsQbRRqGbYQ"
#define DATABASE_URL "https://esp32conect123-default-rtdb.asia-southeast1.firebasedatabase.app/" 


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

bool signupOK = false;


// initialize firebase DB with WIFI ----------------------------------
void ini_Firebase() {

  // connect to WIFI device --------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();


  // Connect to firebase DB ----------------------
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("Connected to Fire DB");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

}



