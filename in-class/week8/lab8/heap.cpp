#include <iostream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int max_index = root;
    int left_child_index = 2*root+1;
    int right_child_index = 2*root+2;
    if(left_child_index<n && arr[max_index]<arr[left_child_index]){
        max_index = left_child_index;
    }
    if(right_child_index<n && arr[max_index]<arr[right_child_index]){
        max_index = right_child_index;
    }
    if(max_index!=root){
        swap(arr[max_index],arr[root]);
        heapify(arr,n,max_index);
    }
    return ;
}


// implementing heap sort

void heapSort(int arr[], int n)
{
   // build heap
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
   // extracting elements from heap one by one
    for(int i = n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
    cout <<"Enter input :\n( For example, if you want to sort [4,3,2,5], please enter \"4 3 2 5\".)\n";
    vector<int> num;
    int buf;
    do{
        cin >> buf;
        num.push_back(buf);
    }while(cin.peek() == ' ');
    int n = num.size();
    int arr3[n];
    for(int j =0 ; j<n;j++) arr3[j] = num.at(j);
    cout<<"Input array"<<endl;
    displayArray(arr3,n);
    heapSort(arr3, n);
    cout << "Sorted array"<<endl;
    displayArray(arr3, n);

    /*
    int heap_arr[] = {4,17,3,12,9,6};
    n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
    */
}
