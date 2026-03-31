#include<stdio.h>
#include<iostream>
void fib(int n)
{
   int a = 0,b= 1 , c = 1;
   while(c<n)
   {
   	a= b;
   	b=c;
   	c= a+b;
   }
   if(c==n)
   	std::cout<<"isfibo";
   	else
   	std::cout<<"notfibo";
}
 
int main ()
{
  int n = 5;
  
  fib(n);
  getchar();
  return 0;
}
