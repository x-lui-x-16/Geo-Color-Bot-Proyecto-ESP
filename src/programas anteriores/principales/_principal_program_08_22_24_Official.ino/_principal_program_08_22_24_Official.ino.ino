// Definir los pines de conexión de los sensores HC-SR04
#define TRIG1 8   // Sensor delantero
#define ECHO1 9
#define TRIG2 10  // Sensor izquierdo
#define ECHO2 11
#define TRIG3 12  // Sensor derecho
#define ECHO3 17
#define TRIG4 4   // Sensor trasero
#define ECHO4 5

// Definición de pines
#define S0 18
#define S1 2
#define S2 3
#define S3 6
#define OUT 7
#define LED 21

// Variables globales para las distancias y color
int distanceFront, distanceRight, distanceLeft, distanceBack;
int redValue, greenValue, blueValue;
unsigned long lastPrintTime = 0;  // Variable para el control de tiempo
const unsigned long printInterval = 10000;  // Intervalo de 10 segundos

// Configuración inicial
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
  if (red >= 40 && red <= 45 && green >= 17 && green <= 22 && blue >= 17 && blue <= 22) {
    return "Cian";
  } else if (red >= 34 && red <= 39 && green >= 26 && green <= 30 && blue >= 25 && blue <= 29) {
    return "Magenta";
  } else if (red >= 46 && red <= 50 && green >= 38 && green <= 43 && blue >= 37 && blue <= 41) {
    return "Verde";
  } else if (red >= 19 && red <= 22 && green >= 30 && green <= 33 && blue >= 30 && blue <= 34) {
    return "Naranja";
  } else if (red >= 45 && red <= 55 && green >= 35 && green <= 40 && blue >= 33 && blue <= 38) {
    return "Violeta";
  } else if (red >= 62 && red <= 68 && green >= 27 && green <= 32 && blue >= 25 && blue <= 30) {
    return "Azul";
  } else if (red >= 18 && red <= 21 && green >= 28 && green <= 32 && blue >= 27 && blue <= 31) {
    return "Amarillo";
  } else if (red >= 23 && red <= 27 && green >= 36 && green <= 45 && blue >= 34 && blue <= 43) {
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
  // Leer los valores de color
  readColor();

  // Medir las distancias de los sensores
  distanceFront = measureDistance(TRIG1, ECHO1);
  distanceLeft = measureDistance(TRIG2, ECHO2);
  distanceRight = measureDistance(TRIG3, ECHO3);
  distanceBack = measureDistance(TRIG4, ECHO4);

  // Imprimir valores cada 10 segundos
  if (millis() - lastPrintTime >= printInterval) {
    Serial.print("Distancia Delantera: ");
    Serial.print(distanceFront);
    Serial.print(" cm, Distancia Izquierda: ");
    Serial.print(distanceLeft);
    Serial.print(" cm, Distancia Derecha: ");
    Serial.print(distanceRight);
    Serial.print(" cm, Distancia Trasera: ");
    Serial.println(distanceBack);

    Serial.print("Rojo: ");
    Serial.print(redValue);
    Serial.print(" Verde: ");
    Serial.print(greenValue);
    Serial.print(" Azul: ");
    Serial.println(blueValue);

    String color = identifyColor(redValue, greenValue, blueValue);
    Serial.print("Color detectado: ");
    Serial.println(color);
    describeCountry(color);

    lastPrintTime = millis();  // Reiniciar el tiempo
  }

  // Esperar un segundo antes de leer nuevamente
  delay(1000);
}
