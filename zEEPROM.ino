#include <EEPROM.h>

void EEPROMComando()
{
  // Espera mientras llega la siguiente letra
  while (Serie.available() <= 0)
  {
    delayMicroseconds(10);
  }
  // Lee el comando
  int comando = Serie.read();
  switch (comando)
  {
    case 'G':
      EscribirDatosEEPROM();
      break;
    case 'L':
      LeerDatosEEPROM();
      break;
    default:
      log(F("Comando EEPROM No valido"), logError);
      Serie.print(F("ERR-CMDEEPROM"));
      break;
  }
}

/*******************************************************************/
/******** FUNCIÓN PARA LEER LOS DATOS GUARDADOS EN EEPROM **********/
/*******************************************************************/
void LeerDatosEEPROM() {
  // Variable donde estan mis datos almacenados en EEPROM.
  log(F("(EEPROM) Leyendo"), logDebug);
  // Leemos los datos
  EEPROM.get( 0, Datos );
  Serial.println(F("!EEPROM=Leido"));
}

/*******************************************************************/
/******* FUNCIÓN PARA GRABAR LOS DATOS EN LA MEMORIA EEPROM ********/
/*******************************************************************/
void EscribirDatosEEPROM() {
  log(F("(EEPROM) Grabando"), logDebug);
  //One simple call, with the address first and the object second.
  EEPROM.put(0, Datos);
  Serial.println(F("!EEPROM=Guardado"));
}
