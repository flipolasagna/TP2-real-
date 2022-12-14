#include <Arduino.h>

#define boton1 ((PIND>>4)&0X01)
#define boton2 ((PIND>>5)&0X01)
#define boton3 ((PIND>>6)&0X01)
#define boton4 ((PIND>>7)&0X01)

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

int main() // se asignan las entradas y salidas (  DDRD &= Entradas----DDRD |= Salidas )
{
    DDRD &= ~(1 << PD4);
    DDRD &= ~(1 << PD5);
    DDRD &= ~(1 << PD6);
    DDRD &= ~(1 << PD7);

    DDRD |= (1 << PD2);
    DDRD |= (1 << PD3);
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);
    DDRB |= (1 << PB4);

    int var;
    int flag_boton1;
    void secuencia_de_leds(char num)

    while (1) // hace que el codigo se repita como un ciclo
    {
        if(boton1==0){
            flag_boton1=1;
        }

        if (flag_boton1==1)
        {
            
        }
        
    }
}

void secuencia_de_leds(char num){
    led1off;
    led2off;
    led3off;
    led4off;
    led5off;
    led6off;
    led7off;

    switch (num)
    {
        case 1 :
            led1on;
        break;
        
        case 2:
        case 3
        case 4
        case 5
        case 6
  
    }
}