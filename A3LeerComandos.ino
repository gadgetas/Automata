void LeerIndicaciones() {
  // Verificamos si hay bytes por leer
  if (Serie.available() > 0)
  {
    // Lee el byte recibido
    int inByte = Serie.read();
    // Comparar para saber que tipo de mensaje es
    switch (inByte)
    {
      case '#':
        LeerComandos();
        break;
      case '?':
        LeerInformacion();
        break;
      case '!':
        LeerMensajes();
        break;
      case '\n':
      case '\r':
        break;
      default:
        SerialLog.print("ERR-NE:");
        if (isGraph(inByte))
          SerialLog.println((char)inByte);
        else
          SerialLog.println(inByte);
        break;
    }
  }
}

void LeerComandos()
{
  // Espera mientras exista el siguiente dato
  while (Serie.available() <= 0)
  {
    delayMicroseconds(10);
  }
  // Lee el comando
  int comando = Serie.read();
  switch (comando)
  {
    case 'L':
      // Gestión del LOG
      LogComando();
      break;
    case 'M':
      // Muestra los comandos disponibles
      MenuComandos();
      break;
    case 'E':
      // Gestión de EEPROM
      EEPROMComando();
      break;
    case '\n':
    case '\r':
      break;
    default:
      Serie.print("ERR-CMD:");
      if (isGraph(comando))
        Serie.println((char)comando);
      else
        Serie.println(comando);
      break;
  }
}

void LeerInformacion() {
  // Espera mientras exista el siguiente dato
  while (Serie.available() <= 0)
  {
    delayMicroseconds(10);
  }
  // Lee el comando
  int comando = Serie.read();
  switch (comando)
  {
    case 'a':
      InformacionDatos();
      break;
    case 'M':
      MenuInformacion();
      break;
    case 'T':
      // Lee la temperatura en Celcius
      // ComandoTemperatura();
      break;
    case '\n':
    case '\r':
      break;
    default:
      Serie.print("ERR-INF:");
      if (isGraph(comando))
        Serie.println((char)comando);
      else
        Serie.println(comando);
      break;
  }
}

void LeerMensajes() {}



