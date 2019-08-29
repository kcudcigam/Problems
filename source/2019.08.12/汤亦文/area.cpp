#include<bits/stdc++.h>
using namespace std;
#define RG register int
#define M 400100
inline int read()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
inline long long power(int a,int b)
{
	long long ans=1;
	for(;b;b>>=1)
	{
		if(b&1) ans=ans*a;
		a=a*a;
	}
	return ans;
}
struct rrr
{
	int u,v;
}rr;
queue<rrr>q;
int x,y;
long long a[50];
int s[3050][3050];
bool vi[3050][3050];
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	x=read(),y=read();
	for(RG i=1;i<=30;i++) a[i]=power(2,i);
	int l=1,r=30;
	if(x==0||y==0) cout<<"infinity";
	else
	{
		int k=max(x,y);
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(a[mid]<k) l=mid+1;
			else r=mid;
		}
		//cout<<a[l-1];
		if(a[l]==k) 
		{
			cout<<"infinity";
			fclose(stdin);fclose(stdout);
			return 0;
		}
		s[0][0]=s[0][1]=s[1][0]=1;
		s[1][1]=-1;
		for(RG k=1;k<l;k++)
		{
			long long len=a[k];
			for(RG i=0;i<=len-1;i++)
			for(RG j=0;j<=len-1;j++)
			{
				s[i+len][j]=s[i][j];
				s[i][j+len]=s[i][j];
				s[i+len][j+len]=-s[i][j];
			}
		}
        long long answ=0;
        while(q.size()) q.pop();
        rr.u=x,rr.v=y;
        q.push(rr);
        while(q.size())
        {
        	rr=q.front();q.pop();++answ;
        	int xx=rr.u,yy=rr.v;
        	int ww=s[xx][yy];
        	vi[xx][yy]=1;
        	if(s[xx+1][yy]==ww&&!vi[xx+1][yy])
        	{
        		if(yy==0)
				{
					cout<<"infinity";
					fclose(stdin);fclose(stdout);
					return 0;
				}
				rr.u=xx+1,rr.v=yy;
				q.push(rr);
			}
			if(s[xx][yy+1]==ww&&!vi[xx][yy+1])
        	{
        		if(xx==0)
				{
					cout<<"infinity";
					fclose(stdin);fclose(stdout);
					return 0;
				}
				rr.u=xx,rr.v=yy+1;
				q.push(rr);
			}
			if(s[xx][yy-1]==ww&&!vi[xx][yy-1])
        	{
        		if((yy-1)==0||xx==0)
				{
					cout<<"infinity";
					fclose(stdin);fclose(stdout);
					return 0;
				}
				rr.u=xx,rr.v=yy-1;
				q.push(rr);
			}
			if(s[xx-1][yy]==ww&&!vi[xx-1][yy])
        	{
        		if(yy==0||(xx-1)==0)
				{
					cout<<"infinity";
					fclose(stdin);fclose(stdout);
					return 0;
				}
				rr.u=xx-1,rr.v=yy;
				q.push(rr);
			}
		}
		cout<<answ;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
