#include <iostream>
#include <string>
#include "MovieDatabase.h"
using namespace std;

MovieDatabase::MovieDatabase()
{
	head=NULL;
}

MovieDatabase::~MovieDatabase()
{
	movie *cur;
	movie *tmp;
	for(cur=head; cur; cur=tmp)
	{
		tmp = cur->next;
		removeMovie(cur->movieTitle);
	}
}

// add movie to the movie database
void MovieDatabase::addMovie( const string movieTitle, const string directorFirstName, const string directorLastName, const int releaseDay, const int releaseMonth, const int releaseYear )
{
	int exist=0;
	movie *ptr = new movie;
	ptr->movieTitle = movieTitle;
	ptr->directorFirstName=directorFirstName;
	ptr->directorLastName=directorLastName;
	ptr->releaseDay=releaseDay;
	ptr->releaseMonth=releaseMonth;
	ptr->releaseYear=releaseYear;
	
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->head = NULL;
	
	if(!head)
	{
		head = ptr;
	}
	else
	{
		movie *cur;
		for(cur=head; cur->next; cur=cur->next)
		{
			// if the user attempts to add a movie with an existing title
			if(cur->next->movieTitle==movieTitle)
			{
				cout << movieTitle << " already exist!" << endl;
				exist=1;
				delete ptr;
				break;
			}
		}
		if(!exist)
		{
			cur->next=ptr;
			ptr->prev=cur;
		}
	}
}

// Remove a movie from the movie database
void MovieDatabase::removeMovie( const string movieTitle )
{
	int exist=0;
	movie *cur;
	movie *tmp;
	actor *tmp2,*tmp3,*cur2;
	
	for(cur=head; cur; cur=cur->next)
	{
		if(cur->movieTitle == movieTitle)
		{
			exist =1;
			tmp = cur;
			tmp2 = cur->head;
			if(cur==head)
			{
				head=cur->next;
			}
			else
			{
				cur->prev->next = cur->next;
			}
			
			for(cur2=tmp2; cur2; cur2=tmp3)
			{
				tmp3=cur2->next;
				delete cur2;
			}
			delete tmp;
			break;
		}
	}
	// If this movie does not exist in the database
	if(exist==0)
		cout << movieTitle << " does not exist!" << endl;
}

// Add an actor/actress to the cast of a movie
void MovieDatabase::addActor( const string movieTitle, const string actorFirstName, const string actorLastName, const string actorRole )
{
	int exist=0,cnt=0;
	string fullName = actorLastName + actorFirstName;
	movie *cur;
	for(cur=head; cur; cur=cur->next)
	{
		if(cur->movieTitle == movieTitle)
		{
			exist=1;
			for(actor *control = cur->head; control; control=control->next)
			{
				// if the user attempts to add an actor/actress with an existing name
				if(control->actorFirstName==actorFirstName && control->actorLastName==actorLastName)
				{
					cout << actorFirstName << " " << actorLastName << " " << "already exists!" << endl;
					cnt=1;
					break;
				}
			}
			if(cnt==1)
				break;
			actor *ptr = new actor;
			ptr->actorFirstName = actorFirstName;
			ptr->actorLastName = actorLastName;
			ptr->actorRole = actorRole;
			if(!cur->head)
			{
				cur->head=ptr;
				ptr->next= NULL;
			}
			else
			{
				actor *cur2;
				// alphabetically ascending order according to the last names of actors/actresses(if there is more than one entry with the same last name, then it is ascending order according to the first names)
				for(cur2=cur->head; cur2->next && (cur2->next->actorLastName + cur2->next->actorFirstName)<fullName;cur2=cur2->next);
				if(cur2==cur->head&& (cur2->actorLastName + cur2->actorFirstName)>fullName)
				{
					ptr->next = cur->head;
					cur->head = ptr;
				}
				else
				{
					ptr->next = cur2->next;
					cur2->next = ptr;
				}
			}
		}
	}
	// If the movie with a specified title does not exist in the database
	if(exist==0)
	{
		cout << movieTitle << " does not exist!" << endl;
	}
}

