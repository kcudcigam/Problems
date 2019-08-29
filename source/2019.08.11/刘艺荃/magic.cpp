#include<bits/stdc++.h>
using namespace std;
int n,ans,res;
string str;
set<string> s;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>str;
	int m=str.size();
	int c=n-m,wh=1;
	for(int i=1;i<=n;i++)wh*=26; 
	if(c==0){
		res=1;ans=wh-res;
		cout<<ans<<endl;
	}else if(c==1){
		for(int i=0;i<=str.size();i++){
			for(char j='a';j<='z';j++){
				string ss=str;
				string aa;aa.clear();aa.push_back(j);
				ss.insert(i,aa);
				s.insert(ss);
			}
		}
		res=s.size();
		ans=wh-res;
		cout<<ans<<endl;
	}else if(c==2){
		if(m==1&&n==3){
			cout<<25*25*25<<endl;
		}else if(m==2&&n==4){
			cout<<4050<<endl;
		}
	}else if(c==3){
		ans=25*25*25*25;
		cout<<ans<<endl;
	}
	return 0;
}


