#include<bits/stdc++.h>
using namespace std;
int a[1000],gx1[500][500],gx2[500][500],n,x,y,d[1000],k=0;
void check()
{
	/*for (int i=1;i<=n-1;i++)
	{
		cout<<a[i]<<' ';		
	}
	cout<<a[n]<<endl;*/
	for (int i=1;i<=n;i++)
	{
		
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int o=a[i];
			if (gx1[i][j]!=gx1[a[i]][a[j] ]) {
				k++;
			/*	for (int p=1;p<=n-1;p++)
	{
		cout<<a[p]<<' ';		
	}
	cout<<a[n]<<endl;*/
				return;
			}
				if (gx2[i][j]!=gx2[a[i]][a[j]]) {
				k++;
			/*	for (int p=1;p<=n-1;p++)
	{
		cout<<a[p]<<' ';		
	}*/
//	cout<<a[n]<<endl;
				return;
			}
		}
	}
}
bool checkp(int dep)
{
	for (int i=1;i<=dep-1;i++)
	{
		if (a[i]==a[dep]) return false;
	
	}
	return true;
}
void work(int dep)
{

	if (dep>n) check();
	else
	{
		for (int i=1;i<=n;i++)
		{
			a[dep]=i;
		if (checkp(dep))
				work(dep+1);
		}
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num;
	cin>>num;
	cin>>n>>x>>y;
	for (int i=1;i<=x;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		gx1[a1][a2]+=1;
		gx1[a2][a1]+=1;
	}
	for (int i=1;i<=y;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		gx2[a1][a2]+=1;
		gx2[a2][a1]+=1;
	}
	work(1);
	cout<<k<<endl;
	return 0;
}


