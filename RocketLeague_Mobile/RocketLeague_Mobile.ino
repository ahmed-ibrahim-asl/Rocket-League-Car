#include "BluetoothSerial.h"



/** Bluetooth section **/
BluetoothSerial serialBT;
char btSignal;
/***********************/

//////// Motors Pins //////
#define MotorL_1        21
#define MotorL_2        19
#define MotorR_1        18
#define MotorR_2        5
///////////////////////////
#define GPIO_OUTPUT_PIN_SEL ((1ULL<<MotorR_1) | (1ULL<<MotorR_2) | (1ULL<<MotorL_1) | (1ULL<<MotorL_2))


inline void setMotorState(uint32_t setPins, uint32_t clearPins) {
  GPIO.out_w1ts = setPins;   // Set specified pins high
  GPIO.out_w1tc = clearPins; // Set specified pins low
}

void setup() {
  Serial.begin(115200);

  serialBT.begin("DeadCode_RcCar");

  // Enable output mode for all motor control pins
  GPIO.enable_w1ts = GPIO_OUTPUT_PIN_SEL;
}

void loop() {
  while(serialBT.available()){

    btSignal = serialBT.read();
    Serial.println(btSignal);

      if (btSignal == 'R') {
        setMotorState((1 << MotorR_2) | (1 << MotorL_2), (1 << MotorR_1) | (1 << MotorL_1));

      } else if (btSignal == 'L') {
          setMotorState((1 << MotorR_1) | (1 << MotorL_1), (1 << MotorR_2) | (1 << MotorL_2));

      } else if (btSignal == 'F') {
          setMotorState((1 << MotorR_2) | (1 << MotorL_1), (1 << MotorR_1) | (1 << MotorL_2));

      } else if (btSignal == 'B') {
            setMotorState((1 << MotorR_1) | (1 << MotorL_2), (1 << MotorR_2) | (1 << MotorL_1));
        
      } else if(btSignal == 'H'){
          setMotorState((1 << MotorL_2), (1 << MotorL_1) | (1 << MotorR_1) | (1 << MotorR_1));
      
      } else if(btSignal == 'I'){
          setMotorState((1 << MotorR_1 ), (1 << MotorR_2) | (1 << MotorL_1) | (1 << MotorL_2));
      
      } else {
          setMotorState(0, (1 << MotorR_1) | (1 << MotorR_2) | (1 << MotorL_1) | (1 << MotorL_2));
        }


  }
}