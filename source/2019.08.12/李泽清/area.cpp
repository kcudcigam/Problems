#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int N=1101010;
const LL M=2000000000;
const int MAXN=N-10;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int f[50],g[50];
int x,y,mb,fff;
int qx[N],qy[N],ql,qr;
map<LL,bool> ma;
int Gt(int x,int y){
	int fg=0;
	D(i,30,1){
		int now=1<<i;
		if(x>now&&y>now)fg^=1;
		if(x>now)x-=now;
		if(y>now)y-=now;
	}
	//cout<<x<<' '<<y<<'\n';
	if(x==2&&y==2)fg^=1;
	return fg;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	//cerr<<(sizeof(qx)+sizeof(qy))/1024/1024<<'\n';
	x=R();y=R();
	++x;++y;
	mb=Gt(x,y);
	ql=qr=1;qx[1]=x;qy[1]=y;
	ma[x*M+y]=1;
	while(ql<=qr){
		int nx=qx[ql],ny=qy[ql];++ql;
		//cout<<nx<<' '<<ny<<'\n';
		if(nx==1||ny==1){
			fff=1;break;
		}
		if((!ma[(nx-1)*M+ny])&&Gt(nx-1,ny)==mb){
			++qr;
			qx[qr]=nx-1;
			qy[qr]=ny;
			ma[(nx-1)*M+ny]=1;
		}
		if((!ma[(nx+1)*M+ny])&&Gt(nx+1,ny)==mb){
			++qr;
			qx[qr]=nx+1;
			qy[qr]=ny;
			ma[(nx+1)*M+ny]=1;
		}
		if((!ma[(nx)*M+ny-1])&&Gt(nx,ny-1)==mb){
			++qr;
			qx[qr]=nx;
			qy[qr]=ny-1;
			ma[(nx)*M+ny-1]=1;
		}
		if((!ma[(nx)*M+ny+1])&&Gt(nx,ny+1)==mb){
			++qr;
			qx[qr]=nx;
			qy[qr]=ny+1;
			ma[(nx)*M+ny+1]=1;
		}
		if(qr>MAXN)break;
	}
	if(fff)qr=MAXN+1;
	if(qr>MAXN){cout<<"infinity\n";exit(0);}
	cout<<qr<<'\n';
	return 0;
}
