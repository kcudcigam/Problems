#include<bits/stdc++.h>
using namespace std;
int maxd;
bool can=false;
//Ï²»¶µÄÊý
int cnt=0;
long long like[3000];
int a[10];
bool check(long long num){
	int cnts=0;
	memset(a,0,sizeof(a));
	while(num){
		int p=num%10;num/=10;
		if(!a[p]){
			if(cnts>=2)return false;
			a[p]=true,cnts++;
		}
	}
	return true;
}
void dfs(int x,long long left){
	if(x==maxd){
		can=check(left);
		return;
	}
	for(int i=1;i<=cnt && left>=like[i]*(maxd-x) && !can;++i)
		dfs(x+1,left-like[i]);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=300000;++i)
		if(check(i))like[++cnt]=i;
	int T;
	cin>>T;
	while(T--){
		can=false;
		long long n;
		cin>>n;
		for(maxd=1;maxd<=3 && !can;++maxd)
			dfs(1,n);
		cout<<--maxd<<endl;
	}
	return 0;
}
