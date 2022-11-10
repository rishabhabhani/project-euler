#include <iostream>
#include <vector>
using namespace std;

inline int convertCharToInt(char x)
{
  return x - '0';
}

inline char convertIntToChar(int x)
{
  return int('0') + x;
}

string largeSum(vector<string> numbers)
{
  string finalNumber = "";
  string carryNumber('0', 50);

  for (int i = 49; i >= 0; i--)
  {
    int sum = 0;
    for (unsigned int j = 0; j < numbers.size(); j++)
    {
      sum += convertCharToInt(numbers[j][i]);
      sum += convertCharToInt(carryNumber[i]);
      int d = sum % 10;
      sum /= 10;
      finalNumber += convertIntToChar(d);
      int counter = 0;
      while (sum > 0)
      {
        int d = sum % 10;
        sum /= 10;
        //// TODO: imlement carry forwading
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<string> numbers(n);
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  return 0;
}