//Definción de Pines de Sensor de Color (TCS3200)
#define OUT 2
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define LED 7

// Definición de Pines de Sensores US (HC-SR04)
#define ECHO1 22 // Sensor delantero
#define TRIG1 23
#define ECHO2 30 // Sensor Izquierdo
#define TRIG2 31
#define ECHO3 36 // Sensor Derecho
#define TRIG3 37
#define ECHO4 46 // Sensor Trasero
#define TRIG4 47

// Definición de Pines del controlador (TB6612)
#define PWMA 54
#define AIN1 54 
#define AIN2 55
#define BIN1 57
#define BIN2 58
#define PWMB 59
#define STBY 70

// Variables globales para las distancias y color
int distanceFront, distanceRight, distanceLeft, distanceBack;
int redValue, greenValue, blueValue;
unsigned long lastPrintTime = 0;  // Variable para el control de tiempo
const unsigned long printInterval = 5000;  // Intervalo de 5 segundos

// Variables de tiempo y velocidad
const int waitTime = 2000;  // Tiempo de espera entre fases en milisegundos
const int speed = 0;    // Velocidad inicial de los motores (se puede modificar)

// Matrices para agrupar los pines de cada motor
const int pinMotorA[3] = { PWMA, AIN2, AIN1 };  // Pines del motor A
const int pinMotorB[3] = { PWMB, BIN1, BIN2 };  // Pines del motor B

// Enumeración para las direcciones de movimiento
enum moveDirection {
  forward,     // Movimiento hacia adelante
  backward     // Movimiento hacia atrás
};

// Enumeración para las direcciones de giro
enum turnDirection {
  clockwise,         // Girar en sentido horario
  counterClockwise   // Girar en sentido antihorario
};

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);

  // Configurar pines del sensor de color
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(LED, OUTPUT);
  
  // Configurar frecuencia del sensor a 100%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  // Encender el LED del sensor
  digitalWrite(LED, HIGH);

  // Configuración de pines de HC-SR04
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG4, OUTPUT);
  pinMode(ECHO4, INPUT);

  //Configuración de pines de TB6612
  pinMode(AIN2, OUTPUT);   // Establece AIN2 como salida
  pinMode(AIN1, OUTPUT);   // Establece AIN1 como salida
  pinMode(PWMA, OUTPUT);   // Establece PWMA como salida
  pinMode(BIN1, OUTPUT);   // Establece BIN1 como salida
  pinMode(BIN2, OUTPUT);   // Establece BIN2 como salida
  pinMode(PWMB, OUTPUT);   // Establece PWMB como salida
  pinMode(STBY, OUTPUT); // Añadir la configuración del pin de standby
  digitalWrite(STBY, HIGH); // Activar el controlador TB6612 (quitar standby)

}

// Función para leer los valores de color
void readColor() {
  // Leer el valor rojo
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  delay(100); // Esperar a que el sensor estabilice
  redValue = pulseIn(OUT, LOW);
  
  // Leer el valor verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  delay(100); // Esperar a que el sensor estabilice
  greenValue = pulseIn(OUT, LOW);
  
  // Leer el valor azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  delay(100); // Esperar a que el sensor estabilice
  blueValue = pulseIn(OUT, LOW);
}

// Función para medir distancia con el HC-SR04
int measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  // Convertir a distancia
  return distance;
}

