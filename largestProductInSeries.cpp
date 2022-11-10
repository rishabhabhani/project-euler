#include <iostream>

long long convertStrToInt(char n)
{
  return n - '0';
}

long long shiftCompute(long long product, char p, char n)
{
  return product * convertStrToInt(n) / convertStrToInt(p);
}

long long bulkCompute(std::string series, int start, int len)
{
  long long prod = 1;
  for (int i = start; i < start + len; i++)
  {
    prod *= convertStrToInt(series[i]);
  }
  return prod;
}

long long largestProduct(std::string series, int digits, int wlen)
{
  long long largestProd = bulkCompute(series, 0, wlen);
  long long lastProduct = largestProd;
  for (int i = 1; i < digits - wlen; i++)
  {
    long long nextProd;
    if (series[i - 1] != '0')
    {
      nextProd = shiftCompute(lastProduct, series[i - 1], series[i + wlen - 1]);
    }
    else
    {
      nextProd = bulkCompute(series, i, wlen);
    }

    if (nextProd > largestProd)
    {
      largestProd = nextProd;
    }

    lastProduct = nextProd;
  }
  return largestProd;
}

int main()
{
  int t;
  std::cin >> t;
  while (t--)
  {
    int digits, length;
    std::cin >> digits >> length;

    std::string series;
    std::cin >> series;

    long long prod = largestProduct(series, digits, length);
    std::cout << prod << std::endl;
  }
  return 0;
}