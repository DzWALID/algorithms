#ifndef THEATER_H
#define THEATER_H
using namespace std;
class Theater
{
	public:
		Theater(string movieName, int theaterId, int numRows, int numSeatsPerRow);
		~Theater();
		int getId();
		string getName();
		void print();
		int availableSeats();
		bool requestedSeats(int row1, int column1);
		void reservation(int row1, int column1, int reservationCode);
		bool controlReservationCode(int reservationCode);
		void canReservation(int reservationCode);
		void seatsNumber(int reservationCode);
	private:
		int id, row, column;
		int **seats;
		string name;
};
#endif
