//#include <ArduinoBLE.h>

// Definir constantes para el control PD
#define DESIRED_DISTANCE 12  // Distancia deseada en cm
#define KP 10  // Ganancia proporcional
#define KD 5   // Ganancia derivativa

// Definir los pines de conexión del TCS3200
#define S0 18
#define S1 2
#define S2 4
#define S3 5
#define OUT 7
#define LED 21

// Definir los pines de conexión de los sensores HC-SR04
#define TRIG1 8
#define ECHO1 9
#define TRIG2 10
#define ECHO2 11
#define TRIG3 12
#define ECHO3 17
#define TRIG4 6
#define ECHO4 3

// Definir los pines de conexión del controlador TB6612
#define AIN1 14
#define AIN2 15
#define PWMA 16
#define BIN1 19
#define BIN2 20
#define PWMB 13
#define STBY 22

// Definir las variables de distancia anteriores
long lastErrorRight = 0;
long lastErrorLeft = 0;

// Variables para controlar el conteo de giros
int turnCount = 0;
bool hasTurned = false;
bool turning = false; 

// Variables para almacenar la posición inicial
bool isReturning = false;

//// Definir servicio y características BLE
//BLEService robotService("180F");  // Servicio con UUID de ejemplo
//BLECharacteristic colorCharacteristic("2A19", BLERead | BLENotify, 20);  // Característica para color
//BLECharacteristic distanceCharacteristic("2A1E", BLERead | BLENotify, 50);  // Característica para distancia

// Definir la velocidad del robot y el tiempo para giros de 90 grados
#define SPEED 80  // Velocidad de avance
#define TURN_DURATION 330  // Duración del giro de 90 grados en milisegundos

// Definir la duración del avance de 360 grados en milisegundos
#define ADVANCE_360_DURATION 330  // Duración para avanzar 360 grados

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

  //// Configurar Bluetooth
  //if (!BLE.begin()) {
    //Serial.println("Error al iniciar Bluetooth");
    //while (1);
  //}
  //BLE.setLocalName("Robot");
  //BLE.setAdvertisedService(robotService);
  //robotService.addCharacteristic(colorCharacteristic);
  //robotService.addCharacteristic(distanceCharacteristic);
  //BLE.addService(robotService);
  //BLE.advertise();
  
  // Avance inicial de 360 grados
  controlMotor(AIN1, AIN2, PWMA, SPEED);
  controlMotor(BIN1, BIN2, PWMB, SPEED);
  delay(ADVANCE_360_DURATION);
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
    analogWrite(in1, speed);
    analogWrite(in2, 0);
  } else if (speed < 0) {
    analogWrite(in1, 0);
    analogWrite(in2, speed);
  } else {
    analogWrite(in1, 0);
    analogWrite(in2, 0);
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

int calculatePD(int distanceLeft, int distanceRight) {
  int error = distanceLeft - distanceRight;
  static int previousError = 0;
  int derivative = error - previousError;
  previousError = error;
  return KP * error + KD * derivative;
}

//void sendBluetoothData(String color, long distanceFront, long distanceRight, long distanceLeft, long distanceBack, int red, int green, int blue) {
  //if (BLE.connected()) {
    //// Convertir datos a cadenas de caracteres
    //String colorData = "Color: " + color + " (R:" + red + ", G:" + green + ", B:" + blue + ")";
    //String distanceData = "Distancia frontal: " + String(distanceFront) + 
                          //", Distancia derecha: " + String(distanceRight) + 
                          //", Distancia izquierda: " + String(distanceLeft) + 
                          //", Distancia trasera: " + String(distanceBack);

    //// Convertir String a const char*
    //const char* colorChar = colorData.c_str();
    //const char* distanceChar = distanceData.c_str();

    //// Enviar datos por Bluetooth
    //colorCharacteristic.setValue(colorChar);
    //colorCharacteristic.setValue(distanceChar); // Actualizar la característica de distancia
  //}
//}

void loop() {
  // Leer colores
  int red = readColor(LOW, LOW);
  int green = readColor(HIGH, LOW);
  int blue = readColor(LOW, HIGH);
  String color = identifyColor(red, green, blue);
  describeCountry(color);

  // Leer distancias
  long distanceFront = readUltrasonic(TRIG1, ECHO1);
  long distanceRight = readUltrasonic(TRIG2, ECHO2);
  long distanceLeft = readUltrasonic(TRIG3, ECHO3);
  long distanceBack = readUltrasonic(TRIG4, ECHO4);

  // Enviar datos por Bluetooth y Serial
  //sendBluetoothData(color, distanceFront, distanceRight, distanceLeft, distanceBack, red, green, blue);
  Serial.print("Color: "); Serial.print(color); 
  Serial.print(" (R: "); Serial.print(red); 
  Serial.print(", G: "); Serial.print(green); 
  Serial.print(", B: "); Serial.print(blue); 
  Serial.println(")");
  Serial.print("Distancia frontal: "); Serial.print(distanceFront); 
  Serial.print(", Distancia derecha: "); Serial.print(distanceRight); 
  Serial.print(", Distancia izquierda: "); Serial.print(distanceLeft); 
  Serial.print(", Distancia trasera: "); Serial.println(distanceBack);

  // Control del robot (solo como ejemplo, ajustar según la lógica)
  if (!turning) {
    int controlValue = calculatePD(distanceLeft, distanceRight);
    if (controlValue > 0) {
      controlMotor(AIN1, AIN2, PWMA, SPEED);
      controlMotor(BIN1, BIN2, PWMB, SPEED - controlValue);
    } else {
      controlMotor(AIN1, AIN2, PWMA, SPEED + controlValue);
      controlMotor(BIN1, BIN2, PWMB, SPEED);
    }
    delay(100);
  }

  // Ejemplo de lógica para giro (ajustar según necesidad)
  if (turnCount < 4 && !turning) {
    turning = true;
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    delay(TURN_DURATION);
    turnCount++;
    turning = false;
  }
  
  if (turnCount >= 4 && !isReturning) {
    isReturning = true;
    // Regresar al punto de inicio (implementa la lógica aquí)
  }
}