String identifyColor(int red, int green, int blue) {
  // Detectar colores basados en rangos específicos de valores RGB
  if (red >= 38 && red <= 42 && green >= 25 && green <= 29 && blue >= 17 && blue <= 21) {
    return "Cian";
  } else if (red >= 34 && red <= 38 && green >= 43 && green <= 47 && blue >= 25 && blue <= 29) { /////
    return "Magenta";
  } else if (red >= 38 && red <= 42 && green >= 28 && green <= 32 && blue >= 32 && blue <= 36) { /////
    return "Verde";
  } else if (red >= 16 && red <= 20 && green >= 26 && green <= 30 && blue >= 28 && blue <= 33) { //////
    return "Naranja";
  } else if (red >= 44 && red <= 47 && green >= 45 && green <= 51 && blue >= 28 && blue <= 34) { //////
    return "Violeta";
  } else if (red >= 62 && red <= 68 && green >= 27 && green <= 32 && blue >= 25 && blue <= 30) {
    return "Azul";
  } else if (red >= 18 && red <= 21 && green >= 28 && green <= 32 && blue >= 27 && blue <= 31) {
    return "Amarillo";
  } else if (red >= 22 && red <= 27 && green >= 49 && green <= 57 && blue >= 36 && blue <= 42) { /////
    return "Rojo";
  }
  return "Indefinido";
}

void describeCountry(String color) {
  if (color == "Rojo") {
    Serial.println("País: China - Descripción: China es el país más poblado del mundo y tiene una gran historia cultural y económica.");
  } else if (color == "Verde") {
    Serial.println("País: Brasil - Descripción: Brasil es el país más grande de Sudamérica, conocido por el Amazonas y el Carnaval.");
  } else if (color == "Azul") {
    Serial.println("País: Francia - Descripción: Francia es conocida por su arte, historia y como un centro de moda mundial.");
  } else if (color == "Cian") {
    Serial.println("País: Bahamas - Descripción: Bahamas es un país insular conocido por sus hermosas playas de arena blanca.");
  } else if (color == "Magenta") {
    Serial.println("País: India - Descripción: India es famosa por su rica cultura, tradiciones y la diversidad de su gente.");
  } else if (color == "Amarillo") {
    Serial.println("País: España - Descripción: España es conocida por su gastronomía, arquitectura histórica y el flamenco.");
  } else if (color == "Naranja") {
    Serial.println("País: Países Bajos - Descripción: Los Países Bajos son famosos por sus tulipanes, molinos de viento y canales.");
  } else if (color == "Violeta") {
    Serial.println("País: Japón - Descripción: Japón es conocido por su tecnología avanzada, cultura tradicional y anime.");
  } else {
    Serial.println("Color no identificado.");
  }
}

void loop() {
  // Hacer dos lecturas iniciales de los sensores
  for (int i = 0; i < 1000; i++) {
    makeReading();
    delay(printInterval);  // Esperar 10 segundos entre lecturas
  }

  // Avanzar hasta detectar 6 cm o menos en el sensor delantero
  while (measureDistance(TRIG1, ECHO1) > 6 || measureDistance(TRIG1, ECHO1) < 4) {
    move(forward, 180);  // Avanzar a velocidad 180
  }
  fullStop();

  // Hacer dos lecturas después de alcanzar los 6 cm
  for (int i = 0; i < 1000; i++) {
    makeReading();
    delay(printInterval);  // Esperar 10 segundos entre lecturas
  }

  // Decidir hacia dónde girar según las lecturas de los sensores laterales
  int distanceLeft = measureDistance(TRIG2, ECHO2);
  int distanceRight = measureDistance(TRIG3, ECHO3);
  
  if (distanceLeft > distanceRight) {
    turn(counterClockwise, 180);  // Girar a la izquierda
  } else {
    turn(clockwise, 180);  // Girar a la derecha
  }
  
  // Avanzar hasta que las distancias de adelante y atrás sean iguales
  while (measureDistance(TRIG1, ECHO1) != measureDistance(TRIG4, ECHO4)) {
    move(forward, 180);
  }
  fullStop();
  
  // Repetir la secuencia
}

