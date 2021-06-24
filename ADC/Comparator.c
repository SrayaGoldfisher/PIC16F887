//A program that compares using the controller comparator 
//between a potentiometer voltage and a constant external voltage of 2.5V supplied to the controller
//If the voltage from the potentiometer is greater, a green LED will light up
//If the voltage obtained from the constant voltage source is greater, a red LED will light up


void main() {
     PORTA = 0;
     TRISA = 0xF7;
     ANSEL = 0x0A;
     ANSELH = 0;
     while(1) {
              CM1CON0 = 0b10100001;
     }
}
