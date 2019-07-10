/*
   Include the various libraries that we need
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

const char *ssid = "<ask>";
const char *password = "<ask>";

ESP8266WebServer server(80); // Create a webserver object that listens for HTTP request on port 80

/*
 * Functions to handle the clients calling the webserver
 */

/*
 * Send HTTP status 200 (Ok) and say hello
 */
void handleRoot()
{
  server.send(200, "text/plain", "Hello world!");
  Serial.println("Root Page Requested");
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
  server.on("/", handleRoot);

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
