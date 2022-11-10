#include <iostream>
#include <vector>
#include <chrono>

std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

bool checkPrime(int n, std::vector<int> primes)
{
  if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
    return false;
  if ((n - 1) % 6 != 0 && (n + 1) % 6 != 0)
    return false;

  for (int i = 3; i < primes.size(); i++)
  {
    if (n % primes[i] == 0)
      return false;
  }
  return true;
}

int nthPrime(int n)
{
  int defaultSize = primes.size();
  if (n <= defaultSize)
    return primes[n - 1];

  n -= defaultSize;

  int num = primes[defaultSize - 1] + 2;
  int lastPrime = num - 2;

  do
  {
    if (checkPrime(num, primes))
    {
      lastPrime = num;
      primes.push_back(num);
      n--;
    }
    num += 2;
  } while (n > 0);

  return lastPrime;
}

int main()
{
  int t;
  std::cin >> t;

  auto start = std::chrono::high_resolution_clock::now();

  while (t--)
  {
    int n;
    std::cin >> n;

    int p = nthPrime(n);
    std::cout << p << std::endl;
  }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Execution Time : " << duration.count();

  return 0;
}