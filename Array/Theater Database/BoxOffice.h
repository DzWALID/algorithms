#include "Theater.h"
using namespace std;
class BoxOffice {
	public:
		BoxOffice();
		~BoxOffice();
		void addTheater( int theaterId, string movieName, int numRows, int numSeatsPerRow );
		void removeTheater( int theaterId );
		void showAllTheaters();
		void showTheater( int theaterId );
		int makeReservation( int theaterId, int numAudiences, char *seatRow, int *seatCol );
		void cancelReservation( int resCode );
		void showReservation( int resCode );
	private:
		Theater **theaters;
		int count;
};
