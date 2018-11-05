#ifndef STACK_H
#define STACK_H

#include "Simple_List.h"
#include "Linked_List.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Stack {
private:
    int size;
    Simple_List<T> stack;

public:

    class Iterator {
    public:
        friend class Stack;

        Iterator() : list() {
        }

        Iterator(typename Simple_List<T>::Iterator rhs) : list(rhs) {
        }

        T& operator*() {
            return *list;
        }

        Iterator& operator++() {
            list.operator++();
            return *this;
        }

        friend Iterator operator++(Iterator& it, int unused) {
            Iterator hold = it;
            it = it.operator++();
            return hold;
        }

        friend bool operator!=(const Iterator& left, const Iterator& right) {
            return left.list != right.list;
        }

        bool is_null() {
            return list.is_null();
        }

    private:
        typename Simple_List<T>::Iterator list; // pointer p being encapsulated in the Iterator class of Simple List Class
    };

    Stack() {
        size = 0;
    }

    //Iterator push

    void push(const T& item) {
        size++;
        stack.InsertHead(item);
        //        cout << size << endl;
    }

    T pop() {
        //assert
        assert(!stack.Begin().is_null());
        size--;
        return stack.Delete(stack.Begin());
    }

    T top() {
        //assert
        assert(!stack.Begin().is_null());
        return stack.Begin().operator *(); // is this right?
    }

    bool empty() {
        return size == 0;
    }

    template <class U>
    friend ostream& operator<<(ostream& outs, const Stack<U>& s) {
        node<U>* walker = s.stack.Begin();
        while (walker != s.stack.End()) {
            outs << " [" << walker->_item << "]";
            walker = walker->_next;
        }
        return outs;
    }

    typename Stack<T>::Iterator begin() const {
        return stack.Begin();
        //        return Iterator(stack.Begin());
    }
    //    

    typename Stack<T>::Iterator end() const {
        return stack.End();
        //        return stack.End(stack.Begin()));
    }

    //    friend bool operator!=(const Stack::Iterator& left, const Stack::Iterator& right) {
    //        return *left != *right;
    //    }

    //true if left == right

    //    friend bool operator==(const Iterator& left, const Iterator& right) {
    //        return left.ptr == right.ptr;
    //    }

    ////OG push
    //    void push(const T& item) {
    //        size++;
    //        stack.insert_head(item);
    //    }

    ////OG pop
    //    T pop() {
    //        assert(stack.Begin() != nullptr);
    //        size--;
    //        return stack.Delete(stack.Begin());
    //    }

    ////OG top
    //    T top() {
    //        assert(stack.Begin() != nullptr);
    //        return stack.Begin()->_item;
    //    }

    ////OG empty doesn't change
    //    bool empty() {
    //        return size == 0;
    //    }

    ////OG ostream operator
    ////WOW I DIDN'T THINK THIS WOULD WORK
    //    template <class U>
    //    friend ostream& operator<<(ostream& outs, const Stack<U>& s) {
    //        node<U>* walker = s.stack.Begin();
    //        while (walker != s.stack.End()) {
    //            outs << " [" << walker->_item << "]";
    //            walker = walker->_next;
    //        }
    //        return outs;
    //    }

};

#endif /* STACK_H */