#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int P = 998244353;
template <typename T> inline void rd(T &x)
{
	x=0; int f=1; char ch=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
int Pow(int x,int y)
{
	if(y==1) return x%P;
	return ((Pow(x,y/2)%P)*(Pow(x,y-y/2)%P))%P;
}
int n,len;
string s;
int comP(int l,int r,string str)
{
	string st="";
	for(int i=0; i<l; ++i) st+=s[i];
	for(int i=0; i<n-len; ++i) st+=" ";
	for(int i=len-l-1; i<len; ++i) st+=s[i];
	if(str=="") return comP(l+1,r-1,st);
	int cnt=0; bool flg=0;
	for(int i=0; i<st.size(); ++i)
	{
		if(st[i]==' ' && str[i]==' ') cnt+=26;
		if((st[i]==' ' || str[i]==' ' )&& st[i]!=str[i]) flg=1;
	}
	if(flg==1) ++cnt;
	if(r==0) return cnt;
	return comP(l+1,r-1,st)+cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	rd(n);
	cin>>s;
	len=s.size();
	int tot=Pow(26,n);
	wrote(tot-(n-len)*(len+1)*26+comP(0,len,""));
	return 0;
}

