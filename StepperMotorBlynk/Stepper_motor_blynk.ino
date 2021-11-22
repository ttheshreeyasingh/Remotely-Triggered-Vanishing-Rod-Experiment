#include <ESP8266WiFi.h> // Allows to connect to the NodeMCU via WiFi
#include <BlynkSimpleEsp8266.h> // Blynk header file to use blynk dashboard services

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "lEiughKLWXb6WgRltKi8APv9_EFoXL3U";

// Your WiFi credentials.
// Set password to "" for open networks.

// char ssid[] = "Skarr";
// char pass[] = "iiith@ece";

#define STEPPER_PIN_1 5 // D1 GPIO 5
#define STEPPER_PIN_2 4 // D2 GPIO 4
#define STEPPER_PIN_3 0 // D3 GPIO 0
#define STEPPER_PIN_4 2 // D4 GPIO 2

int step_number = 0;
int x = 0 , y = 0 ;     // x is for direction of motion , y is for enabling/disabling the motion

void setup() {
  // Setting the pin modes for the pins
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
   
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); // Initialize the blynk interface
}

BLYNK_WRITE(V2){  // enable input read through virtual pin 2
  y = param.asInt();
}
BLYNK_WRITE(V1){ // direction input read through virtual pin 1
  x = param.asInt(); 
} 

void loop() {

Blynk.run(); // Starting command for the blynk app

// Checks if the enable is turned ON or OFF
if ( y != 0 ) { 
    // If enable is ON, then move the motor in the direction specified by x
    Serial.print(x) ; 
    OneStep(1-x);
}

delay(3);
}


// This function toggles the 4 input pins in order after a 3 millisecond delay such that the motors rotate in the appropriate direction
void OneStep(bool dir) {
  if (dir) {
    switch (step_number) {
      case 0:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
    }
  } else {
    switch (step_number) {
      case 0:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);


    }
  }
  step_number++;
  if (step_number > 3) { // This loops the step number as soon as it exceeds 3
    step_number = 0;
  }
}
