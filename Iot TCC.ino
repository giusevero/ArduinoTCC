
/*
 * Variável que mostra em qual porta o LED está ligado
 */
int LED = 13;

/*
 * Seção que mostra quais componente serão utilizados
 * O módulo Bluetooth utilizará comunicação serial
 * O LED será uma saída dependendo da entrada do módulo
 */
void setup() {

  /*
   * A configuração "Serial.begin(9600)" quer dizer que 
   * o módulo terá uma transmissão de dados à taxa de 
   * 9600 bits por segundo 
   */
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

// Seção que define o que será realizado pelo Arduino de forma estrutural
void loop() {

 // Verifica se a entrada serial está disponível
  if(Serial.available()){

	// Estando disponível a entrada será realizada a leitura do dado e inserida em uma varável caractere aqui denominada de 'c'
    char c = (char) Serial.read();
    /*
     * Se 'c' for igual à 1, então o LED será ligado o parâmetro 'HIGH' indica que o LED deve ser aceso 
     * pelo Arduino, em seguida no console da IDE será  exibida a mensagem "LED aceso"
     */
    if(c == '1'){
      digitalWrite(LED, HIGH);
      Serial.println("LED aceso");
    }

    /*
     * Este teste verifica se 'c' é igual à 0, caso seja o LED deverá ser desligado, caso esteja aceso ou  permanecerá desligado. 
	* O parâmetro LOW indica que o  Arduino deverá não enviar energia ao LED tornando  ele apagado
     */
    else if(c == '0'){
      digitalWrite(LED, LOW);
      Serial.println("LED Desligado");
    }
  }

// Este comando define uma pausa na execução do programa em um tempo de 1000 milisegundos
  delay(1000);
}