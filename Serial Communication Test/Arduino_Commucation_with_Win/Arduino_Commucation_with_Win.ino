#define BAUD 9600

int num1,num2,num3 = 0;

void setup(){
  Serial.begin(BAUD);
}

void loop(){
  num1 = 0.15;         // type any number to test
  num2 = 0.64;         // type any number to test
  num3 = 0.87;         // type any number to test
  Serial.print(num1);
  Serial.print(" ");
  Serial.print(num2);
  Serial.print(" ");
  Serial.print(num3);
  Serial.println(" ");
  delay(5);
}
