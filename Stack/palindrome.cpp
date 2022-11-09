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
    int sizeS()
    {
        return size;
    }
};

bool checkpalindrome(string str)
{
    //creating stack
Stack<char> s;
int i;
//pushing till mid
for(i=0;i<str.length()/2;i++)
{
s.push(str[i]);
}

if(str.length()%2!=0)
i++;

char r;
while(str[i]!='\0')
{
    r=s.top();
    s.pop();
    
    if(r!=str[i])
    return false;
    i++;
}
return true;
};

int main()
{
     string s="ADDA";
    if (checkpalindrome(s)) {
         cout << "Yes";
     }
     else {
        cout << "No";
     }
}