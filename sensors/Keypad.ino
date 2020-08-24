#include <Keypad.h>
 
const byte ROWS = 4;    // 행(rows) 개수
const byte COLS = 3;    // 열(columns) 개수
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
 
byte rowPins[ROWS] = {6, 7, 8, 9};   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
byte colPins[COLS] = {5, 4, 3};   // C1, C2, C3 단자가 연결된 아두이노 핀 번호
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup() {
  Serial.begin(9600);
}
   
void loop() {
  char key = keypad.getKey();
   
  if (key) {
    Serial.println(key);
  }
}
