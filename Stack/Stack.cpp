#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int size;
    int current;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        current = -1;
    }
    bool isFull()
    {
        if (current == size - 1)
        return true;
        return false;
    }
    bool isEmpty()
    {
        if (current == -1)
            return true;
        return false;
    }
    void push(int data)
    {
        if (isFull())
            cerr << "stack is full"<<endl;
        else
        {
            current++;
            arr[current] = data;
        }
    }
    int pop()
    {
        if (isEmpty())
            cerr << "Stack is empty"<<endl;
        else
        {
            int temp = arr[current];
            current--;
            return temp;
        }
    }
    int top()
    {
        return arr[current];
    }
    void display()
    {
        for (int i = 0; i <= current; i++)
        {
            cout << arr[i]<<" ";
        }
    }
};

int main()
{
    Stack s(4);
    s.push(78);
    s.push(55);
    s.pop();
    s.push(44);
    s.push(355);
    s.push(45);
    s.pop();
    cout<<s.top()<<endl;
    s.display();
}