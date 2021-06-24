//A program that performs an analog reading from a potentiometer in AN1
//Converts it to digital and displays the digital value in PORTB (without LSB)
//The digital value displayed in PORTB will not change unless there is a change of more than ~0.5V in the input voltage
//Using the ADC module interrupt


void interrupt() {
     if(ADIF_bit) {
        if(abs(PORTB - ADRESH) > 8) {
                  PORTB = ADRESH;
        }
     }
     ADIF_bit = 0;
}

void main() {
     ANSEL = 0x02;
     ANSELH = 0;
     TRISA = 0xFF;
     PORTA = 0;
     TRISB = 0;
     PORTB = 0;
     INTCON = 0b11000000;
     GIE_bit = 1;
     PEIE_bit = 1;
     ADIE_bit = 1;
     ADIF_bit = 0;
     ADCON0 = 0b00000111;
     ADCON1 = 0b00110000;
     Delay_ms(100);
     while(1) {
              ADCON0.F1 = 1;
     }
}