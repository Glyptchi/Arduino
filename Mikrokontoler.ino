const int trigPin = 18;
const int echoPin = 5;
const int LEDG = 19; 
const int LEDY = 21;
const int LEDR = 12;
const int buzzer = 23;

const float tinggiWadah = 100.0;

void setup() {
  
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2;
  float ketinggianAir = tinggiWadah - distance;

  Serial.print("Ketinggian Air: ");
  Serial.print(ketinggianAir);
  Serial.println(" cm");

  if (ketinggianAir < 30) {

    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Status: Aman"); 
  } else if (ketinggianAir >= 30 && ketinggianAir <= 65) {

    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDR, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Status: Siaga"); 
  } else if (ketinggianAir > 65) {

    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDR, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("Status: BAHAYA BANJIR!"); 
  }


  Serial.println("--------------------"); 
  delay(1000);
}
