#include<bits/stdc++.h>
using namespace std;

int n,m,q;
bool v[3010][3010];
bool v2[3010];
int f[3010][3010],way[3010][3010];
vector < int > way2[3010];
int father[3010];

int belone(int now)
{
	if(now != father[now]) return father[now] = belone(father[now]);
	return now;
}

void bianli(int now)
{
	queue < int > he;
	he.push(now);
	v[now][now] = 1;
	while(!he.empty())
	{
		int f2 = he.front();
		he.pop();
		for(int i = 0;i < way2[f2].size();i++)
		{
			if(max(f[now][f2],way[f2][way2[f2][i]]) < f[now][way2[f2][i]] || v[now][way2[f2][i]] == 0)
			{
				v[now][way2[f2][i]] = v[way2[f2][i]][now] = 1;
				f[now][way2[f2][i]] = max(f[now][f2],way[f2][way2[f2][i]]);
				f[way2[f2][i]][now] = max(f[now][f2],way[f2][way2[f2][i]]);
				if(v2[way2[f2][i]] == 0)
				he.push(way2[f2][i]);
				v2[way2[f2][i]] = 1;
			}
		}
		v2[f2] = 0;
	}
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	
	for(int i = 1;i <= n;i++)
	father[i] = i;
	
	for(int i = 1;i <= m;i++)
	{
		int in1,in2,in3;
		scanf("%d%d%d",&in1,&in2,&in3);
		if(in3 < way[in1][in2] || way[in1][in2] == 0)
		{
			if(way[in1][in2] == 0)
			{
				int fa = belone(in1),fb = belone(in2);
				if(fa != fb)
				father[fa] = fb;
				way2[in1].push_back(in2);
				way2[in2].push_back(in1);
			}
			way[in1][in2] = in3;
			way[in2][in1] = in3;
		}
	}
	
	for(int i = 1;i <= n;i++)
	{
		bianli(i);
	}
	
	for(int i = 1;i <= q;i++)
	{
		int in1,in2;
		scanf("%d%d",&in1,&in2);
		if(v[in1][in2] == 0)
		printf("-1\n");
		else
		printf("%d\n",f[in1][in2]);
	}
	
	return 0;
}


