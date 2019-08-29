#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
long long logg[200010],f[200010][30],fi[200010];
long long a,b,c,d,ai[200010];
long long g(long long x){return a*x*x*x+b*x*x+c*x+d;}
long long mini(int ll,int rr)
{
	long long si=logg[rr-ll+1];
	return min(f[ll][si],f[rr-(1<<si)+1][si]);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int n;
	read(n),read(a),read(b),read(c),read(d);
	for(int i=1;i<=n;i++)
		read(ai[i]),fi[i]=LONG_LONG_MIN;
	logg[0]=-1;
	for(int i=1;i<=n;i++)
		f[i][0]=ai[i],logg[i]=logg[i>>1]+1;
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	fi[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			fi[i]=max(fi[i],fi[j]+g(mini(j+1,i)));
	cout<<fi[n]<<endl;
	return 0;
}


