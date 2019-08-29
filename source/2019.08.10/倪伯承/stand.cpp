#include<bits/stdc++.h>
using namespace std;

struct hehe{
	int l,r;
} num[251];

int n,m;
long long cha[10000010],out,xi[10];

bool haha(hehe a,hehe b)
{
	return a.l < b.l;
}

void en(int l,int r)
{
	int lest = 0;
	for(int i = 1;i <= n && num[i].r <= r;i++)
	{
		if(num[i].l >= l)
		{
			cha[num[i].l]++;
			cha[num[i].r + 1]--;
			lest++;
		}
	}
	
	int now_max = 0,now = 0,now_max_i;
	for(int i = l;i <= r;i++)
	{
		now += cha[i];
		if(now > now_max) now_max = now,now_max_i = i;
		cha[i] = 0;
	}
	cha[r + 1] = 0;
	long long x = now_max;
	
	out += xi[1] * x + xi[2] * x * x + xi[3] * x * x * x + xi[4] * x * x * x * x + xi[5] * x * x * x * x * x;
	
	if(lest - x > 0)
	{
		en(l,now_max_i - 1);
		en(now_max_i + 1,r);	
	}
	
}

int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	
	cin>>n>>m;
	cin>>xi[1]>>xi[2]>>xi[3]>>xi[4]>>xi[5];
	for(int i = 1;i <= n;i++)
		cin>>num[i].l>>num[i].r;
	
	sort(num + 1,num + 1 + n,haha);
	
	en(1,m);
	
	cout<<out; 
	
	return 0;
}



