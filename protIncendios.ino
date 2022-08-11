#include <max6675.h>
#include <RTClib.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>

RTC_DS3231 rtc;

float temperatura=0;
int ktcSO = 8;
int ktcCS = 9;
int ktcCLK = 10;
MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
File archivo;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(3, OUTPUT);
  if (! rtc.begin()) {
    Serial.println("No hay un módulo RTC");
    while (1);
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//  while (!Serial) {
//    ;
//  }
  Serial.print("Iniciando tarjeta SD...\n");
  if (!SD.begin(4)) {
    Serial.print("No se pudo iniciar la tarjeta SD...");
    while (1);
  }
  archivo.println(" ");
  Serial.println("Tarjeta SD iniciada con éxito...");
}
void loop() {

DateTime now = rtc.now();
archivo = SD.open("datos.txt", FILE_WRITE);
if (archivo) {
  archivo.print(now.hour());
  archivo.print(":");
  archivo.print(now.minute());
  archivo.print(":");
  archivo.print(now.second());
  archivo.print(",");
  archivo.print(now.day());
  archivo.print("/");
  archivo.print(now.month());
  archivo.print("/");
  archivo.print(now.year());
  archivo.print(",");
  temperatura=ktc.readCelsius();
  temperatura=ktc.readCelsius();
  archivo.print(temperatura);
  archivo.print("°C");
  archivo.println(" ");
  digitalWrite(3, HIGH);
  delay(5000);
  archivo.close();
  digitalWrite(3, LOW);
} else {
  Serial.println("Error al abrir el archivo...");
}
Serial.print("HORA --> ");
Serial.print(now.hour());
Serial.print(":");
Serial.print(now.minute());
Serial.print(":");
Serial.print(now.second());
Serial.print("   FECHA --> ");
Serial.print(now.day());
Serial.print("/");
Serial.print(now.month());
Serial.print("/");
Serial.print(now.year());
temperatura=ktc.readCelsius();
Serial.print("   TEMPERATURA --> ");
Serial.print(temperatura);
Serial.println("°C");
delay(55000);
}
