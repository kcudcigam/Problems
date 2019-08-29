#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long q,n,p,ans[16]={0,0,2,12,58,310,1886,13244,106002,954090,9540982,104950912,1259411066};
int main(){
	freopen("mod.in","r",stdin);freopen("mod.out","w",stdout);
	read(q);
	for(int i=1;i<=q;i++){
		read(n),read(p);
		printf("%lld\n",ans[n]%p);
	}
	return 0;
}
