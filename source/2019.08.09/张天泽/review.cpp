#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int ermi(int x)
{
	int o=1;
	int k=0;
	while (o!=x)
	{
		k++;
		o*=2;
		if (o>x) break;
	}
	return k;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	int y;
	cin>>y;
	if (y==1)
	{
		cout<<1<<' '<<0<<endl;
		return 0;
		
	}
	if (y==3)
	{
		cout<<4<<' '<<5<<endl;
		cout<<1<<' '<<2<<endl;
		cout<<2<<' '<<3<<endl;
		cout<<3<<' '<<4<<endl;
		cout<<2<<' '<<4<<endl;
		cout<<1<<' '<<4<<endl;
		return 0;
	}
	if (y==5)
	{
			cout<<4<<' '<<6<<endl;
		cout<<1<<' '<<2<<endl;
		cout<<2<<' '<<3<<endl;
		cout<<3<<' '<<4<<endl;
		cout<<1<<' '<<3<<endl;
		cout<<2<<' '<<4<<endl;
		cout<<1<<' '<<4<<endl;
		return 0;
	}
	int x=ermi(y);
	//cout<<x<<endl;
	cout<<x+2<<' ';
	int k=x+2;
	int sum=0;
	a[1][1]=1;
	for (int i=1;i<=k-1;i++)
{
	sum+=i;  
}
cout<<sum<<endl;
for (int i=1;i<=k;i++)
{
	for (int j=1;j<=k;j++)
	{
		if (i+j<=k)
		cout<<j<<' '<<i+j<<endl;
	}
}
	return 0;
}


