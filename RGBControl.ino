#include <SoftwareSerial.h>

SoftwareSerial ble(18, 17); // RX, TX
const int ledR = 3, ledG = 5, ledB = 6;
String hexValue, hexValue1, hexValue2, hexValue3;
int Rvalue, Gvalue, Bvalue;
String msg = "Coloque los valores RGB en Hexadecimal:";

void setup() {
    ble.begin(9600);
    Serial.begin(9600);
    while (!ble) { } // do nothing
    ble.println(msg);
    Serial.println(msg);
}

void loop() {
    while (ble.available() > 0) {
        hexValue = ble.readString(); // read hex values
        hexValue1 = hexValue.substring(0,2); // separate values
        hexValue2 = hexValue.substring(2,4);
        hexValue3 = hexValue.substring(4,6);
        Rvalue = strtol(hexValue1.c_str(), NULL, 16); // convert hex to decimal
        Gvalue = strtol(hexValue2.c_str(), NULL, 16);
        Bvalue = strtol(hexValue3.c_str(), NULL, 16);
        analogWrite(ledR, Rvalue);
        analogWrite(ledG, Gvalue);
        analogWrite(ledB, Bvalue);
        ble.print(Rvalue); ble.print(","); ble.print(Gvalue); ble.print(","); ble.println(Bvalue); // print decimal values
        Serial.print(Rvalue);  Serial.print(","); Serial.print(Gvalue);  Serial.print(","); Serial.println(Bvalue);
    }
}
