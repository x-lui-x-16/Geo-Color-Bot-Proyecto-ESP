#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Arduino.h>

// Definir constantes para el control PD
#define DESIRED_DISTANCE 12  // Distancia deseada en cm
#define KP 10  // Ganancia proporcional
#define KD 5   // Ganancia derivativa

// Definir los pines de conexión del TCS3200
#define S0 18
#define S1 2
#define S2 3
#define S3 6
#define OUT 7
#define LED 21

// Definir los pines de conexión de los sensores HC-SR04
#define TRIG1 8   // Sensor delantero
#define ECHO1 9
#define TRIG2 10  // Sensor izquierdo
#define ECHO2 11
#define TRIG3 12  // Sensor derecho
#define ECHO3 17
#define TRIG4 4   // Sensor trasero
#define ECHO4 5

// Pines para los motores
#define MOTOR1_INA_PIN 14
#define MOTOR1_INB_PIN 15
#define MOTOR1_PWM_PIN 16
#define MOTOR1_STBY_PIN 22

#define MOTOR2_INA_PIN 19
#define MOTOR2_INB_PIN 20
#define MOTOR2_PWM_PIN 13
#define MOTOR2_STBY_PIN 22

// Variables de velocidad y control de giros
#define SPEED 80  // Velocidad de avance
#define TURN_DURATION 330  // Duración del giro de 90 grados en milisegundos

// Variables globales para las distancias y color
int distanceFront, distanceRight, distanceLeft, distanceBack;
int redValue, greenValue, blueValue;
unsigned long startTime;
int turnCount = 0;
const int MAX_TURNS = 4;
int error;
int lastError;
int controlSignal;

// Función para leer el valor de color
int readColor(int s2, int s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(100); // Esperar a que el sensor se estabilice
  return pulseIn(OUT, LOW);
}

// Función para describir el país en base al color detectado
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

// Función para obtener la distancia usando el sensor ultrasonido
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

// Función para calcular el control PD
int calculatePD(int distance) {
  error = DESIRED_DISTANCE - distance;
  controlSignal = KP * error + KD * (error - lastError);
  lastError = error;
  return controlSignal;
}

// Función para avanzar el robot
void moveForward() {
  digitalWrite(MOTOR1_STBY_PIN, HIGH); // Habilitar el motor
  analogWrite(MOTOR1_PWM_PIN, SPEED);  // Velocidad hacia adelante
  digitalWrite(MOTOR1_INA_PIN, HIGH);
  digitalWrite(MOTOR1_INB_PIN, LOW);

  digitalWrite(MOTOR2_STBY_PIN, HIGH); // Habilitar el motor
  analogWrite(MOTOR2_PWM_PIN, SPEED);
  digitalWrite(MOTOR2_INA_PIN, HIGH);
  digitalWrite(MOTOR2_INB_PIN, LOW);

  Serial.println("Robot avanzando...");
}

// Función para detener el robot
void stopRobot() {
  analogWrite(MOTOR1_PWM_PIN, 0);
  analogWrite(MOTOR2_PWM_PIN, 0);
  Serial.println("Robot detenido.");
}

// Función para girar el robot hacia la derecha
void turnRight() {
  digitalWrite(MOTOR1_STBY_PIN, HIGH); // Habilitar el motor
  analogWrite(MOTOR1_PWM_PIN, SPEED);  // Motor A avanza
  digitalWrite(MOTOR1_INA_PIN, LOW);
  digitalWrite(MOTOR1_INB_PIN, HIGH);

  digitalWrite(MOTOR2_STBY_PIN, HIGH); // Habilitar el motor
  analogWrite(MOTOR2_PWM_PIN, SPEED);  // Motor B avanza
  digitalWrite(MOTOR2_INA_PIN, HIGH);
  digitalWrite(MOTOR2_INB_PIN, LOW);

  delay(TURN_DURATION); // Ajustar para realizar un giro de 90 grados
  stopRobot();
}

// Función para girar el robot hacia la izquierda
void turnLeft() {
  digitalWrite(MOTOR1_STBY_PIN, HIGH); // Habilitar el motor
  analogWrite(MOTOR1_PWM_PIN, SPEED);  // Motor A avanza
  digitalWrite(MOTOR1_INA_PIN, HIGH);
  digitalWrite(MOTOR1_INB_PIN, LOW);

  digitalWrite(MOTOR2_STBY_PIN, HIGH); // Habilitar el motor
  analogWrite(MOTOR2_PWM_PIN, SPEED);  // Motor B avanza
  digitalWrite(MOTOR2_INA_PIN, LOW);
  digitalWrite(MOTOR2_INB_PIN, HIGH);

  delay(TURN_DURATION); // Ajustar para realizar un giro de 90 grados
  stopRobot();
}

void setup() {
  // Configuración de pines
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG4, OUTPUT);
  pinMode(ECHO4, INPUT);
  
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(LED, OUTPUT);

  pinMode(MOTOR1_INA_PIN, OUTPUT);
  pinMode(MOTOR1_INB_PIN, OUTPUT);
  pinMode(MOTOR1_PWM_PIN, OUTPUT);
  pinMode(MOTOR1_STBY_PIN, OUTPUT);

  pinMode(MOTOR2_INA_PIN, OUTPUT);
  pinMode(MOTOR2_INB_PIN, OUTPUT);
  pinMode(MOTOR2_PWM_PIN, OUTPUT);
  pinMode(MOTOR2_STBY_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Obtener las distancias de los sensores
  distanceFront = getDistance(TRIG1, ECHO1);
  distanceRight = getDistance(TRIG3, ECHO3);
  distanceLeft = getDistance(TRIG2, ECHO2);
  distanceBack = getDistance(TRIG4, ECHO4);

  // Lógica para avanzar y girar
  if (distanceFront > 9) {
    moveForward();
  } else {
    stopRobot();
    int maxDistance = max(distanceRight, distanceLeft);
    
    if (maxDistance == distanceRight) {
      Serial.println("Giro hacia la derecha");
      turnRight();
      turnCount++;
    } else {
      Serial.println("Giro hacia la izquierda");
      turnLeft();
      turnCount++;
    }

    // Verificar si se ha realizado 4 giros
    if (turnCount >= MAX_TURNS) {
      // Regresar a la posición inicial
      while (distanceFront != DESIRED_DISTANCE || distanceBack != DESIRED_DISTANCE) {
        int controlSignal = calculatePD(distanceFront);
        if (controlSignal > 0) {
          moveForward();
        } else {
          stopRobot();
        }
        distanceFront = getDistance(TRIG1, ECHO1);
        distanceBack = getDistance(TRIG4, ECHO4);
        delay(100);
      }

      // Reiniciar el contador de giros
      turnCount = 0;
    }
  }
}