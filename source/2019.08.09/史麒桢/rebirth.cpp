#include<bits/stdc++.h>
using namespace std;
int g[1111][1111];
int x[2222],y[2222],l[2222];
int reads(void){
	int f=1;
	int x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
		   f=-1;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
	return x;
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int N=reads();
	int n=reads();
	int m=reads();
	memset(g,0,sizeof(g));
	for (int i=1;i<=m;i++){
		x[i]=reads();
		y[i]=reads();
		l[i]=reads();
	}
	if (N>7){
		cout<<0<<" ";
		for (int i=2;i<n;i++){
			cout<<-1<<" ";
		}
		cout<<-1<<endl;
		return 0;
	}
	cout<<0;
	for (int ii=2;ii<=n;ii++){
		int ans=0;
		for (int kk=1;kk<=m;kk++){
			memset(g,0,sizeof(g));
			for (int ik=1;ik<=m;ik++){
				if (ik!=kk){
					if (g[x[ik]][y[ik]]){
						if (g[x[ik]][y[ik]]<l[ik]){
							g[x[ik]][y[ik]]=l[ik];
							g[y[ik]][x[ik]]=l[ik];
						}
					}
					else {
						g[x[ik]][y[ik]]=l[ik];
						g[y[ik]][x[ik]]=l[ik];
					}
				}
			}
			for (int k=1;k<=n;k++){
				for (int i=1;i<=n;i++){
					for (int j=1;j<=n;j++){
						if ((i!=k)&&(j!=k)&&(i!=k)){
							if (g[i][j]>0&&g[i][k]>0&&g[k][j]>0){
								if (g[i][k]+g[k][j]<g[i][j]){
									g[i][j]=g[i][k]+g[k][j];
								}
							}
						}
					}
				}
			}
			ans=max(ans,g[ii][1]);
			if (g[ii][1]==0){
				ans=-1;
				break;
			}
		}
		cout<<" "<<ans;
	}
	cout<<endl;
	return 0;
}


