#include<bits/stdc++.h>
#include<cctype>
using namespace std;
inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
vector<int>a[200005],b[200005];
priority_queue<pair<long long,int> >q;
long long ans,h[200005],dist[200005];
int ruizhi,n,m,i,j,k,l,s,d,f,r,frodist[200005],ladist[200005],fro[200005],lafro[200005];
void spfa(){
	memset(dist,0x3f3f3f,sizeof(dist));
	memset(fro,0,sizeof(fro));
	memset(lafro,0,sizeof(lafro));
	memset(frodist,0,sizeof(frodist));
	memset(ladist,0,sizeof(ladist));
	dist[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		long long x=q.top().second;
		q.pop();
		if(h[x]){
			continue;
		}
		h[x]=1;
		for(int i=0;i<a[x].size();i++){
			int y=a[x][i];
			if(dist[y]>dist[x]+b[x][i]){
				dist[y]=dist[x]+b[x][i];
				lafro[y]=fro[y];
				ladist[y]=frodist[y];
				fro[y]=x;
				frodist[y]=b[x][i];
				q.push((make_pair(-dist[y],y)));
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	ruizhi=read();
	n=read();m=read();
	for(i=1;i<=m;i++){
		f=read();r=read();l=read();
		if(f==r){
			continue;
		}
		a[f].push_back(r);
		a[r].push_back(f);
		b[f].push_back(l);
		b[r].push_back(l);
	}
	memset(h,0,sizeof(h));
	spfa();
	/*for(i=1;i<=n;i++){
		cout<<dist[i]<<" "<<fro[i]<<endl;
	}*/
	cout<<0;
	for(i=2;i<=n;i++){
		if(lafro[i]==0){
			if(a[i].size()==1){
				printf(" -1");
			}
			else{
				ans=0x3f3f3f3f3f;
				for(j=0;j<a[i].size();j++){
					if(fro[a[i][j]]!=i&&lafro[a[i][j]]!=i&&(a[i][j]!=fro[i]||(a[i][j]==fro[i]&&b[i][j]!=frodist[i]))){
						ans=min(ans,dist[a[i][j]]+b[i][j]);
					}
				}
				printf(" %d",ans);
			}
		}
		else{
			printf(" %d",dist[lafro[i]]+ladist[i]);
		}
	}
	return 0;
}

