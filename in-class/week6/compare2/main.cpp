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
    srand(time(NULL));
    // start with an initial size of 100
    int input_size = 100;

    // Example usage
    cout << "Stack using Array :\n";

    while (input_size <= 1000) {
        // create arrayStack object
        arrayStack my_stack;
        my_stack.size_ = input_size;

        // push random integers
        clock_t start_push = clock();
        for (int i = 0; i < input_size; i++) {
            my_stack.push(rand() % 100);
        }
        clock_t end_push = clock();

        // display all input
        clock_t start_display = clock();
        my_stack.display();
        clock_t end_display = clock();

        // pop all items
        clock_t start_pop = clock();
        while (!my_stack.isEmpty()) {
            my_stack.pop();
        }
        clock_t end_pop = clock();

        // calculate and display time taken
        double duration_push = double(end_push - start_push) / CLOCKS_PER_SEC;
        double duration_display = double(end_display - start_display) / CLOCKS_PER_SEC;
        double duration_pop = double(end_pop - start_pop) / CLOCKS_PER_SEC;

        cout << "Input size: " << input_size << endl;
        cout << "Push time: " << duration_push << " seconds\n";
        cout << "Display time: " << duration_display << " seconds\n";
        cout << "Pop time: " << duration_pop << " seconds\n\n";

        // increase input size by 100
        input_size += 100;
    }

    cout << "Stack using LinkedList :\n";
    input_size = 100;

    while (input_size <= 1000) {

        arrayLinkedList my_stack2;


        clock_t start_push = clock();
        for (int i = 0; i < input_size; i++) {
            my_stack2.push(rand() % 100);
        }
        clock_t end_push = clock();


        clock_t start_display = clock();
        my_stack2.display();
        clock_t end_display = clock();


        clock_t start_pop = clock();
        while (!my_stack2.isEmpty()) {
            my_stack2.pop();
        }
        clock_t end_pop = clock();


        double duration_push = double(end_push - start_push) / CLOCKS_PER_SEC;
        double duration_display = double(end_display - start_display) / CLOCKS_PER_SEC;
        double duration_pop = double(end_pop - start_pop) / CLOCKS_PER_SEC;

        cout << "Input size: " << input_size << endl;
        cout << "Push time: " << duration_push << " seconds\n";
        cout << "Display time: " << duration_display << " seconds\n";
        cout << "Pop time: " << duration_pop << " seconds\n\n";


        input_size += 100;
    }

    return 0;
}
