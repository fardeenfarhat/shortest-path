#include <iostream>
#include <cmath>
#include "queues.h"
#include "graph.h"
using namespace std;
//our main BFS finding short path function
int dayfinder(graph country, int size, int dest)
{
    Queue<int> que; //making an int queue
    size = size * 4; //quadrupling the size so that we can store visited cities multiple times.
    int days[size]; // Array to store the days taken to reach each node
    int visited[size]; //visited array
    for (int i = 0; i < size; ++i)
    {
        visited[i] = 99; //setting every index as 99
        days[i] = 0; //setting every index as 0
    }
    int day = 0; //temporary day variable
    int iter = 0; //temporary iterator
    que.enqueue(1); //first city is queued into our queue
    //main loop
    while (iter < size)
    {
        int current = que.front(); //front of queue is assigned to current variable which contains current city
        que.dequeue(); //front value of queue is dequed
        visited[iter++] = current; //city is stored into the visited array and iterator is iterated
        //if destination is found, break the loop
        if (current == dest)
        {
            break;
        }
        node *temp = country.head; //head is appointed towards the first city
        for (int i = 0; i < current - 1; i++)
        {
            temp = temp->road; //temp is traversed till the current-1 city
        }
        //if there is an aerial route, we will enter this if statement
        if (temp->aerial != NULL)
        {
            que.enqueue(temp->aerial->value); //aerial route is enqueued
            if (days[current - 1] % 7 != 0)
            {
                int tempo=days[current - 1]; //temporary variable which stores days spent on city
                for (int i = 0; i < 7-(days[current-1] % 7 ); i++) //this loops rounds us upto a whole day if we find an aerial path
                {
                    tempo++;
                }
                days[temp->aerial->value - 1] = tempo; //day after travelling to city is assigned tempo
                
            }
            else
            {
                days[temp->aerial->value - 1] = days[current - 1] + 6; //if aerial route is taken at the start of the day
            }
        }
        //if there is a road route, we enter this if statement
        if (temp->road != NULL)
        {
            que.enqueue(temp->road->value); //neighboring city is enqueued
            days[temp->road->value - 1] = days[current - 1] + 1; // Road route takes 1 day
        }
    }
    int final=0; //our final day to be returned
    for (int i = 0; visited[i] != 99; i++)
    {
        if(visited[i]==dest)
        {
            final=days[visited[i]-1]; //assign final the shortest route's days
        }
    }
    int bruh = static_cast<int>(ceil((float)final/(float)6)); //days are rounded up to the nearest integer
    cout<<"Days : "<<bruh<<endl; //Days are displayed
    return -1; // Return -1 if the destination is not reachable
}
void projectstart()
{
    graph cities; //graph is created
    int num; //num of cities
    try
    {
        system("pause");
        system("cls"); // Clear console
        cout << "+----------------------------------+" << endl;
        cout << "|        " << "Shortest Route" << "            |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "Enter the number of cities : ";
        cin >> num;
        //optimization and error handling
        if (cin.fail()) 
        {
            // User entered a non-integer
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            throw runtime_error("Invalid input. Please enter a valid integer.");
        }
        if (num <= 0) 
        {
            cout << "Enter a  valid number of cities." << endl;
        }
        for (int i = 1; i <= num; i++)
        {
            cities.addroad(i); //cities are added
        }
        int choice = 0;
        cout << "Enter the number of aerial routes between two cities : "; //aerial routes are asked
        cin >> choice;
        //setting of aerial routes
        for (int i = 0; i < choice; i++)
        {
            int start, dest = 0;
            route:
            cout << "Enter start and destination for route " << (i + 1) << ": ";
            cin >> start >> dest;
            if(start<=0 ||start>num)
            {
                cout<<"Invalid starting city. Please try again."<<endl;
                goto route;
            }
            if(dest<=0 ||dest>num)
            {
                cout<<"Invalid destination city. Please try again."<<endl;
                goto route;
            }
            cities.addedge(start, dest); //aerial route created
        }
        dayfinder(cities,num,num); //BFS function called
    }
    //error handling
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
        projectstart(); //our projectstart function is recursively called if an error occurs
    }
}
void project()
{
    int numoftestcases=0;
    system("cls"); // Clear console
    //loop to make sure user doesn't give 0 test cases
    while (numoftestcases <= 0) 
    {
        //error handling
        try 
        {
            //console is paused for the user to take a deep breath LOL :)
            system("pause");
            system("cls"); // Clear console
            cout << "+----------------------------------+" << endl;
            cout << "|        " << "Main Menu" << "                 |" << endl;
            cout << "+----------------------------------+" << endl;
            cout << "Enter the number of test cases: ";
            cin >> numoftestcases;

            if (cin.fail()) 
            {
                // User entered a non-integer
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw runtime_error("Invalid input. Please enter a valid integer.");
            }
            if (numoftestcases <= 0) 
            {
                cout << "Enter a valid number of test cases." << endl;
            }
        } 
        catch (const exception& e) 
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    for (int i = 0; i < numoftestcases; i++) 
    {
        projectstart();
    }
    system("pause");
    system("cls");
    cout << "+----------------------------------+" << endl;
    cout << "|        " << "Goodbye! :)" << "               |" << endl;
    cout << "+----------------------------------+" << endl;
}
int main()
{
    project(); //project STARTS! :)
    return 0;
}