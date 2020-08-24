#define vib_pin A1  // 진동하면 LOW, else HIGH
                    // 아날로그 핀 A1에 진동 센서 연결
int led_pin=13;

void setup() {
  Serial.begin(9600);
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  int val;
  val=analogRead(vib_pin);
  if(val>500)
  {
    digitalWrite(led_pin, LOW);
    Serial.println("NOT VIBRATE");
    delay(1000);
   }
   else
   {
    digitalWrite(led_pin, HIGH);
   Serial.println("VIBRATE");
   delay(1000);
   }
}
