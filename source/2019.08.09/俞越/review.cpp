#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long 
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
LL Y;
int S,T,TTT;
vector<pair<int,int> > ans;
void make(int lv){
	if (!TTT){
		if (lv==0){
			T++;
			TTT=T;
			ans.pb(make_pair(S,T));
			return ;
		}
		int tmp=S;
		F(i,1,lv){
			++T;
//			cout<<S<<" "<<T<<"   ggg\n";
			ans.pb(make_pair(tmp,T));
			++T;
			ans.pb(make_pair(T-1,T));
			ans.pb(make_pair(tmp,T));
			tmp=T;
		}
		TTT=T;
	}
	else {
		if (lv==0){
			T++;
			ans.pb(make_pair(S,T));
			ans.pb(make_pair(T,TTT));
			return ;
		}
		int tmp=S;
		F(i,1,lv){
			++T;
			ans.pb(make_pair(tmp,T));
			++T;
			ans.pb(make_pair(T-1,T));
			ans.pb(make_pair(tmp,T));
			tmp=T;
		}
		ans.pb(make_pair(T,TTT));
	}
//	cout<<lv<<" "<<T<<" FFFFUCK\n";
//	system("pause");
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y; S=T=1; 
	F(i,0,63){
		if (Y>>i&1){
			make(i);
		}
	}
	cout<<T<<" "<<SZ(ans)+1<<"\n";
	F(i,0,SZ(ans)){
		int x=ans[i].first,y=ans[i].second;
		if (x>TTT) x--;
		if (y==TTT) y=T,cout<<x<<" "<<T<<"\n";
		else {
			if (y>TTT) y--;
			cout<<x<<" "<<y<<"\n";	
		}
		
	}
	return 0;
}


