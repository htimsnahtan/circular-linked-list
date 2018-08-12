/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: 8-5-18
** Description: main function to call and show how Queue class works.
* Impliments menu system which allows user to add a value to a queue, get the 
* first value, remove the first value, display the queue, and exit
*********************************************************************/
#include "utilityFunctions.hpp"
#include "Queue.hpp"
#include <iostream>

int main()
{
    std::string menuItems = "1. Add a value to the back of queue \n2. Display th"
    "e front value\n3. Remove the front node\n4. Display the queue’s content\n5. Exit";
    
    bool programInProgress = true;
    Queue queue;
    
    std::cout << "Welcome!" << std::endl;
    
    while (programInProgress)
    {
        std::cout << "Please choose from the following options:" << std::endl;
        int userInput = getValidNumber(menuItems, "Please enter 1-5",0,6);
        
        switch(userInput)
        {
            case 1:
            {
                queue.addBack(getValidNumber("Enter a positive integer:"));
                break;
            }
            case 2:
            {
                int frontVal = queue.getFront();
                if (frontVal == -1)
                {
                    std::cout << "Queue is empty!" << std::endl;
                }
                else
                {
                    std::cout << frontVal << std::endl;
                }
                break;
            }
            case 3:
            {
                queue.removeFront();
                break;
            }
                
            case 4:
            {
                queue.printQueue();
                break;
            }
            case 5:
            {
                programInProgress = false;
                break;
            }
        }
    }
    
    return 0;
}