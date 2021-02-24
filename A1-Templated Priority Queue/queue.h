/*----------------------------------------------
Programmer: Nicholas Tesch (nlt5582@rit.edu)
Date: 2/1/2021

----------------------------------------------*/

//A queue is the same as people lining up: everyone enters
//the line from the back, and the person who got there first 
//is the person at the front of the line, and will leave the
//queue first.
#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_

#include <iostream>

//System Class
template <typename Placeholder>
class PriorityQueue
{
public:
	/*
	Usage: Constructor
	Arguments: ---
	Output: class object instance
	Instantiating values
	*/
	PriorityQueue()
	{
		itemCount = 0;
		backIndex =  -1;
		currentIndex = 0;
		maxSize = 1;
		dataArray = new Placeholder[maxSize*2];
	};
	/*
	Usage: Copy Constructor
	Arguments: class object to copy
	Output: class object instance
	Takes the queue and clones its contents in a new object
	*/
	PriorityQueue(PriorityQueue const& other)
	{
		maxSize = other.maxSize;
		currentIndex = other.currentIndex;
		itemCount = other.itemCount;
		backIndex = other.backIndex;
		dataArray = new Placeholder[maxSize];

		copy(other.dataArray, other.dataArray + other.maxSize*2, dataArray);
	};
	/*
	Usage: Copy Assignment Operator
	Arguments: class object to copy
	Output: ---
	Reinitialize an existing queue object and copy the content from the queue to be copied onto it
	*/
	PriorityQueue& operator=(PriorityQueue const& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (dataArray != nullptr)
		{
			delete[] dataArray;
			dataArray = nullptr;
			dataArray = 0;
		}

		maxSize = other.maxSize;
		currentIndex = other.currentIndex;
		backIndex = other.backIndex;
		itemCount = other.itemCount;
		dataArray = new int[maxSize];
		
		copy(other.dataArray, other.dataArray + other.maxSize, dataArray);

		return *this;
	};

	/*
	Usage: Destructor
	Arguments: ---
	Output: ---
	Deallocates all memory of the queue
	*/
	~PriorityQueue()
	{
		delete[] dataArray;
		dataArray = nullptr;
		dataArray = 0;
	};

	

	//Pushing values on from the back
	void Push(Placeholder data)
	{
		bool notSorted = true;
		bool sorted = false;
		
		if (backIndex == maxSize)
		{
			maxSize *= 2;
			
			Placeholder* tempArray = new Placeholder[maxSize*2];
			for (int i = 0; i < maxSize; i++)
			{
				tempArray[i] = dataArray[i];
			}
			delete[] dataArray;
			dataArray = tempArray;
			
		}
		backIndex++;
		dataArray[backIndex] = data;
		itemCount++;

		while (notSorted) {
			notSorted = false;
			for (int i = 0; i < backIndex; i++)
			{
				
				if (!(dataArray[i] < dataArray[i+1])) {
					Swap(i, i+1);
					notSorted = true;
				}
			}
		}
	};

	//Attempting to swap values based on index position
	void Swap(int a, int b) {
		Placeholder temp = dataArray[a];
		dataArray[a] = dataArray[b];
		dataArray[b] = temp;
	}

	//Popping data off from the front
	Placeholder Pop()
	{
		if (currentIndex < 0) {
			return NULL;
		}
		else
		{
			itemCount--;
			currentIndex++;
			return dataArray[currentIndex];
		}
	};

	//Printing results
	void Print()
	{
		if (itemCount == 0)
		{
			cout << "Queue is empty ";
		}
		if(itemCount>0) {
			int i;
			for (i = currentIndex; i <= backIndex; i++)
			{
				cout << "Element on Queue: " << dataArray[i] << endl;
			}
		}
	};

	//Checks if Queue is full
	bool isFull() {
		return itemCount == maxSize;
	}
	
	//Getting the size of the current stack
	int GetSize()
	{
		return itemCount;
	};

	//Checking if the Queue is empty
	bool IsEmpty()
	{
		if (itemCount==0) {
			return true;
		}
		else {
			return false;
		}
	};

private:
	Placeholder* dataArray;
	int maxSize = 1;
	int currentIndex = 0;
	int itemCount = 1;
	int backIndex = -1;
};//class


#endif // __PRIORITYQUEUE_H_
