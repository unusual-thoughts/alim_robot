#define LED_24_RED 1
#define LED_24_YLW 2
#define LED_24_GRN 3

#define LED_12_RED 16
#define LED_12_YLW 15
#define LED_12_GRN 14

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  digitalWrite(LED_24_RED, HIGH);
  delay(100);
  digitalWrite(LED_24_RED, LOW);
  digitalWrite(LED_24_YLW, HIGH);
  delay(100);
  digitalWrite(LED_24_YLW, LOW);
  digitalWrite(LED_24_GRN, HIGH);
  delay(100);
  digitalWrite(LED_24_GRN, LOW);
  digitalWrite(LED_12_RED, HIGH);
  delay(100);
  digitalWrite(LED_12_RED, LOW);
  digitalWrite(LED_12_YLW, HIGH);
  delay(100);
  digitalWrite(LED_12_YLW, LOW);
  digitalWrite(LED_12_GRN, HIGH);
  delay(100);
  digitalWrite(LED_12_GRN, LOW);  
}
