#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char nume1[10];
    char nume2[10];
    float timp;
    struct Node*next;
};
struct Node* creare_nod()
{
    struct Node*nod_nou=(struct Node*)malloc(sizeof(struct Node));
     scanf("%s",nod_nou->nume1);
     scanf("%s",nod_nou->nume2);
     scanf("%f",&nod_nou->timp);
     nod_nou->next=NULL;
     return nod_nou;
}
struct Node*adaugare_nod(struct Node*head)
{
    struct Node*ptr=head;
    if(ptr==NULL)
    {
        struct Node*nod_nou=creare_nod();
        return nod_nou;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
     struct Node*nod_nou=creare_nod();
     ptr->next=nod_nou;
     return head;
}
void afisare(struct Node*head)
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
        printf("%s %s %0.2f\n",temp->nume1,temp->nume2,temp->timp);
        temp=temp->next;
    }
}
void afisare_min(struct Node*head)
{
    float mi=99;
     struct Node*temp=head;
      while(temp!=NULL)
    {
        if(temp->timp<mi)mi=temp->timp;
        temp=temp->next;
    }
    temp=head;
      while(temp!=NULL)
    {
        if(temp->timp==mi){
        printf("%s %s %0.2f\n",temp->nume1,temp->nume2,temp->timp);
        break;
        }
         temp=temp->next;
    }
}
void afisare_prag(struct Node*head)
{
    struct Node*temp=head;
    float s=0,ct=0;
      while(temp!=NULL)
    {
       s=s+temp->timp;
       ct++;
       temp=temp->next;
    }
    temp=head;
      while(temp!=NULL)
    {
       if(temp->timp>s/ct)
        printf("%s %s %0.2f\n",temp->nume1,temp->nume2,temp->timp);
        temp=temp->next;
    }
}
void sortare(struct Node*head)
{
    float a[10];
    float aux;
    int nr1=0;
   struct Node*temp=head;
   while(temp!=NULL)
   {
       a[nr1]=temp->timp;
       nr1++;
       temp=temp->next;

   }


       for(int i=0;i<nr1-1;i++)
        for(int j=i+1;j<nr1;j++)
        if(a[i]>a[j]){
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }

        temp=head;
    for(int i=0;i<nr1;i++)
    {  temp=head;
        while(temp!=NULL)
        {
       if(a[i]==temp->timp)
        printf("%s %s %0.2f\n",temp->nume1,temp->nume2,temp->timp);
        temp=temp->next;
    }
}

}
int main()
{
    struct Node*head=NULL;
    int test,nr;
     scanf("%d",&nr);
    for(int i=0;i<nr;i++)
      head=adaugare_nod(head);
      scanf("%d",&test);
    switch(test)
    {
        case 1:
        {
            afisare(head);
            break;
        }
         case 2:
        {
            afisare_min(head);
            break;
        }
        case 3:
        {
            afisare_prag(head);
            break;
        }
        case 4:
        {
            sortare(head);
            break;
        }
    }
}
