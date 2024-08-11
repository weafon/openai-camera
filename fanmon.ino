#include "private.h" // put your definition of YOURSSD, WIFIPASS, OPENAIKEY here to prevent from the commition on github
#include "esp_http_server.h"
#include "esp_timer.h"
#include "esp_camera.h"
#include "img_converters.h"
#include "fb_gfx.h"
#include "sdkconfig.h"
#include <WiFi.h>
//#include <WiFiClientSecure.h>
//#include <ArduinoJson.h>
//#include <ChatGPT.hpp>
//#include <BluetoothSerial.h>
//#include <WebServer.h>
//BluetoothSerial BT;

#include "camera.h"
static const char *ssid = YOURSSID;
static const char *pass = WIFIPASS;

//WiFiClientSecure client;
//ChatGPT<WiFiClientSecure> chatGPT_Client(&client, "v1", OPENAIKEY, 60000);
bool inited=false;


void setup() {
  
  Serial.begin(115200);

  Serial.printf("init camera\n");
  if (camera_init()!=0) {
    Serial.print("Fail to init camera.");
    return;
  }
  Serial.print("Connecting to WiFi network: ");
  Serial.print(ssid);
  Serial.println("'...");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(1000);
  }
  Serial.println("Connected!");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());  
  startCameraServer();
  // Ignore SSL certificate validation
  //client.setInsecure();
  inited=true;
 
}



void loop() 
{
  if (inited==false)
    return;
  delay(1000);
}
