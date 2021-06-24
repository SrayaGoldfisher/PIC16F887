int flag = 0;
int x = 0;
int rise_time = 0;
int fall_time = 0;
int total_time = 0;

void interrupt () {
     if(CCP1IF_bit) {
                    INTCON = 0;
                    if(!flag) {
                              rise_time = CCPR1H << 8;
                              rise_time = rise_time + CCPR1L;
                              flag = 1;
                              CCP1CON = 0b00000100;
                    }
                    else {
                         fall_time = CCPR1H << 8;
                         fall_time = fall_time + CCPR1L;
                         flag = 0;
                         CCP1CON = 0b00000101;
                    }
                    CCP1IF_bit = 0;
                    INTCON = 0b11000000;
     }
}

void main() {
     ANSEL = ANSELH = 0;
     TRISD = TRISB = 0;
     TRISC = 0xFF;
     PORTD = PORTB = 0;
     C1ON_bit = 0;
     C2ON_bit = 0;
     TMR1IE_bit = 0;
     TMR1L = 0;
     TMR1H = 0;
     GIE_bit = 1;
     PEIE_bit = 1;
     CCP1IE_bit = 1;
     T1CON = 0b00110001;
     CCP1CON = 0b00000101;
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