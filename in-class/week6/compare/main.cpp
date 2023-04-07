#include <iostream>
#include <ctime>
#include <random>

using namespace std;

const int MAX_SIZE = 100;
struct Node{
    int data;
    struct Node* next = NULL;
};
struct arrayLinkedList {
    struct Node* head = NULL;
    int top = -1;

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        // Linked list implementation of a stack is never full
        return false;
    }

    void push(int element) {
        struct Node* node = new Node;
        node->data = element;

        if(isEmpty()) {
            head = node;
        }
        else {
            node->next = head;
            head = node;
        }
        top++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "stack Underflow!\n";
            return;
        }

        struct Node* temp = head;
        head = head->next;
        delete temp;
        top--;
    }

    void stackTop() {
        if (isEmpty()) {
            return;
        }
        cout << head->data<<"\n";
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        struct Node* current = head;
        cout << "[ ";
        while (current->next != NULL) {
            cout << current->data << " ,";
            current = current->next;
        }
        cout <<current->data<< "]\n";
    }
};

struct arrayStack {
    int size_;
    int stack_arr[MAX_SIZE];
    int top = -1;
    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == size_ - 1) {
            return true;
        }
        return false;
    }

    void push(int element) {
        if (isFull()) {
            cout << "stack Overflow!\n";
            return;
        }
        top += 1;
        stack_arr[top] = element;
    }

    void pop() {
        if (isEmpty()) {
            cout << "stack Underflow!\n";
            return;
        }
        stack_arr[top] = 0;
        top -= 1;
    }

    void stackTop() {
        if (isEmpty()) {
            return;
        }
        cout << stack_arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout <<"Stack is Empty!\n";
            return;
        }
        int current = top;
        cout << "[ ";
        while (current >= 1) {
            int elem = stack_arr[current];
            cout << elem << " ,";
            current -= 1;
        }
        cout << stack_arr[current]<<" ]\n";
    }
};

int main() {
    // Example usage
    cout << "Stack using Array :\n";
    clock_t start1 = clock();
    arrayStack my_stack;
    my_stack.size_ = 10;

    my_stack.push(8);
    my_stack.push(10);
    my_stack.push(5);
    my_stack.push(11);
    my_stack.push(15);
    my_stack.push(23);
    my_stack.push(6);
    my_stack.push(18);
    my_stack.push(20);
    my_stack.push(17);
    my_stack.display();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.display();
    my_stack.push(4);
    my_stack.push(30);
    my_stack.push(3);
    my_stack.push(1);
    my_stack.display();
    clock_t end1 = clock();
    double duration = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Taken time:- "<< duration<<"\n\n";

    cout << "Stack using LinkedList :\n";
    arrayLinkedList my_stack2;
    clock_t start2 = clock();

    my_stack2.push(8);
    my_stack2.push(10);
    my_stack2.push(5);
    my_stack2.push(11);
    my_stack2.push(15);
    my_stack2.push(23);
    my_stack2.push(6);
    my_stack2.push(18);
    my_stack2.push(20);
    my_stack2.push(17);
    my_stack2.display();

    my_stack2.pop();
    my_stack2.pop();
    my_stack2.pop();
    my_stack2.pop();
    my_stack2.pop();
    my_stack2.display();

    my_stack2.push(4);
    my_stack2.push(30);
    my_stack2.push(3);
    my_stack2.push(1);
    my_stack2.display();
    clock_t end2 = clock();
    double duration2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Taken time:- "<< duration2<<"\n\n";
    return 0;
}
