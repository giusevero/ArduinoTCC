
/*
 * Vari�vel que mostra em qual porta o LED est� ligado
 */
int LED = 13;

/*
 * Se��o que mostra quais componente ser�o utilizados
 * O m�dulo Bluetooth utilizar� comunica��o serial
 * O LED ser� uma sa�da dependendo da entrada do m�dulo
 */
void setup() {

  /*
   * A configura��o "Serial.begin(9600)" quer dizer que 
   * o m�dulo ter� uma transmiss�o de dados � taxa de 
   * 9600 bits por segundo 
   */
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

// Se��o que define o que ser� realizado pelo Arduino de forma estrutural
void loop() {

 // Verifica se a entrada serial est� dispon�vel
  if(Serial.available()){

	// Estando dispon�vel a entrada ser� realizada a leitura do dado e inserida em uma var�vel caractere aqui denominada de 'c'
    char c = (char) Serial.read();
    /*
     * Se 'c' for igual � 1, ent�o o LED ser� ligado o par�metro 'HIGH' indica que o LED deve ser aceso 
     * pelo Arduino, em seguida no console da IDE ser�  exibida a mensagem "LED aceso"
     */
    if(c == '1'){
      digitalWrite(LED, HIGH);
      Serial.println("LED aceso");
    }

    /*
     * Este teste verifica se 'c' � igual � 0, caso seja o LED dever� ser desligado, caso esteja aceso ou  permanecer� desligado. 
	* O par�metro LOW indica que o  Arduino dever� n�o enviar energia ao LED tornando  ele apagado
     */
    else if(c == '0'){
      digitalWrite(LED, LOW);
      Serial.println("LED Desligado");
    }
  }

// Este comando define uma pausa na execu��o do programa em um tempo de 1000 milisegundos
  delay(1000);
}