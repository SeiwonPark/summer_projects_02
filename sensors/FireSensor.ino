const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
int touchSensor=8;
int Buzzer=13;
int melody[] =    {100, 40};

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
  pinMode(Buzzer, OUTPUT);
  pinMode(touchSensor, INPUT);
}
void loop() {
   int touchValue = digitalRead(touchSensor);

  if(touchValue==HIGH){
    digitalWrite(Buzzer, HIGH);
    Serial.println("112");           // touch detected
    for (int j = 0; j < 7; j++) {
      for (int i = 0; i < 2; i++) {
        tone(13, melody[i], 400);
        delay(200);
        noTone(13);
      }
    }
  }
  else{
    digitalWrite(Buzzer, LOW);
    Serial.println("999");          // Default Value
  }
  // read the sensor on analog A0:
  int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
    int i,j;
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("119");
    for (j = 0; j < 7; j++) {
      for (i = 0; i < 2; i++) {
        tone(13, melody[i], 400);
        delay(200);
        noTone(13);
    }}
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("119");        // fire detected
    for (j = 0; j < 7; j++) {
      for (i = 0; i < 2; i++) {
        tone(13, melody[i], 400);
        delay(200);
        noTone(13);
    }}
    break;
  case 2:    // No fire detected.
    Serial.println("999");       // Default Value
    break;
  }
  delay(500);  // delay between reads
}
