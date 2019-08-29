#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long  n,m;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	long long  maxx=-INT_MAX;
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	long long  s1=0;
	for (int i=1;i<=n;i++)
	{
		s1=s1+a[i];
		if (s1<0) s1=0;
		maxx=max(s1,maxx);
			long long  s2=0;
	long long maxy=-INT_MAX;
		for (int j=n;j>=i+1;j--)
		{
			s2=s2+a[j];
		if (s2<0) s2=0;
	    maxx=max(maxx,s1+s2);
		}
	}
	cout<<maxx<<endl;
	return 0;
}


