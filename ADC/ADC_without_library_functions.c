void main() {
     ANSEL = 0x04;
     TRISA = 0xFF;
     ANSELH = 0;
     TRISC = 0x3F;
     TRISB = 0;
     ADCON0 = 0x08;
     ADCON0.ADON = 1;
     ADCON1.ADFM = 1;
     do {
        GO_DONE_bit = 1;
        while(GO_DONE_bit) {
                          PORTB = ADRESL;
                          PORTC = ADRESH << 6;
        }
     } while(1);
}