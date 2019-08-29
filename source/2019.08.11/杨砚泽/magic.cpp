#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}
inline long long log2(long long p)
{
	if (p==0) return 1;
	if (p==1) return 26;
	else {
		long long k=log2(p/2)%P;
		if (p%2==0) return (k*k)%P;
		else return (k*k*26)%P;
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
    ios::sync_with_stdio(false);
    long long n;
    string s;
    read(n);
    cin>>s;
    long long t1=log2(n)%P;
    long long t2;
    if (n==s.size())
    {
       t2=1;	
	}
  else {
  	long long k=log2(n-s.size());
   t2=(k+(k/26*25)*s.size())%P;
  }
    if (t1<t2) cout<<t1+P-t2<<endl;
    else cout<<t1-t2<<endl;   
	return 0;
}


