#include<bits/stdc++.h>
#include<cctype>
#include<vector>
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
const int maxn=7000;
vector<int>sonnum[maxn],ba[maxn],baci[maxn],son[maxn],jia[maxn],jiaci[maxn],jiasum[maxn];
int ans[maxn],n,m,i,j,k,l,s,d,faa,fab,f,cnt,okle,r,fa[maxn];
void shuchu(int x){
	int tt=0,s=0,t=x;
	while(t!=0){
		tt=tt*10+t%10;
		t=t/10;
	}
	while(tt!=0){
		printf("%d",(tt%10));
		tt=tt/10;
	}
	printf(" ");
	return;
}
int zhao(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=zhao(fa[x]);
	return fa[x];
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	memset(ans,0,sizeof(ans));
	cnt=0;
	for(i=1;i<=m;i++){
		l=read();f=read();r=read();
		if(l==1){
			faa=zhao(f);
			fab=zhao(r);
			if(faa==fab){
				continue;
			}
			fa[faa]=fab;
			if(!son[faa].empty()){
				for(j=0;j<=son[faa].size();j++){
					son[fab].push_back(son[faa][j]);
					ba[son[faa][j]].push_back(fab);
					baci[son[faa][j]].push_back(cnt);
					sonnum[fab].push_back(ba[son[faa][j]].size()-1);
				}
			}
			son[fab].push_back(faa);
			ba[faa].push_back(fab);
			baci[faa].push_back(cnt);
			sonnum[fab].push_back(ba[faa].size()-1);
		}
		else{
			faa=zhao(f);
			jia[faa].push_back(r);
			jiaci[faa].push_back(cnt);
			ans[faa]+=r;
			cnt++;
		}
	}
//	cout<<"OK1"<<endl;
	for(i=1;i<=n;i++){
		if(!jia[i].empty()){
			jiasum[i].push_back(jia[i][0]);
			for(j=1;j<jia[i].size();j++){
				jiasum[i].push_back(jiasum[i][j-1]+jia[i][j]);
			}
		}
	}
	//cout<<"OK2"<<endl;
	for(i=1;i<=n;i++){
		if(!son[i].empty()){
			for(j=0;j<son[i].size();j++){
				okle=0;
				//cout<<"OK1.1"<<endl;
				for(k=0;k<jia[i].size();k++){
					if(jiaci[i][k]>=baci[son[i][j]][sonnum[i][j]]){
						okle=k;
						break;
					}
				}
				//cout<<"OK1.2"<<endl;
				if(okle==0){
					ans[son[i][j]]+=jiasum[i][jiasum[i].size()-1];
				}
				else{
					ans[son[i][j]]+=jiasum[i][jiasum[i].size()-1]-jiasum[i][okle-1];
				}
				//cout<<"OK1.3"<<endl;
			}
		}
		//cout<<i<<endl;
	}
	//cout<<"OK3"<<endl;
	for(i=1;i<=n;i++){
		shuchu(ans[i]);
	}
	cout<<endl;
	return 0;
}


