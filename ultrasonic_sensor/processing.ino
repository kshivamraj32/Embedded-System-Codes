int trigPin = 8; 
int echoPin = 7; 
int digiPin = 13;
int pirpin = 2;
int motion=0;
float v=331.5+0.6*20;
int val =0;

void setup() 
{
Serial.begin(9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(digiPin, INPUT); 
pinMode(pirpin, INPUT);
}
float distanceCm(){ //
  // send sound pulse //
  digitalWrite(trigPin, LOW); //
  delayMicroseconds(3); //
  digitalWrite(trigPin, HIGH); //
  delayMicroseconds(5); //
  digitalWrite(trigPin, LOW); //
  // listen for echo //
  float tUs = pulseIn(echoPin, HIGH); // microseconds //
  float t = tUs / 1000.0 / 1000.0 / 2.0; // s //
  float d = t*v; // m //
  return d*100; // cm //
}
void loop() //
{
  val = digitalRead(pirpin);
  Serial.print("Pir =");
  Serial.println(val);
  if(val==1){
    int d=distanceCm(); //
    if (d<1000){
    Serial.println(d);} //
    delay(200); // ms // 
 }
 else{
  Serial.println(0);
  delay(200);
 }
}
