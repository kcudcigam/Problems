#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main()
{
    freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout); 
	int t,n,m,i,j,k,T,x,y,xx,yy,f=0,tt;
	read(t); 
	for (k=1;k<=t;k++)
	{
		read(n);
		f=0; 
		x=0;y=0;
		tt=0;
		for (i=1;i<=n;i++)
		{
			read(T);
			read(xx);
			read(yy);
			if (abs(x-xx)+abs(yy-y)>T-tt) f=1;
			if (((T-tt)-abs(x-xx)-abs(y-yy))%2==1) f=1;
			x=xx;
			y=yy;
			tt=T; 
		}
		if (f==1) cout<<"No"<<endl;
		   else cout<<"Yes"<<endl;
	}
	return 0;
} 
