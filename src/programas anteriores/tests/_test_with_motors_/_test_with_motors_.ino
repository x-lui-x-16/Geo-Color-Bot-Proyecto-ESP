// Definir los pines de conexión del TCS3200
#define S0 18
#define S1 2 //3
#define S2 4
#define S3 5
#define OUT 7 //6
#define LED 21

// Definir los pines de conexión de los sensores HC-SR04
#define TRIG1 8 //8
#define ECHO1 9 //9
#define TRIG2 12
#define ECHO2 17
#define TRIG3 10
#define ECHO3 11
#define TRIG4 6 //7
#define ECHO4 3 //2

// Definir los pines de conexión del controlador TB6612
#define AIN1 14
#define AIN2 15
#define PWMA 16
#define BIN1 19
#define BIN2 20
#define PWMB 13
#define STBY 22

void setup() {
  // Configurar pines del TCS3200
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  digitalWrite(LED, HIGH);

  // Configurar pines de los sensores HC-SR04
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG4, OUTPUT);
  pinMode(ECHO4, INPUT);

  // Configurar pines del controlador TB6612
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  
  digitalWrite(STBY, HIGH);  // Activar motores

  // Iniciar comunicación serial
  Serial.begin(9600);
}

int readColor(int s2, int s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(100); // Esperar a que el sensor se estabilice
  return pulseIn(OUT, LOW);
}

long readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Convertir tiempo en distancia
  return distance;
}

void controlMotor(int in1, int in2, int pwm, int speed) {
  analogWrite(pwm, abs(speed));
  if (speed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}

void loop() {
  // Leer colores
  int red = readColor(LOW, LOW);
  int green = readColor(HIGH, HIGH);
  int blue = readColor(LOW, HIGH);

  // Leer distancias
  long distance1 = readUltrasonic(TRIG1, ECHO1);
  long distance2 = readUltrasonic(TRIG2, ECHO2);
  long distance3 = readUltrasonic(TRIG3, ECHO3);
  long distance4 = readUltrasonic(TRIG4, ECHO4);

  // Control de motores
  controlMotor(AIN1, AIN2, PWMA, 255);  // Motor A hacia adelante a velocidad máxima
  controlMotor(BIN1, BIN2, PWMB, 255);  // Motor B hacia adelante a velocidad máxima
  
  // Imprimir valores de colores
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  
  Serial.print(" Blue: ");
  Serial.println(blue);

  // Imprimir valores de distancias
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Distance 3: ");
  Serial.print(distance3);
  Serial.print(" cm, Distance 4: ");
  Serial.println(distance4);

  delay(1000); // Esperar 1 segundo antes de la próxima lectura
}