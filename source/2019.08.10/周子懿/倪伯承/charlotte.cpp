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
�ʺ������ֻʺ�����
�ʺ������ֻʺ�����
�ʺ�������Ϊ���޻ʹ�
�ʺ����� �����糱ӿ

�������� 
�������� 
֪��һȥ�ݰ�Զȥ�ⶼ��
Ҫ��ΰ���ͬ־�������˼ 
*/ 
