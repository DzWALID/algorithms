#include "Discography.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct song
{
	string songName;
	string albumTitle;
	int songLength;
	song *leftSong;
	song *rightSong;
};
	
struct album
{
	album *leftAlbum;
	album *rightAlbum;
	string albumTitle;
	int releaseDay, releaseMonth, releaseYear;
	string singerName;
	song *songRoot;
}*albumRoot;

// Constructor
Discography::Discography(){
	albumRoot = NULL;
}

// deleting all song
void deleteSongTree(song *root)
{
	if(root != NULL)
	{
		deleteSongTree(root->leftSong);
		deleteSongTree(root->rightSong);
		delete root;
		root = NULL;
	}
}

// deleting all album
void deleteAlbumTree(album *root)
{
	if(root != NULL)
	{
		deleteAlbumTree(root->leftAlbum);
		deleteAlbumTree(root->rightAlbum);
		deleteSongTree(root->songRoot);
		delete root;
		root = NULL;
	}
}

// destructor
Discography::~Discography()
{
	deleteAlbumTree(albumRoot);
}

int shorterSongNumber;
vector<song> songList;
vector<album> albumList;

// add album
void addAlbumRecursive(album *&root, album *newAlbum)
{
	// add new album
	if(root == NULL)
	{
		root = newAlbum;
		cout << "INFO: Album " << newAlbum->albumTitle << " has been added" << endl;
		return;
	}
	// if album exists
	else if(root->albumTitle == newAlbum->albumTitle)
	{
		cout << "ERROR: Album " << root->albumTitle << " already exists" << endl;
		delete newAlbum;
		return;
	}
	// find accurate place for new album
	if((root->releaseYear <= newAlbum->releaseYear))
		addAlbumRecursive(root->rightAlbum,newAlbum);
	else
	{
		addAlbumRecursive(root->leftAlbum,newAlbum);
	}
}

void Discography::addAlbum(const string albumTitle, const string singerName, const int releaseDay, const int releaseMonth, const int releaseYear)
{
	// create new album
	album *newAlbum = new album;
	newAlbum->albumTitle = albumTitle;
	newAlbum->releaseDay = releaseDay;
	newAlbum->releaseMonth = releaseMonth;
	newAlbum->releaseYear = releaseYear;
	newAlbum->singerName = singerName;;
	newAlbum->songRoot = NULL;
	newAlbum->rightAlbum = NULL;
	newAlbum->leftAlbum = NULL;
	
	addAlbumRecursive(albumRoot,newAlbum);
}

// remove album
void removeSongFromDeletedAlbum(song *root)
{
	if(root == NULL)
	{
		return;
	}
	removeSongFromDeletedAlbum(root->leftSong);
	removeSongFromDeletedAlbum(root->rightSong);
	delete root;
	root = NULL;
}

void albumWithTwoChildren(album *&root, album *&right)
{
	if(right->leftAlbum == NULL)
	{
		album *tmpAlbum = right;
		root->albumTitle = right->albumTitle;
		root->releaseDay = right->releaseDay;
		root->releaseMonth = right->releaseMonth;
		root->releaseYear = right->releaseYear;
		root->singerName = right->singerName;
		root->songRoot = right->songRoot;
		right = right->rightAlbum;
		tmpAlbum->rightAlbum = NULL;
		delete tmpAlbum;
		return;
	}
	if(root->leftAlbum != NULL)
		albumWithTwoChildren(root,right->leftAlbum);
}

void removeAlbumRecursive(album *&root, const string albumTitle)
{
	// if album does not have children
	if(root->leftAlbum == NULL && root->rightAlbum == NULL)
	{
		delete root;
		root = NULL;
	}
	// if album have one child
	else if(root->leftAlbum == NULL && root->rightAlbum != NULL)
	{
		album *tmp = root;
		root = root->rightAlbum;
		tmp->rightAlbum = NULL;
		delete tmp;
	}
	else if(root->leftAlbum != NULL && root->rightAlbum == NULL)
	{
		album *tmp = root;
		root = root->leftAlbum;
		tmp->leftAlbum = NULL;
		delete tmp;
	}
	// if album have two children
	else
	{
		albumWithTwoChildren(root,root->rightAlbum);
	}
	cout << "INFO: Album " << albumTitle << " has been removed" << endl;
	return;
}

