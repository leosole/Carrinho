#define IN1 6                       //Pinos motor A (Direita)
#define IN2 7                       //Pinos motor A (Direita)
#define IN3 8                       //Pinos motor B (Esquerda)
#define IN4 9                       //Pinos motor B (Esquerda)
#define ENA 10                      //Pino velocidade motor A (Enable A)
#define ENB 11                      //Pino velocidade motor B (Enable B)
#define V0 25						//Velocidade baixa
#define V1 50						//Velocidade média
#define V2 100						//Velocidade alta


void setup() {
	pinMode(IN1,OUTPUT);
	pinMode(IN2,OUTPUT);
	pinMode(IN3,OUTPUT);
	pinMode(IN4,OUTPUT);
	pinMode(ENA,OUTPUT);
	pinMode(ENB,OUTPUT);
	// Transferi essas chamadas para dentro do loop
	// analogWrite(ENA,110);
	// analogWrite(ENB,110);
}

char cha;

void loop() {
	if (Serial.available() > 0) {
		cha = Serial.read();
		delay(2);
		//Movimenta para frente
		if(cha == 'C') { // 22
			analogWrite(ENA,V2);
			analogWrite(ENB,V2);
			digitalWrite(IN1,HIGH);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,HIGH);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'V') { // 11
			analogWrite(ENA,V1);
			analogWrite(ENB,V1);
			digitalWrite(IN1,HIGH);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,HIGH);
			digitalWrite(IN4,LOW);
		}
		//Movimenta para trás
		else if(cha == 'B') {  // -2-2
			analogWrite(ENA,V2);
			analogWrite(ENB,V2);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,HIGH);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,HIGH);
		}
		else if(cha == 'N') {  // -1-1
			analogWrite(ENA,V1);
			analogWrite(ENB,V1);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,HIGH);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,HIGH);
		}
		//movimenta para direita
		else if(cha == 'R') {  // 20
			analogWrite(ENB,V1);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,HIGH);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'T') {  // 10
			analogWrite(ENB,V0);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,HIGH);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'U') {  // -10
			analogWrite(ENB,V0);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,HIGH);
		}
		else if(cha == 'Y') {  // 21
			analogWrite(ENA,V0);
			analogWrite(ENB,V1);
			digitalWrite(IN1,HIGH);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,HIGH);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'I') {  // -2-1
			analogWrite(ENA,V0);
			analogWrite(ENB,V1);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,HIGH);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,HIGH);
		}
		//movimenta para esquerda
		else if(cha == 'F') {  // 02
			analogWrite(ENA,V1);
			digitalWrite(IN1,HIGH);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'G') {  // 01
			analogWrite(ENA,V0);
			digitalWrite(IN1,HIGH);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'J') {  // 0-1
			analogWrite(ENA,V0);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,HIGH);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'H') {  // 12
			analogWrite(ENA,V1);
			analogWrite(ENB,V0);
			digitalWrite(IN1,HIGH);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,HIGH);
			digitalWrite(IN4,LOW);
		}
		else if(cha == 'K') {  // -2-1
			analogWrite(ENA,V1);
			analogWrite(ENB,V0);
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,HIGH);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,HIGH);
		}
		//Sem movimento
		// else if(cha == '0') {
		else {
			digitalWrite(IN1,LOW);
			digitalWrite(IN2,LOW);
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,LOW);
		}
	}
}
