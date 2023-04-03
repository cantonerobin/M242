/*********************************************************************************************************
  Autor:    Robin Schoch, Robin Cantone
  Version:  1.0
  Date:     03.04.2023
*********************************************************************************************************/
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int buttonState = 0;
int sensor = 0;

int relay_1 = 1;
int relay_2 = 2;

// PullUp https://docs.arduino.cc/tutorials/generic/digital-input-pullup

// Button connected on Pin 2 and Ground

// LCD Display connected on SCL => SCL , GND => GND , VCC => 5V , SDA => SDA
// https://www.arduino.cc/reference/en/libraries/liquidcrystal/


// Potentiometer connected SIG = A3 , GND = GND , VCC = VCC
// https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial

// Näherungssensor/Lichtschranke VCC => VCC , GND =Y GND , AO => A1 

// Relay
// https://docs.arduino.cc/tutorials/mkr-relay-proto-shield/mkr-relay-shield-basic
// 

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Startup");
  //BUTTON, Setup which Pin is used and PULLUP for not the resistance
  pinMode(3, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  //Potentiometer
  Serial.begin(9600);

  //Pumpe
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
}

void loop() {
  //BUTTON
  // read the state of the pushbutton value
  buttonState = digitalRead(3);
  // check if pushbutton is pressed.  if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // Button nicht gedrückt = hohe Spannung
    lcd.print("BUTTON OFF");
    //Relay_1 aktivieren , Pumpe 1 wird eingeschalten
    digitalWrite(relay_1, LOW);
  }
  else {
    // Button gedrückt = niedrige Spannung
    lcd.print("BUTTON ON");
    //Relay_1 ist NICHT aktiviert , Pumpe 1 ist ausgeschalten
    digitalWrite(relay_1, HIGH);
  }
  delay(500); // Delay a little bit to improve simulation performance
 
  //Store Value of the Potentiometer in Variable
  //int Potentiometer = analogRead(A3);
  //lcd.print(Potentiometer);
  //Serial.println(Potentiometer);
  //delay(100);
  // Lichtschranke
  //sensor=analogRead(A1);
  //Serial.println(sensor);


 //Clear Screen
  lcd.clear();

}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/