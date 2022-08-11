# Dispositivo Automático para el Monitoreo de Altas Temperaturas *In situ* para Incendios Forestales
Sistema de medición de la evolución de la temperatura a nivel de suelo de un sistema expuesto a un incendio forestal.

## Introducción 

Se creó un sistema el cual permite medir tanto los niveles como la evolución de la temperatura en todos los sistemas que se encuentran sujetos al riesgo de un incendio forestal. Este sistema cuenta con un sensor de temperatura conocido como **termocupla** y es enterrado cerca del incendio para que así no sufra daños a causa de las altas temperaturas una vez que el evento se propague. Dicho sensor queda expuesto en la superficie para así capturar los datos una vez que el incendio pase sobre este.

## Componentes del sistema
- Arduino Uno o Nano: Es el procesador del sistema que se encarga de la
interconexión de todos los componentes del sistema y también de recibir los
datos, interpretarlos y enviarlos al dispositivo de memoria.

- Sensor de Temperatura: El sensor de temperatura es una Termocupla tipo K
que tolera valores de hasta 600ºC. También se cuenta con un módulo
MAX6675 el cual se encarga de convertir los valores tomados por el sensor
en una señal que el Arduino pueda interpretar.

- Reloj de Tiempo Real: Se tiene un DS3231 el cual es un Real Time Clock de
alta precisión que se encarga de registrar la fecha y hora en la que es tomado
cada dato. Este es alimentado con una batería tipo moneda de 3 Voltios.
- Memoria: Para el almacenamiento de los datos se cuenta con un módulo
para tarjetas MicroSD de la marca SparkFun. En este se crea un archivo de
texto en el cual se encuentran todos los datos registrados por el sistema.

- Alimentación: Para hacer al sistema funcionar de forma completamente
independiente, se implementó una fuente de alimentación usando una batería
de 9 Voltios. Esto es ya que dichas baterías son muy fáciles de encontrar
alrededor del país sin importar que tan remota sea la zona en la que se
implemente el sistema.

- Encapsulado: El sistema es guardado en un tubo de Policloruro de Vinilo
(PVC) para que de esta forma no sufra daños a causa de la tierra, la
humedad de esta y las altas temperatura a las que va a ser expuesto al estar
enterrado.

## Diagrama eléctrico
El sistema se implementó en un Arduino UNO y un Arduino Nano para verificar que el sistema funciona en diferentes plataformas y placas de desarrollo. Se implementaron dos LEDs que se encargan de indicar cuando el sistema
se encuentra encendido y cada vez que un dato esté siendo tomado.

![UNO_Version](https://user-images.githubusercontent.com/111079577/184231145-031e9310-0b66-41cb-a7e3-146600c62283.png) ![NANO_Version]()

