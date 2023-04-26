#include <iostream>

using namespace std ;

struct Node {
    int data ;
    struct Node *next ;
};

struct LinkedList {
    struct Node *root;

    LinkedList() {
        root = NULL ;
    }

    void insert(int data) {
        struct Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (root == NULL) {
            root = newNode;
            return;
        }

        struct Node *temp = root;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    struct Node* findElement(int index){
        struct Node *temp = root ;
        int c_index = 0;
        while(index != c_index){
            if(temp==NULL) {
                throw out_of_range("Index out of range");
            }
            temp = temp->next ;
            c_index++ ;
        }
        return temp ;
    }

    int length(){
        int len = 0;
        if(root==NULL) return 0 ;
        struct Node *temp = root ;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }

    bool binarySearch(int target) {
        int len = length();
        int left = 0, right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            struct Node *midNode = findElement(mid);

            if (midNode->data == target) {
                return true;
            } else if (midNode->data < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    };
};

int main() {
    struct LinkedList ll;
    for (int i = -1; i <= 21; i++) {
        ll.insert(i);
    }

    int length = 0;
    struct Node *temp = ll.root ;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
        length += 1;
    }
    cout << endl << "Length: " << length << endl;
    return 0;
}

