#include <iostream>

long long sumSquareDiff(int n)
{
  long long squaredSum = n * (n + 1) * (2 * n + 1) / 6;
  long long sum = n * (n + 1) / 2;
  long long sumSquared = sum * sum;
  return sumSquared - squaredSum;
}

int main()
{
  int t;
  std::cin >> t;
  while (t--)
  {
    long long n;
    std::cin >> n;
    long long diff = sumSquareDiff(n);
    std::cout << diff << std::endl;
  }
  return 0;
}