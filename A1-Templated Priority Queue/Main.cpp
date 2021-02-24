#include "queue.h"
#include <iostream>

using namespace std;


void wrapper()
{
    //Integer Queue created
    cout << "Integers on a Queue ->" << endl;
    PriorityQueue<int> myQueue;
     
    //Pushing integer elements onto Queue
    myQueue.Push(2);
    cout << "	just pushed +++++" << endl;
    myQueue.Push(1);
    cout << "	just pushed +++++" << endl;
    myQueue.Push(4);
    cout << "	just pushed +++++" << endl;
    myQueue.Push(3);
    cout << "	just pushed +++++" << endl;

    //Checks if queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue.GetSize() << endl;

    //Printing result
    myQueue.Print();
    
    cout << endl;

    //Popping values off of Queue(2, 1)
    cout << "Integers removed on Queue ->" << endl;
    myQueue.Pop();
    cout << "		just popped -----" << endl;
    myQueue.Pop();
    cout << "		just popped -----" << endl;

    //Push 5
    myQueue.Push(5);

    //Print result
    myQueue.Print();

    cout << endl;

    //Checks if queue is empty and the current size
    cout << "Is the stack empty? " << myQueue.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Stack size: " << myQueue.GetSize() << endl;

    cout << endl << endl;

    //Character queue created
    cout << "Characters on a Queue ->" << endl;
    PriorityQueue<char> myQueue2;

    //Pushing character elements on queue
    myQueue2.Push('b');
    cout << "	just pushed +++++" << endl;
    myQueue2.Push('a');
    cout << "	just pushed +++++" << endl;
    myQueue2.Push('d');
    cout << "	just pushed +++++" << endl;
    myQueue2.Push('c');
    cout << "	just pushed +++++" << endl;

    //Checks if queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue2.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue2.GetSize() << endl;

    //Print result
    myQueue2.Print();

    cout << endl;

    //Popping characters off queue(a, and b)
    cout << "Characters removed on Queue ->" << endl;
    myQueue2.Pop();
    cout << "		just popped -----" << endl;
    myQueue2.Pop();
    cout << "		just popped -----" << endl;

    //Push e
    myQueue2.Push('e');

    //Print result
    myQueue2.Print();

    cout << endl;

    // Checks if queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue2.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue2.GetSize() << endl;

    cout << endl << endl;

    //Creating double elements on Queue
    cout << "Double on a Queue ->" << endl;
    PriorityQueue<double> myQueue3;

    //Pushing double elements on Queue
    myQueue3.Push(11.1);
    cout << "	just pushed +++++" << endl;
    myQueue3.Push(22.2);
    cout << "	just pushed +++++" << endl;
    myQueue3.Push(33.3);
    cout << "	just pushed +++++" << endl;
    myQueue3.Push(44.4);
    cout << "	just pushed +++++" << endl;
    cout << "Is the Queue empty? " << myQueue3.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue3.GetSize() << endl;
    //Print result
    myQueue3.Print();

    cout << endl;

    //Popping off elements from queue (11.1, and 22.2)
    cout << "Popping off the two back elements on Queue ->" << endl;
    myQueue3.Pop();
    cout << "		just popped -----" << endl;
    myQueue3.Pop();
    cout << "		just popped -----" << endl;

    //Pushing 55.5
    myQueue3.Push(55.5);

    //Print result
    myQueue3.Print();

    cout << endl;

    // Checks if Queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue3.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue3.GetSize() << endl;

    cout << endl << endl;

    //Creating Float elements on Queue
    cout << "Float on a Queue ->" << endl;
    PriorityQueue<float> myQueue4;

    //Pushing Float elements on Queue
    myQueue4.Push(11.1f);
    cout << "	just pushed +++++" << endl;
    myQueue4.Push(22.2f);
    cout << "	just pushed +++++" << endl;
    myQueue4.Push(33.3f);
    cout << "	just pushed +++++" << endl;
    myQueue4.Push(44.4f);
    cout << "	just pushed +++++" << endl;

    cout << "Is the Queue empty? " << myQueue4.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue4.GetSize() << endl;

    //Print result
    myQueue4.Print();

    cout << endl;

    //Popping off elements from Queue (11.1, and 22.2)
    cout << "Popping off the two back elements on Queue ->" << endl;
    myQueue4.Pop();
    cout << "		just popped -----" << endl;
    myQueue4.Pop();
    cout << "		just popped -----" << endl;

    //Pushing 55.5f
    myQueue4.Push(55.5f);

    //Print result
    myQueue4.Print();

    cout << endl;

    // Checks if Queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue4.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue4.GetSize() << endl;

    cout << endl << endl;

    cout << "Short on a Queue ->" << endl;

    //Creating Short elements on Queue
    PriorityQueue<short> myQueue5;

    //Pushing short elements on Queue
    myQueue5.Push(22);
    cout << "	just pushed +++++" << endl;
    myQueue5.Push(33);
    cout << "	just pushed +++++" << endl;
    myQueue5.Push(11);
    cout << "	just pushed +++++" << endl;
    myQueue5.Push(44);
    cout << "	just pushed +++++" << endl;

     //Checks if queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue5.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue5.GetSize() << endl;

    //Print result
    myQueue5.Print();

    cout << endl;

    //Popping off elements from stack (44.4, and 33.3)
    cout << "Popping off the two back elements on Queue ->" << endl;
    myQueue5.Pop();
    cout << "		just popped -----" << endl;
    myQueue5.Pop();
    cout << "		just popped -----" << endl;

    //Pushing 55
    myQueue5.Push(55);

    //Print result
    myQueue5.Print();

    cout << endl;

    // Checks if Queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue5.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue5.GetSize() << endl;

    cout << endl << endl;


    //Creating long elements on Queue
    PriorityQueue<long> myQueue6;

    //Pushing short elements on Queue
    myQueue6.Push(22);
    cout << "	just pushed +++++" << endl;
    myQueue6.Push(33);
    cout << "	just pushed +++++" << endl;
    myQueue6.Push(11);
    cout << "	just pushed +++++" << endl;
    myQueue6.Push(44);
    cout << "	just pushed +++++" << endl;

    //Checks if queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue6.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue6.GetSize() << endl;

    //Print result
    myQueue6.Print();

    cout << endl;

    //Popping off elements from stack (44.4, and 33.3)
    cout << "Popping off the two back elements on Queue ->" << endl;
    myQueue6.Pop();
    cout << "		just popped -----" << endl;
    myQueue6.Pop();
    cout << "		just popped -----" << endl;

    //Pushing 55
    myQueue6.Push(55);

    //Print result
    myQueue6.Print();

    cout << endl;

    // Checks if Queue is empty and the current size
    cout << "Is the Queue empty? " << myQueue6.IsEmpty() << " (1 = True, 0 = False)" << endl;
    cout << "Queue size: " << myQueue6.GetSize() << endl;

    cout << endl << endl;
}

//Sets up wrapper function to dump memory leaks
int main()
{
    wrapper();
    _CrtDumpMemoryLeaks();
    getchar();
}