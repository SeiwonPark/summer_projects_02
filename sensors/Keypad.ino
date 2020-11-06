#include <Keypad.h>
 
const byte ROWS = 4;    // rows
const byte COLS = 3;    // columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
 
byte rowPins[ROWS] = {6, 7, 8, 9}; // Arduino Pin number connected to R1, R2, R3, R4
byte colPins[COLS] = {5, 4, 3};    // Arduino Pin number connected to C1, C2, C3
 
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
