#include <16f887.h> 
#device *=16 ADC=8 // Khai bao during con tro 16-bt 
#FUSES NOWDT, HS, NOPUT, NOBROWNOUT,NOPROTECT, NOLVP 
#use delay(clock=8000000) // Khai bao su ðung Thach Anh 8 - Mhz

int i,m;
int n;
const char led7[] = {0x3f,0x3f, 0x06, 0x5b, 0x4f,0x66,0x6d, 0x7d, 0x07,0x7f,0x6f};
void main()
{
set_tris_a(0x00);
set_tris_b(0x00); 
set_tris_c(0x00);
set_tris_d(0x00); 

output_a(0x08); 



while(TRUE)
{
output_low(pin_d0);
output_low(pin_d1);
output_low(pin_d2);


output_b(~led7[3]);

for(i=6;i >=1;i--){
output_c(~led7[i]);
delay_ms(500);

output_high(pin_d0);
output_low(pin_d1);
output_low(pin_d2);
}


for(m=2;m>=1;m--){ 
output_b(~led7[m]);

for(n=10;n >=1;n--){
output_c(~led7[n]);
delay_ms(500);

output_high(pin_d0);
output_low(pin_d1);
output_low(pin_d2);
}
}



for(m=1;m>=1;m--){ 
output_b(~led7[m]);

for(i=4;i >= 1;i--)
{
output_low(pin_d0);
output_high(pin_d1);
output_low(pin_d2);
output_c(~led7[i]);
delay_ms(500);


}
}

for(m=5;m>=1;m--){ 
output_b(~led7[m]);

for(i=10;i >= 1;i--)
{
output_c(~led7[i]);
delay_ms(500);

output_low(pin_d0);
output_low(pin_d1);
output_high(pin_d2);
}
}



}
}
