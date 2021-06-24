//A program that at the push of a button in RC0 receives analog data from a potentiometer in AN1
//Converts it to digital and displays the digital value in PORTB
//At the push of a button in RC1 receives analog data from an LDR sensor in AN2
//Converts it to digital and displays the digital signal in PORTD
//The system works using the model's internal RC clock


void main() {
     PORTA = PORTB = PORTC = PORTD = 0;
     TRISA = 0x60;
     TRISC = 0xFF;
     TRISB = 0;
     TRISD = 0;
     ANSEL = 0x60;
     ANSELH = 0;
     ADCON1.ADFM = 0;
     while(1) {
              while(RC0_bit) {
                             ADCON0 = 0b11000101;
                             GO_DONE_bit = 1;
                             while(GO_DONE_bit) {
                                                PORTB = ADRESH;
                             }
              }
              while(RC1_bit) {
                             ADCON0 = 0b11001001;
                             GO_DONE_bit = 1;
                             while(GO_DONE_bit) {
                                                PORTD = ADRESH;
                             }
              }
     }
}
