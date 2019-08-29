#include<bits/stdc++.h>

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
}

inline void readstring(string &s)
{
	s = "";
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		s = s + ch, ch = getchar();
}

int main(int argc, char *argv[])
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	int T;
	read(T);
	while (T--)
	{
		int tot = 0;
		string s, now = "19260817";
		readstring(s);
		sort (s.begin(), s.end());
		while (now != "")
		{
			now = "";
			int len = s.size(), fir, sec = -1;
			fir = s[0] - '0', s[0] = '0';
			for (int i = 1; i < len; ++i)
			{
				if (sec == -1 && s[i] - '0' != fir)
					sec = s[i] - '0';
				if (sec == -1)
					s[i] -= fir;
				else s[i] -= sec;
				if (s[i] != '0')
					now = now + s[i];
			}
			s = now;
			++tot;
		}
		printf ("%d\n", tot);
	}
	return 0;
}
