#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010];
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		ll l=read(),r=read(),s=read(),e=read();
		ll gongcha=(e-s)/(r-l);
		ll pos=l,cnt=gongcha+s;
		a[l]+=s;
		while(pos<r){
			a[++pos]+=cnt;
			cnt+=gongcha;
		}
	}
	ll ans=a[1];
	for(int i=2;i<=n;i++)ans=ans^a[i];
	printf("%d\n",ans);
	return 0;
}


