void MenuComandos() {
  Serie.println(F("----------- MENU DE COMANDOS -----------"));
  Serie.println(F("X:(Modulo): Comando a ejecutar"));
  if (Datos.verbosidad == 7)
    MenuComandosDesarrollo();
}

void MenuComandosDesarrollo() {
  Serie.println(F("Ln:(LOG) Establece verbosidad"));
  Serie.println(F("EG:(EEPROM)Guardar"));
  Serie.println(F("EL:(EEPROM)Leer"));
}

void MenuInformacion(){
  Serie.println(F("---- MENU DE INFORMACION DE VALORES ----"));
}
