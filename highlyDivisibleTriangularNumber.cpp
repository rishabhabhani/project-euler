#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, ULL> pairs;

vector<int> divs(1001, 0);

int divisors(ULL n)
{
  if (n == 1)
    return 1;
  int numOfDivs = 2;
  for (int i = 2; i * i < n; i++)
  {
    if (n % i == 0)
    {
      numOfDivs += 2;
    }
  }

  if (ceil(sqrt(n)) == floor(sqrt(n)))
    numOfDivs++;
  return numOfDivs;
}

void generateDivisiors()
{
  int counter = 0, num = 0;
  for (int i = 1; i <= 1000; i++)
  {
    while (num <= i)
    {
      counter++;
      if (counter % 2 == 0)
        num = divisors(counter / 2) * divisors(counter + 1);
      else
        num = divisors(counter) * divisors((counter + 1) / 2);
    }
    divs[i] = ((counter * (counter + 1)) / 2);
  }
}

int main()
{
  int t;
  cin >> t;
  vector<int> a;
  while (t--)
  {
    int n;
    cin >> n;
    a.push_back(n);
  }
  auto start = chrono::high_resolution_clock::now();
  generateDivisiors();
  for (int i = 0; i < a.size(); i++)
  {
    cout << divs[a[i]] << endl;
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "Execution Time : " << duration.count();
  return 0;
}