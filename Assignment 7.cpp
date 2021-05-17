//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : The ticket booking system of Cinemax theater has to be implemented using C++ program.
//There are 10 rows and 7 seats in each row.
//Doubly circular linked list has to be maintained to keep track of free seats at rows.
//Assume some random booking to start with. Use array to store pointers (Head pointer) to each row.
//On demand
//. The list of available seats is to be displayed
//. The seats are to be booked
//. The booking can be cancelled.
//============================================================================

#include<iostream>
#include<iomanip>
using namespace std;

class node {
	bool booking = false;
	node *next, *prev;
	friend class TICKET;
};

class TICKET {
	node *(head[10]);
public:
	TICKET() {
		for (int i = 0; i < 10; i++)
			head[i] = NULL;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 7; j++) {
				node *temp = new node();

				// INITIALISING SEAT CONFIGURATION
				if (head[i] == NULL) {
					head[i] = temp;

					head[i]->next = head[i];
					head[i]->prev = head[i];


				} else {
					node *temp1 = head[i];

					while (temp1->next != head[i])
						temp1 = temp1->next;

					temp1->next = temp;
					temp->prev = temp1;
					temp->next = head[i];
					head[i]->prev = temp;
				}

			}
		}
	}
	void available();
	void book();
	void cancel();
};

void TICKET::available() {
	cout << setw(23) << "ROW/COL";
	for (int i = 0; i < 7; i++)
		cout << setw(8) << "col" << setw(2) << i;
	cout << endl;

	for (int i = 0; i < 10; i++) {
		node *temp = head[i];
		cout << setw(20) << "ROW -" << setw(3) << i;
		while (temp->next != head[i]) {
			if (temp->booking == false)
				cout << setw(10) << "A |";
			else
				cout << setw(10) << "N/A |";
			temp = temp->next;
		}

		if (temp->booking == false)
			cout << setw(10) << "A |";
		else
			cout << setw(10) << "N/A |";
		cout << endl;
	}
}

void TICKET::book() {
	int row, col;

	cout << "Enter the Row : ";
	cin >> row;
	cout << "Enter the column :";
	cin >> col;
	if (row > 9 || col > 6) {
		cout << "\nInvalid Choice." << endl << endl;
		return;
	}

	node *temp = head[row];
	for (int j = 0; j < col; j++)
		temp = temp->next;

	if (temp->booking == true)
		cout << "\nThe Ticket is already booked." << endl << endl;
	else {
		temp->booking = true;
		cout << "\nTicket booked at Seat [" << row << "][" << col << "]\n\n";
	}
}

void TICKET::cancel() {
	int row, col;

	cout << "Enter the Row : ";
	cin >> row;
	cout << "Enter the column :";
	cin >> col;
	if (row > 9 || col > 6) {
		cout << "\nInvalid Choice." << endl << endl;
		return;
	}

	node *temp = head[row];
	for (int j = 0; j < col; j++)
		temp = temp->next;

	if (temp->booking == false)
		cout << "\nThe Ticket is not booked yet." << endl << endl;
	else {
		temp->booking = false;
		cout << "\nTicket cancelled at Seat [" << row << "][" << col << "]\n\n";
	}
}

int main() {
	TICKET t;
	int choice;
	bool start = true;

	cout << "\nTicket Booking System of Cinemax Theater" ;
	cout << "\n1. The list of available seats.";
	cout << "\n2. Book seats.";
	cout << "\n3. Cancel seat booking.";
	cout << "\n0. Exit." << endl;

	while (start) {
		cout << "\nEnter choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			t.available();
			break;
		case 2:
			t.book();
			break;
		case 3:
			t.cancel();
			break;
		case 0:
			return 0;
		default:
			cout << "\nInvalid choice";
		}
	}

	return 0;
}
