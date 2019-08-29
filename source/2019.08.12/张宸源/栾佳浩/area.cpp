#include<bits/stdc++.h>
using namespace std;
int x,y;
int lg[10005];
int cnt;
int solve(int x,int y)
{
	if(x>y)swap(x,y);
	if(x<=1&&y<=1)
	{
		if(x==1&&y==1)return -1;
		return 1;
	}
	int cov=1<<(lg[max(x,y)]+1);
	if(x<cov/2)return solve(x,y-cov/2);
	else return -solve(x-cov/2,y-cov/2);
}
int solve2(int x,int y)
{
	if(x>y)swap(x,y);
	if(x<=1&&y<=1)
	{
		if(x==1&&y==1)return -1;
		return 1;
	}
	int cov=1<<(int(log2(1.0000*y+0.5))+1);
	if(x<cov/2)return solve2(x,y-cov/2);
	else return -solve2(x-cov/2,y-cov/2);
}
set<pair<int,int> >st;
int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
const int inf=2000000000;
int dfs(int x,int y)
{
	//cout<<x<<" "<<y<<" "<<solve(x,y)<<endl;
	if(x==0||y==0)return inf;
	st.insert(make_pair(x,y));
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		int rx=x+dx[i];
		int ry=y+dy[i];
		if(solve(rx,ry)==solve(x,y)&&!st.count(make_pair(rx,ry)))
		{
			int pls=dfs(rx,ry);
			if(pls==inf)return inf;
			else ans+=pls;
		}
	}
	return ans+1;
}
int dfs2(int x,int y)
{
	cnt++;
	//cout<<x<<" "<<y<<" "<<solve(x,y)<<endl;
	if(x==0||y==0||(cnt>5000000&&solve(x,y)==1))
	{
		puts("infinity");
		exit(0);
	}
	st.insert(make_pair(x,y));
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		int rx=x+dx[i];
		int ry=y+dy[i];
		if(solve2(rx,ry)==solve2(x,y)&&!st.count(make_pair(rx,ry)))
		{
			ans+=dfs2(rx,ry);	
		}
	}
	return ans+1;
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&x,&y);
	if(x<=10000&&y<=10000)
	{
	for(int i=2;i<=10000;i++)
	lg[i]=lg[i>>1]+1;
	int ans=dfs(x,y);
	if(ans!=inf)printf("%d\n",ans);
	else puts("infinity");
	}
	else 
	{
		printf("%d\n",dfs2(x,y));
	}
}
