#include<bits/stdc++.h>
using namespace std;
int n,q,t,x,y,fa[500001];
long long ans[500001];
vector <int > son[500001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
queue<int> que;

int get(int x)
{
	if(x==fa[x])
	return x;
	
	return fa[x]=get(fa[x]);
}

int fi(int x)
{
	if(x==fa[x])
	return x;
	else
	return fi(fa[x]);
}
int main(){
    freopen("merge.in","r",stdin);
    freopen("merge.out","w",stdout);
    read(n);read(q);
    for(register int i=1;i<=n;i++)
    fa[i]=i;
    while(q--)
    {
    	read(t);read(x);read(y);
    	if(t==1)
    	{
    		int xx,yy;
    		xx=get(x);yy=get(y);
    		if(xx==yy)
    		continue;
    		else
    		fa[xx]=yy,son[yy].push_back(xx);
		}
		else
		{
			int xx=fi(x);
			que.push(xx);
			while(!que.empty())
			{
				xx=que.front();
				ans[xx]+=y;
				que.pop();
			for(int i=0;i<son[xx].size();i++)
				que.push(son[xx][i]);
	    	}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<' ';
	return 0;
}

