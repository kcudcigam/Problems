#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
int f[10],num[10000010];
pii r[300];
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=5;i++)f[i]=read();
	for(int i=1;i<=n;i++){
		int L=read(),R=read();
		r[i]=make_pair(L,R);
	}
	sort(r+1,r+n+1);
	int pos=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(pos<r[i].first){
			pos=r[i].second;
			num[pos]++;
		}
		else {
			int origin=pos;
			pos=min(pos,r[i].second);
			if(origin==pos)num[pos]++;
			else {
				num[pos]=num[origin]+1;
				num[origin]=0;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll cnt=1;
		if(num[i]){
			for(int j=1;j<=5;j++){
				cnt=cnt*num[i];
				ans+=f[j]*cnt;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}