bool findGivenAlbumTitleToRemoveAlbum(album *&root, const string albumTitle)
{
	if(root == NULL)
		return false;
	if(root->albumTitle == albumTitle)
	{
		removeSongFromDeletedAlbum(root->songRoot);
		removeAlbumRecursive(root,albumTitle);
		return true;
	}
	return findGivenAlbumTitleToRemoveAlbum(root->leftAlbum,albumTitle)||findGivenAlbumTitleToRemoveAlbum(root->rightAlbum,albumTitle);
}

void Discography::removeAlbum(const string albumTitle)
{
	if(!findGivenAlbumTitleToRemoveAlbum(albumRoot,albumTitle))
		cout << "ERROR: Album " << albumTitle << " does not exist" << endl;
}

// add song
void addSongRecursive(song *&rootsong, song *newSong, const string albumTitle)
{
	// add new song
	if(rootsong == NULL)
	{
		rootsong = newSong;
		cout << "INFO: " << rootsong->songName << " has been added to the album " << albumTitle << endl;
		return;
	}
	// if song exists
	else if(rootsong->songName == newSong->songName)
	{
		cout << "ERROR: " << rootsong->songName << " already exist." << endl;
		delete newSong;
		return;
	}
	// find accurate place for new song
	if((rootsong->songName > newSong->songName))
		addSongRecursive(rootsong->leftSong,newSong,albumTitle);
	else
		addSongRecursive(rootsong->rightSong,newSong,albumTitle);
}

bool findGivenAlbumTitleToAddSong(album *root, const string albumTitle, const string songName, const int songLength )
{
	if(root == NULL)
		return false;
	if(root->albumTitle == albumTitle)
	{
		song *newSong = new song;
		newSong->songName = songName;
		newSong->songLength = songLength;
		newSong->albumTitle = albumTitle;
		newSong->rightSong = NULL;
		newSong->leftSong = NULL;
		addSongRecursive(root->songRoot,newSong,albumTitle);
		return true;
	}
	return findGivenAlbumTitleToAddSong(root->leftAlbum,albumTitle,songName,songLength)||findGivenAlbumTitleToAddSong(root->rightAlbum,albumTitle,songName,songLength);
}

void Discography::addSong(const string albumTitle, const string songName, const int songLength)
{
	if(!findGivenAlbumTitleToAddSong(albumRoot,albumTitle,songName,songLength))
		cout << "ERROR: Album " << albumTitle << " does not exist" << endl;
}

// remove song
void songWithTwoChildren(song *&root, song *&right)
{
	if(right->leftSong == NULL)
	{
		song *tmpSong = right;
		root->songName = right->songName;
		root->songLength = right->songLength;
		root->albumTitle = right->albumTitle;
		right = right->rightSong;
		tmpSong->rightSong = NULL;
		delete tmpSong;
		return;
	}
	if(root->leftSong != NULL)
		songWithTwoChildren(root,right->leftSong);
}

void removeSongRecursive(song *&root, const string songName, const string albumTitle)
{
	// if song does not exist
	if(root == NULL)
	{
		cout << "ERROR: " << songName << " does not exist in the " << albumTitle << endl;
		return;
	}
	// deletion
	if(songName == root->songName)
	{
		// if song does not have children
		if(root->leftSong == NULL && root->rightSong == NULL)
		{
			delete root;
			root = NULL;
		}
		// if song have one child
		else if(root->leftSong == NULL && root->rightSong != NULL)
		{
			song *tmp = root;
			root = root->rightSong;
			tmp->rightSong = NULL;
			delete tmp;
		}
		else if(root->leftSong != NULL && root->rightSong == NULL)
		{
			song *tmp = root;
			root = root->leftSong;
			tmp->leftSong = NULL;
			delete tmp;
		}
		// if song have two children
		else
		{
			songWithTwoChildren(root,root->rightSong);
		}
		cout << "INFO: " << songName << " has been removed from the album " << albumTitle << endl;
		return;
	}
	// find song that will be removed
	if((root->songName > songName))
		removeSongRecursive(root->leftSong,songName,albumTitle);
	else
		removeSongRecursive(root->rightSong,songName,albumTitle);
}

