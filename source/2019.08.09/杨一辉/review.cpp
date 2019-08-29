#include<bits/stdc++.h>
using namespace std;
long long y;
long long b[65];
long long sum;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	if(y>1000&&y<=1000000000)
	{
		b[1]=1;b[2]=1;sum=1;
		for(int i=3;i<=64;i++)
		{
			sum+=i-1;
			b[i]=b[i-1]*2;
			if(b[i]==y)
			{
				cout<<i<<" "<<sum<<endl;
				for(int j=1;j<=i;j++)
				for(int k=j+1;k<=i;k++)cout<<j<<" "<<k<<endl;
				break;
			}
		}
	}
	else
	{
		cout<<y+1<<" "<<2*y-1<<endl;
		for(int i=2;i<=y;i++)
		{
			cout<<1<<" "<<i<<endl;
			cout<<i<<" "<<y+1<<endl;
		}
		cout<<1<<" "<<y+1<<endl;
	}
	return 0;
}

