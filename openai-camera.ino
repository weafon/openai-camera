#include "private.h" // put your definition of YOURSSD, WIFIPASS, OPENAIKEY here to prevent from the commition on github
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <ChatGPT.hpp>

#include "camera.h"
static const char *ssid = YOURSSID;
static const char *pass = WIFIPASS;

WiFiClientSecure client;
ChatGPT<WiFiClientSecure> chatGPT_Client(&client, "v1", OPENAIKEY, 60000);

void setup() {
  bool inited=false;
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

  // Ignore SSL certificate validation
  client.setInsecure();
  inited=true;
}

void loop() {

  String result;
  char* imgdata;
  if (inited==false)
    return;
  Serial.println("[ChatGPT] - camera vision");
  Serial.println("press 't' to take picture");
  while(Serial.read()!='t')
    delay(1000);

  int sz = camera_take2base64(&imgdata);
  Serial.printf("submit pic (%d bytes) to openai.\n", sz);
  unsigned long tm_start = millis();
  if (chatGPT_Client.vision_question("gpt-4o-mini", "user", "text", 
            "Directly point out the focus item in the picture", "image_url", 
            imgdata, "auto", 30, true, result)) {
    Serial.printf("escape %lu ms\n", millis()-tm_start);
    Serial.print("[ChatGPT] Response: ");
    Serial.println(result);
  } else {
    Serial.printf("escape %lu ms\n", millis()-tm_start);
    Serial.print("[ChatGPT] Error: ");
    Serial.println(result);
  }
  free(imgdata);
}
