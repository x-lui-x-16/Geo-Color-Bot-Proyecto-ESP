# Geo-Color-Bot-Proyecto
Proyecto: "Geo-Color Bot"

[Version en Inglés](https://github.com/x-lui-x-16/Geo-Color-Bot-Project-ENG)

## Materiales de Ingienería
Todos los materiales que utilizamos para este proyecto. 
- 1 Arduino Mega R3 2560 (https://docs.arduino.cc/hardware/mega-2560/)
- 1 TB6612 Puente-H (HW-166)
- 1 Módulo de Bluetooth (HC-05)
- 4 Sensores ultrasónicos (HC-SR04) (1 adelante, 1 atrás, los otros dos a la derecha y a la izquierda)
- 1 Sensor de Color (TCS3200) (En la parte inferior del vehículo)
- 1 Case de 2 Baterías 18650
- 2 Baterías 18650 (cerca de 7.4 v)
- 1 Chasis 2wd - Esto incluye:
    - 1 Base de Acrílico
    - 2 Motores Amarillos
    - 2 Ruedas
    - 1 Rueda Loca
- ... Protocables
- Múltiples piezas 3D utilizadas se pueden encontrar en el siguiente directorio.
[Archivos 3D](archivos3d/)

## Instrucciones de Construcción
- Chasis 2wd: https://iesjuanlopezmorillas.es/index.php/departamentos/area-cientifico-tecnologica/tecnologia/blog/102-montaje-chasis-coche-2wd
- Electrónica (Circuito y Batería): [El diagrama del circuito se encuentra en la carpeta de esquemas](esquemas/)
- Código (Para el Arduino): [El código se encuentra en la carpeta de src](src/)

## Contenido
[Archivos 3d](archivos3d/) En esta carpeta se muestran todos los archivos 3d utilizados.

[Componentes Electromecánicos](componentes-electromecánicos/) En esta carpeta se encuentran todos los componentes electromecánicos utilizados.

[Esquemas](esquemas/) En esta carpeta se muestran todos los esquemas del proyecto. 

[Código](src/) En esta carpeta se encuentra el código utilizados.

[Imágenes del vehículo](v-photos/) En esta carpeta se encuentran imágenes del vehiculo desde diferentes ángulos.

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
A continuación se detalla el presupuesto estimado para el desarrollo del proyecto Geo-Color Bot:

- Arduino Mega 2560 - $57.31
- Sensor de Color TCS3200 - $9.49
- Sensor Ultrasónico HC-SR04 (x4) - $22.00 ($5.50 c/u)
- Puente H TB6612 - $3.50
- Protoboard - $3.00
- Kit de Arduino 2WD - $10.00
    - Incluye:
    - Base de Acrílico
    - Motor Amarillo
    - Rueda
    - Rueda Loca
- Base de Impresión 3D para Sensores Ultrasónicos (x2) - Donación
- Case de 2 Baterías 18650 - $3.00
- Baterías 18650 de 3.7V (x2) - $7.00 ($3.50 c/u)
- Pack de 10 Cables Dupont Macho-Macho (x3) - $4.50 ($1.50 c/u)
- Pack de 10 Cables Dupont Macho-Hembra (x2) - $3.00 ($1.50 c/u)
- Estación de Soldadura con Cautín - $25.95
- Estaño - $12.30
- Caja de Termoretráctiles - $6.50
- Pinza Pelacables - $4.29
- Alicate - $2.50
- Alicate de Corte - $3.00
- Mechero - $2.00
- Tape Transparente - $0.50
- Tape Doble Contacto - $7.00
- Cinta Eléctrica de Vinilo Super 33 - $3.00
- Paquete de Zunchos (x2) - $7.00 ($3.50 c/u)

Total - $196.94

## Conclusión
Este proyecto ha logrado desarrollar una herramienta educativa innovadora, enfocada en mejorar el aprendizaje para personas con TDAH y daltonismo. Gracias a la integración del sensor de color TCS3200 y los sensores ultrasónicos HC-SR04, el robot es capaz de detectar colores con gran precisión y navegar de forma segura, proporcionando una experiencia educativa interactiva y accesible.

El diseño garantiza fiabilidad y estabilidad durante el uso prolongado, lo que permite su aplicación en entornos educativos sin interrupciones. Además, su capacidad de adaptación y mejora continua asegura que este proyecto se mantenga relevante y efectivo a largo plazo.

En resumen, el Geo-Color Bot representa un avance significativo hacia la educación inclusiva, proporcionando un aprendizaje más dinámico y personalizado para los usuarios que enfrentan desafíos en la percepción del color y la atención.

## Explicación del Código

### Mobilidad
[Código de Mobilidad](src/partes-del-código/Mobilidad.ino)

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