// Función para realizar una lectura de todos los sensores y el color
void makeReading() {
  // Leer las distancias de todos los sensores ultrasónicos
  distanceFront = measureDistance(TRIG1, ECHO1);
  distanceLeft = measureDistance(TRIG2, ECHO2);
  distanceRight = measureDistance(TRIG3, ECHO3);
  distanceBack = measureDistance(TRIG4, ECHO4);

  // Leer los valores de color
  readColor();
  
  // Identificar el color y describir el país
  String detectedColor = identifyColor(redValue, greenValue, blueValue);
  describeCountry(detectedColor);

  // Imprimir los datos en el Serial
  Serial.print("Distancia delantera: "); Serial.println(distanceFront);
  Serial.print("Distancia izquierda: "); Serial.println(distanceLeft);
  Serial.print("Distancia derecha: "); Serial.println(distanceRight);
  Serial.print("Distancia trasera: "); Serial.println(distanceBack);
  Serial.print("Color detectado: "); Serial.println(detectedColor);
  Serial.print("Color (RGB): ");    
  Serial.print("R: "); Serial.print(redValue);
  Serial.print(" G: "); Serial.print(greenValue);
  Serial.print(" B: "); Serial.println(blueValue);
}

// Función para mover el vehículo hacia adelante o atrás
void move(int direction, int speed)
{
  if (direction == forward)  // Si la dirección es hacia adelante
  {
    moveMotorForward(pinMotorA, speed);  // Mover el motor A hacia adelante
    moveMotorForward(pinMotorB, speed);  // Mover el motor B hacia adelante
  }
  else  // Si la dirección es hacia atrás
  {
    moveMotorBackward(pinMotorA, speed); // Mover el motor A hacia atrás
    moveMotorBackward(pinMotorB, speed); // Mover el motor B hacia atrás
  }
}

// Función para girar el vehículo
void turn(int direction, int speed)
{
  if (direction == clockwise)  // Si la dirección es sentido horario
  {
    moveMotorForward(pinMotorA, speed);  // Mover motor A hacia adelante
    moveMotorBackward(pinMotorB, speed); // Mover motor B hacia atrás
  }
  else  // Si la dirección es sentido antihorario
  {
    moveMotorBackward(pinMotorA, speed); // Mover motor A hacia atrás
    moveMotorForward(pinMotorB, speed);  // Mover motor B hacia adelante
  }
}

// Función para detener completamente el vehículo
void fullStop()
{
  disableMotors();         // Desactivar los motores
  stopMotor(pinMotorA);    // Detener el motor A
  stopMotor(pinMotorB);    // Detener el motor B
}

// Función para mover un motor hacia adelante
void moveMotorForward(const int pinMotor[3], int speed)
{
  digitalWrite(pinMotor[1], HIGH);   // Establecer dirección del motor (AIN2/BIN1 en HIGH)
  digitalWrite(pinMotor[2], LOW);    // Establecer dirección del motor (AIN1/BIN2 en LOW)

  analogWrite(pinMotor[0], speed);   // Establecer la velocidad del motor (PWM)
}

// Función para mover un motor hacia atrás
void moveMotorBackward(const int pinMotor[3], int speed)
{
  digitalWrite(pinMotor[1], LOW);    // Establecer dirección del motor (AIN2/BIN1 en LOW)
  digitalWrite(pinMotor[2], HIGH);   // Establecer dirección del motor (AIN1/BIN2 en HIGH)

  analogWrite(pinMotor[0], speed);   // Establecer la velocidad del motor (PWM)
}

// Función para detener un motor
void stopMotor(const int pinMotor[3])
{
  digitalWrite(pinMotor[1], LOW);    // Establecer AIN2/BIN1 en LOW (detener)
  digitalWrite(pinMotor[2], LOW);    // Establecer AIN1/BIN2 en LOW (detener)

  analogWrite(pinMotor[0], 0);       // Establecer la velocidad del motor en 0 (detener)
}

// Función para activar los motores
void enableMotors()
{
  digitalWrite(STBY, HIGH);       // Activar el pin STBY para habilitar los motores
}

// Función para desactivar los motores
void disableMotors()
{
  digitalWrite(STBY, LOW);        // Desactivar el pin STBY para deshabilitar los motores
}
