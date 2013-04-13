#include <iostream>
#include <string>
#include "Theater.h"
using namespace std;

// Constructor
Theater::Theater(string movieName, int theaterId, int numRows, int numSeatsPerRow)
{
	name = movieName;
	id = theaterId;
	row = numRows;
	column = numSeatsPerRow;
	
	seats = new int *[row];
	for(int i=0; i<row; i++)
	{
		seats[i] = new int[column];
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			seats[i][j] = 0;
	}
}

// Destructor
Theater::~Theater()
{
	for(int i=0; i<row; i++)
	{
		if(seats[i] != NULL)
		{
			delete [] seats[i];
		}
	}
	delete [] seats;
}

int Theater::getId()
{
	return id;
}

string Theater::getName()
{
	return name;
}

// Show detailed information about a particular movie theater
void Theater::print()
{
	int number = 1;
	char letter = 'A';
	cout << "  ";
	for(int i=0; i<column; i++)
	{
		cout << number << " ";
		number++;
	}
	cout << endl;
	for(int i=0; i<row; i++)
	{
		cout << letter << " ";
		letter++;
		for(int j=0; j<column; j++)
		{
			if(seats[i][j])
				cout << "x" << " ";
			else
				cout << "o" << " ";
		}
		cout << endl;
	}
}

// Calculate available seats number
int Theater::availableSeats()
{
	int NumberOfAvailableSeats = 0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			if(!seats[i][j])
				NumberOfAvailableSeats++;
		}
	}
	return NumberOfAvailableSeats;
}

// check whether or not the given seat is available
bool Theater::requestedSeats(int row1, int column1)
{
	if(seats[row1][column1])
		return true;
	else
		return false;
}

// put reservation code in given seat
void Theater::reservation(int row1, int column1, int reservationCode)
{
	seats[row1][column1] = reservationCode;
}

// check whether or not the given reservation code exists
bool Theater::controlReservationCode(int reservationCode)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			if(seats[i][j] == reservationCode)
				return true;
		}
	}
	return false;
}

// cancel given reservation code
void Theater::canReservation(int reservationCode)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			if(seats[i][j] == reservationCode)
				seats[i][j] = 0;
		}
	}
}

// print seats number that keep reservation code
void Theater::seatsNumber(int reservationCode)
{
	char c='A';
	char letter;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			if(seats[i][j] == reservationCode)
			{
				letter = c+i;
				cout << letter << j+1 << " ";
			}
		}
	}
}
