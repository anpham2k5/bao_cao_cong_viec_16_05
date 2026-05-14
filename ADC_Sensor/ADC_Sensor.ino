#include "ADCTouchSensor.h"

// Khởi tạo cảm biến: chân PA0 là cảm biến, PA1 là chân xả, delay 50us
ADCTouchSensor pressure(PA0, PA1, 150);

void setup() {
  Serial.begin(115200);           // Bắt đầu giao tiếp Serial
  delay(2000);

  analogReadResolution(12);       // Độ phân giải ADC 12 bit
  pressure.begin(4000);           // Lấy baseline khi KHÔNG NHẤN
}

void loop() {
  int value = pressure.read(200); // Đọc giá trị áp lực (đã trừ baseline)

  Serial.println(value);          // Chỉ in số thôi
  delay(300);
}