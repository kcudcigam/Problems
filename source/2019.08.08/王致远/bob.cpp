#include<bits/stdc++.h>
using namespace std;
bool f;
int a,t[100010],tt[100010],s,w[5];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') x=-x;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void chk()
{
	w[1]=tt[1];w[2]=tt[2];w[3]=tt[3];w[4]=tt[4];
	for (int i=1;i<=400;i++)
	{
		f=0;
		if (w[1]==1) f=1;
		if (w[1]>0) w[1]--;
		if (w[1]>0)
		{
			if (w[2]==0) w[2]=t[w[1]];
			else 
			if (w[3]==0) w[3]=t[w[1]];
			else
			if (w[4]==0) w[4]=t[w[1]];
		}
		if (w[2]==1) f=1;
		if (w[2]>0) w[2]--;
		if (w[2]>0)
		{
			if (w[1]==0) w[1]=t[w[2]];
			else 
			if (w[3]==0) w[3]=t[w[2]];
			else
			if (w[4]==0) w[4]=t[w[2]];
		}
		if (w[3]==1) f=1;
		if (w[3]>0) w[3]--;
		if (w[3]>0)
		{
			if (w[1]==0) w[1]=t[w[3]];
			else 
			if (w[2]==0) w[2]=t[w[3]];
			else
			if (w[4]==0) w[4]=t[w[3]];
		}
		if (w[4]==1) f=1;
		if (w[4]>0) w[4]--;
		if (w[4]>0)
		{
			if (w[1]==0) w[1]=t[w[4]];
			else 
			if (w[2]==0) w[2]=t[w[4]];
			else
			if (w[3]==0) w[3]=t[w[4]];
		}
		if (f==0) return;
	}
	s++;
}
void wrk(int u)
{
	if (u>4) chk();
	else
	for (int i=0;i<=a;i++)
	{
		tt[u]=i;
		wrk(u+1);
	}
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	read(a);
	for (int i=1;i<a;i++) read(t[i]);
	wrk(1);
	cout<<s<<endl;
	return 0;
}

