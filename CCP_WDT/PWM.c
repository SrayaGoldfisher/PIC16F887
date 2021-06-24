void main(){
     TRISB = 0xFE;
     TRISC = 0xFB;
     PORTB = PORTC = 0;
     PR2 = 249;
     CCP1CON = 0b00001100;
     CCPR1L = 0b01001011;
     TMR2IF_bit = 0;
     T2CON = 0b00000100;
     ANSEL = ANSELH = 0;
     GIE_bit = 1;
     ADCON0 = 0B11000001;
     ADCON1 = 0;
     while(1) {
              Delay_ms(500);
              GO_DONE_bit = 1;
              while(GO_DONE_bit);
              CCPR1L = ADRESH;
     }
}
