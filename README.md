# openai-camera
  A small and interesting code that combines two library examples to take a picture from esp32-cam and then ask Openai what it is. The first library is ChatGPT_Client and the second one is camera_example in esp32_camera.

  This small code will get a jpg photo from esp32-cam, then encode the photo in base64, and then send it to openai for query. Before compiling, please remember to add the "ChatGPT_Client" library and the "base64_encode" library to the arduino ide. Thanks to Eric Nam Written library to access openai. Also remember to define yourssid, wifipass, openaikey. You can define them in private.h or modify them directly in openai-camera.ino. 
  
  The board I use is esp32-cam, and the lens module is ov2640. The board selected for Arduino IDE is AI Thinker ESP32-CAM.

  You may encounter many problems when using the esp32-cam board for the first time. Newbies are advised to complete the basic example CameraWebServer of esp32-cam before playing this small example.

  Asking for a photo through openai only costs you a little Money <0.01 USD. So don’t worry.
