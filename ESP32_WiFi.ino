/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL1FFBD9xD"
#define BLYNK_DEVICE_NAME "ESP32"
#define BLYNK_AUTH_TOKEN "B0TjDHo7qAsxeADNGd4d46dpStftDM1U"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "B0TjDHo7qAsxeADNGd4d46dpStftDM1U";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Dinh Thanh";
char pass[] = "thanhdat16";

#define led 2
int btn;
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(led, OUTPUT);
}
BLYNK_WRITE(V1){
  btn = param.asInt();
  if (btn == 1)
  {
      digitalWrite(led, HIGH);
  }
  else 
    digitalWrite(led, LOW);
}
void loop()
{
  Blynk.run();
}

