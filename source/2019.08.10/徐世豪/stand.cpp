#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long ans;
int n,m;
int s[10000009];
int x[10],l[300],r[300],book[300];
int find(int k){
	int i=1,w=1;
	long long t=0;
	while(i<=5){w*=k;t+=w*x[i];i++;}
	return t;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d %d",&x[1],&x[2],&x[3],&x[4],&x[5]);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l[i],&r[i]);
		for(int j=l[i];j<=r[i];j++) s[j]++;
	}
	queue<int>q;
	q.push(1);
	while(q.size()){
		q.pop();
		int t=0,w;
		for(int i=1;i<=m;i++)
			if(t<s[i]){t=s[i];w=i;}
		if(t){
			q.push(w);
			ans+=find(t);
			for(int i=1;i<=n;i++){
				if(l[i]<=w&&w<=r[i]&&!book[i]){
					book[i]=1;
					for(int j=l[i];j<=r[i];j++) s[j]--;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
