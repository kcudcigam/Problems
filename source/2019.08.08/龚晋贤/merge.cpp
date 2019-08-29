#include<bits/stdc++.h>
using namespace std;
int n,f[500005],l[500005],s[500005],m,i,j,c,x,y;
vector<int> r[500005];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
} 
int g(int n)
{
	if (f[n]==n) return n;
	return g(f[n]);
}
void jj(int n,int k)
{
	s[n]+=k;
	for (int i=0;i<r[n].size();i++)
	jj(r[n][i],k);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	f[i]=i;
	for (i=1;i<=m;i++)
	{
		cin>>c>>x>>y;
		if (c==2) {
			jj(g(x),y);
		}
		else {
			if (g(x)!=g(y)) {
			r[g(y)].push_back(g(x));
			f[g(x)]=g(y);
		    }
		}
	}
	for (i=1;i<=n;i++)
	{
	cout<<s[i]<<' ';
    }
	return 0;
}
/*
4 6
2 1 1
1 1 4
1 2 4
2 2 2
1 3 4
2 4 1
*/


