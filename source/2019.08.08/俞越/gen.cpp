#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("tree.in","w",stdout);
	cout<<"1\n";
	srand(time(0));
	int n=2e5;
	cout<<n<<" "<<rand()%100000+1<<"\n";
	for (int i=2;i<=n;i++){
		int x=rand()%(i-1)+1;
		cout<<x<<" "<<i<<"\n";
	}
	for (int i=1;i<=n;i++){
		cout<<0<<" ";
	}
	cout<<"\n";
	for (int i=1;i<=n;i++){
		cout<<1<<" ";
	}
	cout<<"\n";
	return 0;
}

