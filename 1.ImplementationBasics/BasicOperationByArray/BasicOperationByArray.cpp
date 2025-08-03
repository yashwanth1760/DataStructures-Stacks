#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int top;
    int capacity;
    int *arr;

    Stack(int s) : top(-1), capacity(s), arr(new int[s]) {
        cout << "[Init] Created stack with capacity = " << capacity << "\n";
    }

    ~Stack() {
        delete[] arr;
        cout << "[Destroy] Freed stack memory\n";
    }

    void push(int x) {
        if (top >= capacity - 1) {
            cout << "[push] Stack Overflow: cannot push " << x << "\n";
        } else {
            arr[++top] = x;
            cout << "[push] Pushed " << x << " (new top index = " << top << ")\n";
        }
    }

    void pop() {
        if (top < 0) {
            cout << "[pop] Stack Underflow: nothing to pop\n";
        } else {
            cout << "[pop] Popped " << arr[top] << " (old top index = " << top << ")\n";
            top--;
        }
    }

    void peek() const {
        if (top < 0) {
            cout << "[peek] Stack is empty\n";
        } else {
            cout << "[peek] Top element is " << arr[top] << " (at index " << top << ")\n";
        }
    }

    bool isEmpty() const {
        bool empty = (top == -1);
        cout << "[isEmpty] Stack " << (empty ? "is" : "is not") << " empty\n";
        return empty;
    }

    int size() const {
        int sz = top + 1;
        cout << "[size] Current stack size = " << sz << "\n";
        return sz;
    }

    // Helper to print all elements from bottom to top
    void printContents() const {
        if (top < 0) {
            cout << "[printContents] Stack is empty\n";
            return;
        }
        cout << "[printContents] Stack elements (bottom -> top): ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i];
            if (i != top) cout << " | ";
        }
        cout << "\n";
    }
};

int main() {
    // Create a stack of capacity 5
    Stack s(5);

    // Push some elements
    s.push(10);
    s.push(20);
    s.push(-1);
    s.push(40);
    s.push(50);

    // Try pushing beyond capacity to show overflow handling
    s.push(60);

    // Peek at top
    s.peek();

    // Print current size and emptiness
    s.size();
    s.isEmpty();

    // Print full contents
    s.printContents();

    // Pop a few elements
    s.pop();
    s.pop();

    // Show updated state
    s.peek();
    s.size();
    s.printContents();

    return 0;
}
