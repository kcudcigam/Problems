#include<bits/stdc++.h>
using namespace std;
vector<long long>a[200001][3];
long long shor[200001];
long long ans[200001];
long long qu[200001];
long long vis[200001];
long long ge[200001];
void read(long long &x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
		ch=getchar();
		if(ch=='-')f=-1;
	}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    x*=f;
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	
	int num;
	cin>>num;
	int n,m;
	cin>>n>>m;
	long long x,y,len;
	for(int i=2;i<=n;i++){
		shor[i]=1152921504606847089;
		ans[i]=1152921504606847089;
	}
	for(int i=1;i<=m;i++){
		read(x);read(y);read(len);
		a[x][0].push_back(y);
		a[x][1].push_back(len);
		a[x][2].push_back(i);
		a[y][0].push_back(x);
		a[y][1].push_back(len);
		a[y][2].push_back(i);
	}
	int f=0,r=1;qu[1]=1;int pd;int t;
	while(f<r){
		f++;
		for(int i=0;i<a[qu[f]][1].size();i++){
			if(a[qu[f]][1][i]+shor[qu[f]]<shor[a[qu[f]][0][i]]){
				shor[a[qu[f]][0][i]]=a[qu[f]][1][i]+shor[qu[f]];
				r++;qu[r]=a[qu[f]][0][i];ge[a[qu[f]][0][i]]=a[qu[f]][2][i];vis[qu[r]]=qu[f];
			}
			if(a[qu[f]][1][i]+shor[qu[f]]<ans[a[qu[f]][0][i]]&&ge[a[qu[f]][0][i]]!=a[qu[f]][2][i]){
				pd=qu[f];t=0;
				while(vis[pd]){
					pd=vis[pd];
					if(pd==a[qu[f]][0][i]){
						t=1;break;
					}
				}
				if(t==0){
					ans[a[qu[f]][0][i]]=a[qu[f]][1][i]+shor[qu[f]];
					r++;qu[r]=a[qu[f]][0][i];
			}
				if(t==1&&vis[qu[f]]!=a[qu[f]][0][i]){
					ans[a[qu[f]][0][i]]=min(ans[a[qu[f]][0][i]],a[qu[f]][1][i]+ans[qu[f]]);
					r++;qu[r]=a[qu[f]][0][i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",ans[i]==1152921504606847089?-1:ans[i]);
	}
	return 0;
}
/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/

