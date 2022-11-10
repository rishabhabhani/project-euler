#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <iterator>
using namespace std;

vector<int> primes;

bool checkPrime(long long x)
{
  if (x == 2 || x == 3)
    return true;
  if (x % 2 == 0 || x % 3 == 0)
    return false;

  for (int i = 0; i < primes.size(); i++)
  {
    if (x % primes[i] == 0 && x != primes[i])
      return false;
  }
  return true;
}

void generatePrimes()
{
  primes.push_back(5);
  primes.push_back(7);

  for (int i = 11; i < 10000; i += 2)
    if (checkPrime(i))
      primes.push_back(i);
}

int main()
{
  generatePrimes();

  int t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;

    if (checkPrime(n))
    {
      cout << n << endl;
      continue;
    }

    for (int i = 2; i < n / 2; i++)
    {
      if (n % i == 0)
      {
        long long x = n / i;
        if (checkPrime(x))
        {
          cout << x << endl;
          break;
        }
      }
    }
  }
}