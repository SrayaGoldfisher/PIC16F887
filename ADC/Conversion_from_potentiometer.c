//A program that receives data from a potentiometer converts it and displays it on PORTC


void main() {
     ANSEL = 0x04;
     ANSELH = 0;
     TRISA = 0xFF;
     TRISC = 0;
     ADCON0 = 0xC8;
     ADCON0.ADON = 1;
     ADCON1.ADFM = 0;
     while(1) {
              GO_DONE_bit = 1;
              while(GO_DONE_bit) {
                                 PORTC = ADRESH;
              }
     }
}