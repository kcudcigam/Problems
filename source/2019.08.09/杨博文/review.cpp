#include<bits/stdc++.h>
using namespace std;
long long Y;
int ans,a[1000];
struct edge{
	int x,y;
}b[10000];
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	int len=0;
	while(Y)
	{
		a[++len]=Y&1;
		Y>>=1;
	}
	int n=len+2;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			b[++ans].x=i;
			b[ans].y=j;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i-1])
		{
			b[++ans].x=i;
			b[ans].y=n;
		}
	}
	cout<<n<<" "<<ans<<endl;
	for(int i=1;i<=ans;i++)
	{
		cout<<b[i].x<<" "<<b[i].y<<endl;
	}
	return 0;
} 
