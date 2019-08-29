#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
int main(){
	#ifndef lpcak
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	#endif
	int t,n,la=0,cur,x,y,lx=0,ly=0,f=1;
	ios::sync_with_stdio(0);
	cin>>t;
	F(k,1,t){
		cin>>n;la=0;lx=0;ly=0;f=1;
		F(i,1,n){
			cin>>cur>>x>>y;
			if(abs(x-lx)+abs(y-ly)>cur-la)
				{cout<<"No\n";f=0;break;}
			if((abs(x-lx)+abs(y-ly)-(cur-la))&1)
				{cout<<"No\n";f=0;break;}
		}
		if(f)cout<<"Yes\n";
	}
	return 0;
}
