#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int isSatisfied(int x, vector<int> factors)
{
  for (int i = 0; i < factors.size(); i++)
  {
    if (x % factors[i] == 0)
      x /= factors[i];
  }
  return x;
}

vector<int> generateFactors(int limit)
{
  vector<int> factors;
  vector<int> additionals;
  for (int i = 2; i <= limit; i++)
  {
    int r = isSatisfied(i, factors);
    if (r > 1)
    {
      factors.push_back(r);
    }
  }
  return factors;
}

int getMultiple(int limit)
{
  vector<int> factors = generateFactors(limit);
  unsigned long long multiple = 1;
  for (auto itr = factors.begin(); itr != factors.end(); itr++)
  {
    multiple *= (*itr);
  }
  return multiple;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    long long m = getMultiple(n);
    cout << m << endl;
  }
  return 0;
}