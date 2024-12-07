#include <wiringPi.h>
#include <iostream>

using namespace std;

void setup();
void loop();

// Define GPIO pin numbers 
#define LASER_PIN 0 // Pin connected to the laser receiver (GPIO 17) 
#define RED_LED_PIN 1 // Pin connected to the red LED (GPIO 18) 
#define GREEN_LED_PIN 2 // Pin connected to the green LED (GPIO 27)

int main(void)
{
    setup();
    loop();
    return 0;
}

void setup() { 
    wiringPiSetup(); // Initialize wiringPi 

    // Set the pin modes 
    pinMode(LASER_PIN, INPUT); // Laser receiver as input 
    pinMode(RED_LED_PIN, OUTPUT); // Red LED as output 
    pinMode(GREEN_LED_PIN, OUTPUT); // Green LED as output 

    // Initial state: Green LED on, Red LED off 
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