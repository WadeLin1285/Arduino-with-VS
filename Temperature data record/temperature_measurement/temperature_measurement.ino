#include <stdio.h>

#define _SCK 4
#define _CS  2
#define _SO  6

static volatile uint8_t is_tc_open;

void setup() {
  Serial.begin(9600);
  max6675_init();
  Serial.println( "MAX6675 Ready !" );
}

void loop() {
  // 確認 TC 是否開路或是故障
    if( is_tc_open ) 
  {
    static uint8_t tc_check;
    Serial.println( "TC is Open !");
  }
  else
  {
    float C = max6675_getCelsius();
    Serial.println( C );
  }
}

void max6675_init() {
  pinMode( _SCK, OUTPUT );
  pinMode( _SO,  INPUT );
  pinMode( _CS,  OUTPUT );
  
  digitalWrite( _CS, HIGH );
}

float max6675_getCelsius() {
  uint16_t t_c = 0;
  
  //初始化溫度轉換
  digitalWrite( _CS, LOW );
  delay(2);
  digitalWrite( _CS, HIGH );
  delay(180);
  
  // 開始溫度轉換
  digitalWrite( _CS, LOW );
  
  // 15th-bit, dummy bit
  digitalWrite( _SCK, HIGH );
  delay(1);
  digitalWrite( _SCK, LOW );
  
  // 14th - 4th bits, temperature valuw
  for( int i = 11; i >= 0; i-- )
  {
    digitalWrite( _SCK, HIGH );
    t_c += digitalRead( _SO ) << i;
    digitalWrite( _SCK, LOW );
  }
  
  // 3th bit, 此位元可以用來判斷 TC 是否損壞或是開路
  // Bit D2 is normally low and goes high when the therometer input is open.
  digitalWrite( _SCK , HIGH );
  is_tc_open = digitalRead( _SO );
  digitalWrite( _SCK, LOW );
  
  // 2nd - 1st bits,
  // D1 is low to provide a device ID for the MAX6675 and bit D0 is three-state.
  for( int i = 1; i >= 0; i-- )
  {
    digitalWrite( _SCK, HIGH );
    delay(1);
    digitalWrite( _SCK, LOW );
  }
  
  // 關閉 MAX6675
  digitalWrite( _CS, HIGH );
  
  return (float)(t_c * 0.25);
}


