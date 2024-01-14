#include <iostream>
using namespace std;
struct node
{
    int value; //value of node
    node *road; //road routes
    node *aerial; //aerial routes
    //constructor
    node(int value)
    {
        this->value = value; //struct's value is being assigned the other value
        //both routes are set to NULL
        road = NULL;
        aerial = NULL;
    }
};
struct graph
{
    node *head; //our head pointer
    node *tail; //our tail pointer

    graph()
    {
        //our graph constructor
        head = tail = NULL; //both head and tail are set to NULL
    }
    ~graph()
    {
        node*temp = NULL;
        while(head!=tail)
        {
            temp = head;
            head = head->road;
            temp = NULL;
        }
        head = NULL;
        tail = NULL;
        temp = NULL;
    }
    //addition of a road route
    void addroad(int val)
    {
        node *new_node = new node(val); //a new node is made
        if (head == NULL) //graph contains no city YET
        {
            head = new_node; //head is assigned the first city
            tail = new_node; //tail is assigned the first city
            return; //function is returned
        }
        tail->road = new_node; //if graph does contain an existing city, then we add the city to the end of the graph
        tail = new_node; //tail pointer is moved forward and pointed to the new city
    }
    //addition of aerial route
    void addedge(int start, int end)
    {
        node *temp1 = head; //temp pointer is used as a traversal pointer
        while (temp1 != NULL && temp1->value != start) //loop to traverse to the "start"
        {
            temp1 = temp1->road;
        }
        //if start city does not exist
        if (temp1 == NULL)
        {
            cout << "start point not found" << endl;
            return; //return function
        }
        else
        {
            node *temp2 = head; //temp2 pointer is used as a traversal pointer
            while (temp2 != NULL && temp2->value != end) //loop to traverse to the "end"
            {
                temp2 = temp2->road;
            }
            //end city is not found
            if (temp2 == NULL)
            {
                cout << "end point not found" << endl;
                return; //return function
            }
            else
            {
                temp1->aerial = temp2; //aerial route is added
            }
        }
    }
    void printgraph()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->road;
        }
        cout << endl;
        cout << endl;
        node *temp2 = head;
        while (temp2 != NULL)
        {
            if (temp2->aerial!=NULL)
            {
                cout << "Aerial : " << temp2->value << " -> " << temp2->aerial->value << endl;
            }
            temp2=temp2->road;
        }
    }
};