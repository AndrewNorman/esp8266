/*
 * Connect the Red LED (plus resistor) to the pin
 * that you have entered the number below
 */
#define RED_LED 16
#define BLUE_LED 5
#define GREEN_LED 4
#define WHITE_LED 0
#define YELLOW_LED 2

/*
 * Set the digital pins that have LED
 * attached to operate as an Output pins
 * 
 * i.e. We can turn it on and off by writing to it
 */
void setup()
{
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

/*
 * Turn on a LED, wait 1 second, turn on the next and so on
 */
void loop()
{
  Serial.println("Red");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  delay(1000);

  Serial.println("Blue");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  delay(1000);

  Serial.println("Green");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  delay(1000);

  Serial.println("White");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(WHITE_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  delay(1000);
  
  Serial.println("Yellow");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(1000);
}
