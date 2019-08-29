#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;++i)
#define dn(r,l,i) for(register int i=r;i>=l;--i)
using namespace std;
typedef long long LL;
const int INF =2147483647;
const int SIZ =1e5;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int ret,w=1,c;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
bool typ;
int n,x,y,t;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	dn(qread(),1,T){
		n=qread(),x=0,y=0,t=0,typ=true;
		up(1,n,i){
			int nt=qread(),nx=qread(),ny=qread();
			if(abs(nx-x)+abs(ny-y)>nt-t) typ=false;
			bool t1=((x&1)==(y&1)),t2=((nx&1)==(ny&1));
			if(((nt-t)&1)==(t1&t2)) typ=false;
			t=nt,x=nx,y=ny;
		}
		puts(typ?"Yes":"No");
	}
	return 0;
}//MMP
