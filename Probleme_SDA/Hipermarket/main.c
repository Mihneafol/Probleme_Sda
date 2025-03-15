#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Node
{
    char nume[64];
    int nr;
    struct Node*next;
};
struct Node*creare_nod(char nume[],int nr)
{
    struct Node*nod_nou=(struct Node*) malloc(sizeof(struct Node));
    strcpy(nod_nou->nume,nume);
    nod_nou->nr=nr;
    nod_nou->next=NULL;
    return nod_nou;
}
struct Node*adaugare_nod(struct Node *head,char nume[],int nr)
{
    struct Node*ptr=head;
    if(ptr==NULL)
    {
         struct Node*nod_nou=creare_nod(nume,nr);
         return nod_nou;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
     struct Node*nod_nou=creare_nod(nume,nr);
     ptr->next=nod_nou;
    return head;
}
void afisare(struct Node*head)
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
       printf("%s %d\n",temp->nume,temp->nr);
       temp=temp->next;
    }
}
void  nr_produse(struct Node*head)
{
    int s=0;
    struct Node*temp=head;
    while(temp!=NULL)
    {
       s=s+temp->nr;
       temp=temp->next;
    }
    printf("%d",s);
}
void bifurcare_coada(struct Node *head)
{
    struct Node*coada1=NULL;
    struct Node*coada2=NULL;
     struct Node*temp=head;
     int ct=0;
     while(temp!=NULL)
    {
       if(ct%2==0)coada1=adaugare_nod(coada1,temp->nume,temp->nr);
       else coada2=adaugare_nod(coada2,temp->nume,temp->nr);
       ct++;
       temp=temp->next;
    }
    struct Node*ptr=coada1;
    while(ptr!=NULL)
    {
        printf("%s\n",ptr->nume);
        ptr=ptr->next;
    }
    ptr=coada2;
     while(ptr!=NULL)
    {
        printf("%s\n",ptr->nume);
        ptr=ptr->next;
    }
}
void distribuie_clienti(struct Node* head)
{
    struct Node* coada1 = NULL;
    struct Node* coada2 = NULL;
    int s1 = 0, s2 = 0;

    struct Node* temp = head;
    while (temp != NULL)
    {
        if (s1 <= s2)
        {
            coada1 = adaugare_nod(coada1, temp->nume, temp->nr);
            s1 += temp->nr;
        }
        else
        {
            coada2 = adaugare_nod(coada2, temp->nume, temp->nr);
            s2 += temp->nr;
        }

        temp = temp->next;
    }

    struct Node* ptr = coada1;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->nume);
        ptr = ptr->next;
    }

    ptr = coada2;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->nume);
        ptr = ptr->next;
    }
}
int main()
{
    int test,pct5;
    struct Node *head=NULL;
    scanf("%d",&test);
     scanf("%d",&pct5);
    char nume[64];
    int nr;
    while(scanf("%s %d",nume,&nr)!=EOF)
    {
        head=adaugare_nod(head,nume,nr);
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
            nr_produse(head);
            break;
        }
          case 3:
        {
            bifurcare_coada(head);
            break;
        }
        case 4:
        {
            distribuie_clienti(head);
            break;
        }
    }

}
