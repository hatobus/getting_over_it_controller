#include <Nunchuk.h>
#include <Wire.h>
#include <Mouse.h>
#include <math.h>

void setup() {
    Serial.begin(9600);
    Wire.begin();
    // nunchuk_init_power(); // A1 and A2 is power supply
    nunchuk_init();
}

void loop() {
    if (nunchuk_read()) {
        // Work with nunchuk_data
        nunchuk_print();
        
        int xpoint = nunchuk_joystickX();
        int ypoint = -1 * nunchuk_joystickY();
        
        //Serial.println(xpoint);
        // Print debug

        if(fabs(xpoint) < 5) xpoint = 0;
        if(fabs(ypoint) < 7) ypoint = 0; 

        Serial.println(xpoint);
        
        Mouse.move(xpoint, ypoint, 0);
    }


    // Left click
    if(nunchuk_buttonC() == 1 && nunchuk_buttonZ() != 1){
      if (!Mouse.isPressed(MOUSE_LEFT)) {
         Mouse.press(MOUSE_LEFT);
      }
    }
    else {
      // if the mouse is pressed, release it:
      if (Mouse.isPressed(MOUSE_LEFT)) {
        Mouse.release(MOUSE_LEFT);
      }
    }

    // Right click
    if(nunchuk_buttonC() != 1 && nunchuk_buttonZ() == 1){
      if (!Mouse.isPressed(MOUSE_RIGHT)) {
         Mouse.press(MOUSE_RIGHT);
      }
    }
    else {
      // if the mouse is pressed, release it:
      if (Mouse.isPressed(MOUSE_RIGHT)) {
        Mouse.release(MOUSE_RIGHT);
      }
    }
    delay(10);
}

