#include<bits/stdc++.h>
using namespace std;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){num=num*10+c-'0';c=getchar();}
	return num*f;
}
int T,n,t,x,y,flag;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		t=x=y=flag=0;
		for(int i=1;i<=n;i++)
		{
			int a=read(),b=read(),c=read();
			if (a-t<abs(x-b)+abs(y-c)||(a-t-abs(x-b)-abs(y-c))%2==1)
				flag=1;
		}
		if (flag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
