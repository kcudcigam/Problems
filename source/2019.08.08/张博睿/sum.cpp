#include<bits/stdc++.h>
using namespace std;
long long a[100010],h[100010],n,duck,x,y,x2,y2,f,f2;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		h[i]=h[i-1]+a[i];
	}
	x=LONG_LONG_MAX;y=-LONG_LONG_MAX;x2=10000000;y2=10000000;
	for(int i=1;i<=n;i++)
	{
		if(h[i]<x&&i<y2) {x=h[i];x2=i;}
		if(h[i]>y&&i>x2) {y=h[i];y2=i;}
	}
	if(x>0){x=0;x2=1;}
	duck=duck+y-x;
	f=0;f2=0;
	for(int i=1;i<x2-1;i++){
	 if(h[i]>h[i+1]) f=1;
	 if(h[i]==h[i+1]) f2=1;	
	}
	for(int i=y2+1;i<n;i++){
	if(h[i]>h[i+1]) f=1;
	if(h[i]==h[i+1]) f2=1;	
	} 
	if(y2-x2+1==1) 
	{
		a[x2]=INT_MIN;
		x=INT_MIN;
		for(int i=1;i<=n;i++) x=max(x,a[i]);
		duck+=x;
	}
	else
	if(y2-x2+1!=n)
	{
		if(f==0)
	{
		for(int i=y2+1;i<=n;i++) a[i-y2+x2-1]=a[i];
		n=n-(y2-x2+1);
		for(int i=1;i<=n;i++) h[i]=h[i-1]+a[i];
		x=LONG_LONG_MAX;y=-LONG_LONG_MAX;x2=10000000;y2=10000000;
	for(int i=1;i<=n;i++)
	{
		if(h[i]<x&&i<y2) 
		{
			x=h[i];
			x2=i;
		}
		if(h[i]>y&&i>x2)
		{
			y=h[i];
			y2=i;
		}
	}
	if(x>0)
	{
		x=0;x2=1;
	}
	duck=duck+y-x;
	}
	else 
	if(f2==1)
	{
		long long minl=0;
		for(int i=x2;i<=y2;i++){
		 if(a[i]<0) x+=a[i];	
		 else if(minl>x) minl=x; 	
		}
		duck-=minl;
 	}
 	else
 	{
 		long long minl=0;
 		x=0;y=-INT_MAX;
 		for(int i=x2;i<=y2;i++){
 		 if(a[i]<0) x+=a[i];
		 else if(minl>x) minl=x; 
		}
		if(x==0)
		{
			x=INT_MAX;
			for(int i=x2;i<=y2;i++) x=min(x,a[i]);
		}
 		for(int i=1;i<x2;i++) y=max(y,a[i]);
 		for(int i=y2+1;i<=n;i++) y=max(y,a[i]);
 		if(x<=0) duck-=x;
 		else 
 		{
 			if(y>=0) duck+=y;
 			else
 			{
 				y=-y;
 				if(x>y) duck-=y;
 				else duck-=x;
			 }
		}
	}
	 } 
	cout<<duck<<endl;
	return 0;
}

