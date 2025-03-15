#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  char nume[15];
  int id;
  struct Node *next;
};
struct Node* creare_nod(char nume[],int id)
{
    struct Node*nod_nou=(struct Node*)malloc(sizeof(struct Node));
    strcpy(nod_nou->nume,nume);
    nod_nou->id=id;
    nod_nou->next=NULL;
    return nod_nou;
}
struct Node*adaugare_nod(struct Node *head,char nume[],int id)
{
      struct Node* ptr=head;
        if(ptr==NULL)
      {
          struct Node*nod_nou=creare_nod(nume,id);
          return nod_nou;
      }
     /* while(ptr->next!=NULL)
      {
          ptr=ptr->next;
      }*/
      struct Node*nod_nou=creare_nod(nume,id);
      //ptr->next=nod_nou;
      nod_nou->next=head;
      head=nod_nou;
      return head;
}
void afisare(struct Node *head)
{
     struct Node* temp=head;
     while(temp!=NULL)
     {
        printf("%s %d\n",temp->nume,temp->id);
        temp=temp->next;
     }
}
void maxi(struct Node *head)
{
    int max=-99;
      struct Node* temp=head;
      while(temp!=NULL)
      {
          if(temp->id>max)max=temp->id;
          temp=temp->next;
      }
      temp=head;
      while(temp!=NULL)
      {
          if(temp->id==max){
               max=temp->id;
               printf("%s\n",temp->nume);
               break;
          }
          temp=temp->next;
      }

}
void ident(struct Node *head,int pct3)
{

      struct Node* temp=head;
      while(temp!=NULL)
      {

     if (temp->next != NULL && temp->next->id == pct3 && temp->next->next != NULL)
          {
                printf("%s %d\n",temp->nume,temp->id);
              temp=temp->next->next;


          }

          else
          {
              printf("%s %d\n",temp->nume,temp->id);
              temp=temp->next;
           }
      }
}
int main()
{
    struct Node*head=NULL;
    int test,pct3;
    char nume[15];
    int id;
    scanf("%d",&test);
    scanf("%d",&pct3);
    while(scanf("%s %d",nume,&id)!=EOF)
    {
       head=adaugare_nod(head,nume,id);
    }
    switch(test)
    {
        case 1:
        {
            afisare(head);
            break;
        }
         case 2:
        {
            maxi(head);
            break;
        }
           case 3:
        {
            ident(head,pct3);
            break;
        }
    }
}
