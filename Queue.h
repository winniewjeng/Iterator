
#ifndef QUEUE_H
#define QUEUE_H

#include "Linked_List.h"
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>

class Queue {
private:
    node<T>* front;
    node<T>* rear;
    int size;

public:

    class Iterator {
    private:
        node<T>* ptr; //pointer being encapsulated

    public:
        friend class Queue;

        //ctor

        Iterator(node<T>* p = nullptr) : ptr(p) {
        }

        // return an iterator to the next location in the list  

        Iterator next() {
            return Iterator(ptr->_next);
        }

        //return the dereferenced item

        T& operator*() {
            // assert ptr != nullptr
            assert(ptr);
            return ptr->_item;
        }

        // still don't know what this is for
        //        node<T>& operator*() const {
        //            assert(ptr);
        //            return *ptr;
        //        }

        // ++it

        Iterator& operator++() {
            ptr = ptr->_next;
            return *this;
        }

        // it++

        friend Iterator operator++(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it.ptr = it.ptr->_next;
            return hold;
        }

        //it != it

        friend bool operator!=(const Iterator& left, const Iterator& right) {
            return left.ptr != right.ptr;
        }
        
        friend bool operator==(const Iterator& left, const Iterator& right) {
            return left.ptr == right.ptr;
        }

    }; // end of iterator class

    //constructor

    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    //copy constructor
    //NOT YET TESTED

    Queue(const Queue& other) {
        front = copy_list(other.front);
        rear = LastNode(front);
        size = other.size;
    }

    //destructor

    ~Queue() {
        // Delete the list, set front and rear to null
        clear_list(front);
        front = nullptr;
        rear = nullptr;
    }

    //assignment operator
    //NOT YET TESTED

    Queue<T>& operator=(const Queue<T>& rhs) {
        //self-check
        if (*this == rhs) {
            return *this;
        }
        //clean up
        clear_list(front);
        rear = front;

        //re-instantiate lhs attributes
        front = copy_list(rhs.front);
        rear = LastNode(front);
        size = rhs->size;

        return *this;
    }

    // pushes item to the rear

    void push(const T& item) {

        // declare a walker to traverse down the queue
        node<T>* walker = front;

        // if the queue is empty, create a new node of capacity 1
        if (walker == rear) {
            insert_head(front, item);
            rear = LastNode(front);
            //qqq LastNode takes way too long to run
            //            walker->_next = rear;
        }// Does this work?
        else {

            while (walker->_next != rear) {
                walker = walker->_next;
            }
            insert_after(front, walker, item);
            //resetting rear
            rear = LastNode(front);
        }

        //queue size enlarges by 1
        this->size++;
    }

    //pop items from the front

    T pop() {
        // cannot pop an empty queue
        assert(!empty());

        //decrement the queue size
        size--;
        // hold the item front of the queue and delete front
        T hold = delete_head(front);

        //NOOOOOOOO!!! What about the rear??
        // reset rear to the last element
        rear = LastNode(front);

        //Do i need this??
        if (empty()) {
            rear = front; //does this work? I am aligning my rear to my front 
        }
        return hold;
    }

    T top() {
        // cannot check top of an empty queue
        assert(!empty());

        return front->_item;
    }

    bool empty() {
        return this->size == 0;
    }

    template <class U>
    friend ostream& operator<<(ostream& outs, const Queue<U>& q) {
        node<U>* walker = q.front;
//        outs << "\n.. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. ..\n";
        while (walker != q.rear) {
            outs << " [" << walker->_item << "] ->";
            walker = walker->_next;
        }
        outs << " |||";
        return outs;
    }
    
    // get the size of the queue
    int get_size() {
        return size;
    }

    //an iterator to the start of List
    //

    Iterator Begin() const {
        //C++ requires you to use the keyword typename when referring to the Iterator outside the class declaration

        return Iterator(front);
    }

    //an iterator to the end of List

    Iterator End() const {
        return Iterator(rear);
    }

};


#endif /* QUEUE_H */

