// This #include statement was automatically added by the Particle IDE.
#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();
int published = 0;

void setup() {
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

void runRecipe(const char *event, const char *data)
{
    if (String(data) == "Recipe 1") {
        blinkLED(12, 0, 0, 255);
    } else if (String(data) == "Recipe 2") {
        blinkLED(3, 0, 0, 255);
    } else if (String(data) == "Recipe 3") {
        blinkLED(6, 0, 0, 255);
    } else if (String(data) == "Recipe 4") {
        blinkLED(9, 0, 0, 255);
    }
}

void loop() {
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

