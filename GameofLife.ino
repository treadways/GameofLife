
#include "LedControl.h" 
LedControl lc=LedControl(12,11,10,1);

void setup() {
lc.shutdown(0,false);
lc.setIntensity(0,8);
Serial.begin(9600);
}


void loop() {
  
int ledMatrix[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,0,1,1,1,0,0},
  {0,0,0,1,1,1,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,1,0,1,0,1,0}
  };
  
for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
    if (ledMatrix[i][j] == 1) {
      lc.setLed(0,i,j,true);
    }
  }
 }
 
int go = 1;

while (go == 1) {

 delay(1000);
   for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      
        int neighbours = 0;

          if (ledMatrix[i-1][j-1] == 1) {
           neighbours = neighbours + 1;
          }
          if (ledMatrix[i-1][j] == 1) {
            neighbours = neighbours + 1;
          }
          if (ledMatrix[i-1][j+1] == 1) {
            neighbours = neighbours + 1;
          }
          if (ledMatrix[i][j-1] == 1) {
            neighbours = neighbours + 1;
          }
          if (ledMatrix[i][j+1] == 1) {
            neighbours = neighbours + 1;
          }
          if (ledMatrix[i+1][j-1] == 1) {
            neighbours = neighbours + 1;
          }
          if (ledMatrix[i+1][j] == 1) {
            neighbours = neighbours + 1;
          }
          if (ledMatrix[i+1][j+1] == 1) {
            neighbours = neighbours + 1;
          }

        if (ledMatrix[i][j] == 1) {
          if (neighbours < 2) { 
            ledMatrix[i][j] = 0;
          }
          if (neighbours > 3) {
            ledMatrix[i][j] = 0;
          }
        }
        
        else if (ledMatrix[i][j] == 0) {
        if (neighbours == 3) {
          ledMatrix[i][j] = 1;
        }
        else {
          ledMatrix[i][j] = 0;
        }
       }
    }
   }
 for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
    if (ledMatrix[i][j] == 1) {
      lc.setLed(0,i,j,true);
    }
  }
 }
   delay(100);

}
}


