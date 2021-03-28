#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

//#define IR_LED 4  // ESP8266 GPIO pin to use. Recommended: 4 (D2). 16(D4)

#define IR_LED 4

IRsend irsend(IR_LED);  // Set the GPIO to be used to sending the message.

// Example of data captured by IRrecvDumpV2.ino
uint16_t rawData[199] = {4584, 4200, 724, 1456, 696, 400, 720, 1468, 696, 1484, 668, 424, 696, 400, 668, 1512, 704, 396, 720, 372, 724, 1464, 696, 396, 696, 400, 696, 1484, 696, 1488, 692, 404, 724, 1464, 692, 404, 724, 368, 700, 396, 696, 1484, 724, 1460, 696, 1484, 724, 1456, 696, 1492, 696, 1488, 728, 1456, 668, 1512, 692, 404, 696, 396, 700, 396, 696, 400, 696, 400, 640, 456, 696, 1488, 696, 1488, 696, 396, 724, 1464, 696, 396, 644, 452, 696, 400, 696, 1488, 692, 404, 692, 400, 696, 1488, 700, 392, 724, 1460, 696, 1488, 724, 1456, 528, 5264, 4584, 4204, 668, 1516, 724, 368, 724, 1464, 692, 1488, 696, 400, 724, 368, 668, 1516, 724, 372, 696, 400, 696, 1492, 696, 396, 700, 396, 724, 1456, 700, 1484, 724, 368, 700, 1488, 724, 372, 668, 428, 692, 404, 732, 1448, 696, 1484, 696, 1488, 696, 1484, 696, 1488, 668, 1520, 720, 1460, 696, 1484, 640, 456, 732, 364, 724, 368, 728, 368, 696, 400, 672, 428, 696, 1488, 700, 1480, 700, 396, 696, 1492, 664, 428, 728, 368, 724, 372, 724, 1460, 696, 396, 696, 400, 700, 1480, 696, 400, 668, 1516, 696, 1488, 728, 1456, 524};

void setup() {
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}

void loop() {
//#if SEND_NEC
//  Serial.println("NEC");
//  irsend.sendNEC(0x00FFE01FUL, 32);
//#endif  // SEND_NEC
//  delay(2000);
//#if SEND_SONY
//  Serial.println("Sony");
//  irsend.sendSony(0xa90, 12, 2);
//#endif  // SEND_SONY
//  delay(2000);
//#if SEND_RAW
  Serial.println("sinal enviado");
  irsend.sendRaw(rawData, 199, 38);  // Send a raw data capture at 38kHz.
//#endif  // SEND_RAW
  delay(3000);
}
