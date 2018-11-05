#include "Simple_List.h"
#include "Linked_List.h"
#include "Stack.h"
#include "Queue.h"
#include <cstdlib>
#include <iostream>
#include <cassert>

using namespace std;

void test_iterator_queue();
void test_iterator_stack();

int main(int argc, char** argv) {

    test_iterator_queue();
    test_iterator_stack();
    return 0;

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

    //prefix works but not post fix
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
        cout << "The top is: " <<s.top() << " | " << *it << " goes pop" << endl;
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
        cout << "The top is: " <<sstr.top() << " | " << *sit << " goes pop" << endl;
        sstr.pop();
    }
    
    cout << sstr.top() << endl; //assertion failed because list is empty

}
