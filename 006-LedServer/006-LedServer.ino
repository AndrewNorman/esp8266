/*
 * Include the various libraries that we need
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

const char *ssid = "BjssWifi";
const char *password = "bjssweekend";

/*
 * Connect the LEDs (plus resistor) to the pins
 * that you have entered the number below
 */
#define RED_LED 16
#define BLUE_LED 5
#define GREEN_LED 4
#define WHITE_LED 0
#define YELLOW_LED 2

ESP8266WebServer server(80); // Create a webserver object that listens for HTTP request on port 80

void turnOnLed(int led_pin)
{
   /*
    * Turn off all the LEDS
    */
   digitalWrite(RED_LED, LOW);
   digitalWrite(BLUE_LED, LOW);
   digitalWrite(GREEN_LED, LOW);
   digitalWrite(WHITE_LED, LOW);
   digitalWrite(YELLOW_LED, LOW);
   /*
    * Turn on the LED we want on
    */
   digitalWrite(led_pin, HIGH);
}

/*
 * Functions to handle the clients calling the webserver
 */

// Send HTTP status 200 (Ok) and turn on the Red LED
void turnOnRed()
{
   server.send(200, "text/plain", "Red On");
   Serial.println("Red LED On");
   turnOnLed(RED_LED);
}

// Send HTTP status 200 (Ok) and turn on the Blue LED
void turnOnBlue()
{
   server.send(200, "text/plain", "Blue On");
   Serial.println("Blue LED On");
   turnOnLed(BLUE_LED);
}

// Send HTTP status 200 (Ok) and turn on the Green LED
void turnOnGreen()
{
   server.send(200, "text/plain", "Green On");
   Serial.println("Green LED On");
   turnOnLed(GREEN_LED);
}

// Send HTTP status 200 (Ok) and turn on the White LED
void turnOnWhite()
{
   server.send(200, "text/plain", "White On");
   Serial.println("White LED On");
   turnOnLed(WHITE_LED);
}

// Send HTTP status 200 (Ok) and turn on the Yellow LED
void turnOnYellow()
{
   server.send(200, "text/plain", "Yellow On");
   Serial.println("Yellow LED On");
   turnOnLed(YELLOW_LED);
}

/*
 * Send HTTP Status 404 (Not Found) when we cannot find
 * the page that the client asked for
 */
void handleNotFound()
{
   server.send(404, "text/plain", "404: Not found");
   Serial.println("Unknown Page Requested");
}

void setup(void)
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
    * Set the digital pins that have LED
    * attached to operate as an Output pins
    */
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
   pinMode(GREEN_LED, OUTPUT);
   pinMode(WHITE_LED, OUTPUT);
   pinMode(YELLOW_LED, OUTPUT);

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

   /*
    * Add in the pages that the webserver knows about the
    * link the function that will be called when the page
    * is requested by the client.
    */
   server.on("/red", turnOnRed);
   server.on("/green", turnOnGreen);
   server.on("/blue", turnOnBlue);
   server.on("/yellow", turnOnYellow);
   server.on("/white", turnOnWhite);

   /*
    * Add in the function that will handle the times when
    * the client asks for a page that cannot be found
    */
   server.onNotFound(handleNotFound);

   /*
    * Start the webserver
    */
   server.begin();
   Serial.println("HTTP server started");
}

void loop(void)
{
   /*
    * This needs to be called each loop so we can handle any
    * client trying to talk to the WebServer.
    */
   server.handleClient();
}
