#include<bits/stdc++.h>
using namespace std;
int a,c,zcl,qzcl,hzcl,fdl,zc[500010],fd[500010],qzc[500010],hzc[500010],s;
priority_queue<int> q;
string b;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);
	for (int i=1;i<=a;i++)
	{
		cin>>b;read(c);
		if (b=="11") 
		{
			zcl++;
			zc[zcl]=c;
		}
		if (b=="10")
		{
			qzcl++;
			qzc[qzcl]=c;
		}
		if (b=="01")
		{
			hzcl++;
			hzc[hzcl]=c;
		}
		if (b=="00")
		{
			fdl++;
			fd[fdl]=c;
		}
	}
	sort(qzc+1,qzc+qzcl+1,cmp);
	sort(hzc+1,hzc+hzcl+1,cmp);
	for (int i=1;i<=fdl;i++) q.push(fd[i]);
	if (qzc>=hzc)
	{
		for (int i=1;i<=hzcl;i++) s+=qzc[i]+hzc[i];
		for (int i=hzcl+1;i<=qzcl;i++) q.push(qzc[i]);
	}
	else
	{
		for (int i=1;i<=qzcl;i++) s+=qzc[i]+hzc[i];
		for (int i=qzcl+1;i<=hzcl;i++) q.push(hzc[i]);		
	}
	for (int i=1;i<=zcl;i++)
	{
		s+=zc[i];
		if (!q.empty())
		{
			s+=q.top();
			q.pop();
		}
	}
	cout<<s<<endl;
	return 0;
}


