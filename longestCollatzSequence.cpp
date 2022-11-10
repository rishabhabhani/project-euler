#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <chrono>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

ULL hashed[5000001];
ULL results[5000001];

ULL generateSequence(LL n)
{
  if (hashed[n] != 0)
  {
    return hashed[n];
  }

  if (n % 2 == 0)
  {
    hashed[n] += generateSequence(n / 2) + 1;
  }
  else
  {
    ULL temp = 3 * n + 1;
    ULL count = 1;
    while (temp > 5000001)
    {
      if (temp % 2 == 0)
      {
        temp /= 2;
      }
      else
      {
        temp = 3 * temp + 1;
      }
      count++;
    }
    hashed[n] = count + generateSequence(temp);
  }
  return hashed[n];
}

void preGenerateSequences()
{
  hashed[1] = 1;
  ULL count = 0;
  for (ULL i = 2; i < 5000001; i *= 2)
  {
    hashed[i] = ++count;
  }
  for (ULL i = 1; i < 5000001; i++)
  {
    generateSequence(i);
  }
}

void preComputeResults()
{
  results[1] = 1;
  for (ULL i = 2; i < 5000001; i++)
  {
    if (hashed[i] >= hashed[results[i - 1]])
    {
      results[i] = i;
    }
    else
    {
      results[i] = results[i - 1];
    }
  }
}

int main()
{
  int t;
  cin >> t;
  vector<LL> n(t);
  for (int i = 0; i < t; i++)
  {
    cin >> n[i];
  }

  auto start = chrono::high_resolution_clock::now();
  preGenerateSequences();
  preComputeResults();
  for (int i = 0; i < t; i++)
  {
    cout << results[n[i]] << endl;
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "Execution time : " << duration.count();
  return 0;
}