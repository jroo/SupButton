// This #include statement was automatically added by the Particle IDE.
#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();
int published = 0;
uint32_t notificationTimeOut = 300000; //five minutes
uint32_t notificationTime;
int notificationOn = 0;

void setup() {
    Serial.begin(9600);
    Particle.subscribe("SupRecipe", runRecipe);
    b.begin();
}

void blinkLED(int led, int rc, int gc, int bc) {
    for (int i=0; i<5; i++) {
        b.ledOn(led, rc, gc, bc);
        delay(1000);
        b.ledOff(led);
        delay(1000);
    }
}

void showAll(int rc, int gc, int bc) {
    for (int i=1; i<=12; i++) {
        b.ledOn(i, rc, gc, bc);
    }
}

void clearAll() {
    for (int i=1; i<=12; i++) {
        b.ledOn(i, 0, 0, 0);
    }
}

void clearNotification() {
    notificationOn = 0;
    clearAll(); //clear LEDs
}

void runRecipe(const char *event, const char *data)
{
    if (String(data) == "Recipe 1") {
        // do nothing
    } else if (String(data) == "Recipe 2") {
        // do nothing
    } else if (String(data) == "Recipe 3") {
        notificationTime = millis();
        showAll(255, 255, 255);
        notificationOn = 1;
    } else if (String(data) == "Recipe 4") {
        // do nothing
    }
}

void loop() {
    // if notification is on, check for timeout
    if (notificationOn && ((millis() - notificationTime) > notificationTimeOut)) {
        clearNotification();
    }
    if(b.buttonOn(1)) {
        if(!published) {
            Particle.publish("SupRecipe", "Recipe 1");
            published = 1;                                  
        }
    } else if (b.buttonOn(2)) {
         if(!published) {
            Particle.publish("SupRecipe", "Recipe 2");
            published = 1;                                  
        }   
    } else if (b.buttonOn(3)) {
         if(!published) {
            Particle.publish("SupRecipe", "Recipe 3");
            published = 1;                                  
        }   
    } else if (b.buttonOn(4)) {
         if(!published) {
            Particle.publish("SupRecipe", "Recipe 4");
            published = 1;                                  
        }      
    }
    else {published = 0;} 
}

