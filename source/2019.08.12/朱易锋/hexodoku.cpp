#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
	R int f=1,num=0;
	R char ch=getchar();
	while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(0!=isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num*f;
}
set<int>s[100][100];
set<int>::iterator it;
const int maxn=40;
int pos[maxn];
struct node
{
	int line[4];
	int qool[4];
}a[maxn];
I V tag(R int l,R int r,R int line_num,R int line_to)
{
	for(R int i=l;i<=r;i++)
	{
		a[i].line[line_to]=line_num;
	}
}
I V pre()
{
	pos[5]=1,pos[9]=2,pos[12]=3,pos[16]=4,pos[20]=5,pos[23]=6,pos[27]=7;
	tag(1,2,1,1);tag(3,7,2,1);tag(8,13,3,1);
	tag(14,18,4,1);tag(19,24,5,1);tag(25,29,6,1);tag(30,31,7,1);
	a[3].line[2]=a[8].line[2]=1;
	a[1].line[2]=a[4].line[2]=a[9].line[2]=a[14].line[2]=a[19].line[2]=2;
	a[2].line[2]=a[5].line[2]=a[10].line[2]=a[15].line[2]=a[20].line[2]=a[25].line[2]=3;
	a[6].line[2]=a[11].line[2]=a[16].line[2]=a[21].line[2]=a[26].line[2]=4;
	a[7].line[2]=a[12].line[2]=a[17].line[2]=a[22].line[2]=a[27].line[2]=a[30].line[2]=5;
	a[13].line[2]=a[18].line[2]=a[23].line[2]=a[28].line[2]=a[31].line[2]=6;
	a[24].line[2]=a[29].line[2]=7;
	
	a[7].line[3]=a[13].line[3]=1;
	a[2].line[3]=a[6].line[3]=a[12].line[3]=a[18].line[3]=a[24].line[3]=2;
	a[1].line[3]=a[5].line[3]=a[11].line[3]=a[17].line[3]=a[23].line[3]=a[29].line[3]=3;
	a[4].line[3]=a[10].line[3]=a[16].line[3]=a[22].line[3]=a[28].line[3]=4;
	a[3].line[3]=a[9].line[3]=a[15].line[3]=a[21].line[3]=a[27].line[3]=a[31].line[3]=5;
	a[8].line[3]=a[14].line[3]=a[20].line[3]=a[26].line[3]=a[30].line[3]=6;
	a[19].line[3]=a[25].line[3]=7;
	
	a[1].qool[1]=a[2].qool[1]=5;
	a[3].qool[1]=a[8].qool[1]=9;
	a[19].qool[1]=a[25].qool[1]=20;
	a[30].qool[1]=a[31].qool[1]=27;
	a[29].qool[1]=a[24].qool[1]=23;
	a[7].qool[1]=a[13].qool[1]=12;
	
	a[4].qool[1]=5; a[4].qool[2]=9;
	a[14].qool[1]=9; a[14].qool[2]=20;
	a[26].qool[1]=20; a[26].qool[2]=27;
	a[28].qool[1]=27; a[28].qool[2]=23;
	a[18].qool[1]=23; a[18].qool[2]=12;
	a[6].qool[1]=5; a[6].qool[2]=12;
	
	a[10].qool[1]=5; a[10].qool[2]=9; a[10].qool[3]=16;
	a[15].qool[1]=9; a[15].qool[2]=16; a[15].qool[3]=20;
	a[21].qool[1]=16; a[21].qool[2]=20; a[21].qool[3]=27;
	a[22].qool[1]=27; a[22].qool[2]=16; a[22].qool[3]=23;
	a[17].qool[1]=16; a[17].qool[2]=23; a[17].qool[3]=12;
	a[11].qool[1]=16; a[11].qool[2]=12; a[11].qool[3]=5;
}
int ans[maxn];
int K=0,n=0;
V INSERT(R int id,R int val)
{
	for(R int i=1;i<=3;i++)
	{
		s[i][a[id].line[i]].insert(val);
		R int to=a[id].qool[i];
		if(to!=0)s[4][pos[to]].insert(val);
	}
	if(pos[id]!=0)
	{
		s[4][pos[id]].insert(val);
	}
}
I V DEL(R int id,R int val)
{
	for(R int i=1;i<=3;i++)
	{
		s[i][a[id].line[i]].erase(val);
		R int to=a[id].qool[i];
		if(to!=0)s[4][pos[to]].erase(val);
	}
	if(pos[id]!=0)
	{
		s[4][pos[id]].erase(val);
	}
}
I bool check(R int id,R int val)
{
	if(ans[id]!=0)
	{
		return 1;
	}
	for(R int i=1;i<=3;i++)
	{
		it=s[i][a[id].line[i]].lower_bound(val);
		if(it!=s[i][a[id].line[i]].end())
		{
			if(*it==val)return 1;
		}
		R int to=a[id].qool[i];
		if(to!=0)
		{
			it=s[4][pos[to]].lower_bound(val);
			if(it!=s[4][pos[to]].end())
			{
				if(*it==val)return 1;
			}
		}
	}
	if(pos[id]!=0)
	{
		it=s[4][pos[id]].lower_bound(val);
		if(it!=s[4][pos[id]].end())
		{
			if(*it==val)return 1;
		}
	}
	return 0;
}
int num=0;
V dfs(R int now)
{
	if(num>=n)return;
	if(now==31)
	{
		num++;
		if(num==n)
		{
			printf("Found\n");
			for(R int i=1;i<=31;i++)
			{
				cout<<ans[i]<<" ";
			}
		}
		return;
	}
	R int id=now+1;
	if(ans[id]!=0)dfs(now+1);
	else
	{
		for(R int i=1;i<=K;i++)
		{
			R int val=i;
			if(check(id,val))continue;
			else 
			{
				INSERT(id,val);
				ans[id]=i,dfs(now+1);
				DEL(id,i);
				ans[id]=0;
			}
		}
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	pre();
	K=read();n=read();
	for(R int i=1;i<=31;i++)
	{
		R int x=read();
		if(x!=0)
		{
			INSERT(i,x);
			ans[i]=x;
		}
	}
	if(K>=7)dfs(0);
	if(num<n)printf("No way\n");
	return 0;
}
