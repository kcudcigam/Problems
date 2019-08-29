#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
priority_queue<int> k,k1,k2,K;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,x;
	read(n);
	long long sum=0,num=0,s=0,ansi=0,ans=0,qi=0,c1=0,c2=0,rs=0,fl=0,S=0;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a; read(x);
		if(a=="00") k.push(-x),s++,S+=x;
		else if(a=="10") k1.push(x);
		else if(a=="01") k2.push(x);
		else sum+=x,num++;
	}
	while(!k1.empty()&&!k2.empty())
	{
		ansi+=k1.top()+k2.top();
		k1.pop(),k2.pop(); qi++;
	}
	while(!k1.empty()) K.push(k1.top()),k1.pop(),fl=1;
	while(!k2.empty()) K.push(k2.top()),k2.pop(),fl=2;
	c1=c2=num+qi;rs=num+qi*2+min(num,s)+1;
	ansi+=S+sum;
	k.push(0);
	for(int i=1;i<=s-min(num,s);i++)
	{
		ansi-=-1*k.top();
		k.pop();
	}
	for(int i=min(num,s);i>=0;i--)
	{
		int lst=0;
		ansi-=k.top()*-1; k.pop(); rs--;
		while(c1>=ceil(double(rs)/2.0)&&c2>=ceil(double(rs)/2.0)&&!K.empty())
		{
			ansi+=K.top(); lst=K.top();
			K.pop(); rs++;
			if(fl==1) c1++; else c2++;
		}
		if(!(c1>=ceil(double(rs)/2.0)&&c2>=ceil(double(rs)/2.0)))
		{
			rs--; if(fl==1) c1--; else c2--;
			ansi-=lst;K.push(lst);
		}
		ans=max(ans,ansi);
	}
	cout<<ans<<endl;
	return 0;
}


