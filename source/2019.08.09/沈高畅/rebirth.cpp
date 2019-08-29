#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f;
}
vector<int> vec[10005];
vector<int> qz[10005];
int vis[10005];
int dis[10005];
int la[10005];
int n,m;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
void dij()
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	int Q=n-1;
	pq.push(make_pair(0,make_pair(1,0)));
	while(Q--)
		{
			while(!pq.empty()&&vis[pq.top().second.first]) pq.pop();
			if(pq.empty()) break;
			int va=pq.top().first;
			int to=pq.top().second.first;
			la[to]=pq.top().second.second;
			vis[to]=1;
			dis[to]=va;
			pq.pop();
			for(int i=0;i<vec[to].size();i++)
				{
					if(va+qz[to][i]<dis[vec[to][i]])
						{
							dis[vec[to][i]]=va+qz[to][i];
							pq.push(make_pair(va+qz[to][i],make_pair(vec[to][i],to)));
						}
				}
		}
}
signed main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int Num;
	Num=read();
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
		{
			int a,b,c;
			a=read();
			b=read();
			c=read();
			if(a==b) continue;
			vec[a].push_back(b);
			qz[a].push_back(c);
			vec[b].push_back(a);
			qz[b].push_back(c);
		}
	dij();
	cout<<0<<" ";
	for(int i=2;i<=n;i++)
		{
			if(vec[i].size()==1)
				{
					cout<<-1<<" ";
					if(i!=n) continue;
					else break;
				}
			int lao=la[i];
//			cout<<lao<<endl;
			int cd=-1,cd2=INT_MAX,cd3=-1;
			for(int j=0;j<vec[i].size();j++)
				if(vec[i][j]==lao&&qz[i][j]<cd2)
					{
						cd=j;
						cd2=qz[i][j];
					}
			for(int j=0;j<vec[lao].size();j++)
				if(vec[lao][j]==i&&qz[lao][j]==cd2)
					{
						cd3=j;
					}
//				cout<<cd2<<endl;
//			cout<<cd<<" "<<cd2<<" "<<cd3<<endl;
			vec[i][cd]=1;
			vec[lao][cd3]=1;
//			system("pause");
			dij();
			if(vis[i])cout<<dis[i]<<" ";
			else cout<<-1<<" ";
			vec[i][cd]=lao;
			vec[lao][cd3]=i;
			dij();
		}
	return 0;
}
