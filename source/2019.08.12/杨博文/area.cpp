#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;bool f=0;char c;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
queue<pair<int,int> > q;
#define lowbit(x) x&-x
inline int qe(register int x)
{
	bool ans=0;
	while(x)x-=lowbit(x),ans=!ans;
	return ans;
}
map<pair<int,int>,bool> xx; 
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	
	register int x,y,w,ans=0;
	yin>>x>>y;
	w=qe(x&y);
	q.push(make_pair(x,y));
	xx[make_pair(x,y)]=1;
	while(!q.empty())
	{
		ans++;
		if(xx.size()>=300000)
		{
			puts("infinity");
			return 0;
		}
		register pair<int,int> tx=q.front();
		if((tx.first<=1||tx.second<=1)&&(w==0))
		{
			puts("infinity");
			return 0;
		}
		q.pop();
		--tx.first;
		if(!xx[tx]&&tx.first>=0&&qe(tx.first&tx.second)==w)q.push(tx),xx[tx]=1;
		++tx.first;
		--tx.second;
		if(!xx[tx]&&tx.second>=0&&qe(tx.first&tx.second)==w)q.push(tx),xx[tx]=1;
		++tx.first;
		++tx.second;
		if(!xx[tx]&&qe(tx.first&tx.second)==w)q.push(tx),xx[tx]=1;
		++tx.second;
		--tx.first;
		if(!xx[tx]&&qe(tx.first&tx.second)==w)q.push(tx),xx[tx]=1;
	}
	cout<<ans<<endl;
	return 0;
}

