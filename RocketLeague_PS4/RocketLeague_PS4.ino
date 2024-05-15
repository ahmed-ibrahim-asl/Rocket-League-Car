#include <PS4Controller.h>


#define MotorL_1 18
#define MotorL_2 5
 

#define MotorR_1 21
#define MotorR_2 19


#define GPIO_OUTPUT_PIN_SEL ((1ULL<<MotorR_1) | (1ULL<<MotorR_2) | (1ULL<<MotorL_1) | (1ULL<<MotorL_2))

inline void setMotorState(uint32_t setPins, uint32_t clearPins) {
    GPIO.out_w1ts = setPins;   // Set specified pins high
    GPIO.out_w1tc = clearPins; // Set specified pins low
}

void setup() {
    Serial.begin(115200);
    PS4.begin("cc:db:a7:63:95:42");
    Serial.println("Ready.");

    GPIO.enable_w1ts = GPIO_OUTPUT_PIN_SEL; // Enable output mode for all motor control pins
}

void loop() {
    if (PS4.isConnected()) {
        if (PS4.Left()) {
            setMotorState((1 << MotorR_2) | (1 << MotorL_2), (1 << MotorR_1) | (1 << MotorL_1));
        } else if (PS4.Right()) {
            setMotorState((1 << MotorR_1) | (1 << MotorL_1), (1 << MotorR_2) | (1 << MotorL_2));
        } else if (PS4.L1()) {
            setMotorState((1 << MotorR_2) | (1 << MotorL_1), (1 << MotorR_1) | (1 << MotorL_2));
        } else if (PS4.R1()) {
            setMotorState((1 << MotorR_1) | (1 << MotorL_2), (1 << MotorR_2) | (1 << MotorL_1));
        
        }
        
        else if (PS4.Cross()) Serial.println("Cross Button");

        
        else {
            setMotorState(0, (1 << MotorR_1) | (1 << MotorR_2) | (1 << MotorL_1) | (1 << MotorL_2));
        }

        
    }
}
