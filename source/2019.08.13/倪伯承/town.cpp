#include<bits/stdc++.h>
using namespace std;

int n,mmax,now_num,num1;
vector < int > way[7010];
bool v[7010];

void dfs(int now)
{
	v[now] = 1;
	if(now_num > mmax)
	{
		mmax = now_num;
		num1 = now;
	}
	
	for(int i = 0;i < way[now].size();i++)
	{
		if(v[way[now][i]] == 0)
		{
			now_num++;
			dfs(way[now][i]);
			now_num--;
		}
	}
	v[now] = 0;
}

int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	
	cin>>n;
	
	if(n > 7000)
	{
		cout<<"Ctrl"<<endl;																																																												//chang tiao rap l...
		return 0;
	}
	
	for(int i = 1;i < n;i++)
	{
		int in1,in2;
		cin>>in1>>in2;
		way[in1].push_back(in2);
		way[in2].push_back(in1);
		
		mmax = 0;
		dfs(in1);
		dfs(num1);
		cout<<mmax<<endl;
		
	}
	
	return 0;
}


