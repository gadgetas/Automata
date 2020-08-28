/*******************************************************************/
/* DEBUG & LOG
  /* Funcionalidad para depuracion de código auxiliar
  /* en la generación de mensajes considerando grados
  /* de severidad, de acuerdo a RFC5424
  /*  0     Emergencia: Luzi no es funcional system is unusable
  /*  1     Alerta: Se deben tomar acciones inmediatas
  /*  2     Critico: Surgen condiciones de funcionamiento critico
  /*  3     Error: Surgen condiciones de errores
  /*  4     Advertencia: Surgen condiciones de advertencia (warning)
  /*  5     Noticia: Infomación normal pero relevante
  /*  6     Informacion: Mensajes informativos
  /*  7     Debug: Mensajes de depuración y desarrollo del programa
  /*******************************************************************/
#define logEmergencia 0
#define logAlerta 1
#define logCritico 2
#define logError 3
#define logAdvertencia 4
#define logNoticia 5
#define logInfo 6
#define logDebug 7

/*******************************************************************/
/************** VARIABLES GLOBALES PARA DEPURACIÓN *****************/
/*******************************************************************/
String logMsj;
int verbosidadAnt;

/*******************************************************************/
/******** CONFIGURACIÓN INICIAL DE TERMINALES Y VARIABLES **********/
/*******************************************************************/
void A2ConfLog() {
  // Verbosidad por defecto, LogDebug
  verbosidadAnt = logDebug;
  Datos.verbosidad = logDebug;
  logMsj = String(F("!LOG"));
}

/*******************************************************************/
/***** ENVIA UN MENSAJE POR EL PUERTO DE VALORES DE VARIABLES ******/
/*******************************************************************/
void log(String msj, int grado) {
  if (grado > Datos.verbosidad)
    return;
  SerialLog.println(logMsj + grado + "-" + msj);
}

// Define el grado de verbosidad en el log
void LogComando()
{
  // Leemos los grados Celcius
  String parametro = Serie.readStringUntil('\n');
  // Convertimos de texto a entero
  int valor = parametro.toInt();
  SetVerbosidad(valor);
}

void SetVerbosidad(int grado) {
  Datos.verbosidad = grado;
  if (Datos.verbosidad > logDebug)
    Datos.verbosidad = logDebug;
  if (Datos.verbosidad < logEmergencia)
    Datos.verbosidad = logEmergencia;
  Serie.println(logMsj + "=" + Datos.verbosidad);
}

/******************************************************************************/
/******************** ESTABLECE EL MODO DEBUG DEL PROYECTO*********************/
/******************************************************************************/
void A2ModoDebug() {
  //Switchea entre los mensajes debug y el que tiene establecido
  if (Datos.verbosidad == logDebug){
    // Aqui van las instrucciones de modo debug 
  }
  else{
    // Aqui van las instrucciones de modo NO
  }
}
