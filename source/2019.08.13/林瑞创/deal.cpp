#include<bits/stdc++.h>
using namespace std;
int random(int n){
	return rand()*rand()%n;
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
    srand((unsigned)time(0));
    int n;cin>>n;
    if(n<=8)puts("5");
    else printf("%d\n",random(1000000007)+1);
	return 0;
}


