#ifndef KIZ_TAVLASI_STACK_H
#define KIZ_TAVLASI_STACK_H

class Stack{
private:
    char piece;
    int size;
    char *arr;
    int index;
public:
    Stack();       //default constructor
    Stack(char p, int s);                  //parametric constructor
    ~Stack();                   //destructor
    bool isFull()   const;              //returns true when it is full
    bool isEmpty()  const;             //returns true when it is empty
    void Push();                //pushes a piece if it is available
    void Pop();              //pops an element if it is available
    int getSize() const;        //returns the size of the array
    char getPiece(int n) const;
    const Stack & operator=(const Stack& rhs);              //operator overload for =
};

#endif
