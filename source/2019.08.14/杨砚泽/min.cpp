#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}int n,a,b,c,d;
inline long long calc(int x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
struct node{
	int l;
	int r;
	long long num;
	long long tot;
};
node f[200051];
long long g[100051];
inline long long build(int dep,int lf,int rt)
{
	int mid=lf+rt>>1;
	f[dep].l=lf;
	f[dep].r=rt;
	if (lf==rt) {f[dep].num=g[lf];
      f[dep].tot=calc(f[dep].num);
      return f[dep].num;
	}
	else {
		f[dep].num=min(build(dep*2,lf,mid),build(dep*2+1,mid+1,rt));
		f[dep].tot=calc(f[dep].num);
		return f[dep].num;
	}
}
inline long long fnd(int dep)
{
	if (f[dep].l==f[dep].r) return f[dep].tot;
	else return f[dep].tot=max(f[dep].tot,fnd(dep*2)+fnd(dep*2+1));
}
long long dp[151][151];
inline int fond(int dep,int le,int rt)
{
	if (le<=f[dep].l&&rt>=f[dep].r) return f[dep].num;
	int mid=f[dep].l+f[dep].r>>1;
	if (rt<=mid) return fond(dep*2,le,rt);
	else if (le>mid) return fond(dep*2+1,le,rt);
    else return min(fond(dep*2,le,mid),fond(dep*2+1,mid+1,rt));
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    read(n);read(a);read(b);read(c);read(d);
    long long opt=0;
	for (int i=1;i<=n;i++)
      {
      	read(g[i]);
      	opt+=calc(g[i]);
   }
   	memset(f,0,sizeof(f));
    build(1,1,n);
    cout<<max(opt,fnd(1))<<endl;
	return 0;
}

