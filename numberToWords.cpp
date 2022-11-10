#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
using namespace std;

typedef unsigned long long ULL;

string words[] = {
    "Zero",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
};

string tens[] = {
    "Zero", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string ending[] = {
    "", "Thousand", "Million", "Billion", "Trillion"};

int charToInt(char x)
{
  return x - '0';
}

string numberToWords(ULL number)
{
  string name = "";

  
  return name;
}

int main()
{
  int t;
  cin >> t;
  vector<ULL> n(t);
  for (int i = 0; i < t; i++)
  {
    cin >> n[i];
  }

  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < t; i++)
  {
    cout << numberToWords(n[i]) << endl;
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cout << "Execution time : " << duration.count();

  return 0;
}