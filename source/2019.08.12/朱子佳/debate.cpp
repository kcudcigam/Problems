#include<bits/stdc++.h>
using namespace std;
int maxn=-1,r[400001],n,r1[400001];
char a[400001],b[400001];
void dfs(int dep,int hy,int za,int zb,int zg){
	if(dep>n){
		if(hy>maxn){
			if(za*2>=zg&&zb*2>=zg){
				maxn=hy;	
			}

		}
		return ;
	}
	dfs(dep+1,hy+r[dep],za+a[dep]-48,zb+b[dep]-48,zg+1);
	dfs(dep+1,hy,za,zb,zg);
	return ;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int b1=0,z1=0,z2=0,z3=0,ans=0,ans1=0,zh=0;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		a[i]=getchar();
		b[i]=getchar();
		cin>>r[i];
		if(r[i]!=r[i-1]&&i>=2){
			b1=1;
		}
		if(a[i]=='1'&&b[i]=='1'){
			ans1+=r[i];
			z3++;
		}
		if(a[i]=='1'){
			z1++;
		}
		if(b[i]=='1'){
			z2++;
		}
		getchar();
	}
	if(n<=25){
		dfs(1,0,0,0,0);
		cout<<maxn<<endl;
		return 0;
	}
	if(!b1){
		int z=min(z1-z3,z2-z3);
		cout<<(z*2+z3+min(z3,n-z1-z2+z3))*r[1]<<endl;
	}else{
		if(z3*2>=n){
			for(int i=1;i<=n;i++){
				ans+=r[i];
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]=='0'){
					zh++;
					r1[zh]=r[i];
				}
			}
			sort(r1+1,r1+zh+1);
			for(int i=zh;i>=zh-z3+1;i--){
				ans1+=r1[i];
			}
			cout<<ans1<<endl;
		}
	}
	return 0;
}