bool findGivenAlbumTitleToRemoveSong(album *&root, const string albumTitle, const string songName)
{
	if(root == NULL)
		return false;
	if(root->albumTitle == albumTitle)
	{
		removeSongRecursive(root->songRoot,songName,albumTitle);
		return true;
	}
	return findGivenAlbumTitleToRemoveSong(root->leftAlbum,albumTitle,songName)||findGivenAlbumTitleToRemoveSong(root->rightAlbum,albumTitle,songName);
}

void Discography::removeSong( const string albumTitle, const string songName )
{
	if(!findGivenAlbumTitleToRemoveSong(albumRoot,albumTitle,songName))
		cout << "ERROR : Album " << albumTitle << " does not exist" << endl;
}

// show all albums
void showAllAlbumsRecursive(album *root)
{
	if(root == NULL)
		return;
	else
	{
		showAllAlbumsRecursive(root->leftAlbum);
		cout << root->albumTitle << ", " << root->releaseYear << ", " << root->singerName << endl;
		showAllAlbumsRecursive(root->rightAlbum);
	}
}

void Discography::showAllAlbums()
{
	if(albumRoot == NULL)
	{
		cout << "---none---" << endl;
	}
	else
	{
		showAllAlbumsRecursive(albumRoot);
	}
}

// show given album
void showAlbumRecursive(song *root)
{
	if(root == NULL)
		return;
	showAlbumRecursive(root->leftSong);
	cout << root->songName << ", " << root->songLength << endl;
	showAlbumRecursive(root->rightSong);
}

bool findGivenAlbumTitleToShowAlbum(album *root, const string albumTitle)
{
	if(root == NULL)
		return false;
	if(root->albumTitle == albumTitle)
	{
		cout << root->albumTitle << endl;
		cout << root->releaseDay << "/" << root->releaseMonth << "/" << root->releaseYear << endl;
		cout << root->singerName << endl;
		if(root->songRoot == NULL)
			cout << "---none---" << endl;
		else
			showAlbumRecursive(root->songRoot);
		return true;
	}
	return findGivenAlbumTitleToShowAlbum(root->leftAlbum,albumTitle)||findGivenAlbumTitleToShowAlbum(root->rightAlbum,albumTitle);
}

void Discography::showAlbum(const string albumTitle)
{
	if(!findGivenAlbumTitleToShowAlbum(albumRoot,albumTitle))
	{
		cout << albumTitle << endl;
		cout << "---none---" << endl;
	}
}

// show albums whose length is shorter than given value
void showSongRecursive(song *root, const string albumTitle, const int length)
{
	if(root == NULL)
		return;
	showSongRecursive(root->leftSong,albumTitle,length);
	// if length of song < given length, keep it in vector
	if(root->songLength < length)
	{
		shorterSongNumber++;
		songList.push_back(*root);
	}
	showSongRecursive(root->rightSong,albumTitle,length);
}

void traverseAlbumsForShortSong(album *root, const int length)
{
	if(root == NULL)
		return;
	if(root->leftAlbum != NULL)
		traverseAlbumsForShortSong(root->leftAlbum,length);
	showSongRecursive(root->songRoot,root->albumTitle,length);
	if(root->rightAlbum != NULL)
		traverseAlbumsForShortSong(root->rightAlbum,length);
}

bool compareSongs(song a, song b)
{
    return a.songName < b.songName;
}

