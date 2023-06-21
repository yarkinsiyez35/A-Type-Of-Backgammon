#include "stack.h"


#ifndef KIZ_TAVLASI_BOARD_H
#define KIZ_TAVLASI_BOARD_H

class Board{
private:
    bool adding;                    //this will determine if we are adding or subtracting
    bool active;                    //determines if stack should be popped
    int size;             //determines how many stacks there will be
    Stack *stackArray;        //a Stack array with size many elements
    char piece;
public:
    Board(int n = 6, char p= 'O');       //constructor
    ~Board();                   //destructor
    void initialize();          //adds one piece to every stack
    void Add(int n);            //adds to nth stack
    void Remove(int n);         //removes from the nth stack
    void updateAdding();         //checks if every stack is full and updates the adding
    void updateActive();          //checks if every stack is empty and updates the active
    bool continueAdding() const;      //returns adding value
    bool continueRemoving() const;    //returns active value
    void print() const;               //prints stack horizontally

};
#endif
