/*******************************************************************************
 * NOMBRE DEL PROYECTO
 *  
 *  En esta parte esta la descripción del programa, debemos ser concisos, 
 *  redactar un resumen general que explique el alcance y finalidad del programa
 *  
 *  Version 0.18.1207 -- Esta es la versión
 *  Placa Arduino: Arduino Pro Mini
 *
 *  Última revisión:
 *  19/03/06 Augusto - Agregan leds de monitoreo
/******************************************************************************/
/***************************INFORMACIÓN DEL AUTÓMATA***************************/
const String modelo="Alcancia01";
const String firmware="0.19.0121";
const String numSerie="000002";
/******************************************************************************/
// Definimos puerto serial para Comunicación
#define Serie Serial
#define SerialLog_bps 9600

// Definimos puerto serial para LOG
#define SerialLog Serial
#define SerialLog_bps 9600

/*****************************DEFINICIÓN DE ESTADOS****************************/
const int estadoPrueba=-3;        // Estado usado para pruebas
const int estadoError=-2;         // Estado usado para pruebas
const int estadoDesconectado = -1;// Estado de puerto serial desconectad
// Modulo Alcancia
const int estadoConfiguracion = 0;// Estado inicial
/******************************************************************************/
int Estado;

void setup() {
  /****SI ES DIFERENTE EL PUERTO DEL LOG***/
  SerialLog.begin(SerialLog_bps);
  A1Informacion();
  CambiarEstado(estadoConfiguracion);
}

void loop() {
  LeerIndicaciones();  
  switch (Estado) {
    case estadoPrueba:
      EstadoPrueba();
      break;
    case estadoError:
      EstadoError();
      break;
    case estadoDesconectado:
      EstadoDesconectado();
      break;
    case estadoConfiguracion:
      EstadoConfiguracion();
      break;
    default:
      EstadoError();
      break;
  }
}
