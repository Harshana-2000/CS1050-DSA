#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

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
}

