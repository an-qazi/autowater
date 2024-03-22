const int waterpin = 9;
const int potentipin = A0;
int potenti;
int speed;
const int dry = 504;
const int wet = 249;
const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance;
const int buzzer = 7;

void setup() {

pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
while (distance > 15)
{
tone(buzzer, 1000);
}
int moisturevalue = analogRead(A0);
int moisturelevel = map(moisturevalue, wet, dry, 100, 0);
while(moisturelevel<30)
{
  potenti = analogRead(potentipin);
  speed = map(potenti, 0, 1023,0,255);
  analogWrite(waterpin, speed);
}
// Serial.print(moisturelevel);
// Serial.println("%");
// delay(155);

}





