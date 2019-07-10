// Include the Wi-Fi library
#include <ESP8266WiFi.h>

// The name and password of the Wi-Fi network to connect to
const char *ssid = "BjssWifi";
const char *password = "bjssweekend";

void setup()
{
   /*
    * Start the Serial communication
    *
    * This allows us to send information back to the computer
    * connected to the board.
    */
   Serial.begin(115200);
   delay(50);
   Serial.println('Starting');

   /*
    * Connect to the WIFI network using the username
    * and password specified above
    */
   WiFi.begin(ssid, password);
   Serial.print("Starting to connect to ");
   Serial.println(ssid);

   /*
    * Every second check to see if we are connected to
    * the WIFI network.
    * Each time we check output a '.' character to show
    * that we are still working.
    */
   while (WiFi.status() != WL_CONNECTED)
   {
      delay(1000);
      Serial.print('.');
   }
   Serial.println('\n');

   /*
    * Once we are connected output the IP address of
    * this end of the connect
    */
   Serial.println("Connected");
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
}

void loop()
{
}
