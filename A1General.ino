/*****************************************************************************/
/**************** ESTRUCTURA DE PROPIEDADES DEL ESFERIFICADOR ****************/
/*****************************************************************************/
struct DatosAutomata {
  /********************************** A2Log **********************************/
  int verbosidad;             // Nivel de verbosidad
  /**************************** Activación Error *****************************/
  // Tiempo en el cual debe activarse o liberar una función si excede el tiempo
  // es porque hubo un error
  unsigned long tiempoError;
  /***************************** Tiempo de espera ****************************/
  // Tiempo que espera en la activación para una función de un módulo
  unsigned long tiempoIR1;
};

/*****************************************************************************/
/************** CONFIGURACIÓN INICIAL DE TERMINALES Y VARIABLES **************/
/*****************************************************************************/
DatosAutomata Datos;    //Variable global de propiedades del Vochobot
unsigned long tiempoAnt;//(ms) Variable auxiliar para medir tiempo
unsigned long tEsperaAnt;//(ms) Variable auxiliar para medir tiempo
unsigned long tErrorAnt;//(ms) Variable auxiliar en medir tiempo de estado Error
unsigned long tSegAnt;  // Variable auxiliar para contar segundos
int segundos;           // Variable auxiliar para contar segundos


void A1ConfGeneral() {
  // Reiniciando variables
  tiempoAnt = millis();
  tSegAnt = millis();
  tEsperaAnt = millis();
  randomSeed(millis());
  Datos.tiempoError = 35000;      // 25 segundos
  Datos.verbosidad = 7;           // Nivel de verbosidad por defecto
}

// Envia información del automáta
void A1Informacion() {
  Serial.print(F("!Modelo:"));
  Serial.println(modelo);
  Serial.print(F("!Firmware:"));
  Serial.println(firmware);
  Serial.print(F("!Serie:"));
  Serial.println(numSerie);
}

// Envia la información de los datos del autómata
void InformacionDatos() {
  Serie.println(F("------INFO------"));
  Serie.print(F("!EdoActual="));
  Serie.println(Estado);
  Serie.println(F("------INFO------"));
}
