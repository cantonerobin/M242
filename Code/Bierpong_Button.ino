/*********************************************************************************************************
  Autor:    Robin Schoch, Robin Cantone
  Version:  1.0
  Date:     03.04.2023
*********************************************************************************************************/
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int buttonState = 0;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Startup");
  //BUTTON, Setup which Pin is used and PULLUP to setup resistance
  pinMode(3, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //BUTTON
  // read the state of the pushbutton value
  //buttonState = digitalRead(2);
  // check if pushbutton is pressed.  if it is, the buttonState is HIGH
  //if (buttonState == HIGH) {
    // Button nicht gedrückt = hohe Spannung
  //  lcd.print("BUTTON OFF");
  //}
  //else {
    // Button gedrückt = niedrige Spannung
  //  lcd.print("BUTTON ON");
  //}
  //delay(500); // Delay a little bit to improve simulation performance
 
  //Store Value of the Potentiometer in Variable
  //int Potentiometer = analogRead(A3);
  //lcd.print(Potentiometer);
  //Serial.println(Potentiometer);
  //delay(100);
  // Lichtschranke
  //sensor=analogRead(A1);
  //Serial.println(sensor);


buttonState = digitalRead(3);
// Pumpe
if (buttonState == HIGH) {
     //Button nicht gedrückt = hohe Spannung
    lcd.print("BUTTON OFF");
  }
  else {
    // Button gedrückt = niedrige Spannung
    lcd.print("BUTTON ON");
  }

  delay(100);
 //Clear Screen
  lcd.clear();

}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/