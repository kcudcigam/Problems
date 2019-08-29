#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
priority_queue<int,vector<int>,less<int> >h10,h01,h00;
int main(){
	#ifndef lpcak
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	#endif
	int n,ans=0,c11=0;
	ios::sync_with_stdio(0);
	cin>>n;
	F(i,1,n){
		string s;int x;cin>>s>>x;
		if(s=="11")ans+=x,c11++;
		if(s=="10")h10.push(x);if(s=="01")h01.push(x);
		if(s=="00")h00.push(x);
	}
	while(h10.size()&&h01.size())
		ans+=h10.top()+h01.top(),h10.pop(),h01.pop();
	while(h10.size())h00.push(h10.top()),h10.pop();
	while(h01.size())h00.push(h01.top()),h01.pop();
	F(i,1,c11)ans+=h00.top(),h00.pop();
	cout<<ans<<"\n";
	return 0;
}
