#include "Simple_List.h"
#include "Linked_List.h"
#include "Stack.h"
#include "Queue.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

void test_iterator_queue();
void test_iterator_stack();
void menu_queue();
void print_menu();
char get_select();

int main(int argc, char** argv) {

    //    test_iterator_queue();
    //    test_iterator_stack();
    menu_queue();
    return 0;

}

void menu_queue() {

    Queue<int> q;


    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int num = rand() % 100 + 1;
        q.push(num); // push a random num into queue
    }



    Queue<int>::Iterator it; // the goal of it is to iterate through the entire list
    Queue<int>::Iterator cursor; // the goal of cursor is to iterate until finding a marked item in the list
    cursor = q.Begin();

    for (it = q.Begin(); it != q.End(); ++it) {
        //        cout << *cursor << " ";
        if (cursor.next() == q.End()) {
            cout << "{" << *it << "} -> ";
        }//looping through all the elements of List using the Iterator
        else {
            cout << "[" << *it << "] -> ";
            ++cursor;
        }
        //increment the cursor as you increment the it

    }
    cout << "|||" << endl;


    char select = 'H';


    // implement the menu
    while (select != 'E') {

        //        cout << q << endl;


        //printing the queue

        print_menu();

        select = get_select();

        select = toupper(select);

        //how do i implement cursor?
        //cursor.next() is an iterator

        if (select == 'R') {
            int num = rand() % 100 + 1;
            q.push(num);

            cursor = q.Begin();
            //print the menu
            for (it = q.Begin(); it != q.End(); ++it) {
                if (cursor.next() == q.End()) {
                    cout << "{" << *cursor << "} -> ";
                }//looping through all the elements of List using the Iterator
                else {
                    cout << "[" << *cursor << "] -> ";
                    cursor++;
                }
            }
        } else if (select == 'B') {
           
            cursor = q.Begin();
            
            for (it = q.Begin(); it != q.End(); ++it) {
                if (cursor.next() == q.End()) {
                    cout << "{" << *cursor << "} -> ";
                }//looping through all the elements of List using the Iterator
                else {
                    cout << "[" << *cursor << "] -> ";
                }
            }
        }



        cout << "|||" << endl;


    }




    //    do {
    //        //output the array:
    //        
    //        
    //    } while(toupper(select) != 'E');

    //    Queue<int>::Iterator it; //a queue Iterator object
    //
    //    for (it = q.Begin(); it != q.End(); it++) {
    //        //looping through all the elements of List using the Iterator
    //        cout << *it << " | ";
    //    }



}

void print_menu() {
    cout << "[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd ";
}

char get_select() {
    char select;

    do {
        cin >> select;
    } while (toupper(select) != 'R' && toupper(select) != 'A' && toupper(select) != 'B' &&
            toupper(select) != 'D' && toupper(select) != 'S' && toupper(select) != 'P' &&
            toupper(select) != 'N' && toupper(select) != 'H' && toupper(select) != 'E');

    return select;
}

void test_iterator_queue() {

    cout << endl << "Testing a queue with iterator:" << endl;
    cout << endl << "Testing a list of ints:" << endl;

    Queue<int> q;

    for (int i = 0; i < 10; i++) {
        q.push(i * 10);
    }

    Queue<int>::Iterator it; //a queue Iterator object
    //    it = q.Begin();
    //    cout << *it << endl;

    for (it = q.Begin(); it != q.End(); ++it) {
        //looping through all the elements of List using the Iterator
        cout << *it << " | ";
    }

    //delete it;      //cannot be done.
    //delete it._ptr; //cannot be done.

    cout << endl << "=======================" << endl;
    cout << endl << "Testing a list of strings:" << endl;

    Queue<string> qstr;
    qstr.push("Abel");
    qstr.push("Blake");
    qstr.push("Cory");
    qstr.push("Donovan");
    qstr.push("Edmund");
    Queue<string>::Iterator it_str;

    for (it_str = qstr.Begin(); it_str != qstr.End(); it_str++) {
        cout << *it_str << " | ";
        *it_str = "X";
        cout << *it_str << " | ";
        //        cin.get();
    }

    cout << endl << "=======================" << endl << endl;
}

void test_iterator_stack() {

    cout << endl << "=======================" << endl;

    cout << endl << "Testing a stack with iterator" << endl;
    cout << endl << "Testing a list of ints:" << endl;

    Stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(i * 10);
    }

    Stack<int>::Iterator it;

    for (it = s.begin(); it != s.end(); it++) {
        cout << "The top is: " << s.top() << " | " << *it << " goes pop" << endl;
        s.pop();
    }

    //    cout << s.top() << endl; //assertion failed because list is empty


    cout << endl << "=======================" << endl;
    cout << endl << "Testing a list of strings:" << endl;

    Stack<string> sstr;

    sstr.push("Amy");
    sstr.push("Bella");
    sstr.push("Candy");
    sstr.push("Daisy");
    sstr.push("Emma");

    Stack<string>::Iterator sit;

    for (sit = sstr.begin(); sit != sstr.end(); sit++) {
        cout << "The top is: " << sstr.top() << " | " << *sit << " goes pop" << endl;
        sstr.pop();
    }

    //    cout << sstr.top() << endl; //assertion failed because list is empty

}
