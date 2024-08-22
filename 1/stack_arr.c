// Online C compiler to run C program online
#define MAX 10
#include <stdio.h>

int stack[10], topA = -1, topB = 10;

void pushA(int val)
{
   if (topA == topB - 1)
   {
      printf("stack overflow \n");
   }
   topA++;
   stack[topA] = val;
}

void pushB(int val)
{
   if (topA == topB - 1)
   {
      printf("STACK OVERFLOW \n");
   }
   else
   {
      topB--;
      stack[topB] = val;
   }
}

void popA()
{

   if (topA == -1)
      printf("stack underflow \n");
   else
   {
      int item = stack[topA];
      topA--;
      printf("the popped item is %d", item);
   }
}

void popB()
{
   if (topB == MAX)
      printf("stack underflow \n");
   else
   {
      int item = stack[topB];
      topB++;
      printf("the popped item is %d", item);
   }
}

int peekA()
{
   return stack[topA];
}
int peekB()
{
   return stack[topB];
}

void displayA()
{
   if (topA == -1)
      printf("nothing in stack A \n");
   else
   {
      for (int i = topA; i >= 0; i--)
      {
         printf("%d \n", stack[i]);
      }
   }
}

void displayB()
{
   if (topB == MAX)
      printf("nothing in stack A \n");
   else
   {
      for (int i = topB; i <= MAX - 1; i++)
      {
         printf("%d \n", stack[i]);
      }
   }
}

int main()
{
   int q;
   printf("enter no. of iterations of whole menu ");
   scanf("%d", &q);
   do
   {
      printf("enter the choice according to the options below ----- \n");
      printf("1.PUSH IN STACK A \n");
      printf("2.PUSH IN STACK B \n");
      printf("3.POP IN STACK A \n");
      printf("4.POP IN STACK B \n");
      printf("5.DISPLAY THE STACK A \n");
      printf("6.DISPLAY THE STACK B \n");
      printf("7.GET THE PEEK ELEMENT OF STACK A \n");
      printf("8.GET THE PEEK ELEMENT OF STACK B \n");

      int choice;
      printf("ENTER THE CHOICE NOW -- \n ");
      scanf("%d", &choice);

      switch (choice)
      {

      case 1:
         int a;
         printf("enter val -> ");
         scanf("%d", &a);
         pushA(a);
         break;

      case 2:
         int b;
         printf("enter val -> ");
         scanf("%d", &b);
         pushB(b);
         break;

      case 3:
         popA();
         break;

      case 4:
         popB();
         break;

      case 5:
         displayA();
         break;

      case 6:
         displayB();
         break;

      case 7:
         int peeka = peekA();
         printf("%d", &peeka);
         break;

      case 8:
         int peekb = peekB();
         printf("%d", &peekb);
         break;

      default:
         printf("INVALID CHOICE \n");
      }
   } while (q--);

   return 0;
}