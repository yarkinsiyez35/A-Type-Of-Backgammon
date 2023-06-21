#include <iostream>
#include "board.h"
#include <random>
#include <thread>
#include <chrono>

using namespace std;

int randomNumberGenerator(const int &n)                //creates a random generator between 0 and n (inclusive)
{
    random_device rd;
    uniform_int_distribution<int> dist(0,n);
    return dist(rd);
}


int main() {
    cout << "Welcome to Kız Tavlası, created by Yarkın Siyez\n";
    cout << "How many points/triangles do you want to play with? ";
    int numberOfPoints;
    cin >> numberOfPoints;
    cout << "What are the name of the players?\n";
    cout << "Player 1: ";
    string p1,p2;
    cin >> p1;
    cout << "Player 2: ";
    cin >> p2;
    cout << p1 << ", choose your piece shape: ";
    char userPiece1, userPiece2;
    cin >> userPiece1;
    cout << p2 << ", choose your piece shape: ";
    cin >> userPiece2;
    cout << "Your boards are being created\n";
    Board b1(numberOfPoints,userPiece1);
    Board b2(numberOfPoints, userPiece2);
    cout << "Board of " << p1 << ":\n\n";
    b1.initialize();                //initializes the board
    b1.print();                     //displays the board
    cout << "\n";
    cout << "Board of " << p2 << ":\n\n";
    b2.initialize();                //initializes the board
    b2.print();                     //displays the board
    cout << "\n";

    while (b1.continueRemoving() && b2.continueRemoving())          //while both boards are active
    {
        if (b1.continueAdding())                    //if board1 is adding pieces
        {
            cout << p1 << " ,two dies will be thrown to add pieces.\n";
            this_thread::sleep_for(chrono::seconds(2));
            int dice1 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            int dice2 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            cout << "Your dies are " << dice1+1 << " and " << dice2+1 << "\n";          //prints dice+1 because randomized value is between 0 and numberOfPoints-1
            b1.Add(dice1);                                                          //adds to the nth stack
            b1.Add(dice2);                                                          //adds to the nth stack
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Here is the updated board:\n";
            b1.print();                                                                 //displays the board
            cout << "\n";
            b1.updateAdding();                                                          //checks for adding
            this_thread::sleep_for(chrono::seconds(5));
        }
        else                                       //if board1 is removing pieces
        {
            cout << p1 << " ,two dies will be thrown to remove pieces.\n";
            this_thread::sleep_for(chrono::seconds(2));
            int dice1 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            int dice2 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            cout << "Your dies are " << dice1+1 << " and " << dice2+1 << "\n";          //prints dice+1 because randomized value is between 0 and numberOfPoints-1
            b1.Remove(dice1);                                                        //removes from the nth stack
            b1.Remove(dice2);                                                       //removes from the nth stack
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Here is the updated board:\n";
            b1.print();                                                                 //displays the board
            cout << "\n";
            b1.updateActive();                                                          //checks for active
            this_thread::sleep_for(chrono::seconds(5));
        }
        if (b2.continueAdding())                //if board2 is adding pieces
        {
            cout << p2 << " ,two dies will be thrown to add pieces.\n";
            this_thread::sleep_for(chrono::seconds(2));
            int dice1 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            int dice2 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            cout << "Your dies are " << dice1+1 << " and " << dice2+1 << "\n";          //prints dice+1 because randomized value is between 0 and numberOfPoints-1
            b2.Add(dice1);                                                          //adds to the nth stack
            b2.Add(dice2);                                                          //adds to the nth stack
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Here is the updated board:\n";
            b2.print();                                                                 //displays the board
            cout << "\n";
            b2.updateAdding();                                                          //checks for adding
            this_thread::sleep_for(chrono::seconds(5));
        }
        else                                    //if board2 is removing pieces
        {
            cout << p2 << " ,two dies will be thrown to remove pieces.\n";
            this_thread::sleep_for(chrono::seconds(2));
            int dice1 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            int dice2 = randomNumberGenerator(numberOfPoints-1);                     //number generation
            cout << "Your dies are " << dice1+1 << " and " << dice2+1 << "\n";          //prints dice+1 because randomized value is between 0 and numberOfPoints-1
            b2.Remove(dice1);                                                        //removes from the nth stack
            b2.Remove(dice2);                                                        //removes from the nth stack
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Here is the updated board:\n";
            b2.print();                                                                 //displays the board
            cout << "\n";
            b2.updateActive();                                                          //checks for active
            this_thread::sleep_for(chrono::seconds(5));
        }
    }
    if (!b1.continueRemoving())                             //if board 1 is finished
    {
        if(!b2.continueRemoving())                          //if board2 is finished as well
        {
            cout << "Winners are both. Friendship wins!\n";
        }
        else                                               //only board1 is finished
        {
            cout << "The winner is " << p1 << "!\n";
        }
    }
    else                                                    //only board2 is finished
    {
        cout << "The winner is " << p2 << "!\n";
    }

    cout << "Thank you for playing Kız Tavlası, created by Yarkın Siyez.\n";

    return 0;
}
