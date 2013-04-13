#include <string>
using namespace std;
class Discography {
public:
	Discography();
	~Discography();
	void addAlbum( const string albumTitle, const string singerName, const int releaseDay,
	const int releaseMonth, const int releaseYear );
	void removeAlbum( const string albumTitle );
	void addSong( const string albumTitle, const string songName, const int songLength );
	void removeSong( const string albumTitle, const string songName );
	void showAllAlbums();
	void showAlbum( const string albumTitle );
	void showShorterLength( const int length );
	void showSingerAlbums( const string singerName );
	void showAlbums( const int releaseYear );
	void showAlbums( const int startYear, const int endYear );
};
