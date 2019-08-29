#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[500010],b[500010];
int ri() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
inline bool check(int now,int la,int ra,int lb,int rb){
	int ans1=now-la+1;
	int pos=lower_bound(b+lb,b+rb+1,a[now])-b;
	if(a[now]!=b[pos]){
		pos--;
	}
	int ans2=pos-lb+1,len=rb-lb+1+ra-la+1;
	if(ans1+ans2>=(len+1)/2){
		return true;
	}
	else {
		return false;
	}
}
inline bool check1(int now,int la,int ra,int lb,int rb){
	int ans1=now-lb+1;
	int pos=lower_bound(a+la,a+ra+1,b[now])-a;
	if(b[now]!=a[pos]){
		pos--;
	}
	int ans2=pos-la+1,len=rb-lb+1+ra-la+1;
	if(ans1+ans2>=(len+1)/2){
		return true;
	}
	else {
		return false;
	}
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();
	m=ri();
	for(register int i=1;i<=n;i++){
		a[i]=ri();
	}
	for(register int i=1;i<=n;i++){
		b[i]=ri();
	}
	for(register int i=1;i<=m;i++){
		int opt;
		opt=ri();
		if(opt==1){
			int x,y,z;
			x=ri();
			y=ri();
			z=ri();
			if(x==0){
				a[y]=z;
			}
			else {
				b[y]=z;
			}
		}
		else {
			int la,lb,ra,rb;
			la=ri();ra=ri();
			lb=ri();rb=ri();
			int l=la,r=ra,ans;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid,la,ra,lb,rb)){
					ans=mid;
					r=mid-1;
				}
				else {
					l=mid+1;
				}
			}
			int len=rb-lb+1+ra-la+1;
			
			int pos=lower_bound(b+lb,b+rb+1,a[ans])-b;
			if(a[ans]!=b[pos]) pos--;
			if(ans-la+1+pos-lb+1==(len+1)/2){
				printf("%d\n",a[ans]);
			}
			else {
				l=lb,r=rb;
				while(l<=r){
					int mid=(l+r)>>1;
					if(check1(mid,la,ra,lb,rb)){
						ans=mid;
						r=mid-1;
					}
					else {
						l=mid+1;
					}
				}
				printf("%d\n",b[ans]);
			}
		}
	}
} 
