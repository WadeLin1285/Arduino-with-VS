#define BAUD 9600
int num = 0;
void setup(){
  Serial.begin(BAUD);
}

void loop(){
  Serial.print("Hello From Arduino  Num:");
  Serial.println(num);
  num++;
  delay(1000);
}
