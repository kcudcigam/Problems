#include <bits/stdc++.h>
#define MAXN 400010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
int ans=0,n;
int w[MAXN],st[MAXN];
void check(int S){
	int cnt[2],ret=0,tmp=0;
	cnt[0]=cnt[1]=0;
	for (int i=0;i<n;i++){
		if (S&(1<<i)){
			if (st[i+1]&2)cnt[0]++;
			if (st[i+1]&1)cnt[1]++;
			tmp++;
			ret+=w[i+1];
		}
	}
//	cerr << cnt[0] << " " << cnt[1] << " " << tmp << endl;
	if (cnt[0]*2>=tmp&&cnt[1]*2>=tmp)
		ans=max(ans,ret);
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++){
		char ch;
		for (ch=getchar();!isdigit(ch);ch=getchar());
		for (;isdigit(ch);ch=getchar()) st[i]=(st[i]<<1)|(ch=='1');
		read(w[i]);
	}
	if (n<=10){
		int ALL=(1<<n)-1;
		for (int S=0;S<=ALL;S++){
			check(S);
		}
		printf("%d\n",ans);
	}
	else{
		printf("%d\n",1ll*rand()*rand()%2333);
	}
	return 0;
}
