#include<bits/stdc++.h>
using namespace std;
template <typename T>void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,cnt1,cnt2,cnt0,mi,minum,sum1,sum2,sum3,sum0,len,lef;
long long ans;
priority_queue <int > cnt[5];
vector <int > rq3;
string s;
int w;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
    int x;
    read(n);
    for(int i=1;i<=n;i++)
    {
    	cin>>s;read(w);
    	if(s[0]=='0'&&s[1]=='0') cnt[0].push(w),sum0+=w;
    	else
    	if(s[0]=='1'&&s[1]=='0') cnt[1].push(w),sum1+=w;
    	else if(s[0]=='0'&&s[1]=='1') cnt[2].push(w),sum2+=w;
    	
		else rq3.push_back(i),sum3+=w;
	}
	cnt0=cnt[0].size();
	cnt1=cnt[1].size()+rq3.size();
	cnt2=cnt[2].size()+rq3.size();
	if(cnt1<cnt2){mi=cnt1;minum=1;}
	else {mi=cnt2;minum=2;}
	
	if(mi*2>=n)
	{
		ans=sum0+sum1+sum2+sum3;
		cout<<ans;
		return 0;
	}
	else
	{
        	if(minum==1)
		    {
			     ans=sum1+sum3;
			     len=mi*2;
			     lef=mi-rq3.size();
			     for(register int i=1;i<=lef;i++)
			     {
			     	ans+=cnt[2].top();
			     	cnt[2].pop();
				 }
				 for(register int i=1;i<=cnt[2].size();i++)
				 {
				 	x=cnt[2].top();
				 	cnt[0].push(x);
				 	cnt[2].pop();
				 }
				 x=mi-lef;
				 for(register int i=1;i<=x;i++)
				 {
				 	ans+=cnt[0].top();
				 	cnt[0].pop();
				 }
				 cout<<ans;
				 return 0;
			}	
			else
			{
				ans=sum2+sum3;
			     len=mi*2;
			     lef=mi-rq3.size();
			     for(register int i=1;i<=lef;i++)
			     {
			     	ans+=cnt[1].top();
			     	cnt[1].pop();
				 }
				 for(register int i=1;i<=cnt[1].size();i++)
				 {
				 	x=cnt[1].top();
				 	cnt[0].push(x);
				 	cnt[1].pop();
				 }
				 x=mi-lef;
				 for(register int i=1;i<=x;i++)
				 {
				 	ans+=cnt[0].top();
				 	cnt[0].pop();
				 }
				 cout<<ans;
				 return 0;
			}
	}
	return 0;
 } 
