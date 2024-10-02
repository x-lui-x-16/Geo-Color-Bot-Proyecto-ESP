// Definir los pines de conexión del TCS3200
#define S0 18
#define S1 3
#define S2 4
#define S3 5
#define OUT 6
#define LED 21

// Definir los pines de conexión de los sensores HC-SR04
#define TRIG1 8
#define ECHO1 9
#define TRIG2 10
#define ECHO2 11
#define TRIG3 12
#define ECHO3 17
#define TRIG4 7
#define ECHO4 2

void setup() {
  // Configurar pines del TCS3200
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(LED, OUTPUT); // Configurar pin LED como salida

  // Configurar escala de salida a 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Encender el LED
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