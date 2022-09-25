//Design your implementation of the circular queue.The circular queue is a linear data structure in which the operations are performed based on FIFO(First In First Out) principleand the last position is connected back to the first position to make a circle.It is also called "Ring Buffer".
//
//One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue.But using the circular queue, we can use the space to store new values.
//
//Implementation the MyCircularQueue class :
//
//    MyCircularQueue(k) Initializes the object with the size of the queue to be k.
//    int Front() Gets the front item from the queue.If the queue is empty, return -1.
//    int Rear() Gets the last item from the queue.If the queue is empty, return -1.
//    boolean enQueue(int value) Inserts an element into the circular queue.Return true if the operation is successful.
//    boolean deQueue() Deletes an element from the circular queue.Return true if the operation is successful.
//    boolean isEmpty() Checks whether the circular queue is empty or not.
//    boolean isFull() Checks whether the circular queue is full or not.
//    You must solve the problem without using the built - in queue data structure in your programming language.
//
//Constraints:
//
//1 <= k <= 1000
//0 <= value <= 1000
//At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

#include <iostream>
class MyCircularQueue {

private: 
    //size is queue size
    //FrontIndex tells where the front of queue is
    //BackIndex tells where the back of the queue is
    //basket tells how many items are inside the queue
    //queue is the circular queue
    int size, FrontIndex, BackIndex,basket;
    int* queue;

public:

    MyCircularQueue(int k) {
       //initializing variables
        size = k;
        FrontIndex = 0;
        BackIndex = 0;
        basket = 0;
        queue = new int[k];
    }

    bool enQueue(int value) {
        //checks if queue is full
        if (isFull()) {
            return 0;
        }
        //tells variable that an item has been added
        basket += 1;
        //putting item in queue
        queue[BackIndex] = value;
        //changing back of queue
        if (BackIndex == size -1) {
            BackIndex = 0;
        }
        else {
            BackIndex += 1;
        }
        return 1;
    }

    bool deQueue() {
        //checking if queue is empty
        if (isEmpty()) {
            return 0;
        }
        //tells variable that an item has been removed
        basket -= 1;
        //changing front of queue
        if (FrontIndex == size - 1) {
            FrontIndex = 0;
        }
        else {
            FrontIndex += 1;
        }
        return 1;
    }

    int Front() {
        //don't print if empty
        if (isEmpty()) {
            return -1;
        }
        return queue[FrontIndex];
    }

    int Rear() {
        //don't print if empty
        if (isEmpty()) {
            return -1;
        }
        if (BackIndex == 0) {
            return queue[size - 1];
        }
        return queue[BackIndex-1];
    }

    bool isEmpty() {
        //checking empty by how many items are in queue
        return basket == 0;
    }

    bool isFull() {
        //checking fullness by how many items are in queue
        return basket == size;
    }

};


int main()
{
    MyCircularQueue hello(5);
    std::cout << hello.isEmpty() << "\n";
    hello.enQueue(1);
    hello.enQueue(4);
    hello.enQueue(5);
    hello.enQueue(6);
    hello.enQueue(7);
    hello.deQueue();
    hello.deQueue();
    hello.deQueue();
    hello.deQueue();
    hello.deQueue();
    std::cout << hello.Front() << " " << hello.Rear();
    std::cout << "\n" << hello.isEmpty();
}