#include "board.h"
#include "stack.h"
#include <string>
#include <iostream>
using namespace std;

Board::Board(int n, char p)
{
    size = n;
    adding = true;
    active = true;
    stackArray = new Stack[size];
    piece = p;
    int half = size/2;
    for (unsigned int i =0; i<half; i++)                            //first n/2 elements will have a maximum of 2 pieces
    {
        stackArray[i] = Stack(piece,2);
    }
    for (unsigned int i = half; i<size; i++)                    //last n/2 elements will have a maximum of 3 pieces
    {
        stackArray[i] = Stack(piece,3);
    }
}
Board::~Board()                 //destructor
{
    delete[] stackArray;
}

void Board::initialize()                            //adds one piece to every stack
{
    for (unsigned int i =0; i<size; i++)            //for every stack
    {
        Add(i);                                 //adds one piece
    }
}

void Board::Add(int n)
{
    stackArray[n].Push();                   //adds to the nth element
}

void Board::Remove(int n)
{
    stackArray[n].Pop();                //removes from the nth element
}

void Board::updateAdding()                   //checks if the player should continue to add
{
    for (unsigned int i = 0; i<size; i++)           //for each element
    {
        if (!stackArray[i].isFull())                //stops iterating since there is already one not full stack
        {
            return;
        }
    }
    adding = false;                                 //updates adding to false since every stack is full

}

void Board::updateActive()                          //checks if the player is active
{
    for (unsigned int i = 0; i < size; i++)           //for each element
    {
        if (!stackArray[i].isEmpty())                //stops iterating since there is already one not empty stack
        {
            return;
        }
    }
    active = false;                             //updates active to false since every stack is full
}

bool Board::continueAdding() const
{
    return adding;                  //must continue to add if every stack is not full
}

bool Board::continueRemoving() const
{
    return active;             //must continue to remove if every stack is not empty
}

void Board::print() const
{
    for (int i =0; i<size; i++)         //for each Stack
    {
        cout << i+1 << ": ";
        int limit = stackArray[i].getSize();            //finds the size of the ith Stack
        for (int j =0; j<limit; j++)                //for each element in Stack
        {
            cout << stackArray[i].getPiece(j);              //gets the nth piece in ith Stack
        }
        cout << endl;
    }
}