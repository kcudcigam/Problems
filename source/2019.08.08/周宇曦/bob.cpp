#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &FF)
{
    int RR=1;FF=0;char CH=getchar();
    while(!isdigit(CH)&&CH!='-') CH=getchar();
    if(CH=='-') RR=-1;else FF=CH^48;CH=getchar();
    while(isdigit(CH)) FF=(FF<<1)+(FF<<3)+(CH^48),CH=getchar(); FF*=RR;
}
int ai[16],Ans,n,depth;
int fst[100010],nxt[100010],num[100010],now,flag[100010];
int is[100010],fl[100010];
void add(int u,int v)
{
    nxt[++now]=fst[u],fst[u]=now,num[now]=v;
}
int maketh(int a,int b,int c,int d)
{
	return a*17*17*17+b*17*17+c*17+d;
}
int minx(int a,int b,int c,int d)
{
	int ans=INT_MAX;
	if(a!=0) ans=min(ans,a);
	if(b!=0) ans=min(ans,b);
	if(c!=0) ans=min(ans,c);
	if(d!=0) ans=min(ans,d);
	return ans;
}
void cha(int &a,int &b,int &c,int x)
{
	if(a==0){a=ai[x];return;}
	if(b==0){b=ai[x];return;}
	if(c==0){c=ai[x];return;}
}
bool dfs(int xi)
{
	if(!fl[xi]) return false;
	if(is[xi]) return true;
	if(flag[xi]) return false;
	flag[xi]=depth;
	if(!num[fst[xi]])
	{
		is[xi]=0;
		return false;
	}
    if(flag[num[fst[xi]]]==depth)
    {
    	is[xi]=1;
    	return true;
	}
	is[xi]=dfs(num[fst[xi]]);
    return is[xi];
}
void check(int a)
{
	while(a)
	{
		cout<<a%17-1<<" ";
		a/=17;
	}
	cout<<endl;
}
int main()
{
    freopen("bob.in","r",stdin);
    freopen("bob.out","w",stdout);
	read(n);
	for(int i=1;i<=n-1;i++) read(ai[i]);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int v=0;v<=n;v++)
				{
					if(i||j||k||v)
					{
						int ii=i,jj=j,kk=k,vv=v,fi=0;
						if(i!=0)
						{
							ii-=1;
							if(ii==0) fi=1;
							if(ii!=0) cha(jj,kk,vv,ii);
						}
						if(j!=0)
						{
							jj-=1;
							if(jj==0) fi=1;
							if(jj!=0) cha(ii,kk,vv,jj);
						}
						if(k!=0)
						{
							kk-=1;
							if(kk==0) fi=1;
							if(kk!=0) cha(ii,jj,vv,kk);
						}
 						if(v!=0)
						{
							vv-=1;
							if(vv==0) fi=1;
							if(vv!=0) cha(ii,jj,kk,vv);
						}
						//cout<<i<<" "<<j<<" "<<k<<" "<<v<<"  "<<ii<<" "<<jj<<" "<<kk<<" "<<vv<<" "<<endl;
						fl[maketh(i+1,j+1,k+1,v+1)]=fi;
						add(maketh(i+1,j+1,k+1,v+1),maketh(ii+1,jj+1,kk+1,vv+1));
					}
				}
			}
		}
	}
	int maxn=maketh(n+1,n+1,n+1,n+1);
	for(int i=1;i<=maxn;i++)
		if(!flag[i])
			depth++,dfs(i);
	for(int i=1;i<=maxn;i++)
		if(is[i])
			Ans++;
	cout<<Ans<<endl;
    return 0;
}



