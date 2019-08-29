#include<bits/stdc++.h>
using namespace std;

string s;
int num[1000010],new_num[1000010];
int n;
long long out;
bool l = 0;

void en()
{
	cout<<"En hehe"; // ÔÛÊÇºÃÈË£¬ÔÛ²»¿¨ÆÀ²â£¬Ò²²»¸Ò¿¨ÆÀ²â   ÉúÓãÓÇ»¼£¬ËÀÓã°²ÀÖ¡£ 
}

void hahahaha(int now)
{
	if(now == n)
	{
		bool l1 = 0,l2 = 0;
		for(int i = 1;i <= n;i++)
		{
			l1 = 0;
			for(int j = 1;j < i;j++)
			{
				if(num[j] != new_num[j])
				{
					l1 = 1;
					break;
				}
			}
			if(l1 == 0)
			for(int j = i + n - s.size();j <= n;j++)
			{
				if(num[j + s.size() - n] != new_num[j])
				{
					l1 = 1;
					break;
				}
			}
			if(l1 == 0)
			{
				l2 = 1;
				break;
			}
		}
		if(l2 == 0) out++;
		out %= 998244353; 
	}
	else
	{
		for(int i = 0;i < 26;i++)
		{
			new_num[now + 1] = i;
			hahahaha(now + 1);
		}
	}
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>s;
	for(int i = 0;i < s.size();i++)
	{
		num[i + 1] = s[i] - 'a';
		if(num[i + 1] != num[i] && i > 0)
		l = 0;
	}
	
	if(l == 0 && n > 6)
	{
		en();
		return 0;
	}
	else if(n <= 6)
	{
		hahahaha(0);
	}
	else
	return 0;    // ÔÛÊÇºÃÈË£¬ÔÛ²»¿¨ÆÀ²â£¬Ò²²»¸Ò¿¨ÆÀ²â £¨^-^£©... 
	
	cout<<out;
	
	return 0;
}


