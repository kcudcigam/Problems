#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int q;
LL n,p,ans;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>q;
	for (;q>0;--q){
		cin>>n>>p;
		ans=0ll;
		for (LL i=1;i<=n;++i)
			if ((i%2ll)==0ll) ans=(ans*i+i*(i-1ll)-i+2ll)%p;
				else ans=(ans*i+i*(i-1))%p;
		cout<<ans<<'\n';
	}
	return 0;
}
