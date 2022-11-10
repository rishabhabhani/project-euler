#include <iostream>
#include <math.h>
using namespace std;

long long largestPythagoreanProduct(long long sum)
{
  long long largestProduct = -1;

  for (long long a = 3; a < sum / 2; a++)
  {
    long long num = (a - sum) * (a - sum) - (a * a);
    long long den = 2 * (a - sum) * -1;
    if (num % den != 0)
      continue;
    long long b = num / den;
    long long c = sum - a - b;
    long long product = a * b * c;
    if (product > largestProduct)
      largestProduct = product;
  }

  return largestProduct;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    long long product = largestPythagoreanProduct(n);
    cout << product << endl;
  }

  return 0;
}