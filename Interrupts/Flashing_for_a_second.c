//A program that causes PORTD to flash in one second
//PORTD will be held for a second on "1" and then held for a second on "0" in an infinite loop
//Using the interrupt of timer 0


unsigned cnt;
void interrupt() {
     if (INTCON.TMR0IF) {
        cnt++;
        TMR0 = 96;
     }
     INTCON.TMR0IF = 0;
}

void main() {
     cnt = 0;
     ANSEL  =  ANSELH =  0;
     TRISD = 0;
     TRISA = 0xFF;
     PORTD = 0;
     INTCON = 0b10100000;
     OPTION_REG = 0b00000100;
     TMR0 = 96;
     TMR0IE_bit = 1;
     while(1) {
              if (cnt >= 400){
                 PORTD =~ PORTD;
                 cnt = 0;
              }
     }
}
