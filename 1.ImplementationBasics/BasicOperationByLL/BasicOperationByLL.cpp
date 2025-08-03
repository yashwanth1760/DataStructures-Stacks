#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int size;
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int num)
    {
        Node *temp = new Node(num);
        if (temp == NULL)
        {
            cout << "Memory Error  problem of overflow" << endl;
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        // problem of overflow , exceptionally
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
    bool isSize(){
        return size;
    }

};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
     s.push(50);
     cout << s.peek() << endl;
     s.pop();

    return 0;
}