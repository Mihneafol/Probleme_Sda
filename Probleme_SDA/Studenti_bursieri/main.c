#include<stdio.h>
#include<stdlib.h>
struct student
{
    char nume[10];
    char prenume[10];
    int note[5];
};
void citire(struct student *p1,int n)
{
      for(int i=0;i<n;i++)
    {
    scanf("%s",(p1+i)->nume);
    scanf("%s",(p1+i)->prenume);
     for(int j=0;j<5;j++)
     scanf("%d",&(p1+i)->note[j]);
    }
}
void validare(struct student *p1,int n)
{
    int bursperf=0;
    int bursmeri=0;
      for(int i=0;i<n;i++)
    {
        int ct=0;
        int s=0;
     for(int j=0;j<5;j++)
    { if((p1+i)->note[j]<5)ct++;
      s=s+(p1+i)->note[j];
    }
     if(ct==0&&(float) s/5>=9.80) bursperf++;
     else if(ct==0&&(float)s/5<=9.80&&(float) s/5>=8) bursmeri++;
    }
    printf("%d %d",bursmeri,bursperf);
}
int main()
{
    int n;
    scanf("%d",&n);
    struct student *p1=(struct student*)malloc(n*sizeof(struct student));
    citire(p1,n);
    validare(p1,n);
}



