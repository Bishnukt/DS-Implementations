#include <iostream>
using namespace std;
#define Max 20
class Solution
{
    int front = -1, rear = -1;
    int Queue[Max];

public:
    void enqueue(int data)
    {
        if (front == 0 && rear == Max - 1)
        {
            cout << "Queue overflow. Task failed." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        if (rear == Max - 1)
            rear = 0;
        else
            rear++;
        Queue[rear] = data;
    }

    int dequeue()
    {
        int data;
        if (front == -1)
        {
            cout << "Queue underflow." << endl;
            return -1;
        }
        data = Queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == Max - 1)
            front = 0;
        else
            front++;
        return data;
    }

    void display()
    {
        int i;
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Elements present in queue are: ";
        i = front;
        if (front <= rear)
        {
            while (i <= rear)
                cout << Queue[i++] << " ";
        }
        else
        {
            while (i <= Max - 1)
                cout << Queue[i++] << " ";
            i = 0;
            while (i <= rear)
                cout << Queue[i++] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution queue;
    int data;
    while (true)
    {
        cout << "1.Enqueue." << endl;
        cout << "2.Dequeue." << endl;
        cout << "3.Display." << endl;
        cout << "4.Exit." << endl;
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> data;
            queue.enqueue(data);
            cout << endl;
            break;

        case 2:
            data = queue.dequeue();
            if (data != -1)
                cout << data << " dequeued." << endl;
            cout << endl;
            break;

        case 3:
            queue.display();
            cout << endl;
            break;

        case 4:
            cout << endl;
            exit(0);

        default:
            cout << "Invalid choice. Try again." << endl;
            cout << endl;
        }
    }
    return 0;
}
