#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > t;
long long a,n[100010],s[100010],p,pp,h,hh,maxi,ss,hhh;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);
	for (int i=1;i<=a;i++) 
	{
		read(n[i]);
		s[i]=s[i-1]+n[i];
	}
	h=0;hh=0;maxi=-2147483647;
	for (int i=1;i<=a;i++)
	{
		if (s[i]-s[h]>maxi)
		{
			maxi=s[i]-s[h];
			hh=i;hhh=h; 
		}
		if (s[i]<s[h]) h=i;	
	}
	ss=maxi;
	p=0;pp=0;maxi=-2147483647;
	for (int i=1;i<=hhh;i++)
	{
		if (s[i]-s[p]>maxi)
		{
			maxi=s[i]-s[p];
			pp=i;
		}
		if (s[i]<s[p]) p=i;	
	}	
	p=0;pp=0;
	for (int i=hh+1;i<=a;i++)
	{
		if (s[i]-s[p]>maxi)
		{
			maxi=s[i]-s[p];
			pp=i;
		}
		if (s[i]<s[p]) p=i;	
	}
	cout<<ss+maxi<<endl;
	return 0;
}


