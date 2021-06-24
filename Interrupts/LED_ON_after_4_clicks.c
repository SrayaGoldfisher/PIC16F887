//By using the TMR0 counter - a program that receives input from a push-button, after the fourth press it will turn on LED in RB0
//Using the TMR0 interrupts


void interrupt() {
     if(INTCON.TMR0IF) {
                       RB0_bit = 1;
     }
     INTCON.TMR0IF = 0;
}

void main() {
     ANSEL = ANSELH = 0;
     TRISB = 0xFE;
     TRISA = 0xFF;
     PORTA = PORTB = 0;
     INTCON = 0b10100000;
     OPTION_REG = 0b10101000;
     TMR0 = 252;
     TMR0IE_bit = 1;
     while(1);
}
