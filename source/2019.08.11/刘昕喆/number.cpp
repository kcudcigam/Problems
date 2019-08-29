#include<bits/stdc++.h>
#define int long long
using namespace std;
inline bool check(int n)
{
	int a1=-1,b1=-1;
	while(n!=0)
	{
		if(n%10!=a1 && n%10!=b1)
		{
			if(a1==-1)  a1=n%10;
			else  if(b1==-1)  b1=n%10;
			else  return 0;
		}
		n=n/10;
	}
	return 1;
}
queue<pair<int,int> > q;
int bfs(int state)
{
	int Max=log10(state)*5;
	while(!q.empty())  q.pop();
	q.push(make_pair(state,1));
	while(!q.empty())
	{
		int num=q.front().first,step=q.front().second;
		q.pop();
		if(check(num))
		{
			return step;
		}
		int sum=0;
		for(int i=num-1;i>=0;i--)
		{
			if(check(i))
			{
				q.push(make_pair(num-i,step+1));
				sum++;
			}
			if(sum==Max)  break;
		}
		q.push(make_pair(num,step));
	}
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<bfs(n)<<endl;
	}
	return 0;
}