void Discography::showShorterLength(const int length)
{
	shorterSongNumber = 0;
	cout << length << endl;
	traverseAlbumsForShortSong(albumRoot,length);
	if(shorterSongNumber == 0)
		cout << "---none---" << endl;
	else
	{
		int i = 0;
		sort(songList.begin(),songList.end(),compareSongs);
		while(i < songList.size())
		{
			cout << songList[i].songName << ", " << songList[i].albumTitle << ", " << songList[i].songLength << endl;
			i++;
		}
	}
	songList.clear();
}

// show albums that belong to given singer name
void findGivenSingerNameToShowAlbum(album *root, const string singerName)
{
	if(root == NULL)
		return;
	// if singer name of album = given singer name, keep it in vector
	if(root->singerName == singerName)
	{
		albumList.push_back(*root);
	}
	findGivenSingerNameToShowAlbum(root->leftAlbum,singerName);
	findGivenSingerNameToShowAlbum(root->rightAlbum,singerName);
}

bool compareAlbumsYear(album a, album b)
{
    return a.releaseYear < b.releaseYear;
}


void Discography::showSingerAlbums(const string singerName)
{
	cout << singerName << endl;
	findGivenSingerNameToShowAlbum(albumRoot,singerName);
	if(albumList.size() == 0)
		cout << "---none---" << endl;
	else
	{
		int i = 0;
		sort(albumList.begin(),albumList.end(),compareAlbumsYear);
		while(i < albumList.size())
		{
			cout << albumList[i].albumTitle << ", " << albumList[i].releaseDay << "/" << albumList[i].releaseMonth << "/" << albumList[i].releaseYear << endl;
			i++;
		}
	}
	albumList.clear();
}

// show albums whose release year is same with given year
void findGivenYearToShowAlbum(album *root, const int releaseYear)
{
	if(root == NULL)
		return;
	// if release year of album < given year, keep it in vector
	if(root->releaseYear == releaseYear)
	{
		albumList.push_back(*root);
	}
	findGivenYearToShowAlbum(root->leftAlbum,releaseYear);
	findGivenYearToShowAlbum(root->rightAlbum,releaseYear);
}

bool compareAlbumsMonth(album a, album b)
{
    return a.releaseMonth < b.releaseMonth;
}

void Discography::showAlbums(const int releaseYear)
{
	cout << releaseYear << endl;
	findGivenYearToShowAlbum(albumRoot,releaseYear);
	if(albumList.size() == 0)
		cout << "---none---" << endl;
	else
	{
		int i = 0;
		sort(albumList.begin(),albumList.end(),compareAlbumsMonth);
		while(i < albumList.size())
		{
			cout << albumList[i].albumTitle << ", " << albumList[i].releaseDay << "/" << albumList[i].releaseMonth << endl;
			i++;
		}
	}
	albumList.clear();
}

// show albums that are between given years
void showAlbumsBetweenGivenYears(album *root, const int startYear, const int endYear)
{
	if(root == NULL)
		return;
	// if release year of album is between given years, keep it in vector
	if(root->releaseYear <= endYear && root->releaseYear >= startYear)
	{
		albumList.push_back(*root);
	}
	if(root->releaseYear > endYear)
		showAlbumsBetweenGivenYears(root->leftAlbum,startYear,endYear);
	else if(root->releaseYear < startYear)
		showAlbumsBetweenGivenYears(root->rightAlbum,startYear,endYear);
	else
	{
		showAlbumsBetweenGivenYears(root->leftAlbum,startYear,endYear);
		showAlbumsBetweenGivenYears(root->rightAlbum,startYear,endYear);
	}
}

void Discography::showAlbums(const int startYear, const int endYear)
{
	cout << startYear << "-" << endYear << endl;
	showAlbumsBetweenGivenYears(albumRoot,startYear,endYear);
	if(albumList.size() == 0)
		cout << "---none---" << endl;
	else
	{
		int i = 0;
		sort(albumList.begin(),albumList.end(),compareAlbumsYear);
		while(i < albumList.size())
		{
			cout << albumList[i].albumTitle << ", " << albumList[i].releaseYear << endl;
			i++;
		}
	}
	albumList.clear();
}
