#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "area"
#define INT64 "%lld"
typedef long long int64;

enum STATE {P0, P1, P2D, P2R, M1, M2D, M2R, STATE_NUM};
const int DX = STATE_NUM, DY = STATE_NUM * 2;

int main (void)
{
 int i, x, y, st;
 int64 area, p0, p1, p2, m1, m2, p0n, p1n, p2n, m1n, m2n;
// freopen (TASKNAME ".in", "rt", stdin);
// freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d", &x, &y) != EOF)
 {
  area = p0 = 1; p1 = p2 = m1 = m2 = 0;
  st = P0;
  for (i = 0; i < 31; i++)
  {
   p0n = p0 * 3 + p1 + p2 * 2;
   p1n = m1;
   p2n = p1 + p2 + m2;
   m1n = p0 + p1 + m1 * 2 + m2 * 2;
   m2n = p2 + m2;
   switch (st + DX * ((x >> i) & 1) + DY * ((y >> i) & 1))
   {
    case P0:
    case P1:
    case P2D:
    case P2R:
    case P0 + DX:
    case P0 + DY:
     area = p0n;
     st = P0;
     break;
    case M1 + DX + DY:
     st = P1;
     break;
    case P1 + DY:
    case P2D + DY:
    case M2D + DX + DY:
     st = P2D;
     break;
    case P1 + DX:
    case P2R + DX:
    case M2R + DX + DY:
     st = P2R;
     break;
    case M1 + DX:
    case M2D + DX:
    case M1 + DY:
    case M2R + DY:
    case P0 + DX + DY:
     area = m1n - p1;
     // fallthrough
    case P1 + DX + DY:
     st = M1;
     break;
    case M2D + DY:
    case P2D + DX + DY:
     st = M2D;
     break;
    case M2R + DX:
    case P2R + DX + DY:
     st = M2R;
     break;
    default:
     st = STATE_NUM; // isolated component
     break;
   }
   p0 = p0n;
   p1 = p1n;
   p2 = p2n;
   m1 = m1n;
   m2 = m2n;
   if (st == STATE_NUM) break;
  }
  if (st == P0) printf ("infinity\n");
  else printf (INT64 "\n", area);
 }
 return 0;
}
