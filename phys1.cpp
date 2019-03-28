#include<iostream>  
#include<math.h>  
#define PI 3.14159265  
#define G 9.80665  
using namespace std;  
double f(double x,double d,double l2,double l1){  
double a,b,c;  
a=pow(l1/sin(x),2);  
b=2*l1*(l2/sin(x)-l2-d);  
c=pow(l2/sin(x)-l2-d,2)-pow(l1/sin(x),2)+pow(l1,2);  
return acos((-1*b+pow(b*b-4*a*c,0.5))/(2*a));  
}  
int main(){  
double l1,l2,theta0,d,theta1=0,thetakw=0,vkw=0,skw=0;  
int u;  
cin>>l1>>l2>>theta0>>u>>d;  
int n=100000;  
theta1=acos((l2+d)/l1);  
skw=l1*(PI/2-theta1)/2/n;  
double sum[u]={0};  
for(int k=1;k<u+1;k++){  
    for(int w=0;w<n;w++){  
    vkw=0;  
    if(k!=1)  
    thetakw=(1/2*PI-theta1)*w/n+theta1;  
    else  
    thetakw=(theta0-theta1)*w/n+theta1;  
        for(int w2=0;w2<k;w2++){  
        if(w2!=k-1){  
        vkw+=G*l1*(1-sin(thetakw));}  
        else{  
        vkw+=G*l1*(sin(theta0)-sin(thetakw));}  
        thetakw=f(thetakw,d,l2,l1);  
        }  
    sum[k]+=skw/sqrt(vkw);  
    }  
sum[0]+=sum[k];  
}  
cout<<sum[0];  
return 0;  
}  

