#include <iostream>
using namespace std;

// Node structure for the elements in the queue
template <typename T>
struct Node 
{
    T data;           // Data of the node
    Node* next;       // Pointer to the next node in the queue

    // Constructor to initialize the node with data
    Node(const T& data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Queue structure for managing elements using a linked list
template <typename T>
struct Queue 
{
private:
    Node<T>* fronty;   // Pointer to the front of the queue
    Node<T>* rear;     // Pointer to the rear of the queue
    int size;          // Size of the queue

public:
    // Constructor to initialize an empty queue
    Queue()
    {
        fronty = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor to deallocate memory when the queue goes out of scope
    ~Queue() 
    {
        // Dequeue all elements until the queue is empty
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const 
    {
        // Return true if the size is 0, indicating an empty queue
        if(size==0)
        {
            return 1;
        }
        // Return false if the size is non-zero, indicating a non-empty queue
        else
        {
            return 0;
        }
    }

    // Enqueue a new element to the rear of the queue
    void enqueue(const T& data) 
    {
        // Create a new node with the given data
        Node<T>* newNode = new Node<T>(data);

        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) 
        {
            fronty = rear = newNode;
        } 
        // If the queue is non-empty, add the new node to the rear
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }

        // Increment the size of the queue
        size++;
    }

    // Dequeue the element from the front of the queue
    void dequeue() 
    {
        // If the queue is empty, display an error message and return
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // Store the front node in a temporary variable
        Node<T>* temp = fronty;

        // Move the front pointer to the next node
        fronty = fronty->next;

        // Delete the temporary node
        delete temp;

        // Decrement the size of the queue
        size--;

        // If the queue is now empty, set the rear pointer to nullptr
        if (isEmpty()) 
        {
            rear = nullptr;
        }
    }

    // Get the data of the element at the front of the queue
    T front() const 
    {
        // If the queue is empty, display an error message and exit
        if (isEmpty()) 
        {
            cerr << "Queue is empty." <<endl;
            exit(EXIT_FAILURE);
        }

        // Return the data of the front node
        return fronty->data;
    }

    // Get the current size of the queue
    int getSize() const 
    {
        return size;
    }
};