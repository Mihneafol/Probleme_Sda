#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int timp;
    struct Node* next;
};
struct Node*creare_nod(int timp)
{
    struct Node* nod_nou=(struct Node*)malloc(sizeof(struct Node));
    nod_nou->timp=timp;
    nod_nou->next=NULL;
    return nod_nou;
}
struct Node*adaugare_nod(struct Node*head,int timp)
{
    struct Node*ptr=head;
    if(ptr==NULL){
                     struct Node*nod_nou=creare_nod(timp);
                     return nod_nou;
                 }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
     struct Node*nod_nou=creare_nod(timp);
     ptr->next=nod_nou;
     return head;
}
void afisare(struct Node*head)
{
    struct Node*tmp=head;

    while(tmp!=NULL)
    {
        printf("%d\n",tmp->timp);
        tmp=tmp->next;
    }
}
void medie(struct Node*head)
{
    float s=0,ct=0;
     struct Node*tmp=head;
      while(tmp!=NULL)
      {
          s=s+tmp->timp;
          ct++;
          tmp=tmp->next;
      }
     printf("%0.2f",s/ct);
}
void timpi(struct Node*head)
{
    struct Node*tmp=head;
    int a[10],nr=0,aux;
    while(tmp!=NULL)
    {
        a[nr]=tmp->timp;
        nr++;
        tmp=tmp->next;
    }

    for(int i=0;i<nr-1;i++)
    for(int j=i+1;j<nr;j++)
    {
        if(a[i]>a[j]){
                        aux=a[i];
                        a[i]=a[j];
                        a[j]=aux;
                     }
    }
    //printf("%d",nr);;
    tmp=head;
    while(tmp!=NULL)
    {
        for(int i=0;i<4;i++)
        if(tmp->timp==a[i])printf("%d\n",tmp->timp);
        tmp=tmp->next;
    }
}
void sortare(struct Node*head)
{
    struct Node*tmp1=head;
    struct Node *tmp2;
    int aux;
    while(tmp1!=NULL)
    {
        tmp2=tmp1->next;
        while(tmp2!=NULL)
        {
            if(tmp1->timp<tmp2->timp)
            {
                  aux=tmp1->timp;
                  tmp1->timp= tmp2->timp;
                  tmp2->timp=aux;
            }
            tmp2=tmp2->next;
        }
         tmp1=tmp1->next;
    }
    tmp1=head;
    while(tmp1->next!=NULL)
    {
        printf("%d\n",tmp1->timp);
        tmp1=tmp1->next;
    }
}

int main()
{
    struct Node*head=NULL;
    int test,timp;
    scanf("%d",&test);
    while(scanf("%d",&timp)!=EOF)
    {
        head=adaugare_nod(head,timp);
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
            medie(head);
            break;
        }
          case 3:
        {
            timpi(head);
            break;
        }
          case 4:
        {
            sortare(head);
            break;
        }
    }
}
