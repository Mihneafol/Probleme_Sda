#include<stdio.h>
#include<stdlib.h>
#include <cstring>
struct elev
{
    char nume[20];
    char cod[20];
    int note[9];
};
void citire(struct elev *p1,int n)
{
    for(int i=0;i<n;i++)
    {scanf("%s",(p1+i)->nume);
     scanf("%s",(p1+i)->cod);
    for(int j=0;j<9;j++)
   scanf("%d",&(p1+i)->note[j]);
    }
}
void afisare(struct elev *p1,int n)
{
    for(int i=0;i<n;i++)
    {
     printf("%s\n",(p1+i)->nume);
     printf("%s\n",(p1+i)->cod);
    for(int j=0;j<9;j++)
     printf("%d ",(p1+i)->note[j]);
     printf("\n");
    }
}
void medie(struct elev *p1,int n)
{
    float s;
    float ma=-999;
    for(int i=0;i<n;i++)
    {
    s=0;
    for(int j=0;j<9;j++)
    {
        s=s+(p1+i)->note[j];
    }
    if(s/9>ma)ma=s/9;
    }
    for(int i=0;i<n;i++)
    {
      s=0;
    for(int j=0;j<9;j++)
    {
        s=s+(p1+i)->note[j];
    }
    if(s/9==ma)printf("%s\n",(p1+i)->nume);
    }
}
void picati(struct elev *p1,int n)
{
    int s;
     for(int i=0;i<n;i++)
    {
    s=0;
    for(int j=0;j<9;j++)
    {
        s=s+(p1+i)->note[j];
    }
    if(s/9<6)printf("%s\n",(p1+i)->nume);
    }
}
void valmed(struct elev *p1,int n,char cod[20])
{
    int aux;
     for(int i=0;i<n;i++)
   {
    for(int j=0;j<8;j++)
    {
    for(int k=j+1;k<9;k++)
       if((p1+i)->note[j]>(p1+i)->note[k])
       {
           aux=(p1+i)->note[j];
           (p1+i)->note[j]=(p1+i)->note[k];
           (p1+i)->note[k]=aux;
       }
    }
   }
      for(int i=0;i<n;i++)
    if(strcmp((p1+i)->cod, cod) == 0)printf("%d ",(p1+i)->note[4]);
}
int main()
{
    int test,n;
    char cod[20];
    scanf("%d",&n);
    struct elev *p1=(struct elev*)malloc(n*sizeof(struct elev));
    citire(p1,n);
    scanf("%d",&test);
    switch(test)
    {
    case 1:afisare(p1,n);
    break;
    case 2:medie(p1,n);
      break;
    case 3: picati(p1,n);
    break;
    case 4:
    {
    scanf("%s",cod);
    valmed(p1,n,cod);
    }
}
}
