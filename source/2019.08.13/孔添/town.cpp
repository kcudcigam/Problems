#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> a[300010];//жу╣Ц 
int f[300010];
bool h[300010];
void deal(int st){
	vector< int > v=a[st];
	while(!v.empty()){
		int ed=v.back();
		if(h[ed]==false){
			h[ed]=true;
			if(f[ed]<f[st]+1){
				f[ed]=f[st]+1;
				deal(ed);
				ans=max(ans,f[ed]);
			}
			
		}
		v.pop_back();
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	int x,y;
	for(int i=1;i<n;++i){
		memset(h,false,sizeof(h));
		scanf("%d%d",&x,&y);
		int p=f[x];
		ans=max(f[x],f[y]);
		if(f[x]<f[y]+1){
			f[x]=f[y]+1;
			h[x]=true;
			ans=max(f[x],ans);
			deal(x);
		}
		if(f[y]<p+1){
			f[y]=p+1;
			h[y]=true;
			ans=max(ans,f[y]);
			deal(y);
		}
		printf("%d\n",ans);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	return 0;
}
