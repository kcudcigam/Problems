#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
const int MOD=1e9+7;
inline void add(int &x,int y){x+=y;if(x>=MOD)x-=MOD;}
int num,n,m1,m2,a[11],ans,cnt1[51],cnt2[51];
bool g1[51][51],g2[51][51];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	num=read(),n=read(),m1=read(),m2=read();
	for(int i=1;i<=50;i++)
		for(int j=1;j<=50;j++)g1[i][j]=g2[i][j]=0;
	for(int i=1,x,y;i<=m1;i++)x=read(),y=read(),g1[x][y]=g1[y][x]=1,++cnt1[x],++cnt1[y];
	for(int i=1,x,y;i<=m2;i++)x=read(),y=read(),g2[x][y]=g2[y][x]=1,++cnt2[x],++cnt2[y];
	if(num<=6){
		for(int i=1;i<=n;i++)a[i]=i;
		while(next_permutation(a+1,a+1+n)){
			bool flag=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if((g1[i][j]==0&&g1[a[i]][a[j]])||(g2[i][j]==0&&g2[a[i]][a[j]])){
						flag=1;break;
					}
				}
				if(flag==1)break;
			}
			if(flag==1)add(ans,1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
