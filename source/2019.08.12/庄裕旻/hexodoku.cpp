#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef unsigned int Data;
int Xid[32]={0, 1,1, 2,2,2,2,2, 3,3,3,3,3,3, 4,4,4,4,4, 5,5,5,5,5,5, 6,6,6,6,6, 7,7};
int Yid[32]={0, 2,3, 1,2,3,4,5, 1,2,3,4,5,6, 2,3,4,5,6, 2,3,4,5,6,7, 3,4,5,6,7, 5,6};
int Zid[32]={0, 5,6, 3,4,5,6,7, 2,3,4,5,6,7, 2,3,4,5,6, 1,2,3,4,5,6, 1,2,3,4,5, 2,3};
int Rid[32][3]={{0,0,0}, {1,1,1}, {1,1,1}, {2,2,2}, {1,2,1}, {1,1,1}, {1,3,1}, {3,3,3}, {2,2,2}, {2,2,2}, {1,2,4}, {1,3,4}, {3,3,3}, {3,3,3}, {2,5,2}, {2,4,5}, {4,4,4}, {3,4,6}, {3,6,3}, {5,5,5}, {5,5,5}, {4,5,7}, {4,6,7}, {6,6,6}, {6,6,6}, {5,5,5}, {5,7,5}, {7,7,7}, {6,7,6}, {6,6,6}, {7,7,7}, {7,7,7}};
Data Xcan[8],Ycan[8],Zcan[8],Rcan[8],a[32],K,N,full,one=1,tot;
inline void Flip(int i,Data v)
{
	Xcan[Xid[i]]^=one<<v;
	Ycan[Yid[i]]^=one<<v;
	Zcan[Zid[i]]^=one<<v;
	Rcan[Rid[i][0]]^=one<<v;
	if(Rid[i][1]^Rid[i][0]) Rcan[Rid[i][1]]^=one<<v;
	if(Rid[i][2]^Rid[i][0]) Rcan[Rid[i][2]]^=one<<v;
}
void dfs(Data id)
{
	((Ycan[2]>>1)&1);
	if(id==32)
	{
		if(++tot==N)
		{
			puts("Found");
			for(int i=1;i<=31;i++) printf("%d ",a[i]);
			puts("");
			exit(0);
		}
		return;
	}
	if(a[id]) { dfs(id+1); return; }
	Data can=Xcan[Xid[id]]&Ycan[Yid[id]]&Zcan[Zid[id]]&Rcan[Rid[id][0]]&Rcan[Rid[id][1]]&Rcan[Rid[id][2]];
	for(Data i=1;i<=K;i++) if((can>>i)&1)
	{
		Flip(id,i);
		a[id]=i;
		dfs(id+1);
		a[id]=0;
		Flip(id,i);
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cin>>K>>N;
	for(int i=1;i<=K;i++) full|=one<<i;
	for(int i=1;i<=7;i++) Xcan[i]=Ycan[i]=Zcan[i]=Rcan[i]=full;
	for(int i=1;i<=31;i++)
	{
		cin>>a[i];
		Flip(i,a[i]);
	}
	dfs(1);
	puts("No way");
	return 0;
}
