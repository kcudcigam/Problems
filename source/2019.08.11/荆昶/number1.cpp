#include<bits/stdc++.h>
using namespace std;
int a[10];
int d[10];
int ac(int &dd)
{
	int y;
	for(y=0;y<10&&a[y]==0;y++);
	memset(d,0,sizeof(d));
	for(int i=y+1;i<10;i++)
	if(a[i])
	{
		d[i]=i-y;
		y=i;
	}
	int s=0,h[10],da=0;dd=0;
	memset(h,0,sizeof(h));
	for(int i=1;i<10;i++)
	if(d[i]) 
	{
		s++;
		h[d[i]]++;
	}
	for(int i=1;i<10;i++)
	if(da<h[i])
	{
		da=h[i];
		dd=i;
	}
	return s<=1;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		memset(a,0,sizeof(a));
		while(n)
		{
			a[n%10]++;
			n/=10;
		}
		int ch,s=1;
		while(!ac(ch))
		{
			for(int i=1;i<10;i++)
			if(d[i]==ch)
			{
				a[i-d[i]]+=a[i];
				a[i]=0;
			}
			s++;
		}
		cout<<s<<endl;
	}
	return 0;
}

