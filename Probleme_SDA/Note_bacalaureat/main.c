#include<stdio.h>
#include<stdlib.h>
struct elev
{
    char nume[20];
    char prenume[20];
    float note[10];
};
void citire(struct elev *p2,int n)
{
    for(int i=0;i<n;i++)
    {
    scanf("%s",(p2+i)->nume);
     scanf("%s",(p2+i)->prenume);
     for(int j=0;j<4;j++)
     scanf("%f",&(p2+i)->note[j]);
}
}
void verificare(struct elev *p2,int n)
{
    float s;
    int ct;
     for(int i=n-1;i>=0;i--)
    {
         s=0;
         ct=0;
     for(int j=0;j<4;j++)
    {
     if((p2+i)->note[j]>5) ct++;
     s=s+(p2+i)->note[j];
    }
    if(ct==4&&(s/4)>6){
                        printf("%s ",(p2+i)->nume);
                        printf("%s ",(p2+i)->prenume);
                        printf("%0.2f\n",(s/4));
                    }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    struct elev *p2=(struct elev*)malloc(n*sizeof(struct elev));
    citire(p2,n);
    verificare(p2,n);
    free(p2);
}
