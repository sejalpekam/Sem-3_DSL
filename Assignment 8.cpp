//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program for storing appointment schedule for day. Appointments are booked
//randomly using linked list. Set start and end time and min and max duration for visit slot.
//Write functions for-
//a)Display free slots
//b)Book appointment
//c)Cancel appointment ( check validity, time bounds, availability etc)
//d)Sort list based on time
//e)Sort list based on time using pointer manipulation.
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class appoint {
	int status;
	char start[10];
	char end[10];
	char max[10];
	char min[10];

	appoint *Next;

	friend class appointment;
} *head;

class appointment {
	int nodes;
public:

	void create_app() {
		int i;
		appoint *temp, *p;

		head = NULL;

		cout << "\nEnter number of Appointment slots: ";
		cin >> nodes;

		for (i = 0; i < nodes; i++) {
			cout << "\nAPPOINTMENT " << i + 1 << endl;
			temp = new (struct appoint);  //Step 1: Allocate Memory
			temp->status = 0;

			cout << "\nEnter Start Time: "; //Step 2: Store data and address
			cin >> temp->start;
			cout << "\nEnter End Time: "; //Step 2: Store data and address
			cin >> temp->end;
			cout << "\nEnter min Time: "; //Step 2: Store data and address
			cin >> temp->min;
			cout << "\nEnter max Time: "; //Step 2: Store data and address
			cin >> temp->max;

			temp->Next = NULL;

			if (head == NULL)   //Step 3: Attach node in linked List
			{
				head = temp;
				p = head;
			} else {
				p->Next = temp;
				p = p->Next;
			}

		}

	}

	void display_SLL() {
		appoint *p;

		p = head;
		cout<<"\n";
		cout << "Status\tStart Time\tEnd Time\tMin Time\tMax Time\n";
		while (p != NULL) {
			if (p->status == 0) {
				cout << "Free";
			} else {
				cout << "Booked";
			}
			cout << "\t\t" << p->start << "\t\t" << p->end << "\t\t" << p->min
					<< "\t\t" << p->max << "\t\n";
			p = p->Next;
		}

	}
	void book_app() {
		char time[10];
		struct appoint *p;
		cout << "\nEnter The Time Slot: ";
		cin >> time;
		p = head;
		while (p != NULL) {
			if (strcmp(time, p->start) == 0) {
				if (p->status == 0) {
					p->status = 1;
					cout << "\nYour Appointment Is Booked." << endl;
				} else
					cout << "\nAppointment slot is Busy." << endl;
				break;
			} else
				p = p->Next;
		}

		if (p == NULL)
			cout << "\nAppointment slot is Not available." << endl;
		display_SLL();

	}

	void cancel_app() {
		char time[10];
		struct appoint *p;
		cout << "\nEnter Cancellation Time: ";
		cin >> time;
		p = head;
		while (p != NULL) {
			if (strcmp(time, p->start) == 0) {
				if (p->status == 1) {
					p->status = 0;
					cout << "\nYour Appointment Is Cancelled." << endl;
				} else
					cout << "\nAppointment slot is not Booked." << endl;
				break;
			} else
				p = p->Next;
		}

		if (p == NULL)
			cout << "\nAppointment slot is Not available." << endl;
		display_SLL();

	}

	void sort_app() {
		char str[10];
		appoint *p;
		int i;
		for (i = 0; i < nodes - 1; i++) {
			p = head;
			while (p->Next != NULL) {
				if (strcmp(p->start, p->Next->start) > 0) {
					int tmp = p->status;
					p->status = p->Next->status;
					p->Next->status = tmp;

					strcpy(str, p->start);
					strcpy(p->start, p->Next->start);
					strcpy(p->Next->start, str);

					strcpy(str, p->end);
					strcpy(p->end, p->Next->end);
					strcpy(p->Next->end, str);

					strcpy(str, p->min);
					strcpy(p->min, p->Next->min);
					strcpy(p->Next->min, str);

					strcpy(str, p->max);
					strcpy(p->max, p->Next->max);
					strcpy(p->Next->max, str);

				}
				p = p->Next;
			}
		}
		cout << "\nSORTED." << endl;
		display_SLL();
	}


//	void sort_list() {
//	    appoint *top = nullptr; // first Node we will return this value
//	    appoint *current = nullptr;
//	    bool sorted = false;
//	    while (sorted == false) {
//	        // we are going to look for the lowest value in the list
//	    	appoint *parent = head;
//	    	appoint *lowparent = head; // we need this because list is only linked forward
//	    	appoint *low = head; // this will end up with the lowest Node
//	        sorted = true;
//	        do {
//	            // find the lowest valued key
//	        	appoint* next = parent->Next;
//	            if (strcmp(parent->start, next->start) > 0) {
//	                lowparent = parent;
//	                low = next;
//	                sorted = false;
//	                }
//	            parent = parent->Next;
//	            } while (parent->Next != nullptr);
//	        if (current != nullptr) { // first time current == nullptr
//	            current->Next = low;
//	            }
//	        // remove the lowest item from the list and reconnect the list
//	        // basically you are forming two lists, one with the sorted Nodes
//	        // and one with the remaining unsorted Nodes
//	        current = low;
//	        if (current == head) { head = current->Next; }
//	        lowparent->Next = low->Next;
//	        current->Next = nullptr;
//	        if (top == nullptr) {
//	            top = current;
//	            }
//	        };
//	    current->Next = head;
//	    head = top;
//	    cout << "\nSORTED." << endl;
//	    display_SLL();
//	}

};

int main() {
	bool start = true;
	int choice;
	appointment a1;

	cout << "MENU"
			"\n1.Create Appointment slots."
			"\n2.Display Appointment slots."
			"\n3.Book an Appointment."
			"\n4.Cancel an Appointment."
			"\n5.Sort Appointment slots"
			"\n0.Exit." << endl;

	while (start) {
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			a1.create_app();
			break;
		case 2:
			a1.display_SLL();
			break;
		case 3:
			a1.book_app();
			break;
		case 4:
			a1.cancel_app();
			break;
		case 5:
			a1.sort_app();
			//a1.sort_list();
			break;
		case 0:
			start = false;
			break;

		default:
			cout << "\nEnter valid choice." << endl;
			break;

		}
	}

	return 0;
}
