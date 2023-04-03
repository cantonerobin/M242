/*********************************************************************************************************
  Autor:    Robin Schoch, Robin Cantone
  Version:  1.0
  Date:     03.04.2023
*********************************************************************************************************/

//Libaries einbinden
//*********************************************************************************************************
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

// Variablen Deklarieren
//**********************************************************************************************
// Button_01
int button_01_state = 0;

//Lichtwellensensor 
int sensor_01 = 0;

// Relay
int relay_1 = 1;
int relay_2 = 2;

// Potentiometer
float Potentiometer_prozent = 0.0;
int mixture_set = 0;

// How the Devices are Connected
//**********************************************************************************
// PullUp https://docs.arduino.cc/tutorials/generic/digital-input-pullup

// Button_01 connected on Pin 2 and Ground

// LCD Display connected on SCL => SCL , GND => GND , VCC => 5V , SDA => SDA
// https://www.arduino.cc/reference/en/libraries/liquidcrystal/

// Potentiometer connected SIG = A3 , GND = GND , VCC = VCC
// https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial

// Näherungssensor/Lichtschranke VCC => VCC , GND =Y GND , AO => A1 

// Relay
// https://docs.arduino.cc/tutorials/mkr-relay-proto-shield/mkr-relay-shield-basic
//**************************************************************************************

//*******************************
// Debug Stuff
// Shows Variable Value at Serial Monitor
// //Serial.println(variable);

// Start Setup 
//**************************************
void setup() {

// Setup the Pins
  //Button_01
  pinMode(3, INPUT_PULLUP); // Pullup adds Resistance
  pinMode(LED_BUILTIN, OUTPUT);

  //Relay
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);

  //Potentiometer
  Serial.begin(9600);
      // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
    // Print a message to the LCD.
  lcd.print("Startup");
}

void loop() {
  //BUTTON
  // read the state of the pushbutton value
  button_01_state = digitalRead(3);
  // check if button_01 is pressed.  if it is, thebutton_01_state is HIGH
  if (button_01_state == HIGH) {
    // Button_01 nicht gedrückt = hohe Spannung
    //lcd.print("BUTTON OFF");
    //Relay_1 aktivieren , Pumpe 1 wird eingeschalten
    //digitalWrite(relay_1, LOW);
  }
  else {
    // Button_01 gedrückt = niedrige Spannung
    lcd.print("BUTTON ON");
    //Relay_1 ist NICHT aktiviert , Pumpe 1 ist ausgeschalten
    //digitalWrite(relay_1, HIGH);
    delay(500); // Delay a little bit to improve simulation performance
  }
  /*
  // Set up percent based Mixture

 if ( mixture_set == 0) {
    //Store Value of the Potentiometer in Variable
    int Potentiometer_int = analogRead(A3);
    // Calculate percent value
    Potentiometer_prozent = Potentiometer_int / 1023.0 * 100.0; // Musste bei den Nummer die Nachkommastelle hinzufügen, weil das Resultat sonst abgerundet wird
    // Show percent at screen
    lcd.print(Potentiometer_prozent);
    delay(200);
    lcd.clear();

  if (button_01_state == LOW) {
    // Set variable to 1 so this if will not be repeated
    mixture_set = 1;
    delay(500);
  }
  else {}
 }
 else {}

 lcd.print(Potentiometer_prozent);
 */
  // Lichtschranke
  sensor_01=analogRead(A1);
  
if (sensor_01 < 500) {
 lcd.print("Nahe");

}
else{
   lcd.print("Fern");
}
 //Clear Screen
  delay(100);
  lcd.clear();

}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/