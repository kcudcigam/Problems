#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a);
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+20;
int n,m;
LL p[M];
void add(int l,int r,LL d){
	p[l]+=d;
	p[r+1]-=d;
}
void out(){
	LL tmp=0;
	F(i,1,n) cout<<(tmp+=p[i])<<" GG\n";
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(); m=read();
	while (m--){
		int l=read(),r=read();
		LL s=read(),e=read();
		add(l,l,s); add(r+1,r+1,-s);
		if (l!=r) add(l+1,r,(e-s)/(r-l)),add(r+1,r+1,s-e);
//		out(); cout<<"\n";
	}
	LL ans=0;
	F(i,1,n) p[i]+=p[i-1];
	F(i,1,n) {
		p[i]+=p[i-1];
//		cout<<p[i]<<"    ggg\n";
		ans^=p[i];	
	}
	cout<<ans<<"\n";
//	cout<<LONG_LONG_MAX<<"\n";
	return 0;
}


