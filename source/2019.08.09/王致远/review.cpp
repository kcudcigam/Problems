#include<bits/stdc++.h>
using namespace std;
long long a,h,s,t[100010],hh,hhh,l,x[100010],y[100010],w;
bool f;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);s=1;h=0;t[0]=1;
	if (a==1)
	{
		cout<<"2 1"<<endl;
		cout<<"1 2"<<endl;
		return 0;
	}
	s=1;
	for (int i=1;i<64;i++) 
	{
		if (i>2) s=s*2;
		t[i]=t[i-1]*2;
		if (a==s) h=i;
	}
	if (h!=0)
	{
		cout<<h<<' '<<h*(h-1)/2<<endl;
		for (int i=1;i<h;i++)
			for (int j=i+1;j<=h;j++)
			cout<<i<<' '<<j<<endl;
		return 0;
	}
	hh=1000000000;
	l++;x[l]=1;y[l]=hh;s=1;
	for (int i=2;i<hh;i++)
	{
		l++;x[l]=i;y[l]=hh;
		for (int j=1;j<i;j++)
		{
			w=j-2;
			if (w<0) w=0;
			if (s+t[w]>a) break;
			l++;
			x[l]=j;y[l]=i;
			s+=t[w];
			if (s==a) 
			{
				hhh=i;
				break;
			}
		}
		if (s==a) break;
	}
	cout<<hhh+1<<' '<<l<<endl;
	for (int i=1;i<=l;i++)
	if (y[i]==1000000000)
	cout<<x[i]<<' '<<hhh+1<<endl;
	else cout<<x[i]<<' '<<y[i]<<endl;
	return 0;
}


