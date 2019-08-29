#include <bits/stdc++.h>
using namespace std;
int father[1000000],t[1000000],ans[100000],a,b,n; 
void add(int n,int m)
{
	int p=n,i=0,j=0;
	int q=m;
	int l=ans[father[n]]+ans[father[m]]+1;
	while (father[p]!=p)
	{
		i++;
		t[i]=p;
		p=father[p];
	}
	for (int o=1;o<=i;o++)
	  father[t[o]]=p;
	while (father[q]!=q)
	{
		j++;
		t[j]=q;
		q=father[q];
	}
	for (int o=1;o<=j;o++)
	  father[t[o]]=p;
	father[q]=p;
	ans[p]=max(max(ans[p],ans[q]),l);
	cout<<ans[p]<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	  father[i]=i;
	for (int i=1;i<n;i++)
	  {
	  	cin>>a>>b;
	  	if (a>b)
	  	add(b,a);
	  	else
	  	add(a,b);
	   } 
	return 0;
}
/*10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10*/


