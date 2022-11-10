#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long> primeSums(1000001, 0);

void generatePrimes(unsigned long long n)
{
  for (long long i = 2; i <= n; i++)
  {
    if (primeSums[i] == 0)
    {
      primeSums[i] = primeSums[i - 1] + i;
      for (long long j = i * i; j <= n; j += i)
      {
        primeSums[j] = -1;
      }
    }
    else
    {
      primeSums[i] = primeSums[i - 1];
    }
    // cout << primeSums[i] << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  vector<unsigned long long> ns;
  unsigned long long maxN = 0;
  while (t--)
  {
    unsigned long long n;
    cin >> n;
    ns.push_back(n);
    if (n > maxN)
      maxN = n;
  }

  generatePrimes(maxN);
  for (int i = 0; i < ns.size(); i++)
  {
    cout << primeSums[ns[i]] << endl;
  }

  return 0;
}