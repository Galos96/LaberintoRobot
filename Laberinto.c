/*
Universidad del Valle De Guatemala
Proyecto 1 Fase #2
Algoritmos y Estructura de Datos
Diego Valdez      15397
Sang Woo Shin     15372
Ramon Samayoa     15497
Jorge Mario Lara  15366
*/

#include "simpletools.h"                    
#include "abdrive.h" 
#include "ping.h"                        

// Se declaran las variables a utilizar
int irLeft, irRight, cmDist, loop, turn;

// Se define el main
int main()                   
{
  // Se inician las varibales
  low(26);                                      
  low(27);
  loop=0;
  turn=60;

  // Loop infinito
  while (1){
    cmDist = ping_cm(8);   // Se obtiene la distancia con el sensor                     
    freqout(1, 1, 28000);  // Frecuencia del LED Infrarrojo                     
    irRight = input(2);    // Se obtiene la lectura del infrarrojo derecho

    // Gira a la derecha al encontrarse en la interseccion
    if ((irRight==1)){
      drive_speed(turn, turn);
      pause(40);
      drive_speed(90, 30);
      pause(860);
      loop++; } 

    // Si hay pared a la derecha y la distancia se encuentra entre 4 y 8
    // Callejon sin salida, da la vuelta
    else if ((irRight==0)&& (cmDist < 8) &&(cmDist > 4)){
      drive_speed(1, 1);
      pause(100);
      drive_speed(-turn, turn); //Gira a la izquierda
      pause(320);
      loop=0; }

    // Si hay pared a la derecha, seguir hacia adelante
    else if ((irRight==0)){
      drive_speed(turn, turn);
      pause(20);
      loop=0; }  

    // Si la distancia es menor a 5, o sea se acerca mucho a la pared
    if ((cmDist <5) ){
      drive_speed(-10, -10);  // Retrocede
      pause(1000);
      drive_speed(1, 1);
      pause(100);
      drive_speed(-turn, turn);  // Gira a la izquierda
      pause(150);
      drive_speed(60, 60);    // Avanza Brevemente
      pause(500);
      loop=0; }

    // Si gira a la derecha 4 o mas veces sin encontrar  una pared
    // Va seguir recto hasta encontrar otra pared
    if (loop>=4){
      drive_speed(78, 22);
      pause(100);
      while((irRight==1) && (cmDist>5)){
        drive_speed(60, 60);
        cmDist = ping_cm(8);
        freqout(1, 1, 25000);
        irRight = input(2); }     
      loop=0;   
    }
  }  
}