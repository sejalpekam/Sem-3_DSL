//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Queues are frequently used in computer programming,
//and a typical example is the creation of a job queue by an operating system.
//If the operating system does not use priorities,
//then the jobs are processed in the order they enter the system.
//Write C++ program for simulating job queue.
//Write functions to add job and delete job from queue.
//============================================================================

#include <iostream>
using namespace std;
#define capacity 20

class Queue{
	int front, rear, size;
	int queue[capacity];

public:
	Queue(){
		front = -1;
		rear = -1;
		size = 0;
	}

	bool isFull(){
//		if(size==capacity)
//			return true;
//		else
//			return false;
		return size==capacity;

	}

	bool isEmpty() {
//		if (size == 0)
//			return true;
//		else
//			return false;
		return size==0;
	}

	void enqueue(int ele){
		if(isFull()){
			cout<<"Overflow!!!"<<endl;
		}
		else if(isEmpty()){
			front = 0;
			rear = 0;
			queue[rear] = ele;
			size++;
			cout<<"Element added."<<endl;
		}
		else{
			rear++;
			queue[rear] = ele;
			size++;
			cout<<"Element added."<<endl;
		}
	}

	void dequeue(){
		if (isEmpty()) {
			cout<<"Queue is empty!"<<endl;
		}
		else {
			front++;
			size--;
			cout<<"Element at front deleted."<<endl;
		}
	}

	void display(){
		cout<<"\nQueue is: "<<endl;
		for(int i = front; i<=rear; i++){
			cout<<" "<<queue[i];
		}
		cout<<endl;
	}
};

int main() {
//	Queue q1;
//	q1.enqueue(2);
//	q1.enqueue(3);
//	q1.enqueue(4);
//	q1.display();
//	q1.dequeue();
//	q1.display();
//	q1.dequeue();
//	q1.display();
//	Queue q2;
//	q2.enqueue(5);
//	q2.enqueue(6);
//	q2.enqueue(7);
//	q2.display();

	Queue q;
	int choice;
	bool start = true;

	cout<<"MENU"
		  "\n1.Add element to Queue."
		  "\n2.Delete element from Queue."
		  "\n3.Display Queue."
		  "\n0.Exit."<<endl;

	while(start){
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice){
		case 1:
			int element;
			int n;
			cout<<"Enter number of elements to be added: ";
			cin>>n;
			for (int i = 0; i < n; i++) {
				cout << "\nEnter element "<<i+1<<": ";
				cin >> element;
				q.enqueue(element);
			}
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.display();
			break;
		case 0:
			start = false;
			break;
		default:
			cout<<"\nEnter valid choice.";
			break;
		}
	}

	return 0;
}
