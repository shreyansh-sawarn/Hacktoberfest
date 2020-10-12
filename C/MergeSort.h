#define MERGESORT_H
#include <vector>
template<typename T>
class MergeSort {
  public:
    static void sort(vector<T> &array, bool ascending = false) //p <= q < r
    {
      merge(array, 0, 2, array.size() - 1);
    } 
  private:
    static void merge(vector<T> &A, unsigned int p, unsigned int q, unsigned int r)
    {
      vector<T> L(A.begin() + p, A.begin() + q + 1);
      vector<T> R(A.begin() + q + 1, A.begin() + r + 1);
      for(int i = 0; i < L.size(); i++)
      {
        cout << L[i] << " ";
      }
      cout << endl;
      for(int i = 0; i < R.size(); i++)
      {
        cout << R[i] << " ";
      }
      cout << endl;
      int i, j = 0;
      int k;
      for(k = p; k <= r && i < L.size() && j < R.size(); k++)
      {
        A[k] = (L[i] >= R[j]) ? R[j++] : L[i++];
      }
      if(i == L.size() && j != R.size())
      {
        for(k = k; k <= r && j < R.size(); k++)
        {
          A[k] = R[j++];
        }
      }
      if(j == L.size() && i != R.size())
      {
        for(k = k; k <= r && i < L.size(); k++)
        {
          A[k] = L[i++];
        }
      }
    }
};