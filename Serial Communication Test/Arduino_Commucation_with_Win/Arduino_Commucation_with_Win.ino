#define BAUD 9600
int num1,num2,num3 = 0;
void setup(){
  Serial.begin(BAUD);
}

void loop(){
  num1 = 0.15;
  num2 = 0;
  num3 = 0;
  Serial.print(num1);
  Serial.print(" ");
  Serial.print(num2);
  Serial.print(" ");
  Serial.print(num3);
  Serial.println(" ");
  delay(5);
}
