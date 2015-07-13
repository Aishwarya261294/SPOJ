#include<stdio.h>
int main(){
int a,b,c,temp,ans,t,c1;
scanf("%d",&t);
while(t>0){
scanf("%d %d",&a,&b);
temp=0;
while(a>0)
{
temp=a%10+temp*10;
a=a/10;
}
c1=0;
while(b>0){
c1=b%10+c1*10;
b=b/10;
}
ans=temp+c1;
c=0;
while(ans>0){
c=ans%10+c*10;
ans=ans/10;
}
printf("%d\n",c);
t--;
}
return 0;
}
