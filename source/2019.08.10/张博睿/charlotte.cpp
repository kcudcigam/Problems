#include<bits/stdc++.h>
using namespace std;
int T,n,a,x,y,xi,yi,lt,f;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		x=0;y=0;f=0;lt=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a,&xi,&yi);
			if(abs(xi-x)+abs(yi-y)!=a-lt)
			{
				if(abs(xi-x)+abs(yi-y)>a-lt) f=1;
				else 
				if((a-lt-abs(xi-x)-abs(yi-y))%2==1) f=1;
			}
			lt=a;x=xi;y=yi;
		}
		if(f==1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}


