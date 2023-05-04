#include <iostream>
#include <vector>
using namespace std;

struct heap {
    vector<int> heap_list;
    int head = -1;
    int* sorted_array ;
    bool insert(int value) {
        heap_list.push_back(value);
        head++;
        heapifyUp(head);
        return true;
    }
    int removeMax(int index = 0){
        swap(heap_list.at(index),heap_list.at(head));
        int value = heap_list.at(head);
        heap_list.erase(heap_list.begin() + head);
        head--;
        heapifyDown(index);
        return value ;
    }
    bool heapifyUp(int index) {
        if (index <= 0) return false;
        int parent_index;
        if (index % 2 == 0) {
            parent_index = (index / 2) - 1;
        }
        else {
            parent_index = index / 2;
        }
        check_node(parent_index);
        heapifyUp(parent_index);
        return true;
    }
    bool heapifyDown(int index) {
        if (index >= head) return false;
        int left_child_index = 2*index+1 ;
        int right_child_index = 2*index+2 ;
        if(left_child_index>=heap_list.size() && right_child_index>=heap_list.size()){
            return false ;
        }
        int element = heap_list.at(index);
        int left_child = (left_child_index < heap_list.size()) ? heap_list.at(left_child_index) : -1;
        int right_child = (right_child_index < heap_list.size()) ? heap_list.at(right_child_index) : -1;
        if (left_child >= right_child && left_child > element){
            swap(heap_list.at(left_child_index),heap_list.at(index));
            return heapifyDown(left_child_index);
        }
        else if (right_child > left_child && right_child > element){
            swap(heap_list.at(right_child_index),heap_list.at(index));
            return heapifyDown(right_child_index);
        }

        return true;
    }


    bool check_node(int i) {
        int value = heap_list.at(i);
        if (heap_list.size() > (2 * i + 1)) {
            int left_value = heap_list.at(2 * i + 1);
            if (left_value > value) {
                swap(heap_list.at(i), heap_list.at(2 * i + 1));
                return false;
            }
        }
        if (heap_list.size() > (2 * i + 2)) {
            int right_value = heap_list.at(2 * i + 2);
            if (right_value > value) {
                swap(heap_list.at(i), heap_list.at(2 * i + 2));
                return false;
            }
        }
        return true;
    }
    int* heap_sort(){
        sorted_array = new int[head+1];
        int i = head;
        while (head >= 0) {
            sorted_array[i--] = removeMax();
        }
        return sorted_array;
    }
    void print_sorted_array(){
        sorted_array = heap_sort();
        for (int i = 0; i <= head; i++) {
            cout << sorted_array[i] << " ";
        }
        cout << endl;
    }
    void print_heap() {
        for (int i : heap_list) cout << i << " ";
        cout << endl;
    }
};

int main() {
    vector<int> input_list = {4, 17, 3, 12, 9, 6};
    cout << "Input Array :"<<endl;
    for(int j : input_list) cout << j << " " ;

    cout << endl<< "OutPut Array :"<< endl;
    heap heap1;
    for (int j : input_list) {
        heap1.insert(j);

    }
    //heap1.print_heap();
    heap1.print_sorted_array();
    return 0;
}
