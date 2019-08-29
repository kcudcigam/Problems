#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
int g[10],a[10000010][3],vis[10000010],c[10000010];
long long cal(int x){
	return x*g[1]+x*x*g[2]+x*x*x*g[3]+x*x*x*x*g[4]+x*x*x*x*x*g[5];
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=5;i++)cin>>g[i];
	for(int i=1;i<=m;i++){
		cin>>a[i][0]>>a[i][1];
	}
	int nn=m,maxi=0;
	while(nn>0){
		for(int i=0;i<=m+10;i++)c[i]=0;
		int now=0;int maxn=0;
		for(int i=1;i<=m;i++){
			if((a[i][0]<=maxi&&a[i][1]>=maxi)&&maxi!=0){
				vis[i]=1;
			}
			if(!vis[i]){
				c[a[i][0]]++;c[a[i][1]+1]--;
			}
		}
		for(int i=1;i<=n;i++){
			now+=c[i];
			if(now>maxn){
				maxn=now;maxi=i;
			}
		}
		int x=maxn;
		nn-=x;
		ans+=cal(x);
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 10
0 1 0 0 0
1 3
3 5
2 7
6 10


5 8
0 0 1 0 0
1 4
6 7
7 8
2 3
8 8

4 20
1 1 0 0 0
1 10
1 10
1 10
1 10
*/


