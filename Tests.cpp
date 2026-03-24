#include <iostream>
#include "ArrayQueue.hpp"
#include "Queue.hpp"


int main () {
    // TODO
    //testing array queue, enqueue, front, and back
    ArrayQueue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Front: " << q.front() << std::endl; // should print 1
    cout << "Back: " << q.back();
    cout << " should print 5" << std::endl; // should print 5

    // testing dequeue
    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl;
    cout << "should print 2" << endl; // should print 2
    q.enqueue(6); // should throw an exception because the queue is full

    // testing clear
    q.clear();
    cout << "Length after clear: " << q.getLength() << endl; 
    cout << "should print 0" << std::endl; // should print 0
    cout << "Is empty after clear: " << q.isEmpty() << endl; 
    cout << "should print 1 (true)" << endl;

    //testing copy
    ArrayQueue<int> q2(q);
    cout << "Length of copied queue: " << q2.getLength() << endl;
    cout << "should print 0" << std::endl; // should print 0
    cout << "Is copied queue empty: " << q2.isEmpty() << endl;
    cout << "should print 1 (true)" << endl;
    

    return 0;
}