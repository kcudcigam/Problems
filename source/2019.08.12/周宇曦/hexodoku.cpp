#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
int ai[32],k,n,ki;
bool ci(int a)
{
	return (a>=0&&a<=k)?true:false;
}
bool checki(int a=0,int b=0,int c=0,int d=0,int e=0,int f=0,int g=0)
{
	if(!(ci(ai[a])&&ci(ai[b])&&ci(ai[c])&&ci(ai[d])&&ci(ai[e])&&ci(ai[f])&&ci(ai[g]))) return false;
	int flag[33]={0};
	flag[ai[a]]++,flag[ai[b]]++,flag[ai[c]]++,flag[ai[d]]++,flag[ai[e]]++,flag[ai[f]]++,flag[ai[g]]++;
	for(int i=1;i<=k;i++)
		if(flag[i]>1)
			return false;
	return true;
}
bool check()
{
	return checki(1,2)&&checki(3,4,5,6,7)&&checki(8,9,10,11,12,13)&&checki(14,15,16,17,18)
	&&checki(19,20,21,22,23,24)&&checki(25,26,27,28,29)&&checki(30,31)&&checki(3,8)&&checki(1,4,9,14,19)
	&&checki(2,5,10,15,20,25)&&checki(6,11,16,21,26)&&checki(7,12,17,22,27,30)&&checki(13,18,23,28,31)
	&&checki(24,29)&&checki(7,13)&&checki(2,6,12,18,24)&&checki(1,5,11,17,23,29)&&checki(4,10,16,22,28)
	&&checki(3,9,15,21,27,31)&&checki(8,14,20,26,30)&&checki(19,25)&&checki(1,2,4,5,6,10,11)&&checki(3,4,8,9,10,14,15)
	&&checki(6,7,11,12,13,17,18)&&checki(10,11,15,16,17,21,22)&&checki(14,15,19,20,21,25,26)&&checki(17,18,22,23,24,28,29)
	&&checki(21,22,26,27,28,30,31);
}
void dfs(int step)
{
	if(step==32)
	{
		ki++;
		if(ki==n)
		{
			puts("Found");
			for(int i=1;i<=31;i++)
				cout<<ai[i]<<" ";
			exit(0);
		}
		return;
	}
	if(ai[step])
	{
		 dfs(step+1);
		 return;
	}
	for(int i=1;i<=k;i++)
	{
		ai[step]=i;
		if(check())
			dfs(step+1);	
	}
	ai[step]=0;
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	read(k),read(n);
	for(int i=1;i<=31;i++)
		read(ai[i]);
	if(!check())
	{
		puts("No way");
		return 0;
	}
	dfs(1);
	puts("No way");
	return 0;
}


