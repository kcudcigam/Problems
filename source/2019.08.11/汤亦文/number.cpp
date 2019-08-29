#include<bits/stdc++.h>
using namespace std;
int t,n[300100],m;
bool v[20];
int a[20],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	 char c=getchar();int w=1;
	 m=0;
	 int cnt=0;
	 bool ju=0;
	 memset(v,0,sizeof(v));
	 while((c>'9'||c<'0')&&c!='-') c=getchar();
	 if(c=='-') w=-1,c=getchar();
	 while(c>='0'&&c<='9')
	 {
		if(!ju)
		{
			n[++m]=c-'0';
			if(!v[n[m]])
		  {
			++cnt;
			v[n[m]]=1;
		  }
		  if(m>300000) ju=1;
		}
		c=getchar();
	 }
	 if(cnt<=2) cout<<"1"<<endl;
	 else if(m<=300000&&cnt<=4)
	 {int numm=0;bool jju=0;
	 	for(int i=0;i<=10;i++)
	 	if(v[i]) a[++tot]=i,numm+=i;
	 	if(tot==4)
	 	{for(int j=1;j<=4;j++)
	 		for(int k=1;k<=4;k++)
	 		{
	 			if(j==k) continue;
	 			if(a[j]+a[k]==(numm-a[j]-a[k])&&(a[j]+a[k])<10)
	 			{
	 				jju=1;
	 				break;
				}
			}
			if(!jju)
			cout<<"3"<<endl;
			else cout<<"2"<<endl;
		}
		else cout<<"2"<<endl;
	 }
	 else cout<<"3"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