// Remove an actor/actress from the cast of a movie
void MovieDatabase::removeActor( const string movieTitle, const string actorFirstName, const string actorLastName )
{
	movie *cur;
	int index=0;
	int exist=0,exist2=0;
	for(cur=head; cur; cur=cur->next)
	{
		if(cur->movieTitle == movieTitle)
		{
			exist=1;
			actor *cur2;
			actor *tmp;
			for(cur2=cur->head; cur2; cur2=cur2->next)
			{
				index++;
				if(cur2->actorFirstName==actorFirstName && cur2->actorLastName==actorLastName)
				{
					exist2=1;
					break;
				}
			}
			if(exist2==0)
			{
				break;
			}
			int i;
			if(index==1)
			{
				tmp=cur->head;
				cur->head=cur->head->next;
			}
			else
			{
				for(i=1,cur2=cur->head; i<index-1 && cur2->next; i++,cur2=cur2->next);
				if(cur->next)
				{
					tmp=cur2->next;
					cur2->next = cur2->next->next;
				}
			}
			delete tmp;
			break;
		}
	}
	// If the movie with a specified title does not exist in the database
	if(exist==0)
	{
		cout << movieTitle << " does not exist!" << endl;
		return;
	}
	// if the actor/actress is not in the cast of the specified movie
	if(exist2==0)
	{
		cout << actorFirstName << " " << actorLastName << " does not exist!" << endl;
		return;
	}
}

// Show the list of movies	
void MovieDatabase::showAllMovies()
{
	movie *cur;
	// If the database does not contain any movie
	if(!head)
		cout<< "---none---" << endl;
	else
	{
		for(cur=head; cur; cur=cur->next)
		{
			cout << cur->movieTitle << ", " << cur->releaseYear << ", " << cur->directorFirstName << " " << cur->directorLastName;
			cout << endl;
		}
	}
}

// Show detailed information about a particular movie
void MovieDatabase::showMovie( const string movieTitle )
{
	movie *cur;
	actor *cur2;
	int exist=0;
	for(cur=head; cur; cur=cur->next)
	{
		if(cur->movieTitle == movieTitle)
		{
			exist = 1;
			cout << cur->movieTitle << endl;
			cout << cur->releaseDay << "/" << cur->releaseMonth << "/" << cur->releaseYear << endl;
			cout << cur->directorFirstName << " " << cur->directorLastName << endl;
			for(cur2=cur->head; cur2; cur2=cur2->next)
			{
				cout << cur2->actorFirstName << " " << cur2->actorLastName << " " << cur2->actorRole;
				cout << endl;
			}
		}
	}
	// If the movie with a specified title does not exist in the database
	if(exist==0)
		cout << "---none---" << endl;
}

// Query the roles that were played by a particular actor/actress
void MovieDatabase::showActorRoles( const string actorFirstName, const string actorLastName )
{
	movie *cur;
	actor *cur2;
	int exist=0;
	cout << actorFirstName << " " << actorLastName << endl;
	for(cur=head; cur; cur=cur->next)
	{
		for(cur2=cur->head; cur2; cur2=cur2->next)
		{
			if(cur2->actorFirstName==actorFirstName &&  cur2->actorLastName==actorLastName)
			{
				exist=1;
				cout << cur2->actorRole << ", " << cur->movieTitle << ", " << cur->releaseYear << endl;
			}
		}
	}
	// if the actor/actress did not play a role in any movie
	if(exist==0)
		cout << "---none---" << endl;
}

// Query the movies which are/were released in a particular year
void MovieDatabase::showMovies( const int releaseYear )
{
	movie *cur;
	int exist=0;
	cout << releaseYear << endl;
	for(cur=head; cur; cur=cur->next)
	{
		if(cur->releaseYear == releaseYear)
		{
			exist = 1;
			cout << cur->movieTitle << ", " << cur->directorFirstName << " " << cur->directorLastName << ", " << cur->releaseDay << "/" << cur->releaseMonth << endl;
		}
	}
	// if there is no movie in the specified year
	if(exist==0)
		cout << "---none---" << endl;
}
