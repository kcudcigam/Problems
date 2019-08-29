#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =INT_MAX;
const int SIZ =1e3;
const int P   =998244353;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
LL qread(){
	LL w=1,c,ret;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
string s; char c; int n,len,lft,ans,tot;
LL pwr(LL x,int y){
	LL ret=1,t=x;
	if(x==0) return 1;
	while(y){
		if(y&1) ret=ret*t%P;
		t=t*t%P,y>>=1;
	}
	return ret%P;
}
int main(){
	freopen("magic","r",stdin);
	freopen("magic","w",stdout);
	
	n=qread();
	while((c=readc())>='a'&&c<='z') s+=c;
	if(n==1) puts("25"),exit(0);
	len=s.length(),lft=n-len;
	if(n==len) printf("%d\n",(pwr(n,26)-1+P)%P);
	if(n==2) puts("625"),exit(0);
	if(n==3&&len==1) printf("%d\n",(pwr(n,26)-25*25*2-25*2-1+P)%P);
	if(n==3&&len==2&&s[0]==s[1]) printf("%d\n",(pwr(n,26)-25*3-1+P)%P);
	if(n==3&&len==2&&s[0]!=s[1]) printf("%d\n",(pwr(n,26)-25*3-2+P)%P);
	if(n==4&&len==1) printf("%d\n",(pwr(n,26)-25*25*25*2-25*25*3-25*4-1+P)%P);
	if(n==4&&len==1&&s[0]==s[1]) printf("%d\n",(pwr(n,26)-25*25*3-25*4-1+P)%P);
	if(n==4&&len==1&&s[0]!=s[1]) printf("%d\n",(pwr(n,26)-25*25*3-25*4-1+P)%P);
	up(1,n,i) tot=((LL)tot+(LL)25*pwr(26,min(lft-1,n-i)))%P;
	printf("%d\n",(pwr(26,n)-tot+P)%P);
	return 0;
}//mogic
