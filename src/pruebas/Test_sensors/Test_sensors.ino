// Definición de Pines de Sensor de Color (TCS3200)
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

const unsigned long printInterval = 5000; // Intervalo de 5 segundos
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600); // Iniciar la comunicación Serial

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

  // Configuración de pines de TB6612
  pinMode(AIN2, OUTPUT);   // Establece AIN2 como salida
  pinMode(AIN1, OUTPUT);   // Establece AIN1 como salida
  pinMode(PWMA, OUTPUT);   // Establece PWMA como salida
  pinMode(BIN1, OUTPUT);   // Establece BIN1 como salida
  pinMode(BIN2, OUTPUT);   // Establece BIN2 como salida
  pinMode(PWMB, OUTPUT);   // Establece PWMB como salida
  pinMode(STBY, OUTPUT);   // Añadir la configuración del pin de standby
  digitalWrite(STBY, HIGH); // Activar el controlador TB6612 (quitar standby)
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Verificar si han pasado 5 segundos
  if (currentMillis - previousMillis >= printInterval) {
    previousMillis = currentMillis;
    
    // Obtener los valores de los sensores ultrasónicos y de color
    int distanceFront = measureDistance(TRIG1, ECHO1);
    int distanceLeft = measureDistance(TRIG2, ECHO2);
    int distanceRight = measureDistance(TRIG3, ECHO3);
    int distanceBack = measureDistance(TRIG4, ECHO4);
    int redValue, greenValue, blueValue;
    readColor(&redValue, &greenValue, &blueValue);
    
    // Mostrar los valores en el Serial
    Serial.print("Distancia delantera: "); Serial.print(distanceFront); Serial.println(" cm");
    Serial.print("Distancia izquierda: "); Serial.print(distanceLeft); Serial.println(" cm");
    Serial.print("Distancia derecha: "); Serial.print(distanceRight); Serial.println(" cm");
    Serial.print("Distancia trasera: "); Serial.print(distanceBack); Serial.println(" cm");
    
    Serial.print("Color (RGB): ");
    Serial.print("R: "); Serial.print(redValue);
    Serial.print(" G: "); Serial.print(greenValue);
    Serial.print(" B: "); Serial.println(blueValue);
    
    Serial.println("----------------------------");
  }
}

// Función para medir la distancia con los sensores ultrasónicos
int measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

// Función para leer el sensor de color (TCS3200)
void readColor(int* redValue, int* greenValue, int* blueValue) {
  // Leer el valor rojo
  digitalWrite(S2, LOW);   // <-- Aquí definí cómo leer el valor rojo.
  digitalWrite(S3, LOW);   // <-- Aquí definí cómo leer el valor rojo.
  delay(100);
  *redValue = pulseIn(OUT, LOW);

  // Leer el valor verde
  digitalWrite(S2, HIGH);  // <-- Aquí definí cómo leer el valor verde.
  digitalWrite(S3, HIGH);  // <-- Aquí definí cómo leer el valor verde.
  delay(100);
  *greenValue = pulseIn(OUT, LOW);

  // Leer el valor azul
  digitalWrite(S2, LOW);   // <-- Aquí definí cómo leer el valor azul.
  digitalWrite(S3, HIGH);  // <-- Aquí definí cómo leer el valor azul.
  delay(100);
  *blueValue = pulseIn(OUT, LOW);
}