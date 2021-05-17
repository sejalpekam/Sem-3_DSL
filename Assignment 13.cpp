//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : A double-ended queue (deque) is a linear list in which
//additions and deletions may be made at either end.
//Obtain a data representation mapping a deque into a onedimensional array.
//Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.
//============================================================================

#include<iostream>
using namespace std;
#define size 10

//class Deque
//{
//	int deque[size],front,rear,count;
//
//public:
//	Deque(){
//		front=-1;
//		rear=-1;
//		count=0;
//	}
//
//	int isFull(){
//		if (rear == size-1)
//		      return 1;
//		else
//		      return 0;
//
//	}
//
//	int isEmpty(){
//		if((front == -1 && rear == -1) || front == rear)
//		      return 1;
//		else
//		      return 0;
//
//	}
//
//	void add_at_rear(int item){
//
//		if(isFull()){
//			cout<<"\nInsertion is not possible,overflow!!!"<<endl;
//		}
//
//		else{
//			rear++;
//			deque[rear] = item;
//			count++;
//		}
//	}
//
//	void add_at_front(int item){
//		if(isFull())
//			{
//				cout<<"\nInsertion is not possible,overflow!!!"<<endl;
//			}
//		else
//			{
//			  deque[front] = item;
//			  front--;
//			  count++;
//			}
//	}
//
//	void delete_fr_front(){
//		if(isEmpty())
//			{
//				cout<<"Deletion is not possible: Deque is empty";
//				return;
//			}
//
//		else{
//			   int x;
//			   front++;
//			   x = deque[front];
//			   cout<<"The deleted element is: "<<x<<endl;
//			   count--;
//			}
//
//	}
//
//	void delete_fr_rear(){
//		if(isEmpty())
//			{
//				cout<<"Deletion is not possible: Deque is empty";
//				return;
//			}
//
//		else {
//			   int x;
//
//			   x = deque[rear];
//			   rear--;
//			   cout<<"The deleted element is: "<<x<<endl;
//			   count--;
//
//			}
//	}
//
//	void display(){
//		cout<<"\nFront--->";
//		   for(int i = front+1;i <= rear;i++)
//		      cout<<"  "<<deque[i];
//
//		   cout<<"  <---Rear"<<endl;
//	}
//};

class Deque
{
	int deque[size],front,rear,count;

public:
	Deque(){
		front=-1;
		rear=-1;
		count=0;
	}

	int isFull(){
		if (count == size-1)
		      return 1;
		else
		      return 0;

	}

	int isEmpty(){
		if(count == 0)
		      return 1;
		else
		      return 0;

	}

	int getFront(){
		if(!isEmpty())
			return deque[front];
		return -1;
	}

	int getRear(){
		if(!isEmpty())
			return deque[rear];
		return -1;
	}

	void add_at_rear(int item){

		if(isFull()){
			cout<<"\nInsertion is not possible,overflow!!!"<<endl;
		}
		else if(isEmpty()){
			rear++;
			front++;
			deque[rear] = item;
			count++;
		}

		else{
			rear++;
			deque[rear] = item;
			count++;
		}
	}

	void add_at_front(int item){
		if(isFull()){
			cout<<"\nInsertion is not possible,overflow!!!"<<endl;
		}
		else if(isEmpty()){
			rear++;
			front++;
			deque[rear] = item;
			count++;
		}
		else{
			  front--;
			  deque[front] = item;
			  count++;
			}
	}

	void delete_fr_front(){
		if(isEmpty())
			{
				cout<<"Deletion is not possible: Deque is empty";
				return;
			}

		else{
			   int x;
			   x = deque[front];
			   front++;
			   cout<<"The deleted element is: "<<x<<endl;
			   count--;
			}

	}

	void delete_fr_rear(){
		if(isEmpty())
			{
				cout<<"Deletion is not possible: Deque is empty";
				return;
			}

		else {
			   int x;

			   x = deque[rear];
			   rear--;
			   cout<<"The deleted element is: "<<x<<endl;
			   count--;

			}
	}

	void display(){
		cout<<"\nFront--->";
		   for(int i = front;i <= rear;i++)
		      cout<<"  "<<deque[i];

		   cout<<"  <---Rear"<<endl;
	}
};

int main()
{
	int choice,item;
	bool start = true;
	Deque d1;
	cout<<"MENU\n"
		  "\n1.Insert at rear."
		  "\n2.Insert at front."
		  "\n3.Display."
		  "\n4.Deletion from front."
		  "\n5.Deletion from rear."
		  "\n6.Get Front data."
		  "\n7.Get Rear data."
	      "\n0.Exit."<<endl;

	while(start){

		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"Enter the element to be inserted: ";
			cin>>item;
			d1.add_at_rear(item);
			break;

		case 2:
			cout<<"Enter the element to be inserted: ";
			cin>>item;
			d1.add_at_front(item);
			break;

		case 3:
			d1.display();
			break;

		case 4:
			d1.delete_fr_front();
			break;
		case 5:
			d1.delete_fr_rear();
			break;

		case 6:
			cout<<"Front element is: "<<d1.getFront()<<endl;
			break;

		case 7:
			cout<<"Rear element is: "<<d1.getRear()<<endl;
			break;

		case 0:
			start = false;
			exit(1);
			break;

		default:
			cout<<"Enter valid choice.";
			break;
		}

	}
	return 0;

}



