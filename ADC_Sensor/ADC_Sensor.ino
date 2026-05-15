#include "ADCTouchSensor.h"

// Khởi tạo cảm biến: chân PA0 là cảm biến, PA1 là chân xả, delay 50us
ADCTouchSensor pressure(PA0, PA1, 150);

void setup() {
  Serial.begin(115200);           
  delay(2000);

  analogReadResolution(12);       
  pressure.begin(4000);           
}

void loop() {
  int value = pressure.read(200); 

  Serial.println(value);         
  delay(300);
}
