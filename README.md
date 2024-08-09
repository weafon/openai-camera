# openai-camera
A small and interesting code to take a picture from esp32-cam and then ask Openai what it is.

The small code that combines two library examples. The first is ChatGPT_Client and the second is camera_example in esp32_camera.

This small code will get a jpg photo from esp32-cam, then base64 encode the photo, and then send it to openai for query.

Before compiling, please remember to add the "ChatGPT_Client" library to the arduino ide. Thanks to Eric Nam for writing the library to access openai.

Please also remember to define yourssid, wifipass, openaikey. You can define them in private.h or modify them directly in openai-camera.ino.

Asking for a photo through openai only costs you <0.01 USD. So don’t worry.
