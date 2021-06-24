//A program that creates transmission and reception, at a low bit rate of 1200kbps, using the UART communication protocol of the controller
//The program counts binary in an infinite loop in PORTB
//The number 1 will be broadcast, then the number 2, 3, etc. until 255 and again ...
//The broadcast house will be entered into PORTB
//The transmission and reception will be performed in one controller, ie we will connect between the transmission pin Tx, and the reception pin Rx


void main() {
     int i;
     PORTB = 0;
     TRISB = 0;
     TRISC.F6 = 0;
     TRISC.F7 = 1;
     ANSEL = ANSELH = 0;
     SPBRG = 51;
     TXSTA = 0b00100010;
     RCSTA = 0b10010000;
     TXREG = 0;
     do {
        TXREG++;
        while (!TRMT_bit);
              while (!RCIF_bit);
                    PORTB = RCREG;
        if(TXREG == 255)
                 TXREG = 0;
        for (i = 0;  i < 30000;  i++);
     }
     while(1);
}
