// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "InFix_To_PostFix.h"
#include <string>
using namespace std;


//test inputs
//"7+(9-5)*2"      [{7+(9-5])}*2]     [(10 / 2) + 7 - {6 * 8}] % 9

int main() {
    string input = "7+(9-5)*2";
    InFix_To_PostFix expression;
    Queue<string> queueLine;

    //menu option for infix conversion
    do {
        try {
            cout << "---Options---\n"
                << "C - convert infix to postfix\n"
                << "Q - quit (goes to Queue menu)\n";
            cout << "What choice would you like to pick? ";
            getline(cin, input);
            switch (toupper(input[0])) {
            case 'C':
                cout << "What expression would you like to convert? ";
                getline(cin, input);

                if (expression.isBalanced(input)) expression.convert(input);  //check for parenthesis balancing, will convert expression if true
                else throw runtime_error("expression isn't balanced\n"); //will throw error if expression isnt balanced
                break;


            case 'Q':
                cout << "You entered Q. Going to next section.\n";   //goes to next section and quit this menu
                break;
            }
            cout << "\n\n\n";
        }
        catch (runtime_error e) { cout << e.what() << "\n\n"; }
    } while (toupper(input[0]) != 'Q');




    //menu option for queue
    do {
        try {
            queueLine.show_list(); //shows all element currently in list
            cout << "---Options---\n"
                << "1 - enqueue\n"
                << "2 - dequeue\n"
                << "3 - front\n"
                << "4 - empty\n"
                << "5 - size\n"
                << "Q - quit (exit program)\n";
            cout << "What choice would you like to pick? ";
            getline(cin, input);
            switch (toupper(input[0])) {
            case '1':
                cout << "What element would you like to add? ";
                getline(cin, input); //type an element you want to add
                queueLine.enQueue(input); //queue the input
                break;

            case '2':
                queueLine.deQueue(); //auto deque
                cout << "An element has been removed.\n";
                break;

            case '3':
                cout << "Front of queue is: " << queueLine.front() << endl; //brings the front of queue
                break;
            
            case '4':
                if (queueLine.empty()) cout << "Queue is Empty.\n"; //check if queue is empty or not
                else cout << "Queue is not empty\n";
                break;

            case '5':
                cout << "Total amount of element presented: " << queueLine.size() << endl; //check queue size
                break;

            case 'Q':
                cout << "You entered Q. Exiting program.\n"; //quit program
                break;
            }
            cout << "\n\n\n";
        }
        catch (runtime_error e) { cout << e.what() << "\n\n"; }
    } while (toupper(input[0]) != 'Q');













    





}

