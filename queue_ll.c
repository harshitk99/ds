#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Queue
{
   struct Node *front;
   struct Node *rear;
};

struct Node *createNode(int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   if (!newNode)
   {
      printf("Memory allocatoin failed.\n");
      exit(1);
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

void iniliatizeQueue(struct Queue *q)
{
   q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q)
{
   return (q->front == NULL);
}

void enqueue(struct Queue *q, int data)
{
   struct Node *newNode = createNode(data);
   if (q->rear == NULL)
   {
      q->front = q->rear = newNode;
   }
   else
   {
      q->rear->next = newNode;
      q->rear = newNode;
   }
   printf("%d enqueued to the queue.\n", data);
}

int dequeue(struct Queue *q)
{
   if (isEmpty(q))
   {
      printf("Queue is empty. Cannot deque\n");
      return -1;
   }
   struct Node *temp = q->front;
   int data = temp->data;
   q->front = q->front->next;
   if (q->front == NULL)
   {
      q->rear = NULL;
   }
   free(temp);
   return data;
}

void displayQueue(struct Queue *q)
{
   if (isEmpty(q))
   {
      printf("Queue is empty.\n");
      return;
   }

   struct Node *temp = q->front;
   printf("Queue elements : ");
   while (temp != NULL)
   {
      printf("%d", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main()
{
   struct Queue q;
}