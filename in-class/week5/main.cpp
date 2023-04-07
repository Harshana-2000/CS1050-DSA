#include <iostream>
#include <vector>


using namespace std;
void print_array(vector<int> arr){
    for(int u : arr) cout << u <<" ";
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}

int partition(int arr[], int l, int h)
{
int x = arr[h];
int i = (l - 1);
for (int j = l; j <= h - 1; j++) {
if (arr[j] <= x) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[h]);
return (i + 1);
}

void quickSort(int A[], int l, int h)
{
if (l < h) {
int p = partition(A, l, h);
quickSort(A, l, p - 1);
quickSort(A, p + 1, h);
}
}

int main()
{
int n = 5;
int arr[n] = { 4, 2, 6, 9, 2 };
quickSort(arr, 0, n - 1);
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
return 0;
}
void quick_sort_recursive2(vector<int> *ar,int s,int e){
    if(s>=e) return;
    int pivot =(*ar)[e-1];
    cout << pivot ;
    int j ;
    for(int i=s;i<e;i++){
        j=0;
        for(;j<e;j++){
            if((*ar)[i]>pivot){
                swap((*ar)[i],(*ar)[j]);
            }
        }

    }
    quick_sort_recursive2((ar),s,j-1);
    quick_sort_recursive2((ar),j+1,e);
}
void quick_sort_recursive(vector<int> *ar,int s,int e){
    if(s>=e) return;
    int pivot =(*ar)[e-1];
    cout << pivot ;
    int i=s;
    int j=s+1;
    while(j<e-1){
        while((*ar)[j]>pivot)j++;
        print_array(*ar);
        cout << (*ar)[i]<<" "<<(*ar)[j]<<"-->";
        swap((*ar)[i],(*ar)[j]);
        print_array(*ar);
        i++;
    }
    cout << "#";
    print_array(*ar);
    //swap((*ar)[i], (*ar)[e-1]);
    cout << "*";
    print_array(*ar);
    quick_sort_recursive((ar),s,j-1);
    quick_sort_recursive((ar),j+1,e);
}


int main()
{   vector<vector<int>> arrays ;
  //int e = 10000;
    /*for(int p=1;p<=20;p++){
        int arr[e*p];
        vector<int> v(e*p);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000);
        arrays.push_back(v);

    }*/
    arrays = {{4,3,2,1},{6,5,4,3,2,1},{7,6,5,4,3,2,1},{8,7,6,5,4,3,2,1},{9,8,7,6,5,4,3,2,1}};
    for(vector<int> arr : arrays){
        int len = arr.size();
        quick_sort_recursive(&arr,0,len);
        print_array(arr);
    }

    return 0;
}
