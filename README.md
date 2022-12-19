# ˗ˏˋTrabajo Practico N°2´ˎ˗
## ⿻Consignas:
###### 1. Al presionar el pulsador 1se encienden los LEDs barajando las posibles respuestas rápidamente.

###### 2. Al presionar el pulsador 2se detiene el cambio de los LEDs, quedando encendidos aquellos que indican la "cara del dado que quedo hacia arriba".

###### 3. Una vez que se indica el resultado, se debe poder presionar el pulsador 3 o 4para apagar los LEDsde manera de volver a la condición inicial.

## ⿻Se forma por:
###### • Arduino nano.

###### • 7 leds.

###### • 4 pulsadores.

###### •7 resistencias de 100Ω

# ˗ˏˋInforme´ˎ˗
 
 ## ⿻Diagrama de flujo 
 
 
![Diagrama de flujo](https://user-images.githubusercontent.com/111539493/206243593-f2c489be-cb49-4776-b72d-d419bf197402.png)

##  ⿻Codigo 
#### » lo primero a realizar fue declara las macros.

###### ↳ Esta parte correspone a los botones.
```c
#define boton1 ((PIND >> 4) & 0X01)
#define boton2 ((PIND >> 5) & 0X01)
#define boton3 ((PIND >> 6) & 0X01)
#define boton4 ((PIND >> 7) & 0X01)
```

###### ↳ Esta parte correspone a los leds
```c
#define led1on (PORTD |= (1 << PD2))
#define led1off (PORTD &= ~(1 << PD2))
#define led2on (PORTD |= (1 << PD3))
#define led2off (PORTD &= ~(1 << PD3))
#define led3on (PORTB |= (1 << PB0))
#define led3off (PORTB &= ~(1 << PB0))
#define led4on (PORTB |= (1 << PB1))
#define led4off (PORTB &= ~(1 << PB1))
#define led5on (PORTB |= (1 << PB2))
#define led5off (PORTB &= ~(1 << PB2))
#define led6on (PORTB |= (1 << PB3))
#define led6off (PORTB &= ~(1 << PB3))
#define led7on (PORTB |= (1 << PB4))
#define led7off (PORTB &= ~(1 << PB4))
```
#### » Continuamos seteando los puertos 

###### ↳Esta parte correspone a los botones▸ entradas.
```c
  DDRD &= ~(1 << PD4);
  DDRD &= ~(1 << PD5);
  DDRD &= ~(1 << PD6);
  DDRD &= ~(1 << PD7);
```

###### ↳Esta parte correspone a los leds▸ salidas.
```c
  DDRD |= (1 << PD2);
  DDRD |= (1 << PD3);
  DDRB |= (1 << PB0);
  DDRB |= (1 << PB1);
  DDRB |= (1 << PB2);
  DDRB |= (1 << PB3);
  DDRB |= (1 << PB4);
```
#### » Asignamos las variables y funciones que se usaran.
```c
  int var;
  int flag_boton1;
  void secuencia_de_leds(char num);
```
###### ↳ Esto es lo que esta dentro del void.
```c
void secuencia_de_leds(char num)
{
  led1off;
  led2off;
  led3off;
  led4off;
  led5off;
  led6off;
  led7off;

  switch (num)
  {
   case 1:
    led7on;
    break;

   case 2:
    led1on;
    led6on;
    break;

   case 3:
    led1on;
    led7on;
    led6on;
    break;

   case 4:
    led1on;
    led3on;
    led4on;
    led6on;
    break;

   case 5:
    led1on;
    led3on;
    led7on;
    led4on;
    led6on;
    break;

   case 6:
   led1on;
   led2on;
   led3on;
   led4on;
   led5on;
   led6on;
```
#### » Continuaremos abriendo un while. Dentro de este se preguntara por el boton1 si se esta aprentando y si esto sucede se activara el flag_boton1.

```c
while (1) 
  {
    if (boton1 == 0)
    {
      flag_boton1 = 1;
    }
```
#### » Luego se abrira otro if el cual pregunta por la flag, si esta en 1 la variable se va a ir aumentando hasta el 7, si llega al 7 volvera al estado del 0.Tambien se dara la secuncia_de_leds.

```c
if (flag_boton1 == 1)
    {
      var++;
      if (var > 7)
      {
        var = 0;
      }
      secuencia_de_leds(var);
    }
```

#### » Para que se realice la consigna del boton2 (pausar en el juego de leds que justo paró) se abrira un if preguntando por el boton2 y si sucede se desactivara el flag_boton1.
```c
if (boton2 == 0)
    {
      flag_boton1=0;
    }
```
#### » Ahora haremos que el boton3 o el boton4 apaaguen todos los leds.
```c
if (boton3==0 || boton4==0)
    {
      led1off;
      led2off;
      led3off;
      led4off;
      led5off;
      led6off;
      led7off;
    }
```
