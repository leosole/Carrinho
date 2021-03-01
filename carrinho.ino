#define IN1 7                       //Pinos motor A (Direita)
#define IN2 8                       //Pinos motor A (Direita)
#define IN3 9                       //Pinos motor B (Esquerda)
#define IN4 10                       //Pinos motor B (Esquerda)
#define ENA 5                      //Pino velocidade motor A (Enable A)
#define ENB 6                      //Pino velocidade motor B (Enable B)
#define V0 90            //Velocidade baixa
#define V1 100           //Velocidade média
#define V2 110            //Velocidade alta

char data[5] = "0123";
unsigned long t0 = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
  t0 = millis();
}

void loop() {
  if (Serial.available() > 3) {
    data[0] = Serial.read();
    data[1] = Serial.read();
    data[2] = Serial.read();
    data[3] = Serial.read();

    String command = String(data); // Para poder comparar
    delay(2);

    //Movimenta para frente
    if (command.equals("+2+2")) { // 22
      analogWrite(ENA, V2);
      analogWrite(ENB, V2);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("+1+1")) { // 11
      analogWrite(ENA, V1);
      analogWrite(ENB, V1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    //Movimenta para trás
    else if (command.equals("-2-2")) { // -2-2
      analogWrite(ENA, V2);
      analogWrite(ENB, V2);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if (command.equals("-1-1")) { // -1-1
      analogWrite(ENA, V1);
      analogWrite(ENB, V1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    //movimenta para direita
    else if (command.equals("+2+0")) { // 20
      analogWrite(ENB, V1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("+1+0")) { // 10
      analogWrite(ENB, V0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("-1+0")) { // -10
      analogWrite(ENB, V0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if (command.equals("+2+1")) { // 21
      analogWrite(ENA, V0);
      analogWrite(ENB, V1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("-2-1")) { // -2-1
      analogWrite(ENA, V0);
      analogWrite(ENB, V1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    //movimenta para esquerda
    else if (command.equals("+0+2")) { // 02
      analogWrite(ENA, V1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("+0+1")) { // 01
      analogWrite(ENA, V0);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("+0-1")) { // 0-1
      analogWrite(ENA, V0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("+1+2")) { // 12
      analogWrite(ENA, V1);
      analogWrite(ENB, V0);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if (command.equals("-1-2")) { // -1-2
      analogWrite(ENA, V1);
      analogWrite(ENB, V0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    //Sem movimento
    // else if(command.equals("+0+0")) {
    else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }
  else if (millis() - t0 > 2000) { // 2 segundos
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    t0 = millis();
  }
}
