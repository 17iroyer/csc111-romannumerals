/*
* Project 1: Roman and Arabic number converter
* Programmer: Ian Royer
* Course: S18 CSC111
* Professor: Dr. Lee
*/

#include <stdio.h>
#include <string.h>
#include "mync.h"

char final[13];

void getOnesNumeral(int i)                           //Function to get numeral for one digit
{
   if(i == 4)                                        //Special cases 4 and 9
   {
      strcat(final,  "IV");
   }
   else if(i == 9)
   {
      strcat(final, "IX");
   }
   else if(i <= 3)                                   //if digit is 3 or below, just add that amount of I's
   {      
      for(int count = 0; count < i; count++)
      {
        strcat(final, "I");
      }
   }
   else if(i >= 5 && i <= 8)                          //If digit is between 5-8, subtract 5 and add that amount
   {                                                  //of I's to V
      strcat(final, "V");
      for(int count = 0; count < (i-5); count++)
      {
         strcat(final, "I");
      }
   }
}

void getTensNumeral(int i)                          //Funtion to get the Tens digit numeral
{
   if(i == 4)                                       //Special cases 4 and 9
   {
      strcat(final, "XL"); 
   }
   else if(i == 9)
   {
      strcat(final, "XC");
   }
   else if(i <= 3)                                  //If i <= 3, then add that amount of X's
   {
      for(int count = 0; count < i; count++)
      {
         strcat(final, "X");
      }
   }
   else if(i >= 5 && i <= 8)                        //If i is between 5-8 , subtract 5 and add that amount
   {                                                //of X's to L
      strcat(final, "L");
      for(int count = 0; count < (i-5); count++)
      {
         strcat(final, "X");
      }
   }
}

void getHundNumeral(int i)                          //Function toget the hundreds digit numeral
{
   if(i == 4)                                       //Special cases for 4 and 9
   {
      strcat(final, "CD");
   }
   else if(i == 9)
   {
      strcat(final, "CM");
   }
   else if(i <= 3)                                  //If i <= 3 just add that amount of C's
   {
      for(int count = 0; count < i; count++)
      {
         strcat(final, "C");
      }
   }
   else if(i >= 5 && i <=8)                         //If i is between 5-8, then subtract 5 and add
   {                                                //that amount of C's to a D
      strcat(final, "D");
      for(int count = 0; count < (i-5); count++)
      {
         strcat(final, "C");
      }
   }
}

void getThouNumeral(int i)                          //Since 4999 is the last number before we need a special character,
{                                                   //we only need to worry about numbers up to 4999 
   for(int count = 0; count < i; count++)           //add the appropriate amount of M's
   {
      strcat(final, "M");
   }
}

//Arabic to Roman function
char *a2r()
{
   int number = 1, digitcount = 0;
   do
   {
      printf("Your input: ");                                       //Get user input
      scanf("%d", &number);

      if(number <= 0 && number > 4999)                              //Return an error if the number is out of range
      {
         printf("Please enter a number between 1-4999\n");
      }
   }while(number < 0 && number > 4999);                             //Check if the number is out of range

   int digits = number;
   while(digits != 0)                                               //Count the amount of digits in the input
   {
      digits = digits/10;
      digitcount++;
   }

   digits = number;                                                 //Split up the original number into an array
   int digitar[digitcount];
   for(int i = digitcount-1; i >= 0; i--)
   {
      digitar[i] = digits % 10;
      digits = digits / 10;
   }

   switch(digitcount)                                               //Switch case depending on how many digits are present     
   {
      case 1:
         getOnesNumeral(digitar[0]);
         return final;
      case 2:
         getTensNumeral(digitar[0]);
         getOnesNumeral(digitar[1]);
         return final;
      case 3:
         getHundNumeral(digitar[0]);
         getTensNumeral(digitar[1]);
         getOnesNumeral(digitar[2]);
         return final;
      case 4:
         getThouNumeral(digitar[0]);
         getHundNumeral(digitar[1]);
         getTensNumeral(digitar[2]);
         getOnesNumeral(digitar[3]);
         return final;
      default:
         printf("An error has occured\n");
         return "ERROR";
   }
} 
