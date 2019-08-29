#include<bits/stdc++.h>
using namespace std;
int a,h,l,s;
string b,t;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void chck()
{
	h=-1;
	for (int i=0;i<b.size();i++)
	if (t[i]!=b[i])
	{
		h=i;
		break;
	}
	if (h==-1) h=b.size();
	l=0;
	while (l<b.size())
	{
		if (t[t.size()-1-l]!=b[b.size()-1-l]) break;
		l++;
	}
	if (h+l<b.size()) s++;
}
void wrk(int u)
{
	if (u>a) chck();
	else for (int i=1;i<=26;i++) 
	     {
		 	t+=char(i+96);
		 	wrk(u+1);
		 	t.erase(t.size()-1);
	     }
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>a;
	cin>>b;
	wrk(1);
	cout<<s<<endl;
	return 0;
}


