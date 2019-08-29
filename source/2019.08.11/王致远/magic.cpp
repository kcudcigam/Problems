#include<bits/stdc++.h>
using namespace std;
long long a,len,t,tt,ttt,tttt,ttttt,ss;
string b;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
long long ksm(long long x,long long y)
{
	long long s=1;
	while (y)
	{
		if (y%2==1) s=(s*x)%998244353;
		x=(x*x)%998244353;
		y=y/2;
	}
	return s;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>a>>b;len=b.size();
	if (a==len)
	tttt=1;
	else
	{
		t=ksm(26,a-len-1);
		tt=(t*51)%998244353;
		ttt=(t*25)%998244353;
		tttt=(tt+(ttt*(len-1)))%998244353;		
	}
	ttttt=ksm(26,a);
	ss=ttttt-tttt;
	while (ss<0) ss+=998244353;
	cout<<ss<<endl;
	return 0;
}


