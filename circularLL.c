#include<stdlib.h>
#include<stdio.h>
typedef struct list{
   int data;
   struct list *next;
}Node;

Node *tail=NULL;

Node * getNode(int data)
{
   Node * newNode = (Node*)malloc(sizeof(Node));
   newNode->data=data;
   newNode->next=NULL;
   return newNode;
}

void insertAtStart(int newElement){
   Node * newNode = getNode(newElement);
   if(tail==NULL)
   {
      tail=newNode;
      tail->next=tail;
   }else{
      newNode->next=tail->next;
      tail->next=newNode;
   }
}

void insertAtEnd(int newElement){
   Node *newNode = getNode(newElement);
   if(tail==NULL)
   {
      tail=newNode;
      tail->next=tail;
   }else{
      newNode->next=tail->next;
      tail->next=newNode;
      tail=newNode;
   }
}

void removeAtEnd()
{
   
   if(tail==NULL)
      printf("\nCLL underflow");
   else if(tail->next==tail)
   {
      printf("\nDeleted Element is %d\n",tail->data);
      free(tail);
      tail=NULL;
   }else{
      Node * t= tail;
      while(t->next!=tail)
      {
         t=t->next;
      }
      Node *del=tail;
      printf("\nDeleted element is %d\n",del->data);
      t->next=tail->next;
      tail=t;
   }
}

void removeAtStart()
{
   if(tail==NULL)
      printf("\nCLL underflow");
   else if(tail->next==tail)
   {
      printf("\nDeleted Element is %d\n",tail->data);
      free(tail);
      tail=NULL;
   }
   else{
      Node * del =tail->next;
      tail->next=del->next;
      printf("\nDeleted Element is %d\n",del->data);
      free(del);
   }
}


void display(){
   if(tail==NULL)
      printf("\nCLL underflow");
   else{
      Node * temp=tail->next;
      while(temp!=tail)
      {
         printf("%d ",temp->data);
         temp=temp->next;
      }
      printf("%d ",temp->data);
   }
}


int main()
{
   int choice;
   int newElement;
   while(choice!=0){
      printf("\n1.Insert 2.Delete 3.Display\nEnter choice->");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
            printf("\nEnter new Element->");
            scanf("%d",&newElement);
            insertAtEnd(newElement);
            display();
            break;

         case 2:
            removeAtEnd();
            display();
            break;

         case 3:
            display();
            break;

         default:
               printf("\nInvalid choice");
               break;
      }
   }
   
   return 0;
}
