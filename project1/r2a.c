/*
* Project 1: Roman and Arabic number converter
* Programmer: Ian Royer
* Course: S18 CSC111
* Professor: Dr. Lee
*/

#include <stdio.h>
#include <string.h>
#include "mync.h"

int getValue(char numArray[])
{
   int sum = 0;                                                      //start sum at 0
  
   for(int i = 0; numArray[i] != '\0'; i++)                          //step through the array of numerals
   {
      if(numArray[i] == 'M' || numArray[i] == 'm')                   //add 1000 if M is present
      {
         sum += 1000;
      }
      else if(numArray[i] == 'D' || numArray[i] == 'd')              //add 500 if D is present
      {
         sum += 500;
      }
      else if(numArray[i] == 'C' || numArray[i] == 'c')
      {
         if(numArray[i+1] == 'M' || numArray[i+1] == 'm')            //if C is followed by an M, add 900 
         {
            i++;
            sum += 900;
         }
         else if(numArray[i+1] == 'D' || numArray[i+1] == 'd')       //if C is followed by a D, add 400
         {   
            i++;
            sum += 400;
         }
         else
         {
            sum += 100;                                              //if it is just C, add 100
         }
      }
      else if(numArray[i] == 'L' || numArray[i] == 'l')              //add 50 if L is present
      {
         sum += 50;
      }
      else if(numArray[i] == 'X' || numArray[i] == 'x')              
      {
         if(numArray[i+1] == 'C' || numArray[i+1] == 'c')            //if X is followed by C, add 90
         {  
            i++;
            sum += 90;
         }
         else if(numArray[i+1] == 'L' || numArray[i+1] == 'l')       //if X is followed by L, add 40
         {
            i++;
            sum += 40;
         }
         else
         {
            sum += 10;                                               //if it is just X, add 10
         }
      }
      else if(numArray[i] == 'V' || numArray[i] == 'v')              //add 5 if V is present
      {
         sum += 5;
      }
      else if(numArray[i] == 'I' || numArray[i] == 'i')
      {
         if(numArray[i+1] == 'X' || numArray[i+1] == 'x')            //if I is followed by X, add 9
         {
            i++;
            sum += 9;
         }
         else if(numArray[i+1] == 'V' || numArray[i+1] == 'v')       //if I is followed by V, add 4
         {
            i++;
            sum += 4;
         }
         else
         {
            sum += 1;                                                //if it is just I, add 1
         }
      }
   }

   return sum;                                                      //return the sum
}

//Roman to Arabic function
int r2a()
{
   char inArray[13];                                     //array for the initial input 

   printf("Your input: ");                               //get user input
   scanf("%s", inArray);

   return getValue(inArray);                             //pass in array and return the final value
} 
