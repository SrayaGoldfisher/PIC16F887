//A program that reverses the logical state of RC2 when you press the push-button connected to RB2
//The program is executed using the interrupts of PORTB


void interrupt() {
     if (INTCON.RBIF) {
        RC2_bit =~ RC2_bit;
     }
     RB2_bit=0;
     INTCON.RBIF=0;
}

void main() {
     ANSEL  =  ANSELH =  0;
     TRISC = 0;
     PORTC = 0;
     TRISB = 0xFF;
     PORTB = 0;
     INTCON = 0b11001000;
     GIE_bit = 1;
     RBIE_bit = 1;
     IOCB = 0x01;
     IOCB2_bit = 1;
     Delay_ms(100);
     while(1);
}
