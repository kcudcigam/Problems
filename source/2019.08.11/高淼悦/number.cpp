#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar();
	int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n;
}

int pd(int x,string s)
{
	char ch='0';
	for (int i=x;i<s.size();i++)
	{
		if (s[i]!=0)
		{
			if (ch=='0') ch=s[i];
			else if (ch!=s[i]) return 0;
		}
	}
	return 1;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	cin>>T;
	while (T>=1)
	{
		T--;
		string s;
		cin>>s;
		if (pd(0,s)==1) 
		{
		//	cout<<pd(0,s)<<endl;
			cout<<1<<endl;
			continue;
		}
		sort(s.begin(),s.end());
		int t=0,f=0;
		while (s[t]=='0') t++;
		f=t;
		while (pd(t,s)==0)
		{
		
			f++;
		//	t++;//	cout<<f<<" "<<t<<endl;
			for (int i=t+1;i<s.size();i++)
			{
				s[i]=int(s[i])-int(s[t])+'0';
			//	cout<<f<<" "<<i<<" "<<s[i]<<endl;
			}
			s[t]='0';
			while (s[t]=='0') t++;
		//	cout<<f<<" "<<t<<" "<<s<<" "<<s.size()<<endl;
		}
		cout<<(f+2)/2<<endl;
	}
	return 0;
}


