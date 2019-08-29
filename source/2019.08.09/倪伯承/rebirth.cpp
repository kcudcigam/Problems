#include<bits/stdc++.h>
using namespace std;

long long ans,n,m,re;
vector < int > way[10010],way3[10010];
vector < long long > way2[10010];
long long f[10010][3];
bool v[10010],v2[10010];

void bianli()
{
	queue < int > point;
	point.push(1);
	while(!point.empty())
	{
		int l = point.front();
		for(int i = 0;i < way[l].size();i++)
		{
			if(v[way[l][i]] == 0 || f[l][0] + way2[l][i] < f[way[l][i]][0])
			{
				v[way[l][i]] = 1;
				f[way[l][i]][0] = f[l][0] + way2[l][i];
				f[way[l][i]][1] = way3[l][i];
				f[way[l][i]][2] = 1;
				if(v2[way[l][i]] == 0)
				point.push(way[l][i]);
				v2[way[l][i]] = 1;
			}
			else if(f[l][0] + way2[l][i] == f[way[l][i]][0] && f[way[l][i]][1] == l)
			f[way[l][i]][2] = 2;
		}
		v2[l] = 0;
		point.pop();
	}
}

void hahahaha(int now)
{
	long long f2[10010];
	bool v3[10010],v4[10010];
	for(int i = 1;i <= n;i++) f2[i] = v3[i] = v4[i] = 0;
	queue < int > point;
	point.push(now);
	while(!point.empty())
	{
		int l = point.front();
		for(int i = 0;i < way[l].size();i++)
		{
			if(((way3[l][i] != f[now][1])) && (v3[way[l][i]] == 0 || f2[l] + way2[l][i] < f2[way[l][i]]))
			{
				v3[way[l][i]] = 1;
				f2[way[l][i]] = f2[l] + way2[l][i];
				if(v4[way[l][i]] == 0)
				point.push(way[l][i]);
				v4[way[l][i]] = 1;
			}
		}
		v4[l] = 0;
		point.pop();
	}
	if(v3[1] == 0) re = -1;
	else re = f2[1];
}

int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>ans>>n>>m;
	
	for(int i = 1;i <= m;i++)
	{
		long long in1,in2,in3;
		cin>>in1>>in2>>in3;
		if(in1 != in2)
		{
			way[in1].push_back(in2);
			way[in2].push_back(in1);
			way2[in1].push_back(in3);
			way2[in2].push_back(in3);
			way3[in1].push_back(i);
			way3[in2].push_back(i);
		}
		
	}
	
	bianli();
	
	cout<<0;
	for(int i = 2;i <= n;i++)
	{
		if(f[i][2] == 2) cout<<' '<<f[i][0];
		else
		{
			if(way[i].size() == 1) cout<<" "<<-1;
			else
			{
				hahahaha(i);
				if(re == -1) cout<<' '<<way[i].size();
				else cout<<' '<<re;
			}
		}
	}
	
	return 0;
}

