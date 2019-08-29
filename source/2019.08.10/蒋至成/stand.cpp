#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
	int l,r;
};
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
node a[301];
bool sta[101];
int g[6],d[101];
vector <int> s[101] ;
bool cmp(node A,node B){
	return A.l<B.l;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=5;++i)read(g[i]);
	for(int i=1;i<=n;++i){
	read(a[i].l);
	read(a[i].r);
	if(a[i].l>a[i].r)swap(a[i].l,a[i].r);
	}
	stable_sort(a+1,a+n+1,cmp);
	int coun=0;
	while(coun<n){
		for(int i=1;i<=100;++i){d[i]=0;s[i].clear();}
		int maxn=0,cc=0;
		for(int i=1;i<=n;++i){
			if(sta[i])continue;
			for(int j=a[i].l;j<=a[i].r;++j){
			d[j]++;
			s[j].push_back(i);
			if(d[j]>maxn){
				maxn=d[j];
				cc=j;
			}
			}
		}
		coun+=d[cc];
		for(int i=0;i<s[cc].size();++i)sta[s[cc][i]]=1;
		for(int i=1;i<=5;++i){
			if(g[i]==0)continue;
			int x=1,ci=1;
			while(ci<=i){
				x*=d[cc];
				ci++;
			}
			ans+=(x*g[i]); 
		}
	}
	cout<<ans;
	return 0;
}


