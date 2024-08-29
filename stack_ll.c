#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Node *createNode(int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (newNode == NULL)
   {
      printf("Memory allocation error \n");
      exit(1);
   }
   newNode->data = data;
   return newNode;
}

struct Node *push(struct Node *top, int data)
{
   struct Node *newNode = createNode(data);
   newNode->next = top;
   top = newNode;
   printf("pushed %d into the stack \n", data);
   return top;
}

struct Node *pop(struct Node *top, int *popped)
{
   if (top == NULL)
   {
      printf("stack underflow \n");
      exit(1);
      struct Node *temp = top;
      *popped = temp->data;
      top = top->next;
      free(temp);
      return top;
   }
}

int peek(struct Node *top)
{
   if (top == NULL)
   {
      printf("stack is empty \n");
      return -1;
   }
   return top->data;
}

void display(struct Node *top)
{
   if (top == NULL)
   {
      printf("nothing is there in the stack \n");
      exit(1);
   }
   struct Node *temp = top;
   while (temp != NULL)
   {
      printf("%d \n", temp->data);
      temp = temp->next;
   }
}

int main()
{
   struct Node *stack = NULL;
   int popped;
   stack = push(stack, 10);
   stack = push(stack, 20);
   stack = push(stack, 30);

   printf("top element is %d \n", peek(stack));

   stack = pop(stack, &popped);
   if (popped != -1)
   {
      printf("popped element is %d \n", popped);

      printf("the top after pop is %d \n", peek(stack));

      display(stack);

      return 0;
   }
}