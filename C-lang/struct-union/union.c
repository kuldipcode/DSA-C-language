// https://www.tutorialspoint.com/cprogramming/c_unions.htm

// Both structures and unions are composite data types in C programming. 
// The most significant difference between a structure and a union is the way they store their data. 
// A structure stores each member in separate memory locations, whereas a union stores all its members in the same memory location.

#include <stdio.h>
#include <string.h>

union Data{
   int i;
   float f;
   char str[20];
};

int main(){
   
   union Data data;        
   
   data.i = 10;
   printf("data.i: %d \n", data.i);
   
   data.f = 220.5;
   printf("data.f: %f \n", data.f);
   
   strcpy(data.str, "C Programming");
   printf("data.str: %s \n", data.str);
   return 0;
}