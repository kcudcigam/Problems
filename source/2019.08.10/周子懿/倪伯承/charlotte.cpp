#include<bits/stdc++.h>
using namespace std;

struct hehe{
	int t,x,y;
} num[10010];

int T,n;

bool haha(hehe a,hehe b)
{
	return a.t < b.t;
}

int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		bool l = 0;
		cin>>n;
		for(int i = 1;i <= n;i++)
			cin>>num[i].t>>num[i].x>>num[i].y;
		sort(num + 1,num + 1 + n,haha);
		
		for(int i = 1;i <= n;i++)
		{
			if(abs(num[i - 1].y - num[i].y) + abs(num[i - 1].x - num[i].x) <= num[i].t - num[i - 1].t && ((num[i].t - num[i - 1].t) - (abs(num[i - 1].y - num[i].y) + abs(num[i - 1].x - num[i].x))) % 2 == 0)
				l = 0;
			else
			{
				l = 1;
				break;
			}
		}
		if(l == 0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}
/* 
皇后大道西又皇后大道东
皇后大道东又皇后大道中
皇后大道西上为何无皇宫
皇后大道中 人民如潮涌

………… 
………… 
知己一去拜拜远去这都市
要靠伟大的同志搞搞新意思 
*/ 
