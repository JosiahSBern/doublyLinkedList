#include <iostream>
#include "List.h"
using namespace std;
/***************************************************************
 * Programmer: Josiah St Bernard
 * Date: February 25th, 2025
 * Purpose: Main for doubly linked list
 * Input: None
 * Output: None
 **************************************************************/
void displayMenu()
{
    cout << "\n===== Doubly Linked List =====" << endl;
    cout << "1. Insert at the Back" << endl;
    cout << "2. Insert at the Front" << endl;
    cout << "3. Delete an Item" << endl;
    cout << "4. Search for an Item" << endl;
    cout << "5. Check if List is Empty" << endl;
    cout << "6. Display List Length" << endl;
    cout << "7. Print List Method" << endl;
    cout << "8. Print List using Iterator (Front to Back)" << endl;
    cout << "9. Print List using Iterator (Back to Front)" << endl;
    cout << "10. Test Copy Constructor" << endl;
    cout << "11. Test Assignment Operator" << endl;
    cout << "12. Exit" << endl;
    cout << "==========================================" << endl;
}


int main()
{
    List<int> list;
    List<int> list3;
    int choice;
    int value;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        //Insert at back
        case 1:
        {
            char choice;
            do
            {
                cout << "Enter value to insert to the back: ";
                cin >> value;
                list.insertItem(value);
                cout << value << " inserted at the back" << endl;

                cout << "Would you like to add another value? (y/n): ";
                cin >> choice;

            } while (choice == 'y' || choice == 'Y');
        }
        break;

        //Insert at front
        case 2:
        {
            char choice;
            do
            {
                cout << "Enter value to insert to the front: ";
                cin >> value;
                list.insertItem(value);
                cout << value << " inserted at the front" << endl;

                cout << "Would you like to add another value? (y/n): ";
                cin >> choice;

            } while (choice == 'y' || choice == 'Y');
        }
        break;

        //Delete an item
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            if (list.deleteItem(value))
            {
                cout << value << " has been deleted from the list" << endl;
            }
            else
            {
                cout << value << " was not found in the list" << endl;
            }
            break;

        //Search for an item
        case 4:
            cout << "Enter value to search for: ";
            cin >> value;
            {
                int position = list.searchItem(value);
                if (position != -1)
                {
                    cout << value << " found at position " << position << endl;
                }
                else
                {
                    cout << value << " not found in the list" << endl;
                }
            }
            break;

        //Checks if empty
        case 5:
            if (list.isEmpty())
            {
                cout << "The list is empty" << endl;
            }
            else
            {
                cout << "The list is not empty" << endl;
            }
            break;
        //Display length
        case 6:
            cout << "The length of the list is: " << list.getLength() << endl;
            break;

        //Print list
        case 7:
            cout << "List contents: ";
            list.printList();
            cout << endl;
            break;

        //Print with iterator (front to back)
        case 8:
            cout << "List (front to back): ";
            for (auto i = list.begin(); i != list.end(); i++)
            {
                cout << *i << " ";
            }
            break;

        //Print with iterator (back to front)
        case 9:
        {
            cout << "List (back to front): ";
            for (auto i = list.rbegin(); i != list.rend(); i--)
            {
                cout << *i << " ";
            }
            break;
        }
        break;

        //Test copy constructor
        case 10:
        {
            List<int> list2 = list;
            cout << "List 1 copied to List 2";
            list2.printList();
            break;
        }

        //Test assignment operator
        case 11:
        {
            list3 = list;
            cout << "Assigned List";
            list3.printList();
            break;
        }

        case 12:
            cout << "Exiting" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 11" << endl;
        }

    } while (choice != 12);

    return 0;
}