#include<stdio.h>
#include<stdlib.h>
struct jucator
{
    char nume[20];
    int nr[3];
};
void citire( struct jucator *p1,int k)
{
    for(int i=0;i<k;i++)
    {
    scanf("%s",(p1+i)->nume);
    for(int j=0;j<3;j++)
    scanf("%d",&(p1+i)->nr[j]);
     }
}
void afisare(struct jucator *p1,int k)
{
    for(int i=0;i<k;i++)
    {
    printf("%s\n",(p1+i)->nume);
    for(int j=0;j<3;j++)
    printf("%d\n",(p1+i)->nr[j]);
     }
}
void suma(struct jucator *p1,int k)
{
    int b[100],s;
    int ma=-999;
     for(int i=0;i<k;i++)
    {
        s=0;
    for(int j=0;j<3;j++)
      s=s+(p1+i)->nr[j];

    if(s>ma)ma=s;
    }
    int ma2=-999,q;
     for(int i=0;i<k;i++)
    {
        s=0;
    for(int j=0;j<3;j++)
    {
     s=s+(p1+i)->nr[j];

    }
    if(s==ma){
                  for(int j=0;j<3;j++)
                  if((p1+i)->nr[j]>ma2){ma2=(p1+i)->nr[j];
                                        q=i;}
             }

      }
        printf("%s",(p1+q)->nume);
   }
int main()
{
    int k,test;
    scanf("%d",&test);
    scanf("%d",&k);
    struct jucator *p1=(struct jucator *)malloc(k*sizeof( struct jucator));
    citire(p1,k);
    switch(test)
    {
        case 1:afisare(p1,k);
        break;
         case 2:suma(p1,k);
        break;
    }
}
