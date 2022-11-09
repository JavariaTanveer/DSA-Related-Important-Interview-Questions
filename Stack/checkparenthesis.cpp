#include <iostream>
using namespace std;
template<class T>
class Stack
{
private:
    T *arr;
    int size;
    int current;

public:
    Stack()
    {
        size=10;
        arr=new T[size];
        current=-1;
    }
    Stack(int size)
    {
        this->size = size;
        arr = new T[size];
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
    void push(T data)
    {
        if (isFull())
            cerr << "stack is full"<<endl;
        else
        {
            current++;
            arr[current] = data;
        }
    }
    T pop()
    {
        if (isEmpty())
            cerr << "Stack is empty"<<endl;
        else
        {
            T temp = arr[current];
            current--;
            return temp;
        }
    }
    T top()
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

void checkparenthesis(string str)
{
Stack<char> s;
for(int i=0;i<str.length();i++)
{
if((str[i]=='[')||(str[i]=='{')||(str[i]=='('))
s.push(str[i]);
else if( (s.top()=='{')&&(str[i] =='}')||(s.top()=='(')&&(str[i] ==')')||(s.top()=='[')&&(str[i] ==']'))
s.pop();
else
s.push(str[i]);
}
if(s.isEmpty())
cout<<"balanced";
else
cout<<"not balanced";
}
int main()
{
    string s="{()}[]";
    checkparenthesis(s);
}