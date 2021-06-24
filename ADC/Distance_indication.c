//A program that receives information from a sensor and gives an indication of the distance on LEDs
//The system will display the information on 3 scales:
//10-20 LED at RB0
//20-30 LED in RB1
//Above 30 LED in RB2


unsigned int i;
void main() {
     PORTA = PORTB = 0;
     TRISA = 0xFF;
     TRISB = 0xF8;
     ANSEL = 0x0D;
     ANSELH = 0;
     ADCON0 = 0b11000100;
     ADCON1 = 0b00110000;
     while(1) {
              GO_DONE_bit = 1;
              for(i = 0; i < 10000; i++);
              while(GO_DONE_bit) {
                                 if(ADRESH > 130) {
                                           PORTB = 0;
                                           RB0_bit = 1;
                                 }
                                 if (ADRESH < 130 && ADRESH > 72) {
                                    PORTB = 0;
                                    RB1_bit = 1;
                                 }
                                 if (ADRESH < 72) {
                                    PORTB = 0;
                                    RB2_bit = 1;
                                 }
              }
     }
}
