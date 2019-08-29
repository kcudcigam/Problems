#include<bits/stdc++.h>
#define ll long long
#define fir(a, b, c) for(int a = b; a <= c; a ++)
#define in inline
using namespace std;

template <typename T> void read(T &xx){
int f=1;xx=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) xx=xx*10+c-'0';
xx*=f;
}

const int N = 1e+5;
int n, t, x, y, T; 	

int main()
{
 	freopen("charlotte.in","r",stdin);
  	freopen("charlotte.out","w",stdout);
	read(T);
	while(T>0)
	{
		T--;
		read(n);
		int dis = 0, dt = 0;
		int px = 0, py = 0, pt = 0;
		bool fin = 0;
		fir(i, 1, n)
		{
			read(t); read(x); read(y);
			dis = abs(x-px) + abs(y-py);
			dt = t - pt;
			pt = t;
			px = x, py = y;
			if(dis > dt)
			{
				cout<<"No"<<endl;
				fin = 1;
				break;	
			}
			if(dis == dt) continue;
			if(dis == 0)
				if(dt % 2 == 0) continue;
				else 
				{
					cout<<"No"<<endl;
					fin = 1;
					break;
				}
			if((dt % 2) == (dis % 2)) continue;
				else
				{
					cout<<"No"<<endl;
					fin = 1;
					break;
				}
		}
		if(!fin) cout<<	"Yes"<<endl;
	}
	return 0;
}


