#include<bits/stdc++.h>
using namespace std;
int a,b,l,h;
long long s,ss,mini,t[100010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') x=-x;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	read(a);read(b);l=0;s=1;
	while (a>1)
	{
		if (a%2==1)
		{
			l++;
			t[l]=s;
		}
		s=s*2;
		a=a/2;
	}
	ss=0;
	while ((l+1>b)&&(l>1))
	{
		mini=2147483647;h=0;
		for (int i=2;i<=l;i++)
		if (t[i]-t[i-1]<mini)
		{
			mini=t[i]-t[i-1];
			h=i;
		}
		ss+=mini;
		t[h]=t[h]*2;
		for (int i=h;i<=l;i++)
		t[i-1]=t[i];
		l--;
		sort(t+1,t+l+1);
	}
	if ((l==1)&&(b==1)) ss+=s-t[1];
	cout<<ss<<endl;
	return 0;
}

