#include <iostream>

using namespace std;

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

int main() {
    // Example usage
    arrayLinkedList my_stack;

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
    return 0;
}
