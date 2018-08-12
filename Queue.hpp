/*********************************************************************
** Program name: Queue.hpp
** Author: Nathan Smith
** Date: 8-5-18
** Description: Queue class declaration file as well as struct declaration
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

struct QueueNode
{
    int val;
    QueueNode *next;
    QueueNode *prev;
};

class Queue
{
private:
    QueueNode *head;
    
public:
    // constructor
    Queue();
    // destructor frees all memories of nodes in Queue
    ~Queue(); 
    // isEmpty() checks if the queue is empty. If so, returns true; otherwise, 
    // return false
    bool isEmpty(); 
    // addBack() takes a user-inputted integer, creates a QueueNode with user-
    // inputted integer, and appends it to the back of the list.
    void addBack(int val);
    // getFront() returns the value of the node at the front of the queue.
    int getFront();
    // removeFront() removes the front QueueNode of the queue and free the memory.
    void removeFront();
    // printQueue() traverses through the queue from head using next pointers, 
    // and prints the values of each QueueNode in the queue.
    void printQueue();
};

#endif