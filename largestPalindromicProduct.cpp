#include <iostream>
#include <set>
#include <math.h>
using namespace std;

set<int, greater<int>> palindromes;

int reverse(int n, int counter)
{
  if (n < 10)
    return n;
  return (n % 10) * pow(10, counter) + reverse(n / 10, counter - 1);
}

void generatePalindromes()
{
  for (int i = 100; i < 1000; i++)
  {
    for (int j = 100; j < 1000; j++)
    {
      int num = i * j;
      int counter = (num < 100000) ? 4 : 5;
      if (num == reverse(num, counter))
      {
        palindromes.insert(num);
        // cout << num << endl;
      }
    }
  }
}

int main()
{
  generatePalindromes();
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int p = *palindromes.upper_bound(n);
    cout << p << endl;
  }
  return 0;
}