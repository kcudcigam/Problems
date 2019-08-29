#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f; 
}
string zz,h;
int n;
int ans=0;
bool check()
{
	string p="";
	int cl;
	int len=n-h.size();
	for(cl=0;cl<n;cl++)
		{
			p="";
			int cr=cl+len-1;
			if(cr>=zz.size()) 
				{
					break;
				}
			system("pause");
			for(int j=0;j<cl;j++) p.push_back(zz[j]);
			for(int j=cr+1;j<zz.size();j++) p.push_back(zz[j]);
			
//			cout<<p<<" "<<zz<<endl;
			if(p==h) return 0;
		}
	return 1;
}
void dfs(int dep)
{
	if(dep>n)
		{
			ans+=check();
			return;
		}
	for(int i=0;i<=25;i++) 
		{
			zz.push_back('a'+i);
			dfs(dep+1);
			zz.erase(zz.size()-1);
		}

}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	cin>>h;
	if(n==h.size())
		{
			cout<<1<<endl;
			return 0;
		}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}


