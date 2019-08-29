#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int col[32]={0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7};
int lc[32]={0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6};
int rc[32]={0,3,2,5,4,3,2,1,6,5,4,3,2,1,6,5,4,3,2,7,6,5,4,3,2,7,6,5,4,3,6,5};
int area[8][8]={
{0,0,0,0,0,0,0,0},
{0,1,2,4,5,6,10,11},
{0,3,4,8,9,10,14,15},
{0,6,7,11,12,13,17,18},
{0,10,11,15,16,17,21,22},
{0,14,15,19,20,21,25,26},
{0,17,18,22,23,24,28,29},
{0,21,22,26,27,28,30,31},
};
vector <int> squ[32];
gp_hash_table <int,int> pos;
int k,n,now[32],cnt,scol[8],slc[8],src[8],ssqu[8],sze[32],INF;
inline int lowbit(int x)
{
	return x&(-x);
}
void change(int pos,int x)
{
	int state=1<<(x-1);
	scol[col[pos]]^=state,slc[lc[pos]]^=state,src[rc[pos]]^=state;
	for(int i=0;i<sze[pos];i++)
		ssqu[squ[pos][i]]^=state;
	return;
}
void init()
{
	for(int base=1,x=0;x<=30;x++)
		pos[base]=x,base*=2;
	for(int i=1;i<=7;i++)
		for(int j=1;j<=7;j++)
			squ[area[i][j]].push_back(i);
	for(int i=1;i<=31;i++)
		sze[i]=squ[i].size();
	scanf("%d%d",&k,&n);
	INF=(1LL<<k)-1;
	for(int i=1;i<=7;i++)
		scol[i]=slc[i]=src[i]=ssqu[i]=INF;
	for(int i=1;i<=31;i++)
	{
		scanf("%d",now+i);
		if(now[i])
			change(i,now[i]);
	}
	return;
}
void print()
{
	printf("Found\n");
	for(int i=1;i<=31;i++)
		printf("%d ",now[i]);
	return;
}
void dfs(int dep)
{
	if(cnt==n)
		return;
	if(dep==32)
	{
		cnt++;
		if(cnt==n)
			print();
		return;
	}
	if(now[dep])
	{
		dfs(dep+1);
		return;
	}
	int state=INF;
	state&=scol[col[dep]]&slc[lc[dep]]&src[rc[dep]];
	for(int i=0;i<sze[dep];i++)
		state&=ssqu[squ[dep][i]];
	while(state)
	{
		int last=lowbit(state),p=pos[last];
		change(dep,p+1);
		now[dep]=p+1;
		dfs(dep+1);
		change(dep,p+1);
		now[dep]=0;
		state^=last;
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	init();
	dfs(1);
	if(cnt<n)
		printf("No way");
	return 0;
}
