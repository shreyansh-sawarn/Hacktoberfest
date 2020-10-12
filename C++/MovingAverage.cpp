#include <iostream>
using namespace std;
int main()
{
  int size_1, size_2, n;
  cin>>size_1>>size_2>>n;
  double price[n];
  for (int i = 0; i < n; ++i)
    cin>>price[i];

  double ma_size_1[n-size_1+1], ma_size_2[n-size_2+1];
  double sum_size_1 = 0.0, sum_size_2 = 0.0;
  
  for (int i = 0; i < size_1; ++i)
    sum_size_1 += price[i];
  for (int i = 0; i < size_2; ++i)
    sum_size_2 += price[i];

  ma_size_1[0] = sum_size_1/size_1;
  ma_size_2[0] = sum_size_2/size_2;
  int j = 1;
  for (int i = size_1; i < n; ++i)
  {
    sum_size_1 += (-price[i-size_1] + price[i]);
    ma_size_1[j++] = sum_size_1/size_1;
  }
  j = 1;
  for (int i = size_2; i < n; ++i)
  {
    sum_size_2 += (-price[i-size_2] + price[i]);
    ma_size_2[j++] = sum_size_2/size_2;
  }
  
  int above = 0, count = 0;
  if(ma_size_1[size_2-size_1] > ma_size_2[0]) above = 1;
  if(ma_size_1[size_2-size_1] < ma_size_2[0]) above = -1;


  for (int i = 1; i < n-size_2+1; ++i)
  {
    if(ma_size_1[size_2-size_1+i] < ma_size_2[i] && above == 1)
    {
      count++;
      above = -1;
    }
    else if(ma_size_1[size_2-size_1+i] > ma_size_2[i] && above == -1)
    {
      count++;
      above = 1;
    }
  }
  cout<<count<<endl;
}             
