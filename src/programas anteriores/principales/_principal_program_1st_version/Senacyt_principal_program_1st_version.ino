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

// Definir constantes para el control PD
#define DESIRED_DISTANCE 12  // Distancia deseada en cm
#define KP 10  // Ganancia proporcional
#define KD 5   // Ganancia derivativa

// Variables para contar giros y controlar la posición
int giroCount = 0;
bool atInitialPosition = true;

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

String identifyColor(int red, int green, int blue) {
  if (red > green && red > blue) {
    if (green > blue) {
      return "Naranja";
    } else {
      return "Rojo";
    }
  } else if (green > red && green > blue) {
    if (blue > red) {
      return "Cian";
    } else {
      return "Verde";
    }
  } else if (blue > red && blue > green) {
    if (red > green) {
      return "Magenta";
    } else {
      return "Azul";
    }
  } else if (red == green && green > blue) {
    return "Amarillo";
  } else if (red == blue && red > green) {
    return "Violeta";
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
  // Leer distancias
  long distanceFront = readUltrasonic(TRIG1, ECHO1);
  long distanceRight = readUltrasonic(TRIG2, ECHO2);
  long distanceLeft = readUltrasonic(TRIG3, ECHO3);
  long distanceBack = readUltrasonic(TRIG4, ECHO4);

  // Imprimir distancias de los sensores
  Serial.print("Distancia Frontal: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Distancia Derecha: ");
  Serial.print(distanceRight);
  Serial.print(" cm, Distancia Izquierda: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Distancia Trasera: ");
  Serial.println(distanceBack);

  // Calcular errores y control PD
  long errorLeft = distanceLeft - DESIRED_DISTANCE;
  long errorRight = distanceRight - DESIRED_DISTANCE;
  static long prevErrorLeft = 0;
  static long prevErrorRight = 0;
  long derivativeLeft = errorLeft - prevErrorLeft;
  long derivativeRight = errorRight - prevErrorRight;

  // Control proporcional y derivativo (P y D) para mantener la distancia de pared
  int speedLeft = 255 - (KP * errorLeft + KD * derivativeLeft);
  int speedRight = 255 - (KP * errorRight + KD * derivativeRight);

  // Actualizar errores anteriores
  prevErrorLeft = errorLeft;
  prevErrorRight = errorRight;

  // Controlar el movimiento
  if (distanceFront < 15) {
    // Decidir hacia dónde girar
    if (distanceRight > distanceLeft) {
      // Girar a la derecha
      controlMotor(AIN1, AIN2, PWMA, 255);
      controlMotor(BIN1, BIN2, PWMB, -255);
      giroCount++;
    } else {
      // Girar a la izquierda
      controlMotor(AIN1, AIN2, PWMA, -255);
      controlMotor(BIN1, BIN2, PWMB, 255);
      giroCount++;
    }

    // Detectar colores cuando el robot esté girando
    if (abs(distanceFront - distanceBack) < 2) { // Si la distancia frontal es similar a la trasera
      int red = readColor(LOW, LOW);
      int green = readColor(HIGH, HIGH);
      int blue = readColor(LOW, HIGH);

      // Identificar el color
      String detectedColor = identifyColor(red, green, blue);

      // Describir el país asociado al color
      describeCountry(detectedColor);

      // Imprimir el color detectado
      Serial.print("Color Detectado: ");
      Serial.println(detectedColor);
    }

    // Detener el robot después de 4 giros y volver a la posición inicial
    if (giroCount >= 4) {
      // Imprimir distancias finales antes de detenerse
      Serial.print("Distancia Frontal Final: ");
      Serial.print(distanceFront);
      Serial.print(" cm, Distancia Derecha Final: ");
      Serial.print(distanceRight);
      Serial.print(" cm, Distancia Izquierda Final: ");
      Serial.print(distanceLeft);
      Serial.print(" cm, Distancia Trasera Final: ");
      Serial.println(distanceBack);

      giroCount = 0;  // Resetear el contador de giros
      atInitialPosition = true;  // Volver a la posición inicial

      // Detener los motores
      controlMotor(AIN1, AIN2, PWMA, 0);
      controlMotor(BIN1, BIN2, PWMB, 0);

      // Finalizar el programa o reiniciar el proceso
      while (true) {}  // Detener la ejecución del programa
    }
  } else {
    // Ajustar la velocidad de los motores para mantener la distancia de pared
    controlMotor(AIN1, AIN2, PWMA, speedLeft);
    controlMotor(BIN1, BIN2, PWMB, speedRight);
  }

  delay(1000); // Esperar 1 segundo antes de la próxima lectura
}