#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,t,xx,yy,tt,q;
bool f;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);
	for (int i=1;i<=a;i++)
	{
		read(b);f=0;tt=0;xx=0;yy=0;
		for (int j=1;j<=b;j++)
		{
			read(t);read(x);read(y);
			q=abs(x-xx)+abs(y-yy);
			if (q>t-tt) 
			f=1;
			else
			if ((t-tt-q)%2==1) f=1;
			tt=t;xx=x;yy=y;
		}
		if (f) 
		cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}


