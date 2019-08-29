#include<bits/stdc++.h>
using namespace std;
const long long inf=21390621430;
int n,m,num,d;
long long ans;
long long f[200001];
bool h[200001];
vector<pair<int,pair<int,int> > > a[200001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
void spfa(int s){
	for(int i=1;i<=200000;++i)f[i]=inf;	
	memset(h,0,sizeof(h));
	queue<int> q;
	q.push(s);
	h[s]=1;
	f[s]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		h[t]=0;
		for(int i=0;i<a[t].size();++i){
			if(a[t][i].first==d)continue;
			if(f[t]+a[t][i].second.second<f[a[t][i].second.first]){
			f[a[t][i].second.first]=f[t]+a[t][i].second.second;
			if(!h[a[t][i].second.first]){
				q.push(a[t][i].second.first);
				h[a[t][i].second.first]=1;
			}
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(num);read(n);read(m);
	for(int i=1;i<=m;++i){
		int x,y,z;
		read(x);read(y);read(z);
		a[x].push_back(make_pair(i,make_pair(y,z)));
		a[y].push_back(make_pair(i,make_pair(x,z)));
	}
	for(int i=1;i<=n;++i){
		if(i==1){cout<<0<<' ';continue;}
		ans=0;
		for(int j=0;j<a[i].size();++j){
			d=a[i][j].first;
			spfa(i);
			if(f[1]==inf){
				ans=-1;
				break; 
			}
			ans=max(ans,f[1]);
		}
		printf("%lld ",ans);
	}
	return 0;
}


