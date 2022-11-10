#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int results[10001];

void preComputeResults()
{
  results[0] = 1;
  vector<int> mul(1);
  mul[0] = 1;
  for (int i = 1; i < 10001; i++)
  {
    int carry = 0, sum = 0;
    for (unsigned int j = 0; j < mul.size(); j++)
    {
      int d = carry + 2 * mul[j];
      carry = d / 10;
      mul[j] = d % 10;
      sum += mul[j];
    }

    if (carry > 0)
    {
      sum += carry;
      mul.push_back(carry);
    }

    results[i] = sum;
  }
}

int main()
{
  int t;
  cin >> t;
  vector<int> n(t);
  for (int i = 0; i < t; i++)
  {
    cin >> n[i];
  }

  auto start = chrono::high_resolution_clock::now();
  preComputeResults();
  for (int i = 0; i < t; i++)
  {
    cout << results[n[i]] << endl;
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cout << "Execution time : " << duration.count() << endl;

  return 0;
}