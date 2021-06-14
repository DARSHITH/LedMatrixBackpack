#include "LedControl.h"
LedControl matrixControl=LedControl(13,11,12,1);
int a[5],k=0;
unsigned long delayTime=200;
byte mheart[] =
{
B01110000,
B11111000,
B11111100,
B01111110,
B11111100,
B11111000,
B01110000,
B00000000
};

byte mpeace[] =
{
B00111000,
B01000100,
B10001010,
B11110010,
B10001010,
B01000100,
B00111000,
B00000000
};

byte msmile[] =
{
B00001000,
B00000100,
B01100010,
B00000010,
B00000010,
B01100010,
B00000100,
B00001000
};

byte msq1[] =
{
B11111111,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B11111111
};

byte msq2[] =
{
B00000000,
B01111110,
B01000010,
B01000010,
B01000010,
B01000010,
B01111110,
B00000000
};

byte msq3[] =
{
B00000000,
B00000000,
B00111100,
B00100100,
B00100100,
B00111100,
B00000000,
B00000000
};

byte msq4[] =
{
B00000000,
B00000000,
B00000000,
B00011000,
B00011000,
B00000000,
B00000000,
B00000000
};

void listener(){      
for (k=0;k<4;k++){  
a[k]=a[k+1];
}
a[4]=analogRead(A0)/75;
delay(100);
}

int checking(){      
int accflag=0;
for(k=0;k<4;k++){
if(a[k]!=a[k+1]){
accflag=1;
break;
}
}
return(accflag);
}

void sq1() 
{
for (int i = 0; i < 8; i++)  
{
matrixControl.setColumn(0,i,msq1[i]);
}
}

void sq2()   
{
for (int i = 0; i < 8; i++)
{
matrixControl.setColumn(0,i,msq2[i]);
}
}

void sq3()   
{
for (int i = 0; i < 8; i++)
{
matrixControl.setColumn(0,i,msq3[i]);
}
}
void sq4()  
{
for (int i = 0; i < 8; i++)
{
matrixControl.setColumn(0,i,msq4[i]);
}
}

void heart()   
{
for (int i = 0; i < 8; i++)  
{
matrixControl.setColumn(0,i,mheart[i]);
}
}
void peace()  
{
for (int i = 0; i < 8; i++)  
{
matrixControl.setColumn(0,i,mpeace[i]);
}
}
void smile()   
{
for (int i = 0; i < 8; i++)  
{
matrixControl.setColumn(0,i,msmile[i]);
}
}

void setup(){
matrixControl.setIntensity(0,5);    
matrixControl.clearDisplay(0);      
}

void mdisplay(){   
sq1();
delay(delayTime);
sq2();
delay(delayTime);
sq3();
delay(delayTime);
sq4();
delay(delayTime);
sq3();
delay(delayTime);
sq2();
delay(delayTime);
sq1();
delay(delayTime);
heart();
delay(2000);
smile();
delay(2000);
peace();
delay(2000);
sq1();
delay(delayTime);
sq2();
delay(delayTime);
sq3();
delay(delayTime);
sq4();
delay(delayTime);
sq3();
delay(delayTime);
sq2();
delay(delayTime);
sq1();
delay(delayTime);
}

void loop(){
int test;
listener();
test=checking();
if (test==1){
matrixControl.shutdown(0,false); //Truns matrix on
mdisplay();
}
else{
matrixControl.shutdown(0,true);  // Turns matrix off 
}
}
