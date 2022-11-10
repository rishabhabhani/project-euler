#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

typedef unsigned long long ULL;

ULL modFacts[1001];
ULL mod = 10e9 + 7;

void preComputeFacts()
{
  modFacts[0] = 1;
  ULL mul = 1;
  for (int i = 1; i < 1001; i++)
  {
    mul *= i;
    mul %= mod;
    modFacts[i] = mul;
    cout << i << " " << mul << endl;
  }
}

ULL computeNumberOfPaths(ULL a, ULL b)
{
  ULL sum = a + b;
  ULL max = (a > b) ? a : b;
  ULL min = sum - max;
}

int main()
{
  cout << "mod " << mod << endl;

  int t;
  cin >> t;
  vector<pair<ULL, ULL>> grid(t);
  for (int i = 0; i < t; i++)
  {
    ULL a, b;
    cin >> a >> b;
    grid[i] = {a, b};
  }

  auto start = chrono::high_resolution_clock::now();
  preComputeFacts();
  for (int i = 0; i < t; i++)
  {
    ULL paths = computeNumberOfPaths(grid[i].first, grid[i].second);
    cout << paths << endl;
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "Execution time : " << duration.count();

  return 0;
}

//// TODO: Implement lattice Paths using Dynamic Programming
//// reason - factorials can become very large numbers, simply modding them would result in
//// incorrect divisions. other option is to use Big Integers.