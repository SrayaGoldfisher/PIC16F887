//A program that receives analog voltage from a potentiometer at AN1 and converts it to digital
//If the digital voltage is greater than VDD/2, a LED will turn on at RB0
//If the voltage is lower than VDD/2 a LED will turn on in RB1


void main() {
     PORTA = PORTB = 0;
     TRISA = 0xFF;
     TRISB = 0;
     ANSEL = 0x02;
     ANSELH = 0;
     ADCON1.ADFM = 0;
     while(1) {
              while(RC0_bit) {
                             ADCON0 = 0b11000101;
                             GO_DONE_bit = 1;
                             while(GO_DONE_bit) {
                                                if(ADRESH > 127) {
                                                               RB0_bit = 1;
                                                               RB1_bit = 0;
                                                }
                                                else {
                                                     RB0_bit = 0;
                                                     RB1_bit = 1;
                                                }
                             }
              }
     }
}