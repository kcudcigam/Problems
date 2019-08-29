#include<bits/stdc++.h>
#define N 300010
#define pb emplace_back
#define mr make_pair
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
struct edge{int x,y,z;}e[N];
struct que{int x,y;}qu[N];
int f[N],m,n,q,an[N],si[N];
vector<int> no;
bool c1(const edge &a,const edge &b){return a.z<b.z;}
int que(int x){if (f[x]!=x)return que(f[x]);return f[x];}
void work(vector<int> no,int l,int r){
	if (no.size()==0) return ;
	if (l==r){
		for (auto i:no) an[i]=e[l].z;
		return ;
	}
	vector<pair<int,int> > la;la.clear();
	vector<int> n1,n2;n1.clear();n2.clear();
	int mid=(l+r)/2;
	for (int i=l;i<=mid;i++){
		int nx=que(e[i].x),ny=que(e[i].y);
		if (nx!=ny){
			if (si[nx]>si[ny]) swap(nx,ny);
			la.pb(mr(nx,ny));
			f[nx]=ny;si[ny]+=si[nx];
		}
	}
	for (auto i:no)if (que(qu[i].x)==que(qu[i].y))n1.pb(i);else n2.pb(i);
	work(n2,mid+1,r);
	for (int i=la.size()-1;i>=0;i--){
		f[la[i].first]=la[i].first;
		si[la[i].second]-=si[la[i].first];
	}
	work(n1,l,mid);
}
int main(){
	freopen("graph20.in","r",stdin);
	freopen("graph20.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;i<=m;i++){scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].z);}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	for (int i=1;i<=q;i++){scanf("%d %d",&qu[i].x,&qu[i].y);no.pb(i);}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	sort(e+1,e+m+1,c1);e[m+1].z=-1;
	for (int i=1;i<=n;i++)f[i]=i,si[i]=1;
	work(no,1,m+1);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	for (int i=1;i<=q;i++)printf("%d\n",an[i]);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}
