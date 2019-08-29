#include<bits/stdc++.h>
#define N 5000
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}
int n,s,t;
ll x;
struct node{
	int u,v;
};
int len;
node ans[N];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(x);
	while (x){
		if (x&1){
			ans[++len].u=1;
			ans[len].v=s;
		}
		x>>=1;
		++s;
	}
	for (int i=1;i<=len;i++) ans[i].v=s+1-ans[i].v;
	for (int i=2;i<=s+1;i++)
		for (int j=i+1;j<=s+2;j++){
			ans[++len].u=i;
			ans[len].v=j;
		}
	printf("%d %d\n",s+2,len);
	for (int i=1;i<=len;i++) printf("%d %d\n",ans[i].u,ans[i].v);
	return 0;
}

