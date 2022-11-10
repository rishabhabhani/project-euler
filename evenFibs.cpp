#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> evenFibs;

void computeFibs(long long x, long long y)
{
  long long z;
  while (y < 4 * 10e16)
  {
    if (y % 2 == 0)
      evenFibs.push_back(y);
    z = x + y;
    x = y;
    y = z;
  }
}

long long findSum(long long n)
{
  long long sum = 0;
  for (int i = 0; i < evenFibs.size(); i++)
  {
    if (evenFibs[i] > n)
      break;
    sum += evenFibs[i];
  }
  return sum;
}

int main()
{
  int t;
  cin >> t;
  computeFibs(1, 2);
  while (t--)
  {
    long long n;
    cin >> n;
    long long sum = findSum(n);
    cout << sum << endl;
  }
  return 0;
}
