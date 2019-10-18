/*
* Project 1: Roman and Arabic Number Converters
* Programmer: Ian Royer
* Course: S18 CSC111
* Professor: Dr. Lee
*/

#include <stdio.h>
#include "mync.h"

int main()
{
   int choice;                                             //Stores the user's choice;

   printf("Choose your option: 1.Roman to Arabic\n"
          "                    2.Arabic to Roman\n");
   scanf("%d", &choice);                                   //Take input from the user
   
   do
   {
      switch(choice)                                       //Depending on the choice, take action
      {
         case 1:
            printf("%d\n", r2a());
            break;
         case 2:
            printf("%s\n", a2r());         
            break;
         default:
            printf("Please enter either 1 or 2\n");
            break;
      }
   }while(choice != 1 || choice != 2);                     //Ask again if an incorrect input is entered

   return 0;
}
