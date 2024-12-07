#include <wiringPi.h>
#include <iostream>

using namespace std;

void setup();
void loop();

// Define GPIO pin numbers 
// Pin connected to the laser receiver (GPIO 17)
// Pin connected to the red LED (GPIO 18)
// Pin connected to the green LED (GPIO 27)
#define LASER_PIN 0  
#define RED_LED_PIN 1  
#define GREEN_LED_PIN 2 

int main(void)
{
    setup();
    loop();
    return 0;
}

// Set the pin modes 
// Initial state: Green LED on, Red LED off 
// Laser receiver as input
// Red LED as output 
// Green LED as output 
void setup() { 
    wiringPiSetup(); 
    
    pinMode(LASER_PIN, INPUT);  
    pinMode(RED_LED_PIN, OUTPUT); 
    pinMode(GREEN_LED_PIN, OUTPUT); 
    
    digitalWrite(GREEN_LED_PIN, HIGH); 
    digitalWrite(RED_LED_PIN, LOW); 
}

void loop(){
    while(true) {
        if (digitalRead(LASER_PIN) == LOW) {
            digitalWrite(GREEN_LED_PIN, LOW);
            digitalWrite(RED_LED_PIN, HIGH);
            cout << "laser beam broken: Red LED on" << endl;
        }else{
            digitalWrite(GREEN_LED_PIN, HIGH);
            digitalWrite(RED_LED_PIN, LOW);
            cout << "Laser bean intact: green LED on" << endl;
        }
        delay(100)
    }
}