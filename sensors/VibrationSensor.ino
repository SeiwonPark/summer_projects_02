#define vib_pin A1  // if vibrated: LOW, else: HIGH
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
    Serial.println("999");
    delay(1000);
   }
   else
   {
    digitalWrite(led_pin, HIGH);
   Serial.println("112");
   delay(1000);
   }
}
