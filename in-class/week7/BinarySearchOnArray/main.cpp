#include <iostream>
using namespace std ;
int arr[20] ;

int binarySearchRecursive(int target , int first , int last){
    int mid = (first+last)/2;
    if(arr[mid]==target){
        return mid ;
    }
    if(last-first<=1 ){
        if(arr[first]==target) return first;
        if(arr[last]==target) return last ;
        return -1;
    }

    else if(arr[mid] > target){
        binarySearchRecursive(target,first,mid-1);
    }
    else{
        binarySearchRecursive(target,mid+1,last);
    }
}
int binarySearchIterative(int target, int first, int last) {
    int mid;
    while (last - first >= 0) {
        mid = (first + last) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            first = mid + 1;
        } else if (arr[mid] > target) {
            last = mid - 1;
        }
    }
    return -1;
}

int main(){
    for(int i= 0;i<=20;i++) {arr[i]=i;}
    cout << binarySearchIterative(20,0,19) << endl;

    for(int j = -1 ;j<=21 ;j++){
        cout << j << "-->"<< binarySearchRecursive(j,0,19) << endl ;
    }
    for(int j = -1 ;j<=21 ;j++){
        cout << j << "-->"<< binarySearchIterative(j,0,19) << endl ;
    }
    return 0 ;
}
