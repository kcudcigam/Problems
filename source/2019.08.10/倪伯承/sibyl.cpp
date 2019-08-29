#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int num[300010];
vector < int > way[300010];

int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	
	cin>>n>>m>>q;
	for(int i = 1;i <= m;i++)
	{
		int in1,in2;
		cin>>in1>>in2;
		way[in1].push_back(in2);
		way[in2].push_back(in1);
	}
	
	for(int i = 1;i <= q;i++)
	{
		int in1;
		cin>>in1;
		if(in1 == 0)
		{
			int in2,out;
			cin>>in2;
			out = num[in2];
			for(int j = 0;j < way[in2].size();j++)
			{
				out += num[way[in2][j]];
			}
			cout<<out<<endl;
		}
		else
		{
			int in2,in3;
			cin>>in2>>in3;
			num[in2] += in3;
		}
	}
	
	return 0;
}
/*
从来就没有什么救世主
也不分神仙和皇帝
想创造我们的幸福
全靠我们自己 
旧社会打个落花流水
奴隶们起来起来
不要以为我们一无所有
我们是全世界的主人
这是最后的斗争
团结起来到永远 
*/
 

