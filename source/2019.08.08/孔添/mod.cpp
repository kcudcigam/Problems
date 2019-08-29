#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],h[100],last[100];
long long p,w;
void dfs(int dep){
	if(dep==n+1){
		int tot=0;
		if(m>=1){
			for(int i=1;i<=n;++i){
				if(last[i]!=a[i])
					tot++;
			}
			//cout<<tot;
			w=(w+tot)%p;
		};
		m++;
		for(int i=1;i<=n;++i){
			last[i]=a[i];
		}
			
		
		return;
	}
	for(int i=1;i<=n;++i){
		if(!h[i]){
			h[i]=1;
			a[dep]=i;
			dfs(dep+1);
			h[i]=0;
		}
	}
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	cin>>q;
	for(int i=1;i<=q;++i){
		m=0;w=0;
		cin>>n>>p;
		dfs(1);
		cout<<w<<endl;
	}

	
	return 0;
}

