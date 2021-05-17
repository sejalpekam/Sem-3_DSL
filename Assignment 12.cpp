//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Write program to implement a priority queue in C++ using an
//inorder list to store the items in the queue.
//Create a class that includes the data items (which should be template) and the priority (which should be int).
//The inorder list should contain these objects, with operator <= overloaded
//so that the items with highest priority appear at the beginning of the list
//(which will make it relatively easy to retrieve the highest item.)
//============================================================================

#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#define capacity 10
using namespace std;

template <typename T>
class Queue
{
	int front;
	int rear;
	int size;
	T queue[capacity];

public:
	Queue()
	{
		front = -1;
		rear = -1;
		size = 0;
	}

	bool isFull(){
		return (rear==capacity);
	}

	bool isEmpty(){
		return (size == 0);
	}

	void add(T newItem){
		if(isFull()){
			cout<<"Overflow!!"<<endl;
		}
		else if (isEmpty()) {
			front = 0;
			rear = 0;
			queue[rear] = newItem;
			size++;
			cout << "Job added." << endl;
		}
		else {
			rear++;
			queue[rear] = newItem;
			size++;
			cout << "Job added." << endl;
		}
	}

	void del(){
		 try {
			 if(isEmpty()){
				 throw -1;
			 }
			 else{
			 cout<<"Job deleted"<<endl;
			 front++;
			 //queue[++front];
		     size--;
			 }
		    }
		 catch(int x){
			 if(x==-1)
				 cout<<"No pending jobs"<<endl;
		 }
	}


	void display(){
		 if(isEmpty()) {
			 cout<<"No pending jobs"<<endl;
		 }
		 cout<<queue[front]<<endl;
	}

	void displayQueue(){
			cout<<"\nQueue is: "<<endl;
			for(int i = front; i<=rear; i++){
				cout<<" "<<queue[i];
			}
			cout<<endl;
		}

	T* getJob(){
		return queue;
	}

};

template<typename T>
class JobElement {
public:
	T item;
	int priority;
	JobElement() {
		item=0;
		priority=0;
	}

    JobElement(T data,int p)
    {
    	item=data;
    	priority=p;
    }

    bool operator <= (const JobElement &obj) {
    	if(this->priority<=obj.priority)

    		return true;
    	else
    		return false;
    }

    friend ostream &operator<<(ostream &o, JobElement &obj){
    	o<<obj.item<<" is the job with priority:"<<obj.priority<<endl;
    	return o;
    }

};

int main() {
	Queue<JobElement<int>> queue;
	    int choice;
	    int jobCounter=1;
	    bool start = true;

	    cout<<"MENU"
	    	  "\nNOTE: 1 is taken as the highest priority."
	    	  "\n1.Add a job."
	    	  "\n2.Delete a job."
	    	  "\n3.Display the first priority job."
	    	  "\n4.Display Queue."
	    	  "\n0.Exit."<<endl;

	    while(start){
	    	cout<<"\nEnter choice: ";
	    	cin>>choice;
	    	cout<<endl;

	    	switch(choice) {
	    	case 1:
	        {
	        int job,priority;

	        cout<<"Enter the job data: ";
	        cin>>job;
	        cout<<endl;
	        cout<<"Enter the job priority: ";
	        cin>>priority;
	        cout<<endl;

	        JobElement<int> newJob(job,priority);

	        if(jobCounter==0)
	        	queue.add(newJob);
	        else {

	        	queue.add(newJob);

	        	JobElement<int> *prevJob = queue.getJob();

	            int temp;

	            for(int i=0;i<jobCounter;i++){

	            	for(int j=i+1;j<jobCounter;j++) {
	            		if((prevJob+j)->priority <=(prevJob+i)->priority) {

	            			temp=(prevJob+i)->item;
	                        (prevJob+i)->item=(prevJob+j)->item;
	                        (prevJob+j)->item = temp;
	                        temp=(prevJob+i)->priority;
	                        (prevJob+i)->priority=(prevJob+j)->priority;
	                        (prevJob+j)->priority = temp;
	                    }
	                }
	            }
	        }
	        jobCounter++;
	        break;
	        }

	        case 2:
	        	queue.del();
	        	jobCounter--;
	        	break;

	        case 3:
	        	queue.display();
	        	break;

	        case 4:
	        	queue.displayQueue();
	        	break;

	        case 0:
	        	start = false;
	        	break;

	        default:
	        	cout<<"Enter valid choice."<<endl;
	        	break;

	    }
	}

	return 0;
}
