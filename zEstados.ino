/*****************************************************************************/
/****** FUNCIÓN PARA CAMBIAR DE ESTADO Y EJECUTAR FUNCIONES DE EVENTO ********/
/*****************************************************************************/
void CambiarEstado(int sigEstado) {
  switch (sigEstado) {
    case estadoPrueba:
      log(F("EdoPrueba"), logNoticia);
      break;
    case estadoError:
      log(F("EdoError"), logNoticia);
      break;
    case estadoConfiguracion:
      log(F("EdoConfiguracion"), logNoticia);
      break;
    default:
      log(F("Estado no valido"), logError);
      break;
  }
  Estado = sigEstado;
}


/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
void EstadoPrueba() {
  // Esperar 5 segundos mostrando la pantalla de inicio
  if (millis() - tiempoAnt > 5000) {
    tiempoAnt = millis();
    //TODO: CambiarEstado(estadoEspera);
  }
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
void EstadoError() {
  // Si ya ha pasado 2 segundo, apaga el buzzer
  if (millis() - tiempoAnt > 2000) {
    //buzzer(false);
  }
  // Esperar 5 segundos mostrando la pantalla de inicio
  if (millis() - tiempoAnt > 4500) {
    tiempoAnt = millis();
    CambiarEstado(estadoError);
  }
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
void EstadoDesconectado() {
  // Esperar 5 segundos mostrando la pantalla de inicio
  if (millis() - tiempoAnt > 5000) {
    tiempoAnt = millis();
    // TODO: CambiarEstado(estadoPrueba);
  }
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
void EstadoConfiguracion() {
  A2ConfLog();
  A1ConfGeneral();
  // TODO: CambiarEstado(estadoEspera);
  // TODO: LeerDatosEEPROM();
}


