byte value[4] = {};
byte check[4] = {};
byte button[4] = {};
byte a, d;
boolean b = 0;
byte answer;
unsigned int timer = 1000;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(3));
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  if (b == 0) {
    randomLED();
    Serial.print("timer:");
    Serial.println(timer);
  }
  if (b == 1) {
    Button();
  }
  if (a == 4) {
    Serial.println("BUT");
    Serial.print(button[0]);
    Serial.print(button[1]);
    Serial.print(button[2]);
    Serial.println(button[3]);
    delay(1000);
    digitalWrite(button[0], LOW);
    digitalWrite(button[1], LOW);
    digitalWrite(button[2], LOW);
    digitalWrite(button[3], LOW);
    buttonOFF();
    if (answer == 4) {
      b = 0;
      a = 0;
      answer = 0;
      timer -= 10;
      Serial.print("B:");
      Serial.println(b);
    } else {
      a = 0;
      timer += 10;
      answer = 0;
      Serial.println("answer: ");
      for (byte i = 0; i < 4; i++) {
        digitalWrite(check[i], HIGH);
        Serial.print(check[i]);
        delay(timer);
        digitalWrite(check[i], LOW);
      }
      Serial.println();
    }
  }
}

byte randomLED() {
  //Рандомное загорание светодиодов
  Serial.print("LED: ");
  value[0] = random(2, 6);
  Serial.print(value[0]);
  value[1] = random(2, 6);
  if (value[0] != value [1] && value[0] != check[0]) {
    value[2] = random(2, 6);
    Serial.print(value[1]);
    if (value[2] != value[0] && value[2] != value[1]) {
      value[3] = random(2, 6);
      Serial.print(value[2]);
      if (value[3] != value[0] && value[3] != value[1] && value[3] != value[2]) {
        Serial.println(value[3]);
        for (byte i = 0; i < 4; i++) {
          digitalWrite(value[i], HIGH);
          check[i] = value[i];
          delay(timer);
          digitalWrite(value[i], LOW);
          Serial.print(check[i]);
          Serial.println(value[i]);
        }
        b = 1;
        Serial.print("B:");
        Serial.println(b);
      }
    }
  }
}

int Button() {
  // Отработка нажатий кнопок
  if (digitalRead(7) == 0 && button[0] != 2 && button[1] != 2 && button[2] != 2) {
    button[a] = 2;
    digitalWrite(button[a], HIGH);
    Serial.println(button[a]);
    if (value[a] == button[a]) {
      answer++;
    }
    a++;
    Serial.print(a);
  } else if (digitalRead(8) == 0 && button[0] != 3 && button[1] != 3 && button[2] != 3) {
    button[a] = 3;
    digitalWrite(button[a], HIGH);
    Serial.println(button[a]);
    if (value[a] == button[a]) {
      answer++;
    }
    a++;
    Serial.print(a);
  } else if (digitalRead(9) == 0 && button[0] != 4 && button[1] != 4 && button[2] != 4) {
    button[a] = 4;
    digitalWrite(button[a], HIGH);
    Serial.println(button[a]);
    if (value[a] == button[a]) {
      answer++;
    }
    a++;
    Serial.print(a);
  } else if (digitalRead(10) == 0 && button[0] != 5 && button[1] != 5 && button[2] != 5) {
    button[a] = 5;
    digitalWrite(button[a], HIGH);
    Serial.println(button[a]);
    if (value[a] == button[a]) {
      answer++;
    }
    a++;
    Serial.print(a);
  }
}

byte buttonOFF() {
  for (byte i = 0; i < 4; i++) {
    button[i] = 0;
  }
}
