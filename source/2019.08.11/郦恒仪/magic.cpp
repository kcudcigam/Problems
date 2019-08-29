#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,l,s,d,f,r;
string st;
char str[10005];
void dg(int dep){
	if(dep>n){
		int d=0;
		for(int i=1;i<=st.length();i++){
			if(st[i-1]!=str[i]){
				d=1;
				break;
			}
		}
		if(d==0){
			/*for(int i=1;i<=n;i++){
				cout<<str[i];
			}
			cout<<"1OK"<<endl;*/
			s++;
		}
		else{
			d=0;
			for(int i=1;i<=st.length();i++){
				if(st[i-1]!=str[n-st.length()+i]){
					d=1;
					break;
				}
			}
			if(d==0){
				s++;
				/*for(int i=1;i<=n;i++){
					cout<<str[i];
				}
				cout<<"2OK"<<endl;*/
			}
			else{
				d=0;
				int t=0;
				for(int i=1;i<=st.length();i++){
					if(st[i-1]!=str[i]){
						t=i;
					}
				}
				for(int i=t;i<=st.length();i++){
					if(st[i-1]!=str[n+i-st.length()]){
						d=1;
						break;
					}
				}
				if(d==0){
					/*for(int i=1;i<=n;i++){
						cout<<str[i];
					}
					cout<<"3OK"<<endl;*/
					s++;
				}
			}
		}
	}
	else{
		for(int i=1;i<=26;i++){
			str[dep]=i+'a'-1;
			dg(dep+1);
		}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	cin>>st;
	s=0;
	dg(1);
	int ans=1;
	for(i=1;i<=n;i++){
		ans*=26;
	}
	cout<<ans-s<<endl;
	return 0;
}


