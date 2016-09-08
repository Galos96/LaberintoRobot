#include "simpletools.h"                    
#include "abdrive.h" 
#include "ping.h"                        

int irLeft, irRight,cmDist,loop,turn;

int main()                   
{
  low(26);                                      
  low(27);
  loop=0;
  turn=60;
  while (1){
    cmDist = ping_cm(8);                        
    freqout(1, 1, 25000);                       
    irRight = input(2); 
    if ((irRight==1)){
      drive_speed(turn, turn);
      pause(25);
      drive_speed(90, 30);
      pause(860);
      loop++;
    } else if ((irRight==0)&& (cmDist < 8) &&(cmDist > 4)){
      drive_speed(1, 1);
      pause(100);
      drive_speed(-turn, turn);
      pause(350);
      loop=0;
    } else if ((irRight==0)){
      drive_speed(turn, turn);
      pause(20);
      loop=0;
    }  
    if ((cmDist <5) ){
      drive_speed(-10, -10);
      pause(1000);
      drive_speed(1, 1);
      pause(100);
      drive_speed(-turn, turn);
      pause(150);
      drive_speed(60, 60);
      pause(500);
      loop=0;
    }      
    if (loop>=4){
      drive_speed(78, 22);
      pause(100);
      while((irRight==1) && (cmDist>5)){
        drive_speed(60, 60);
        cmDist = ping_cm(8);
        freqout(1, 1, 25000);
        irRight = input(2);
      }     
      loop=0;   
    }
  }  
}