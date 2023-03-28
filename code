
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int buttonState = 0;
int sensor = 0;

// PullUp https://docs.arduino.cc/tutorials/generic/digital-input-pullup

// Button connected on Pin 2 and Ground

// LCD Display connected on SCl => SCL , GND => GND , VCC => 5V , SDA => SDA
// https://www.arduino.cc/reference/en/libraries/liquidcrystal/


// Potentiometer connected SIG = A3 , GND = GND , VCC = VCC
// https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial

// Näherungssensor/Lichtschranke VCC => VCC , GND =Y GND , AO => A1 

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Startup");
  //BUTTON, Setup which Pin is used and PULLUP for not the resistance
  pinMode(2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  //Potentiometer
  Serial.begin(9600);
}

void loop() {
  //BUTTON
  // read the state of the pushbutton value
  buttonState = digitalRead(2);
  // check if pushbutton is pressed.  if it is, the buttonState is HIGH
  if (buttonState == HIGH ) { //and button1 != 0
    // Button nicht gedrückt = hohe Spannung
    
    lcd.print("BUTTON OFF");
    //int button1 = 0;
  }
  else {
    // Button gedrückt = niedrige Spannung
    lcd.print("BUTTON ON");
    //int button1 = 1;
  }
  delay(500); // Delay a little bit to improve simulation performance
  //Clear Screen
  lcd.clear();
  //Store Value of the Potentiometer in Variable
  int Potentiometer = analogRead(A3);
  lcd.print(Potentiometer);
  Serial.println(Potentiometer);
  delay(100);

  sensor=analogRead(A1); 
  Serial.println(sensor); 
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/