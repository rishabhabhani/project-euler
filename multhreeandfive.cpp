#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long findSum(int n)
{
  long long sum = 0;

  long long int a3 = (n - 1) - (n - 1) % 3;
  long long int a5 = (n - 1) - (n - 1) % 5;
  long long int a15 = (n - 1) - (n - 1) % 15;

  long long int n3 = (a3 - 3) / 3 + 1;
  long long int n5 = (a5 - 5) / 5 + 1;
  long long int n15 = (a15 - 15) / 15 + 1;

  sum += n3 * (a3 + 3) / 2;
  sum += n5 * (a5 + 5) / 2;
  sum -= n15 * (a15 + 15) / 2;

  return sum;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    long long sum = findSum(n);
    cout << sum << endl;
  }
  return 0;
}
