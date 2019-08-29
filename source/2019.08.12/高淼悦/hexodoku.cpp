#include<bits/stdc++.h>
using namespace std;

int read()
{
	char ch=getchar();int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

int t1[35],t2[35],t3[35],t4[35];
int b1[35];
int a[35];
vector <int> v1[10],v2[10],v3[10],v4[35],v5[35];
vector <int> v;
int n,k,ans=0;

void work()
{
	t1[1]=t1[2]=1;
	for (int i=3;i<=7;i++) t1[i]=2;
	for (int i=8;i<=13;i++) t1[i]=3;
	for (int i=14;i<=18;i++) t1[i]=4;
	for (int i=19;i<=24;i++) t1[i]=5;
	for (int i=25;i<=29;i++) t1[i]=6;
	t1[30]=t1[31]=7;
	t2[3]=t2[6]=1;
	t2[1]=2;t2[2]=3;t2[30]=5;t2[31]=6;t2[24]=t2[29]=7;
	for (int i=4;i<=19;i+=5) t2[i]=2;
	for (int i=5;i<=25;i+=5) t2[i]=3;
	for (int i=6;i<=26;i+=5) t2[i]=4;
	for (int i=7;i<=27;i+=5) t2[i]=5;
	for (int i=13;i<=28;i+=5) t2[i]=6;
	t3[7]=t3[13]=1;
	t3[2]=2;t3[1]=3;t3[19]=t3[25]=7;t3[31]=5;t3[30]=6;
	for (int i=6;i<=24;i+=6) t3[i]=2;
	for (int i=5;i<=29;i+=6) t3[i]=3;
	for (int i=4;i<=28;i+=6) t3[i]=4;
	for (int i=3;i<=27;i+=6) t3[i]=5;
	for (int i=8;i<=26;i+=6) t3[i]=6;
	b1[5]=b1[9]=b1[12]=b1[16]=b1[20]=b1[23]=b1[27]=1;
}

int ch(int x,int y)
{
	if (a[x]!=0) return 0;
	for (int i=0;i<v1[t1[x]].size();i++)
	{
		if (a[v1[t1[x]][i]]==y) return 0;
	}
	for (int i=0;i<v2[t2[x]].size();i++)
	{
		if (a[v2[t2[x]][i]]==y) return 0;
	}
	for (int i=0;i<v3[t3[x]].size();i++)
	{
		if (a[v3[t3[x]][i]]==y) return 0;
	}
	int f=0;
	for (int i=0;i<v5[x].size();i++)
	{
		int h=v5[x][i];
		for (int j=0;j<v4[h].size();j++)
		{
			if (a[v4[h][j]]==y) return 0;
		}
	}
	return 1;
}

void pd()
{
	ans++;
//	cout<<ans<<endl;
	if (ans==n)
	{
		cout<<"Found"<<endl;
		cout<<a[1];
		for (int i=2;i<=31;i++) cout<<" "<<a[i];
		cout<<endl;
		exit(0);
	}
}

void dfs(int dep)
{
//	cout<<dep<<endl;
	if (dep>31) {pd();return;}
	else
	{
		if (a[dep]!=0) dfs(dep+1);
		for (int i=1;i<=k;i++)
		{
			if (ch(dep,i)==1)
			{
				a[dep]=i;
				dfs(dep+1);
				a[dep]=0;
			}
		}
		return;
	}
}

int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	k=read();
	n=read();
	work();
	int p=0;
	for (int i=1;i<=31;i++) a[i]=read();
	for (int i=1;i<=31;i++)
	{
		v1[t1[i]].push_back(i);
		v2[t2[i]].push_back(i);
		v3[t3[i]].push_back(i);
		if (b1[i]==1)
		{
			v.push_back(i);
			if (i==5) 
			{
				v4[i].push_back(i-4);
				v5[i-4].push_back(i);
				v4[i].push_back(i-3);
				v5[i-3].push_back(i);
			}
			else
			{
				v4[i].push_back(i-6);
				v5[i-6].push_back(i);
				v4[i].push_back(i-5);
				v5[i-5].push_back(i);
			}
			if (i==27)
			{
				v4[i].push_back(i+3);
				v5[i+4].push_back(i);
				v4[i].push_back(i+4);
				v5[i+3].push_back(i);
			}
			else
			{
				v4[i].push_back(i+5);
				v5[i+5].push_back(i);
				v4[i].push_back(i+6);
				v5[i+6].push_back(i);
			}
			v4[i].push_back(i+1);
			v5[i+1].push_back(i);
			v4[i].push_back(i-1);
			v5[i-1].push_back(i);
		}
	}
	dfs(1);
	cout<<"No way"<<endl;
	return 0;
}


