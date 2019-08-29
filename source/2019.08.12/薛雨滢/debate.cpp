#include<bits/stdc++.h>

using namespace std;

int n,fir,sec,c,ans;
int cnt1,cnt2,cnt;
int tem0,tem1,tem2;

priority_queue<int> q0,q1,q2;

void read(int &p)
{
	p=0;int flag=1;char s=getchar();
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
}


int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);char s;
	for(int i=1;i<=n;i++)
	{
		s=getchar();while(!isdigit(s)) s=getchar();
		fir=s-'0';
		s=getchar();while(!isdigit(s)) s=getchar();
		sec=s-'0';
		read(c);
		if((fir&&sec)) ans+=c,cnt1++,cnt2++,cnt++;
		if(!fir&&!sec) q0.push(c);
		if(fir&&!sec) q1.push(c);
		if(!fir&&sec) q2.push(c);
	}
	
	//cout<<q0.size()<<" "<<q1.size()<<" "<<q2.size()<<endl;
	
	while((q0.size()||q1.size()||q2.size()))
	{
		int flag=0;
		if(q0.size()) tem0=q0.top();
		else tem0=-1;
		if(q1.size()) tem1=q1.top();
		else tem1=-1;
		if(q2.size()) tem2=q2.top();
		else tem2=-1;
	
		if(tem0>=tem1&&tem0>=tem2&&cnt1>=(cnt+2)/2&&cnt2>=(cnt+2)/2)
		{
			flag=1;ans+=tem0;q0.pop();cnt++;continue;
		}
		if(tem1>=tem0&&tem1>=tem2&&cnt1+1>=(cnt+2)/2&&cnt2>=(cnt+2)/2)
		{
		//	cout<<"B";
		flag=1;
			ans+=tem1;q1.pop();cnt1++;cnt++;continue;
		}
		if(tem2>=tem0&&tem2>=tem1&&cnt1>=(cnt+2)/2&&(cnt2+1)>=(cnt+2)/2)
		{
		//	cout<<"C";
		flag=1;
			ans+=tem2;q2.pop();cnt2++;cnt++;continue;
		}
		if(!flag) break;
	}
	
	while(q1.size())
	{
		if(cnt1+1>=(cnt+2)/2&&cnt2>=(cnt+2)/2) 
		{
			ans+=q1.top();q1.pop();cnt1++,cnt++;
		}
		else break;
	}
	while(q2.size())
	{
		if(cnt1>=(cnt+2)/2&&(cnt2+1)>=(cnt+2)/2)
		{
			ans+=q2.top();q2.pop();cnt2++,cnt++;
		}
		else break;
	}
	
	while(q1.size()&&q2.size())
	{
		ans+=q1.top()+q2.top();
		q1.pop();q2.pop();
	}
	cout<<ans;
	return 0;
}
