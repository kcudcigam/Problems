#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int a10[400010],a01[400010],a00[400010];
int a10_num,a01_num,a00_num;
int c,out;

bool hehe(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		int in;
		cin>>s>>in;
		if(s[0] == '1' && s[1] == '1')
		{
			c++;							//choose ++ , ²»ÊÇG++:) 
			out += in;
		}
		else if(s[0] == '1' && s[1] == '0')
		{
			a10[++a10_num] = in;
		}
		else if(s[0] == '0' && s[1] == '1')
		{
			a01[++a01_num] = in;
		}
		else if(s[0] == '0' && s[1] == '0')
		{
			a00[++a00_num] = in;
		}
	}
	
	sort(a10 + 1,a10 + 1 + a10_num,hehe);
	sort(a01 + 1,a01 + 1 + a01_num,hehe);
	sort(a00 + 1,a00 + 1 + a00_num,hehe);
	
	for(int i = 1;i <= min(a10_num,a01_num);i++)
	{
		out += a10[i] + a01[i];
	}
	
	if(a10_num > a01_num)
	{
		for(int i = 1,now_a10 = a01_num + 1,now_a00 = 1;i <= min(a10_num - a01_num + a00_num,c);i++)
		{
			if(a10[now_a10] > a00[now_a00])
				out += a10[now_a10++];
			else
				out += a00[now_a00++];
		}
	}
	else if(a10_num < a01_num)
	{
		for(int i = 1,now_a01 = a10_num + 1,now_a00 = 1;i <= min(a01_num - a10_num + a00_num,c);i++)
		{
			if(a01[now_a01] > a00[now_a00])
				out += a01[now_a01++];
			else
				out += a00[now_a00++];
		}
	}
	else
	{
		for(int i = 1;i <= min(c,a00_num);i++)
		{
			out += a00[i];
		}
	}
	cout<<out;
	
	return 0;
}


