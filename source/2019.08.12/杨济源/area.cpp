#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("area.in", "r", stdin);
	freopen ("area.out", "w", stdout);
	int x, y;
	scanf ("%d", &x, &y);
	
	x++; y++;
	
	if (y % 4 == 2)
	{
		if (x % 4 == 2)
		{
			if (((x - 1) / 4 + 1) % 2 == 0 && ((y - 1) / 4 + 1) % 2 == 0) puts("1");
		}
		else if (((x - 1) / 4 + 1) % 2 == 0 && ((y - 1) / 4 + 1) % 2 == 0) puts("14");
		else puts("5");
	}
	else puts("infinity");
  return 0;
}
