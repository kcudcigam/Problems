#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &FF)
{
	FF=0;int RR=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') RR=-1;else FF=(CH^48);CH=getchar();
	while(isdigit(CH)) FF=(FF<<1)+(FF<<3)+(CH^48),CH=getchar();FF*=RR;
}
#define mod 1000000007
int way[1010][1010];
int ai[1010],flag[1010];
long long jc[51]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,227020758,178290591,674358851,789741546,425606191,660911389,557316307,146326063,72847302,602640637,860734560,657629300,440732388,459042011,394134213,35757887,36978716,109361473,390205642,486580460,57155068,943272305,14530444,523095984,354551275,472948359,444985875,799434881,776829897,626855450,954784168,10503098,472639410,741412713,846397273,627068824,726372166,318608048};
int num,n,m1,m2,u,v;
long long ans;
void dfs(int step)
{
	if(step==n+1) return;
	for(int i=1;i<=n;i++)
		if(!flag[i])
		{
			int fl=0;
			for(int j=1;j<=step-1;j++)
				if(way[step][j]!=way[i][ai[j]])
				{
					ans=(ans+jc[n-step])%mod; fl=1; break;
				}
			if(fl) continue;
			flag[i]=1,ai[step]=i,dfs(step+1),flag[i]=0;
		}
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num);
	read(n),read(m1),read(m2);
	for(int i=1;i<=m1;i++)
		read(u),read(v),way[u][v]=way[v][u]=1;
	for(int i=1;i<=m2;i++)
		read(u),read(v),way[v][u]=way[u][v]=-1;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

