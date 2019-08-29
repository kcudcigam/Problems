#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll q,n,p,ans[3050];
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%lld",&q);
	ans[1]=0;
	ans[2]=2;
	ans[3]=12;
	ans[4]=58;
	ans[5]=310;
	ans[6]=1886;
	ans[7]=13244;
	ans[8]=106002;
	ans[9]=954090;
	ans[10]=9540982;
	while(q--)
	{
		scanf("%lld%lld",&n,&p);
		cout<<(ans[n]%p)<<endl;
	}
	return 0;
}
