#include<bits/stdc++.h>
using namespace std;
int f[2005],s[2005],n,k,i,j,x,y,b[2005],c[2005],r,t;
vector<int> a[2005];
void df(int u,int fa)
{
	f[u]=fa;
	s[u]=1;
	for (int i=0;i<a[u].size();i++)
	if (a[u][i]!=fa) {
		df(a[u][i],u);
		s[u]++;
	}
}
int main(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  cin>>t;
  while (t!=0)
  {
  cin>>n>>k;
  for (i=1;i<=n;i++)
  a[i].clear();
  r=0;
  for (i=1;i<n;i++)
  {
  	cin>>x>>y;
  	a[x].push_back(y);
  	a[y].push_back(x);
  }
  df(1,0);
  for (i=1;i<=n;i++)
  {
  cin>>b[i];
  if (b[i]==0) b[i]--;
  }
  for (i=1;i<=n;i++)
  {
  cin>>c[i];
  if (c[i]==0) c[i]--;
  } 
  int i=1;
  while (i<=n) {
    for (j=1;j<=n;j++)
    if (s[j]==1) break;
    s[f[j]]--;
    if (b[j]==c[j]) i++;
    else {
    	i++;
    	x=1;
    	while (x<=k)
    	{
    		if (j==0) {
    			cout<<"No"<<endl;
    			r=1;
    			break;
			}
			else {
			   b[j]*=-1;
			   x++;
			   j=f[j];	
			}
		}
	}
	if (r==1) break;
  }
  if (r==0)cout<<"Yes"<<endl;
  t--;
  }
  return 0;
}

