#include<bits/stdc++.h>
#define int LL
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int SIZ= 1e3;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int ret,w,c;
	while((c=readc())>'9'||c<'0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret;
}
int Y,cnt,cnt_,cnt__,t;
vector <int> edg[2];
signed main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	t=Y=qread();
	while(t) cnt++,t>>=1; cnt++;
	up(1,cnt,i) up(i+1,cnt,j)
	edg[0].push_back(i),edg[1].push_back(j),cnt__++;
	t=Y,cnt_=2;
	while(t){
		if(t&1) edg[0].push_back(cnt_),edg[1].push_back(cnt+1),cnt__++;
		t>>=1,cnt_++;
	}
	printf("%lld %lld\n",cnt+1,cnt__);
	up(1,cnt__,i) printf("%lld %lld\n",edg[0][i-1],edg[1][i-1]);
	return 0;
} 
