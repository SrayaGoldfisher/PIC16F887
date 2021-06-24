int flag = 0;
int x = 0;
int rise_time = 0;
int fall_time = 0;
int total_time = 0;

void interrupt () {
     if(CCP1IF_bit) {
                    INTCON = 0;
                    if(!flag){
                              rise_time = CCPR1H*256 + CCPR1L + x*65536;
                              flag = 1;
                              CCP1CON = 0b00000100;
                    }
                    else {
                         fall_time = CCPR1H*256 + CCPR1L + x*65536;
                         flag = 0;
                         CCP1CON = 0b00000101;
                    }
                    CCP1IF_bit = 0;
                    INTCON = 0b11000000;
     }
     if(TMR1IF_bit) {
                    INTCON = 0;
                    x++;
                    TMR1IF_bit = 0;
                    INTCON = 0b11100000;
     }
     TMR1IF_bit = 0;
}

void main() {
     ANSEL = ANSELH = 0;
     TRISD = TRISB = 0;
     TRISC = 0xFF;
     PORTD = PORTB = 0;
     INTCON = 0b11100000;
     PIE1 = 0b0000101;
     CCP1CON = 0b00000101;
     T1CON = 0b00110001;
     while(1) {
              while(RC2_bit); {
                              x = 1;
              }
              if(x) {
                    if (fall_time > rise_time) {
                       total_time = fall_time - rise_time;
                    }
                    else {
                         total_time = 65536 + fall_time - rise_time;
                    }
                    PORTB = total_time;
                    PORTD = total_time >> 8;
                    x = 0;
              }
     }
}