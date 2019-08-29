#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e9+7;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f;
}
bool yin[105][105];
bool yang[105][105];
int a[1005];
signed main()
{
    freopen("refrain.in","r",stdin);
    freopen("refrain.out","w",stdout);
	int num,n,m,mp;
	num=read();
	n=read();
	m=read();
	mp=read();
	int dapang=1;
	for(int i=1;i<=n;i++) dapang*=i,dapang%=Mod;
	if(num<=6)
		{
			for(int i=1;i<=m;i++)
				{
					int x,y;
					x=read();
					y=read();
					yin[x][y]=1;
					yin[y][x]=1;
				}
			for(int i=1;i<=mp;i++)
				{
					int x,y;
					x=read();
					y=read();
					yang[x][y]=1;
					yang[y][x]=1;
				}
			for(int i=1;i<=n;i++) a[i]=i;
			int ans=0;
			do{
				bool flag=1;
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
						if(yin[i][j]==1&&yin[a[i]][a[j]]==0 || yang[i][j]==1&&yang[a[i]][a[j]]==0)
							{
								flag=0;
								break;
							}
					if(!flag) break;
				}
				ans+=flag;
				ans%=Mod;
			}while(next_permutation(a+1,a+n+1));
			cout<<(dapang+Mod-ans)%Mod<<endl;
		}
	else
		{
			int ans=1;
			for(int i=1;i<=m;i++)
				{
					ans=ans*i;
					ans=ans*2;
					ans%=Mod;
				}
			for(int j=1;j<mp;j++)
				{
					ans=ans*j;
					ans=ans*2;
					ans%=Mod;
				}
			ans%=Mod;
			cout<<(dapang+Mod-ans)%Mod<<endl;
		}
	return 0;
}
/*
3
3 1 1
1 2
2 3
*/
