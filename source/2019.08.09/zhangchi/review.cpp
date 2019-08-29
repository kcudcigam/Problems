#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=64,M=110000;
pair<int,int> e[M];
int cnt=0,Y;
signed main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	for(int i=2;i<N;i++)
		for(int j=i+1;j<=N;j++)
			e[++cnt]=make_pair(i,j);
	for(int i=2;i<N;i++)
		if(Y&(1ll<<(N-i-1))) e[++cnt]=make_pair(1,i);
	cout<<N<<" "<<cnt<<"\n";
	for(int i=1;i<=cnt;i++)
		cout<<e[i].first<<" "<<e[i].second<<"\n";
	return 0;
}
