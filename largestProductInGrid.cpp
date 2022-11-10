#include <iostream>
using namespace std;

unsigned long long largestProduct(unsigned long long mat[20][20])
{
  unsigned long long prod = 0;
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      unsigned long long curProd = 1;
      if (i < 17)
      {
        curProd = mat[i][j] * mat[i + 1][j] * mat[i + 2][j] * mat[i + 3][j];
        if (prod < curProd)
        {
          prod = curProd;
          // cout << "Down : " << mat[i][j] << " " << mat[i + 1][j + 1] << " "
          //  << mat[i + 2][j + 2] << " " << mat[i + 3][j + 3] << endl;
        }
      }
      if (j < 17)
      {
        curProd = mat[i][j] * mat[i][j + 1] * mat[i][j + 2] * mat[i][j + 3];
        if (prod < curProd)
        {
          prod = curProd;
          // cout << "Right : " << mat[i][j] << " " << mat[i + 1][j + 1] << " "
          //  << mat[i + 2][j + 2] << " " << mat[i + 3][j + 3] << endl;
        }
      }
      if (i < 17 && j < 17)
      {
        curProd = mat[i][j] * mat[i + 1][j + 1] * mat[i + 2][j + 2] * mat[i + 3][j + 3];
        if (prod < curProd)
        {
          prod = curProd;
          // cout << "Down-Right : " << mat[i][j] << " " << mat[i + 1][j + 1] << " "
          //      << mat[i + 2][j + 2] << " " << mat[i + 3][j + 3] << endl;
        }
      }
      if (i < 17 && j > 2)
      {
        curProd = mat[i][j] * mat[i + 1][j - 1] * mat[i + 2][j - 2] * mat[i + 3][j - 3];
        if (prod < curProd)
        {
          prod = curProd;
          // cout << "Down-Left : " << mat[i][j] << " " << mat[i + 1][j + 1] << " "
          //      << mat[i + 2][j + 2] << " " << mat[i + 3][j + 3] << endl;
        }
      }
    }
  }
  return prod;
}

int main()
{
  unsigned long long mat[20][20];
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      cin >> mat[i][j];
    }
  }

  unsigned long long prod = largestProduct(mat);
  cout << prod;
  return 0;
}