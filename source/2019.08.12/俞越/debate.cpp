#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
#define lim (tot+2)/2
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
priority_queue<LL> q[4];
int trans(string g){
	if (g=="00") return 0;
	if (g=="01") return 1;
	if (g=="10") return 2;
	return 3;
}
int mx(int a,int b,int c,int d){
	if (a>=b && a>=c && a>=d) return 1; 	
	if (b>=a && b>=c && b>=d) return 2; 
	if (c>=b && c>=a && c>=d) return 3; 
	return 4; 
}
const int inf=1e9;
int tp(int o){
	if (q[o].empty()) return -inf;
	return q[o].top();
}
int n;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read(); 
	F(i,1,n){
		string o;
		cin>>o;
		int tp=trans(o); 
		q[tp].push(read());
	}
	int num1=0,num2=0,tot=0,ans=0;//
		
		while (q[3].size()){
			num1++; num2++; tot++; ans+=q[3].top();	q[3].pop();
			if (!(q[1].size()+q[2].size()+q[0].size())) continue;
			int tmp=mx(tp(0),tp(1),tp(2),-inf);
			if (tmp==1){
				ans+=q[0].top(); q[0].pop(); tot++;
			}
			else if (tmp==2){
				num1++; tot++;
				ans+=q[1].top(); q[1].pop();
			}
			else {
				num2++; tot++;
				ans+=q[2].top(); q[2].pop();
			}
		}
//		cout<<ans<<" "<<num1<<" "<<num2<<"\n";
		while (q[2].size()){//num2 2ok 1..
			if (!q[1].size() && num1<lim) break;
			num2++; ans+=q[2].top(); q[2].pop(); tot++;
			if (num1>=lim && num2>=lim){//0,1
				if (!(q[0].size()+q[1].size())) continue;
				int tmp=mx(tp(0),tp(1),-inf,-inf);
				if (tmp==1){
					ans+=q[0].top(); q[0].pop(); tot++;
				}
				else if (tmp==2){
					num1++; tot++;
					ans+=q[1].top(); q[1].pop();
				}
			}
			else {//1
				if (!(q[1].size())) continue;
				int tmp=mx(tp(1),-inf,-inf,-inf);
				if (tmp==1){
					num1++; tot++;
					ans+=q[1].top(); q[1].pop(); 
				}
			}
			
		}
		while (q[1].size()){//num1 ok
			if (num2<lim) break;
			num1++; ans+=q[1].top(); q[1].pop();
			if (num1>=lim && num2>=lim){//0
				if (!q[0].size()) continue;
				int tmp=mx(tp(0),-inf,-inf,-inf);
				if (tmp==1){
					ans+=q[0].top(); q[0].pop(); tot++;
				}
			}
		}
		while (q[0].size() && num1>=lim && num2>=lim){
			tot++; ans+=q[0].top(); q[0].pop();
		}
	cout<<ans<<"\n";
	return 0;
}

