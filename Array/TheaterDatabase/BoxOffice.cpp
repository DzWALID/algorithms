#include <iostream>
#include "Theater.h"
#include <string>
#include "BoxOffice.h"
using namespace std;

// Constructor
BoxOffice::BoxOffice()
{
	count = 0;
}

// Destructor
BoxOffice::~BoxOffice()
{
	for(int i=0; i<count; i++)
	{
		if(theaters[i] != NULL)
		{
			delete theaters[i];
		}
	}
	delete [] theaters;
}

void BoxOffice::addTheater( int theaterId, string movieName, int numRows, int numSeatsPerRow )
{
	// check whether or not the specified id already exists
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId)
		{
			cout << "Theater " << theaterId << " (" << theaters[i]->getName()  << ") already exists" << endl;
			return;
		}
	}
	
	Theater **tmp = new Theater*[count+1];
	
	for(int i=0; i<count; i++)
	{
		tmp[i] = theaters[i];
	}
	
	Theater *T = new Theater(movieName, theaterId, numRows, numSeatsPerRow);
	tmp[count] = T;
	if(count)
	{
		delete [] theaters;
	}
	count++;
	theaters = tmp;
	cout << "Theater " << theaterId << " (" << movieName << ") has been added" << endl;
}

void BoxOffice::removeTheater( int theaterId )
{
	int control = -1;
	int index = 0;
	// check whether or not the specified id exists
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId)
		{
			control = i;
		}
	}
	if(control==-1)
		cout << "Theater " << theaterId << " does not exist" << endl;
	else
	{
		Theater **tmp = new Theater*[count-1];
		for(int i=0; i<count; i++)
		{
			if(theaters[i]->getId() != theaterId)
			{
				tmp[index] = theaters[i];
				index++;
			}
		}
		count--;
		cout << "Theater " << theaters[control]->getId() << " (" << theaters[control]->getName() << ") and all of its reservations are canceled" << endl;
		delete theaters[control];
		delete [] theaters;
		theaters = tmp;
	}	
}

void BoxOffice::showAllTheaters()
{
	if(count)
	{
		cout << "Theaters currently in the system:" << endl;
		for(int i=0; i<count; i++)
		{
			cout << "Theater " << theaters[i]->getId() << " (" << theaters[i]->getName() << "): " << theaters[i]->availableSeats() << " available seats" << endl;
		}
	}
	else
	{
		cout << "No movie theaters in the system!" << endl;
	}
}

void BoxOffice::showTheater( int theaterId )
{
	int control = -1;
	char letter = 'A';
	
	// check whether or not the specified id exists
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId)
		{
			control = i;
		}
	}
	if(control==-1)
		cout << "Theater " << theaterId << " does not exist" << endl;
	else
	{
		for(int i=0; i<count; i++)
		{
			if(theaters[i]->getId() == theaterId)
			{
				cout << "Theater " << theaters[i]->getId() << " (" << theaters[i]->getName() << ")" << " has " << theaters[i]->availableSeats() << " available seats" << endl;
			}
		}
		
		for(int i=0; i<count; i++)
		{
			if(theaters[i]->getId() == theaterId)
			{
				theaters[i]->print();
			}
		}
	}
}

int BoxOffice::makeReservation( int theaterId, int numAudiences, char *seatRow, int *seatCol )
{
	int control = -1;
	int code=0;
	char c;
	static int number = 1;
	
	// check whether or not the specified id exists
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId)
		{
			control = i;
		}
	}
	if(control==-1)
	{
		cout << "Theater " << theaterId << " does not exist" << endl;
		return -1;
	}
	
	// check whether or not there are enough available seats in the theater
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId && numAudiences > theaters[i]->availableSeats())
		{
			cout << "Theater " << theaters[i]->getId() << " (" << theaters[i]->getName() << ")" << " does not have enough space for " << numAudiences << " audiences" << endl;
			return -1;
		}
	}
	
	// check whether or not the requested seats are available
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId)
		{
			for(int j=0; j<numAudiences; j++)
			{
				c = seatRow[j];
				if(theaters[i]->requestedSeats(c-'A',seatCol[j]-1))
				{
					cout << "Seat " << seatRow[j] << seatCol[j] << " has already been taken" << endl;
					return -1;
				}
			}
		}
	}
	// make the reservation by creating a unique reservation code
	code = number;
	number++;
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->getId() == theaterId)
		{
			for(int j=0; j<numAudiences; j++)
			{
				c = seatRow[j];
				theaters[i]->reservation(c-'A',seatCol[j]-1,code);
			}
		}
	}
	return code;
}

void BoxOffice::cancelReservation( int resCode )
{
	int control = -1;
	// check whether or not the given reservation code exists
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->controlReservationCode(resCode))
			control = i;
	}
	
	if(control==-1)
	{
		cout << "No reservations are found under code " << resCode << endl;
	}
	else
	{
		cout << "Reservation for seats ";
		theaters[control]->seatsNumber(resCode);
		cout << "is cancelled in Theater " << theaters[control]->getId() << " (" << theaters[control]->getName() << ")" << endl;
		theaters[control]->canReservation(resCode);
	}
}

void BoxOffice::showReservation( int resCode )
{
	int control = -1;
	// check whether or not the given reservation code exists
	for(int i=0; i<count; i++)
	{
		if(theaters[i]->controlReservationCode(resCode))
			control = i;
	}
	
	if(control==-1)
	{
		cout << "No reservations are found under code " << resCode << endl;
	}
	else
	{
		cout << "Reservations under code " << resCode << " in Theater " << theaters[control]->getId() << " (" << theaters[control]->getName() << "): ";
		theaters[control]->seatsNumber(resCode);
		cout << endl;
	}
}
