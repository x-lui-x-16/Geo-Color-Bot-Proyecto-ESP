# Geo-Color-Bot-Proyecto
Proyecto: "Geo-Color Bot"

[Version en Inglés](https://github.com/x-lui-x-16/Geo-Color-Bot-Project-ENG)

## Materiales de ingeniería
Todos los materiales que hemos utilizado para este proyecto. 
- 1 Arduino Mega R3 2560 (https://docs.arduino.cc/hardware/mega-2560/)
- 1 Puente H TB6612 (HW-166)
- 1 Módulo Bluetooth (HC-05)
- 4 Sensores Ultrasónicos (HC-SR04) (1 frontal, 1 trasero, los otros dos a derecha e izquierda)
- 1 Sensor de Color (TCS3200) (En la parte inferior del vehículo)
- 1 Estuche de 3 Baterías 18650
- 3 Baterías 18650 (alrededor de 11.1v)
- 1 Chasis 4wd - Esto incluye:
    - 1 Base Acrílica
    - 4 Motores Amarillos
    - 4 Ruedas
- ... Protocables

## Instrucciones de construcción
- Chasis 4wd: https://youtu.be/kurIK5AGhnw?si=gg4Zbn1UOIr4_YVg
- Electrónica (Circuito y Batería): [El diagrama del circuito se puede encontrar en el directorio de esquemas](esquemas/)
- Código (Para el Arduino): [El código se puede encontrar en el directorio src](src/)

## Contenido
[Componentes electromecánicos](componentes-electromecanicos/) En esta carpeta están todos los componentes electromecánicos utilizados.

[Esquemas](esquemas/) En esta carpeta se muestran todos los esquemas del proyecto. 

[Code](src/) En esta carpeta se encuentra el código utilizado.

[Fotos del vehículo](v-photos/) En esta carpeta encontrarás imágenes del vehículo desde diferentes ángulos.

## Introducción
A continuación está el desarrollo y documentación del proyecto Geo-Color Bot, un robot educativo diseñado para apoyar el aprendizaje de personas con dificultades como el TDAH o el daltonismo. El robot utiliza la detección de colores para asociar cada uno con un país específico, proporcionando información relevante sobre el país mediante inteligencia artificial.

Descripción del Proyecto:
El Geo-Color Bot está equipado con un sensor de color TCS3200 en la base, capaz de identificar colores y enviar la información a un monitor, donde se muestra el país correspondiente junto con una breve descripción generada por IA.

Para su desplazamiento, el robot cuenta con cuatro sensores ultrasónicos HC-SR04, ubicados para medir distancias en las direcciones frontal, trasera, derecha e izquierda, asegurando una navegación precisa y evitando obstáculos.

Componentes Principales:
- Microcontrolador: Arduino Mega 2560
- Sensores de color: TCS3200
- Sensores ultrasónicos: HC-SR04 (x4)
- Comunicación inalámbrica: Módulo Bluetooth HC-05
- Lenguaje de programación: C++ (Arduino IDE)

Funcionalidad:
El Arduino Mega 2560 procesa la información de los sensores, controla los movimientos del robot y permite la comunicación inalámbrica con una computadora a través del módulo Bluetooth, para el monitoreo y control a distancia.

## Objetivos
Objetivo General:
Desarrollar un sistema educativo robótico que facilite el aprendizaje inclusivo y adaptado a personas con dificultades de aprendizaje, como el TDAH y el daltonismo, utilizando tecnologías de detección de colores y sensores ultrasónicos para proporcionar una experiencia de aprendizaje interactiva, efectiva y entretenida.

Objetivos Específicos:
- Diseñar e implementar un robot autónomo que utilice un sensor de color TCS3200 para identificar colores y asociarlos con información educativa, como países y sus características, permitiendo a los usuarios aprender de manera dinámica y contextualizada.
- Realizar una programación precisa para controlar el robot, asegurando que todos los sensores y motores funcionen de manera coordinada y eficiente. Esta programación incluirá algoritmos que permitan al robot detectar colores, medir distancias y tomar decisiones autónomas, convirtiendo al robot en una herramienta útil y aplicable en el mundo real.
- Integrar sensores ultrasónicos HC-SR04 en el sistema robótico para garantizar que el robot pueda navegar de manera segura, evitar obstáculos y posicionarse adecuadamente para realizar la detección de colores en diferentes entornos.
- Desarrollar una interfaz de comunicación mediante el módulo Bluetooth HC-05, que permita transmitir los datos de color y las distancias medidas por el robot a una computadora, facilitando el monitoreo y el análisis de la información en tiempo real.
- Evaluar la efectividad del método educativo propuesto mediante pruebas con usuarios que presenten TDAH y daltonismo, recopilando datos sobre su experiencia de aprendizaje y ajustando el sistema según sea necesario para mejorar su accesibilidad y eficacia.
- Promover el uso de tecnologías robóticas en el ámbito educativo, demostrando cómo herramientas interactivas y adaptativas pueden hacer el aprendizaje más accesible y atractivo para personas con diversas necesidades educativas.

## Beneficiarios e Impacto
Beneficiarios del Proyecto:
- Personas con TDAH (Trastorno por Déficit de Atención e Hiperactividad): El Geo-Color Bot está diseñado para ayudar a mejorar la concentración y el aprendizaje de personas con TDAH a través de un enfoque interactivo y multisensorial. Al integrar estímulos visuales, auditivos y táctiles, se crea una experiencia educativa dinámica que puede captar y mantener la atención de los estudiantes.
- Personas con Daltonismo: El proyecto también ofrece beneficios a personas con daltonismo, facilitando el reconocimiento de colores mediante la asociación con información contextual, como la identificación de países. Esto ayuda a crear una comprensión más funcional de los colores en un entorno educativo.
- Educadores y Centros Educativos: Los educadores pueden utilizar el Geo-Color Bot como una herramienta inclusiva para personalizar el aprendizaje según las necesidades de sus estudiantes, mejorando tanto los resultados académicos como el bienestar general de los estudiantes.
- Familias y Cuidadores: Las familias y cuidadores de personas con TDAH y daltonismo verán mejoras en las habilidades de aprendizaje y confianza de sus seres queridos, lo que hace que este proyecto también sea un recurso útil para el apoyo en el hogar.
- Desarrolladores y Entusiastas de la Robótica: Los desarrolladores de tecnología educativa y los entusiastas de la robótica pueden beneficiarse de este proyecto como un caso de estudio o inspiración para futuras iniciativas, demostrando cómo la robótica y la programación pueden contribuir a la educación inclusiva.

Impacto del Proyecto:
- Mejora de la Inclusión Educativa: El proyecto tiene un impacto positivo en la educación inclusiva al adaptar los métodos de enseñanza a las necesidades de estudiantes con TDAH y daltonismo, permitiendo que más estudiantes accedan a una educación de calidad.
- Fomento del Aprendizaje Activo y Motivación: Al incorporar la robótica e interactividad en el proceso educativo, el Geo-Color Bot promueve un aprendizaje activo, donde los estudiantes son participantes activos, lo que incrementa la motivación y el compromiso.
- Desarrollo de Habilidades Técnicas y Cognitivas: A través de la interacción con el robot, los estudiantes no solo adquieren conocimientos educativos, sino que también desarrollan habilidades técnicas y cognitivas clave, como la resolución de problemas y el pensamiento crítico.
- Sensibilización y Conciencia Social: El proyecto aumenta la conciencia sobre las necesidades educativas especiales, promoviendo una mayor comprensión y apoyo hacia las personas con TDAH y daltonismo en la sociedad.
- Innovación en Educación: El Geo-Color Bot representa un avance en la innovación educativa, demostrando cómo la tecnología puede ser utilizada para abordar desafíos específicos y complejos en la enseñanza, inspirando nuevas soluciones tecnológicas en el ámbito educativo inclusivo.

## Metodología
El desarrollo del Geo-Color Bot se centró en varios pasos clave: planificación y diseño, desarrollo del hardware, desarrollo del software, integración y pruebas, evaluación y documentación, y finalmente, la mejora continua.

Planificación y Diseño:
Definimos objetivos claros para el proyecto, enfocándonos en la detección precisa de colores y la movilidad eficiente. Seleccionamos los componentes electrónicos más adecuados, como el sensor de color TCS3200, los sensores ultrasónicos HC-SR04 para medir distancias, y el microprocesador RP2040, entre otros.

Desarrollo del Hardware:
Se integraron los componentes en la base del robot 2WD. El sensor de color se ubicó en la parte inferior para detectar colores en el suelo, mientras que los sensores ultrasónicos se colocaron en las posiciones frontal, trasera, derecha e izquierda para medir distancias. Todas las conexiones se realizaron de manera que la comunicación entre los sensores y el microprocesador fuera eficiente.
- Imagen del Proyecto:
[A continuación estan algunas imagenes del proyecto para mejor referencia:](v-photos/)
- Diagrama del Cableado:
[A continuación está como estan conectados los componentes:](esquemas/)

Desarrollo del Software:
El código se escribió en C++ utilizando Arduino IDE. Programamos el sensor de color para detectar los valores RGB y los sensores ultrasónicos para medir distancias en todas las direcciones. La lógica del software permite al robot navegar de manera autónoma y evitar obstáculos, asegurando una detección y movilidad precisa.
- Código
[A continuación se encuentra el código para mayor entendimiento:](src/)

Integración y Pruebas:
Este proceso se dividió en tres etapas:
- Integración del Sistema: Conectamos todos los componentes electrónicos al Arduino Nano RP2040.
- Pruebas de Funcionamiento: Realizamos pruebas exhaustivas y calibraciones de los sensores ultrasónicos y del sensor de color para asegurar un correcto funcionamiento
- Ajustes y Optimización: Ajustamos los parámetros de los sensores para optimizar la navegación y la precisión en la detección de colores.

Evaluación y Documentación:
Se realizaron pruebas en diversos entornos para asegurar la consistencia del robot. Recopilamos datos que ayudaron a identificar áreas de mejora. Todo el proceso y los resultados de las pruebas fueron documentados para facilitar futuras modificaciones y mejoras.

Mejora Continua:
Implementamos las mejoras identificadas durante la fase de evaluación. Estas incluyen la calibración de los sensores, ajustes en las velocidades de movimiento y refinamientos en la detección de distancias y colores, asegurando que el robot reaccione de manera eficiente ante distintos escenarios.

## Resultados Esperados
A continuación, se detallan los principales resultados que esperamos lograr con el desarrollo del Geo-Color Bot:

- Precisión en la Detección de Colores:
Se espera que el robot detecte colores con alta precisión utilizando el sensor TCS3200, incluso en diferentes condiciones de iluminación y superficies. La exactitud en la detección es crucial para que el sistema asocie correctamente cada color con su respectiva información educativa, como la identificación de países. Esto asegurará que los usuarios reciban información confiable y relevante, mejorando la efectividad del aprendizaje.

- Visualización Rápida y Clara de la Información:
Una vez detectado un color, el sistema debe mostrar la información educativa asociada de forma rápida y clara en una pantalla. El tiempo de respuesta será breve para que los datos educativos se presenten casi instantáneamente después de la detección del color. Esto es fundamental para mantener un flujo educativo continuo y una experiencia de usuario fluida.

- Movilidad Eficiente y Evitación de Colisiones:
Gracias a los sensores ultrasónicos HC-SR04, el robot se moverá de manera eficiente, detectando y evitando obstáculos en todas las direcciones (adelante, atrás, derecha e izquierda). Esto permitirá que el robot opere de forma autónoma y segura, sin riesgo de colisiones, garantizando la integridad del robot y su entorno, y prolongando su vida útil.

- Interacción Educativa y Atractiva:
El robot proporcionará una experiencia educativa interactiva y atractiva, diseñada especialmente para captar el interés de personas con dificultades de aprendizaje, como el TDAH y el daltonismo. La combinación de aprendizaje multisensorial y visual motivará a los usuarios, haciendo que el proceso de enseñanza sea dinámico, divertido y efectivo.

- Confiabilidad y Estabilidad en Uso Prolongado:
El sistema mostrará una alta confiabilidad y estabilidad durante periodos de uso prolongado. Incluso después de varias horas de funcionamiento continuo, el robot mantendrá su rendimiento sin errores técnicos o fallos, garantizando su aplicabilidad en entornos educativos reales.

- Capacidad de Mejora Continua:
El diseño del robot permitirá futuras mejoras basadas en los datos recopilados y el feedback de los usuarios. Esto incluye la posibilidad de ajustar la programación para mejorar la detección de colores, optimizar la movilidad y refinar la experiencia educativa. Esta adaptabilidad asegurará la evolución constante del robot frente a nuevas necesidades.

- Adaptabilidad a Nuevas Condiciones:
El robot será capaz de adaptarse a diferentes condiciones ambientales, como cambios en la iluminación o en la disposición del espacio. Esta versatilidad permitirá que sea útil en diversos entornos, desde aulas con configuraciones variables hasta eventos educativos.

- Incorporación de Funcionalidades Futuras:
El sistema será diseñado con flexibilidad para permitir la integración de nuevas funcionalidades en el futuro, como la incorporación de otros sensores, mejoras en la interfaz de usuario, o la expansión a otras disciplinas educativas. Esta capacidad de expansión asegurará la longevidad del proyecto y aumentará su impacto.

## Presupuesto
El siguiente es el presupuesto estimado para el desarrollo del proyecto Geo-Color Bot:

- Arduino Mega 2560 R3 - $49.65
- Sensor de Color TCS3200 - $9.99
- Kit de 5 Sensores Ultrasónicos (HC-SR04) y sus respectivas Bases - $9.99
- Kit de 5 Controladores de Motor (TB6612FNG) - $12.99
- Módulo Bluetooth (HC-05) - $9.99
- Kit de Protoboard y Cable Dupont - $9.99
- Pantalla LCD - $11.99
- Kit Arduino 4WD - $21.49
      Incluye:
    - Base Acrílica
    - 4 Motor Amarillo
    - 4 Ruedas
- Estuche de 3 Baterías 18650 - $3.00
- 3.7V 18650 Baterías (x3) - $10.50 ($3.50 cada una)
- Estación de Soldadura con Soldador - $25.95
- Estaño - $12.30
- Caja termoretráctil - $6.50
- Pelacables - $4.29
- Alicates - $2.50
- Alicates de corte - $3.00
- Mechero - $2.00
- Cinta transparente - $0.50
- Cinta de doble contacto - $7.00
- Cinta eléctrica de vinilo Super 33 - $3.00
- Paquete de zunchos (x2) - $7.00 ($3.50 cada uno)

Total - $226.12

## Conclusión
La exitosa combinación de tecnología y educación interactiva está representada en el desarrollo y puesta en marcha de un robot autónomo. Este robot es capaz de detectar colores y asociarlos a información educativa sobre distintos países, todo ello gracias a sus sensores ultrasónicos que le permiten moverse por sí solo. Además de mostrar una integración efectiva de componentes electrónicos avanzados como el sensor de color TCS3200 y los sensores ultrasónicos HC-SR04 con el microcontrolador Arduino Nano RP2040, este proyecto también proporciona una plataforma atractiva para aprender jugando.

## Bibliografía
[Arduino. (s.f.). Arduino Mega 2560 Rev3.](https://www.arduino.cc/en/Main/ArduinoBoardMega2560)

[Borenstein, J. & Koren, Y. (1991). The vector field histogram—Fast obstacle avoidance for mobile robots. IEEE Transactions on Robotics and Automation, 7(3), 278-288. ](https://doi.org/10.1109/70.88137)

[García, E., Jiménez, M., de Santos, P. G., & Armada, M. (2007). The evolution of robotics research. IEEE Robotics & Automation Magazine, 14(1), 90-103.](https://doi.org/10.1109/MRA.2007.339639)

[Instituto Nacional de Estadística y Censo (INEC). (2023). Estadísticas sobre educación en Panamá.](https://www.inec.gob.pa/)

Kernighan, B. W., & Ritchie, D. M. (1988). The C programming language (2nd ed.). Prentice Hall.

Murray, R. M., Li, Z., & Sastry, S. S. (1994). A mathematical introduction to robotic manipulation. CRC Press.

[NASA. (2021). The impact of AI and automation in space exploration.](https://www.nasa.gov/AI_in_Space)

[OCDE. (2022). Tendencias en educación y tecnología: Integración de la robótica en el aprendizaje.](https://www.oecd.org/)

[Panama Canal Authority. (2022). Engineering and sustainability in the Panama Canal expansion.](https://www.pancanal.com/)

Phu, T., & Dung, L. T. (2019). Color detection and recognition using TCS3200 color sensor and Arduino. International Journal of Engineering and Technology, 8(2), 50-55.

[Rouse, M. (2018). What is PWM (Pulse Width Modulation)? TechTarget.](https://www.techtarget.com)

[UNESCO. (2020). Educación inclusiva y el uso de tecnologías en América Latina.](https://unesdoc.unesco.org)

## Explicación del Código
### Código Pricipal
[Código Principal](src/main/)

Este código está diseñado para manejar un robot que utiliza varios sensores ultrasónicos y un sensor de color TCS3200, controlando el movimiento con el controlador de motores TB6612. A continuación, te explico cada parte del código:

#### Definición de Pines

// Definición de Pines de Sensor de Color (TCS3200)

#define OUT 2

#define S0 3

#define S1 4

#define S2 5

#define S3 6

#define LED 7


Se definen los pines para conectar el sensor de color TCS3200. Estos pines controlan la configuración del sensor para leer los diferentes valores de color y activar su LED:
- OUT es el pin donde se recibe el pulso del sensor, que varía en función del color detectado.
- S0, S1, S2, S3 controlan la frecuencia de salida del sensor y seleccionan qué componente del color (rojo, verde, azul) medir.
- LED enciende la luz LED del sensor.


// Definición de Pines de Sensores US (HC-SR04)

#define ECHO1 22 // Sensor delantero

#define TRIG1 23

#define ECHO2 30 // Sensor Izquierdo

#define TRIG2 31

#define ECHO3 36 // Sensor Derecho

#define TRIG3 37

#define ECHO4 46 // Sensor Trasero

#define TRIG4 47


Aquí se definen los pines para los sensores ultrasónicos (HC-SR04). Cada sensor tiene dos pines principales:
- TRIG: Pin para enviar la señal de disparo.
- ECHO: Pin para recibir el eco, que permite calcular la distancia.


// Definición de Pines del controlador (TB6612)

#define PWMA 53

#define AIN1 54

#define AIN2 55

#define BIN1 57

#define BIN2 58

#define PWMB 59

#define STBY 70


Los pines para controlar el driver de motores TB6612 están definidos. Estos pines permiten controlar la dirección y velocidad de los motores del robot:
- PWMA y PWMB controlan la velocidad de los motores.
- AIN1, AIN2, BIN1, BIN2 controlan la dirección de los motores.
- STBY saca el controlador del modo de espera, permitiendo que los motores funcionen.


#### Variables para el control del tiempo

const unsigned long printInterval = 5000; // Intervalo de 5 segundos

unsigned long previousMillis = 0;


Estas variables se utilizan para controlar el intervalo de tiempo entre lecturas de los sensores. printInterval define un intervalo de 5 segundos, mientras que previousMillis guarda el momento en el que se hizo la última lectura.

#### Función setup()

void setup() {

  Serial.begin(9600); // Iniciar la comunicación Serial
  

Aquí se inicia la comunicación serial a una velocidad de 9600 baudios, lo cual permitirá enviar datos al monitor serial.

##### Configuración del sensor de color

  pinMode(S0, OUTPUT);
  
  pinMode(S1, OUTPUT);
  
  pinMode(S2, OUTPUT);
  
  pinMode(S3, OUTPUT);
  
  pinMode(OUT, INPUT);
  
  pinMode(LED, OUTPUT);
  
  
  digitalWrite(S0, HIGH);
  
  digitalWrite(S1, LOW);
  
  digitalWrite(LED, HIGH);
  

Se configuran los pines del sensor de color como entradas o salidas según sea necesario. S0 y S1 controlan la frecuencia de salida, que en este caso se configura al 100%. El LED del sensor se enciende para iluminar el área que se está detectando.

##### Configuración de los sensores ultrasónicos

  pinMode(TRIG1, OUTPUT);
  
  pinMode(ECHO1, INPUT);
  
  pinMode(TRIG2, OUTPUT);
  
  pinMode(ECHO2, INPUT);
  
  pinMode(TRIG3, OUTPUT);
  
  pinMode(ECHO3, INPUT);
  
  pinMode(TRIG4, OUTPUT);
  
  pinMode(ECHO4, INPUT);
  

Cada sensor ultrasónico tiene un pin TRIG para enviar la señal y un pin ECHO para recibir la señal reflejada. Aquí se configuran los pines para estos sensores.

##### Configuración del controlador TB6612

  pinMode(AIN2, OUTPUT);
  
  pinMode(AIN1, OUTPUT);
  
  pinMode(PWMA, OUTPUT);
  
  pinMode(BIN1, OUTPUT);
  
  pinMode(BIN2, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  
  pinMode(STBY, OUTPUT);
  
  digitalWrite(STBY, HIGH);
  

Se configuran los pines del controlador de motores como salidas y se saca el controlador del modo standby activando el pin STBY.

#### Función loop()

void loop() {

  unsigned long currentMillis = millis();
  
  
  if (currentMillis - previousMillis >= printInterval) {
  
    previousMillis = currentMillis;
    

En el bucle principal (loop()), se revisa si han pasado 5 segundos (printInterval) desde la última vez que se imprimieron los datos. Si es así, se actualiza el temporizador y se realizan nuevas lecturas.

#### Obtener y mostrar datos de sensores

  int distanceFront = measureDistance(TRIG1, ECHO1);
  
  int distanceLeft = measureDistance(TRIG2, ECHO2);
  
  int distanceRight = measureDistance(TRIG3, ECHO3);
  
  int distanceBack = measureDistance(TRIG4, ECHO4);
  
  int redValue, greenValue, blueValue;
  
  readColor(&redValue, &greenValue, &blueValue);
  

Se llaman a las funciones measureDistance y readColor para obtener las distancias de los sensores ultrasónicos y los valores de color del sensor TCS3200, respectivamente.


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


Los resultados de las mediciones de distancia y color se imprimen en el monitor serial, mostrando las distancias y los valores RGB del sensor de color.

#### Función measureDistance()

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


Esta función mide la distancia utilizando un sensor ultrasónico. Se envía un pulso corto desde el pin TRIG, y luego se mide el tiempo que tarda en recibir el eco en el pin ECHO. La distancia se calcula en función de ese tiempo.

#### Función readColor()

void readColor(int* redValue, int* greenValue, int* blueValue) {

  // Leer el valor rojo
  
  digitalWrite(S2, LOW);
  
  digitalWrite(S3, LOW);
  
  delay(100);
  
  *redValue = pulseIn(OUT, LOW);
  

  // Leer el valor verde
  
  digitalWrite(S2, HIGH);
  
  digitalWrite(S3, HIGH);
  
  delay(100);
  
  *greenValue = pulseIn(OUT, LOW);
  

  // Leer el valor azul
  
  digitalWrite(S2, LOW);
  
  digitalWrite(S3, HIGH);
  
  delay(100);
  
  *blueValue = pulseIn(OUT, LOW);
  
}


Esta función lee los valores de color (rojo, verde, azul) del sensor TCS3200. Dependiendo de la configuración de los pines S2 y S3, el sensor detecta uno de los tres colores y envía un pulso cuya duración se mide con pulseIn() para obtener los valores RGB.


### Mobilidad
[Código de Mobilidad](src/partes-del-código/Mobilidad.ino)

Te explico cada parte del código:

#### Definición de pines

#define pinPWMA 54

#define pinAIN2 55

#define pinAIN1 56

#define pinBIN1 58

#define pinBIN2 59

#define pinPWMB 60

#define pinSTBY 61

- **pinPWMA**: Pin de velocidad para el motor A. El controlador TB6612 controla la velocidad con una señal PWM (modulación por ancho de pulso).
- **pinAIN1, pinAIN2**: Pines que controlan la dirección del motor A. Dependiendo de cómo estén, el motor irá hacia adelante o hacia atrás.
- **pinPWMB**: Pin de velocidad para el motor B.
- **pinBIN1, pinBIN2**: Pines que controlan la dirección del motor B, similar a los de A.
- **pinSTBY**: Pin que activa o desactiva los motores (standby).

#### Variables de tiempo y velocidad

const int waitTime = 2000;

const int speed = 0;

- **waitTime**: Tiempo de espera en milisegundos entre cada acción.
- **speed**: Valor inicial de velocidad (aquí es 0, pero se puede cambiar en el loop).

#### Matrices de pines de los motores

const int pinMotorA[3] = { pinPWMA, pinAIN2, pinAIN1 };

const int pinMotorB[3] = { pinPWMB, pinBIN1, pinBIN2 };

- Estas matrices agrupan los pines de cada motor para que sea más fácil pasar los pines como argumento a las funciones que los controlan.

#### Enumeraciones para el movimiento

enum moveDirection {

  forward,  
  
  backward   
  
};

enum turnDirection {

  clockwise,     
  
  counterClockwise   
  
};


- **moveDirection**: Define las direcciones de movimiento: forward (hacia adelante) y backward (hacia atrás).
- **turnDirection**: Define los giros: clockwise (horario) y counterClockwise (antihorario).

#### Configuración inicial

void setup() {

  pinMode(pinAIN2, OUTPUT);
  
  pinMode(pinAIN1, OUTPUT);
  
  pinMode(pinPWMA, OUTPUT);
  
  pinMode(pinBIN1, OUTPUT);
  
  pinMode(pinBIN2, OUTPUT);
  
  pinMode(pinPWMB, OUTPUT);
  
}


- Se configuran todos los pines asociados a los motores como salidas.

#### Bucle principal (loop)

void loop() {

  enableMotors();  
  
  move(forward, 250);  
  
  delay(waitTime);    
  

  move(backward, 250);     
  
  delay(waitTime);       
  

  turn(clockwise, 250);    
  
  delay(waitTime); 
  

  turn(counterClockwise, 250); 
  
  delay(waitTime);        
  

  fullStop();            
  
  delay(waitTime);         
  
}


- **enableMotors()**: Activa los motores.
- **move(forward, 250)**: Mueve el robot hacia adelante con una velocidad de 250 (en una escala PWM).
- **move(backward, 250)**: Mueve el robot hacia atrás.
- **turn(clockwise, 250)**: Gira el robot en sentido horario.
- **turn(counterClockwise, 250)**: Gira en sentido antihorario.
- **fullStop()**: Detiene todos los motores.

#### Función para mover el vehículo hacia adelante o atrás

void move(int direction, int speed) {

  if (direction == forward) {
  
    moveMotorForward(pinMotorA, speed);
    
    moveMotorForward(pinMotorB, speed);
    
  } else {
  
    moveMotorBackward(pinMotorA, speed);
    
    moveMotorBackward(pinMotorB, speed);
    
  }
  
}


- Según la dirección (hacia adelante o atrás), se llaman las funciones correspondientes para mover ambos motores.

#### Función para girar

void turn(int direction, int speed) {

  if (direction == clockwise) {
  
    moveMotorForward(pinMotorA, speed);
    
    moveMotorBackward(pinMotorB, speed);
    
  } else {
  
    moveMotorBackward(pinMotorA, speed);
    
    moveMotorForward(pinMotorB, speed);
    
  }
  
}


- Para girar, un motor se mueve hacia adelante y el otro hacia atrás, dependiendo de la dirección del giro.

#### Función para detener el vehículo

void fullStop() {

  disableMotors();
  
  stopMotor(pinMotorA);
  
  stopMotor(pinMotorB);
  
}


- Llama a **disableMotors()** para desactivar los motores y a **stopMotor()** para detener cada motor.

#### Funciones para mover los motores

void moveMotorForward(const int pinMotor[3], int speed) {

  digitalWrite(pinMotor[1], HIGH);  
  
  digitalWrite(pinMotor[2], LOW);   
  
  analogWrite(pinMotor[0], speed);  
  
}


void moveMotorBackward(const int pinMotor[3], int speed) {

  digitalWrite(pinMotor[1], LOW);   
  
  digitalWrite(pinMotor[2], HIGH);  
  
  analogWrite(pinMotor[0], speed);  
  
}


- Estas funciones controlan el motor individualmente, estableciendo los pines de dirección y la velocidad según se necesite.

#### Función para detener un motor

void stopMotor(const int pinMotor[3]) {

  digitalWrite(pinMotor[1], LOW);   
  
  digitalWrite(pinMotor[2], LOW);   
  
  analogWrite(pinMotor[0], 0);    
  
}


- Detiene completamente un motor poniendo la velocidad en 0 y apagando los pines de dirección.

#### Activar y desactivar motores

void enableMotors() {

  digitalWrite(pinSTBY, HIGH);    
  
}

void disableMotors() {

  digitalWrite(pinSTBY, LOW);      
  
}


- **enableMotors()**: Activa los motores al desactivar el modo standby.
- **disableMotors()**: Desactiva los motores activando el modo standby.

Este código proporciona un control completo sobre los motores, con funciones que permiten mover el robot hacia adelante y atrás, girar y detenerse.


#### Descripción del Código

Este código controla dos motores utilizando un controlador de motores dual (como el TB6612), asignando pines del Arduino para gestionar la velocidad y la dirección de cada motor. A continuación, se detalla cómo está estructurado:

1. Definición de Pines
Se definen los pines para controlar la velocidad (PWM) y la dirección (AIN1, AIN2, BIN1, BIN2) de los motores A y B. Además, se asigna un pin para controlar el estado de los motores (standby).
2. Variables y Matrices
waitTime establece el tiempo de espera entre cada fase de movimiento.
speed define la velocidad inicial de los motores, la cual puede ser modificada en el código.
Las matrices pinMotorA y pinMotorB agrupan los pines de cada motor, facilitando su control en las funciones.
3. Enumeraciones para Movimiento y Giro
Se utilizan enumeraciones (enum) para definir las posibles direcciones de movimiento (adelante, atrás) y de giro (horario, antihorario), haciendo el código más legible y fácil de entender.
4. Función setup()
Aquí se configuran los pines de salida para controlar los motores. Los pines de dirección y velocidad se preparan para enviar señales a los motores.
5. Función loop()
Esta función es el bucle principal del programa, donde se ejecutan las siguientes acciones:
Activar los motores mediante la función enableMotors().
Mover hacia adelante a velocidad 15.
Mover hacia atrás a velocidad 15.
Girar en sentido horario a velocidad 15.
Girar en sentido antihorario a velocidad 15.
Detener los motores mediante la función fullStop().
Cada acción está separada por un retraso (delay(waitTime)) para observar el comportamiento de los motores antes de pasar a la siguiente acción.
6. Funciones de Control de Movimiento
move(direction, speed): Mueve los motores hacia adelante o atrás dependiendo de la dirección indicada.
turn(direction, speed): Gira el vehículo en el sentido indicado (horario o antihorario), moviendo un motor hacia adelante y el otro hacia atrás.
7. Funciones Auxiliares
moveMotorForward(pinMotor, speed): Controla un motor para que gire hacia adelante, estableciendo la dirección y la velocidad mediante PWM.
moveMotorBackward(pinMotor, speed): Controla un motor para que gire hacia atrás.
stopMotor(pinMotor): Detiene el motor bajando la velocidad a 0 y estableciendo ambos pines de dirección en LOW.
enableMotors() y disableMotors(): Activan o desactivan los motores controlando el pin de standby (pinSTBY).

#### Resumen

Este código ofrece un control básico pero flexible para un sistema con dos motores, permitiendo mover el vehículo hacia adelante, atrás y realizar giros. Las funciones están organizadas de manera que es fácil modificar la velocidad, dirección y comportamiento general del sistema, lo que lo hace ideal para robots móviles básicos o proyectos de control de motores en Arduino.

## Componentes Electromecánicos

[A continuación se muestran los componentes electromecánicos que se utilizaron](componentes-electromecánico/)

## Gestión de Energía

