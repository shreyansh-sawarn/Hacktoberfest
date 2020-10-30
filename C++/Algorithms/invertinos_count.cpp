#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;

int merge(vector<int> &v, int l, int m, int r){
  int inv = 0;//invertions counter
  int n1 = m-l+1;
  int n2 = r-m;
  vector<int> v1(n1);
  vector<int> v2(n2);

  //creating auxiliar vectors
  for(int i=0; i<n1; i++){
    v1[i] = v[l+i];
  }
  for(int i=0; i<n2; i++){
    v2[i] = v[m+1+i];
  }

  int i=0, j=0, k=l;
  //merg and invertions count
  while(i<n1 && j<n2){
    if(v1[i] <= v2[j]){
      v[k] = v1[i];
      i++;
    }else{
      v[k] = v2[j];
      j++;
      inv += (n1-i);
    }
    k++;
  }
  while(i<n1){
    v[k] = v1[i];
    i++;k++;
  }

  while(j<n2){
    v[k] = v2[j];
    j++;k++;
  }

  return inv;
}

//a merg-sort that counts the invertions
int merge_count(vector<int> &v, int l, int r){
  if(!(l<r)) return 0;

  int inv = 0;
  int m = l+(r-l)/2;

  //recursive call to both sides
  inv += merge_count(v, l, m);
  inv += merge_count(v, m+1, r);

  inv += merge(v, l, m, r);

  return inv;
}

int main(void){
  int n, c;
  //input
  cin >> n;//number of test cases
  for(int i=0; i<n; i++){
    cin >> c;//number of inputs per test case
    vector<int> v(c);
    for(int j=0; j<c; j++){
      cin >> v[j];//test case inputs
    }
    //counting invertions
    cout << merge_count(v, 0, c-1) << "\n";
  }
}
