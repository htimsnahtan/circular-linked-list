/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: 8-5-18
** Description: Queue class implimentation file. Has constructor/destructor
* to deal with memory as well as functions to interact with Queue.
*********************************************************************/

#include "Queue.hpp"
#include <iostream>

// constructor
Queue::Queue()
{
    head = NULL;
}

// destructor frees all memories of nodes in Queue
Queue::~Queue()
{
    // start deleting at head of queue
    while (!isEmpty())
    {
        removeFront();
    }
}

// isEmpty() checks if the queue is empty. If so, returns true; otherwise, 
// return false
bool Queue::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

// addBack() takes a user-inputted integer, creates a QueueNode with user-
// inputted integer, and appends it to the back of the list.
void Queue::addBack(int integerIn)
{
    QueueNode *queueNodePtr = new QueueNode;
    queueNodePtr->val = integerIn;
    // if list is empty create new head
    if (isEmpty())
    {
        queueNodePtr->prev = queueNodePtr;
        queueNodePtr->next = queueNodePtr;
        head = queueNodePtr;
    }
    else
    {
        // get pointer to current end of queue
        QueueNode *queueEndNodePtr = head->prev;
        
        // set new node's prev to end of queue
        queueNodePtr->prev = queueEndNodePtr;
        // set new node's nex to head
        queueNodePtr->next = head;
        // set end of queue's next to new node
        queueEndNodePtr->next = queueNodePtr;
        // set head's prev to new node
        head->prev = queueNodePtr;
    }
}

// getFront() returns the value of the node at the front of the queue.
// returns -1 if queue is empty
int Queue::getFront()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        return head->val;
    }
}

// removeFront() removes the front QueueNode of the queue and free the memory.
void Queue::removeFront()
{   
    // if Queue is empty
    if (isEmpty())
    {
        std::cout << "Nothing to be deleted!" << std::endl;
        return;
    }
    // if Queue only has 1 item
    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    // if Queue has more than 1 item
    else
    {
        QueueNode *newHead = head->next;
        QueueNode *currentEnd = head->prev;
        
        newHead->prev = currentEnd;
        currentEnd->next = newHead;
        
        delete head;
        head = newHead;
    }
}

// printQueue() traverses through the queue from head using next pointers, 
// and prints the values of each QueueNode in the queue.
void Queue::printQueue()
{
    QueueNode *queueNodePtr = head;
    if (!isEmpty())
    {
        do
        {
            // print current node value
            std::cout << queueNodePtr->val << " ";
            // move to next node
            queueNodePtr = queueNodePtr->next;
        }
        while(queueNodePtr != head);
        
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Queue is empty!" << std::endl;
    }
}