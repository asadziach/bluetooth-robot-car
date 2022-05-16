#include <SoftwareSerial.h>

const int txPin = 11;
const int rxPin = 10;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int motor1pwm = 9;
int motor2pwm = 6;

SoftwareSerial BTSerial(rxPin, txPin); // RX, TX

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);

  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(motor1pwm, OUTPUT);
  pinMode(motor2pwm, OUTPUT);

  //control speed
  analogWrite(motor1pwm, 255);
  analogWrite(motor2pwm, 255);
}

void loop() {
  char bt = 'S';
  if (BTSerial.available()) {
    bt = BTSerial.read();
    Serial.write(bt);
    processCommand(bt);
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}

void processCommand(char bt) {

  if (bt == 'F')
  {
    forward();
  }

  if (bt == 'B')
  {
    backward();
  }

  if (bt == 'L')
  {
    left();
  }

  if (bt == 'R')
  {
    right();
  }

  if (bt == 'S')
  {
    stopCar();
  }

}

void forward() {
  digitalWrite(LED_BUILTIN, HIGH);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void backward() {
  digitalWrite(LED_BUILTIN, HIGH);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}


void left() {
  digitalWrite(LED_BUILTIN, HIGH);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void right() {
  digitalWrite(LED_BUILTIN, HIGH);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void stopCar() {
  digitalWrite(LED_BUILTIN, LOW);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
