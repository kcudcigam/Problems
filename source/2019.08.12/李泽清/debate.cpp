#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int N=800010;
int n,cnt,mm;
LL ans,anss;
char s[100];
int p1[N],p2[N],p0[N];
int r1,r2,r0,pt;
int h[1000000];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	F(i,1,n){
		int x;
		cin>>s>>x;
		if(s[0]=='1'&&s[1]=='1'){
			ans+=x;++cnt;
			continue;
		}
		p0[++r0]=x;
		if(s[0]=='1')p1[++r1]=x;
		if(s[1]=='1')p2[++r2]=x;
	}
	sort(p1+1,p1+r1+1,cmp);
	sort(p2+1,p2+r2+1,cmp);
	sort(p0+1,p0+r0+1,cmp);
	int ma=min(r1,r2);
	F(i,1,ma){
		++h[p1[i]];
		++h[p2[i]];
		ans+=p1[i]+p2[i];
	}
	int pt=0;
	while(cnt){
		++pt;
		if(h[p0[pt]]){--h[p0[pt]];continue;}
		--cnt;ans+=p0[pt];
	}
	cout<<ans<<'\n';
	return 0;
}
