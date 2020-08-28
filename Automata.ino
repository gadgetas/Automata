/******************************************************************************/
/**************************** NOMBRE DEL PROYECTO *****************************/
/******************************************************************************/
/** Aquí redacta la descripción del programa, esta debe ser concisa, un      **/
/** resumen general que explique el alcance y finalidad del programa         **/
/**   Placa Hardware:      Arduino UNO      || Para que hardware se programa **/
/**   Versión IDE Arduino: 1.8.9            || Versión con que se desarrolla **/
/******************************************************************************/
/** Version 0.1.190729 || Esta es la versión actual, se usa la semántica para
/**                       los dos primero números y en el último la fecha AAMMDD
/**
/** Última revisión:   || Última revisión o actualización, solo la última
/** 19/03/06 Augusto - Agregan leds de monitoreo
/******************************************************************************/
/***************************INFORMACIÓN DEL AUTÓMATA***************************/
const String modelo="Modelo01";
const String firmware="0.19.0121";
const String numSerie="000002";

/******************************************************************************/
/******************* DECLARACIÓN DE LIBRERÍAS DEL AUTOMATA ********************/
/******************************************************************************/
/** Estas son las librerias que se usan, los módulos que la utilizan y las   **/
/** versiones de cada una ordenadas por prioridad y utilización              **/
/**************************************||**************************************/
// Librería con la funcionalidad principal de manejo del WiFi
// NombreLibrería :: https://dondeesta.com/aqui.html
// #include <libreria.h>        //2.5.2 - M1Funcion (Nombre del modulo que la ocupa)

/******************************************************************************/
// Definimos puerto serial para Comunicación
#define Serie Serial
#define Serial_bps 9600

// Definimos puerto serial para LOG
#define SerialLog Serial
#define SerialLog_bps 9600

/*****************************DEFINICIÓN DE ESTADOS****************************/
const int estadoPrueba=-3;        // Estado usado para pruebas
const int estadoError=-2;         // Estado usado para pruebas
const int estadoDesconectado = -1;// Estado de puerto serial desconectad
// Modulo Alcancia
const int estadoInicio = 0;// Estado inicial
const int estadoConfiguracion = 1;// Estado de configuración de módulos
const int estadoEspera = 2;// Estado inicial
/******************************************************************************/
int Estado;

void setup() {
  CambiarEstado(estadoInicio);
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
    case estadoInicio:
      EstadoInicio();
      break;
    case estadoConfiguracion:
      EstadoConfiguracion();
      break;
    case estadoEspera:
      EstadoEspera();
      break;
    default:
      EstadoError();
      break;
  }
}
