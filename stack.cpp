#include "stack.h"
using namespace std;

Stack::Stack()              //default constructor
{
    size = 0;
    piece = 'O';
    arr = new char[0];
    index = -1;
}

Stack::Stack(char p, int s)         //parametric constructor
{
    piece = p;
    size = s;
    arr = new char[size];
    index = -1;
    for (int i =0; i< size; i++)            //sets each element of the array to ' ' for design choices
    {
        arr[i] = ' ';
    }
}
Stack::~Stack()                    //destructor
{
    delete[] arr;
}
bool Stack::isEmpty() const
{
    return index == -1;
}

bool Stack::isFull() const
{
    return index == size-1;
}

void Stack::Push()
{
    if(!isFull())
    {
        index++;                    //increments index
        arr[index] = piece;         //adds piece to the stack
    }
}

void Stack::Pop()
{
    if (!isEmpty())
    {
        arr[index] = ' ';       //empties the index because of design choices
        index--;                //updates current index
    }
}



int Stack::getSize() const
{
    return size;
}
char Stack::getPiece(int n) const       //gets nth element in the array
{
    return arr[n];
}



const Stack & Stack::operator=(const Stack & rhs)
{
    if (this != &rhs)
    {
        delete this->arr;               //deallocates the array pointer
        this->size = rhs.size;
        this->piece = rhs.piece;
        this->index = rhs.index;
        this->arr = new char[size];
        for (unsigned int i =0; i<size; i++)
        {
            this->arr[i] = rhs.arr[i];
        }
    }
    return *this;
}