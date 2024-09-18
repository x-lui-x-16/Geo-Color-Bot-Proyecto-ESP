// Definición de pines para controlar el controlador de motor
const int pinPWMA = 6;   // Pin para la velocidad del motor A (PWM)
const int pinAIN2 = 7;   // Pin para la dirección del motor A (AIN2)
const int pinAIN1 = 8;   // Pin para la dirección del motor A (AIN1)
const int pinBIN1 = 9;   // Pin para la dirección del motor B (BIN1)
const int pinBIN2 = 10;  // Pin para la dirección del motor B (BIN2)
const int pinPWMB = 11;  // Pin para la velocidad del motor B (PWM)
const int pinSTBY = 12;  // Pin para activar/desactivar los motores (standby)

// Variables de tiempo y velocidad
const int waitTime = 2000;  // Tiempo de espera entre fases en milisegundos
const int speed = 0;    // Velocidad inicial de los motores (se puede modificar)

// Matrices para agrupar los pines de cada motor
const int pinMotorA[3] = { pinPWMA, pinAIN2, pinAIN1 };  // Pines del motor A
const int pinMotorB[3] = { pinPWMB, pinBIN1, pinBIN2 };  // Pines del motor B

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

// Configuración inicial de los pines
void setup()
{
  pinMode(pinAIN2, OUTPUT);   // Establece AIN2 como salida
  pinMode(pinAIN1, OUTPUT);   // Establece AIN1 como salida
  pinMode(pinPWMA, OUTPUT);   // Establece PWMA como salida
  pinMode(pinBIN1, OUTPUT);   // Establece BIN1 como salida
  pinMode(pinBIN2, OUTPUT);   // Establece BIN2 como salida
  pinMode(pinPWMB, OUTPUT);   // Establece PWMB como salida
}

// Bucle principal que controla las acciones del robot
void loop()
{
  enableMotors();          // Activar los motores
  move(forward, 15);       // Mover hacia adelante a velocidad 15
  delay(waitTime);         // Esperar el tiempo definido

  move(backward, 15);      // Mover hacia atrás a velocidad 15
  delay(waitTime);         // Esperar

  turn(clockwise, 15);     // Girar en sentido horario a velocidad 15
  delay(waitTime);         // Esperar

  turn(counterClockwise, 15); // Girar en sentido antihorario a velocidad 15
  delay(waitTime);         // Esperar

  fullStop();              // Detener los motores
  delay(waitTime);         // Esperar
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
  digitalWrite(pinSTBY, HIGH);       // Activar el pin STBY para habilitar los motores
}

// Función para desactivar los motores
void disableMotors()
{
  digitalWrite(pinSTBY, LOW);        // Desactivar el pin STBY para deshabilitar los motores
}