#include <string>
using namespace std;
class MovieDatabase {
	public:
	MovieDatabase();
	~MovieDatabase();
	void addMovie( const string movieTitle, const string directorFirstName, const string directorLastName,
	const int releaseDay, const int releaseMonth, const int releaseYear );
	void removeMovie( const string movieTitle );
	void addActor( const string movieTitle, const string actorFirstName, const string actorLastName,
	const string actorRole );
	void removeActor( const string movieTitle, const string actorFirstName, const string actorLastName );
	void showAllMovies();
	void showMovie( const string movieTitle );
	void showActorRoles( const string actorFirstName, const string actorLastName );
	void showMovies( const int releaseYear );
	
	struct actor
	{
		string actorFirstName, actorLastName, actorRole;
		actor *next;
	};
	
	struct movie
	{
		string movieTitle, directorFirstName, directorLastName;
		int releaseDay,releaseMonth,releaseYear;
		movie *next;
		movie *prev;
		actor *head;
	}*head;
};
