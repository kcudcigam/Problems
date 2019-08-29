#include<bits/stdc++.h>
using namespace std;

struct node{
	int pos;
	long long dis;
	bool operator < (const node a)const{
		return dis>a.dis;
	}
};
int num,n,m;
int x[500010],y[500010],z[500010],la[200010],k[200010],ll[200010];
long long dis[200010],ans[200010];
vector<int> ne[200010],l[200010],nu[200010];
priority_queue<node> q;

void read(int &x){
	x=0;char h=' ';
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<1)+(x<<3)+h-48;
	return ;
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num;
	read(n);read(m);
	for (int i=1;i<=m;i++){
		read(x[i]);read(y[i]);read(z[i]);
		ne[x[i]].push_back(y[i]);ne[y[i]].push_back(x[i]); 
		l[x[i]].push_back(z[i]);l[y[i]].push_back(z[i]); 
		nu[x[i]].push_back(i);nu[y[i]].push_back(i);  
	}
	for (int i=1;i<=n;i++) dis[i]=1e16,ans[i]=1e16;
	q.push((node){1,0});dis[1]=0;
	while (!q.empty()){
		if (q.top().dis>dis[q.top().pos]) {q.pop();continue;}
		for (int i=0;i<ne[q.top().pos].size();i++)
		if (dis[ne[q.top().pos][i]]>dis[q.top().pos]+l[q.top().pos][i]){
			dis[ne[q.top().pos][i]]=dis[q.top().pos]+l[q.top().pos][i];
			q.push((node){ne[q.top().pos][i],dis[ne[q.top().pos][i]]});
			k[ne[q.top().pos][i]]=nu[q.top().pos][i];
			la[ne[q.top().pos][i]]=q.top().pos;
		}
		q.pop();
	}
	/*for (int i=1;i<=m;i++){
		if (x[i]==y[i]) continue;
		if (k[x[i]]!=i && k[y[i]]!=i) ans[x[i]]=min(ans[x[i]],z[i]+dis[y[i]]);
		if (k[y[i]]!=i && k[x[i]]!=i) ans[y[i]]=min(ans[y[i]],z[i]+dis[x[i]]);
	}*/
	for (int i=1;i<=m;i++){
		if (x[i]==y[i]) continue;
		if (k[x[i]]!=i) {
			int p=0,t=y[i];
			while (0==0) {
				if (la[t]==0) break;
				if (t==x[i]) {p=1;break;}
				t=la[t];
			}
			if (p==0) 
				if (z[i]+dis[y[i]]<ans[x[i]]) ll[x[i]]=y[i],ans[x[i]]=z[i]+dis[y[i]];
			
			
		}
		if (k[y[i]]!=i) {
			int p=0,t=x[i];
			while (0==0) {
				if (la[t]==0) break;
				if (t==y[i]) {p=1;break;}
				t=la[t];
			}
			if (p==0) 
				if (z[i]+dis[x[i]]<ans[y[i]]) ll[y[i]]=x[i],ans[y[i]]=z[i]+dis[x[i]];
		}
	}
	/*for (int i=1;i<=m;i++){
		if (x[i]==y[i]) continue;
		if (k[x[i]]!=i) {
			int p=0,t=y[i],j=0;
			while (0==0) {
				if (ll[t]==0) break;j++;
				if (j>40) break;
				if (t==x[i]) {p=1;break;}
				t=ll[t];
				cout<<t<<' '<<ll[t]<<endl;
			}
			if (p==0) ans[x[i]]=min(ans[x[i]],z[i]+ans[y[i]]);
		}
		if (k[y[i]]!=i) {
			int p=0,t=x[i],j=0;
			while (0==0) {
				if (ll[t]==0) break;j++;
				if (j>20) break;
				if (t==y[i]) {p=1;break;}
				t=ll[t];
			}
			if (p==0) ans[y[i]]=min(ans[y[i]],z[i]+ans[x[i]]);
		}
	}*/
	/*for (int i=1;i<=m;i++){
		if (x[i]==y[i]) continue;
		if (k[x[i]]!=i) ans[x[i]]=min(ans[x[i]],z[i]+ans[y[i]]);
		if (k[y[i]]!=i) ans[y[i]]=min(ans[y[i]],z[i]+ans[x[i]]);
	}*/
	ans[1]=0;
	for (int i=1;i<=n;i++)
	if (ans[i]==1e16) ans[i]=-1;
	for (int i=1;i<n;i++)
	printf("%lld ",ans[i]);
	printf("%lld\n",ans[n]);
	return 0;
}


