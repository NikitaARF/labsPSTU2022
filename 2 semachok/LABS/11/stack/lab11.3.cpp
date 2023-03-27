#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack { 
public: 
    Node* head; 
    Stack() { 
        head = nullptr;
    }

    void push(int value) { 
        Node* node = new Node; 
        node->data = value; 
        node->next = head;
        head = node; 
    }

    void pop() { 
        Node* node = head; 
        head = head->next; 
        delete node; 
    }

    int top() { 
        return head->data; 
    }

    bool empty() { 
        return head == nullptr;
    }

    void pushK(int value, int k) {  
        for (int i = 0; i < k; i++) {
            Node* node = new Node; 
            node->data = value; 
            node->next = head; 
            head = node;
        }
    }

    void popK(int k) { 
        for (int i = 0; i < k; i++) {
            Node* node = head; 
            head = head->next; 
            delete node; 
        }
    }

    Node* search(int value) { 
        Node* current = head;
        while (current != nullptr) { 
            if (current->data == value) { 
                return current; 
            }
            current = current->next; 
        }
        return nullptr; 
};

int main() {
    Stack stack;
    int n, value, numberForPush, KForPush, KForPop;

    cout << "How many elements will stack take?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        stack.push(i);
    }

    Node* current = stack.head; 
    while (current != nullptr) { 
        cout << current->data << " ";
        current = current->next; 
    }
    cout << endl;

    cout << "Top element: " << stack.top() << endl;

    cout << "Enter value of element: ";
    cin >> numberForPush;
    cout << "Enter the quantity of K elements: ";
    cin >> KForPush;
    stack.pushK(numberForPush, KForPush);
    cout << "Top element: " << stack.top() << endl;

    cout << "Enter quatity of K elements that will be remove from stack: ";
    cin >> KForPop;
    stack.popK(KForPop);
    cout << "Top element: " << stack.top() << endl;

    cout << "enter the value of the element you want to find: ";
    cin >> value;
    Node* node = stack.search(value);
    if (node != nullptr) {
        cout << "Element is found" << endl;
    }
    else {
        cout << "Element is not found" << endl;
    }
    return 0;
}