#include <iostream>
#include "MovieDatabase.h"
using namespace std;

int main()
{
	MovieDatabase movieList;
	
	movieList.showAllMovies();
	
	movieList.addMovie("Fight Club","David","Fincher",5,8,1999);
	movieList.addMovie("Next","Lee","Tamahori",9,12,2007);
	movieList.addMovie("Immortals","Tarsem","Singh",15,10,2011);
	movieList.addMovie("Ted","Seth","MacFarlane",22,12,2012);
	movieList.addMovie("The Words","Brian","Klugman",23,1,2012);
	movieList.addMovie("Forest Gump","Robert","Zemeckis",12,10,1994);
	movieList.addMovie("The Pianist","Roman","Polanski",28,5,2002);
	movieList.addMovie("V For Vendetta","James","McTeigue",8,9,2006);
	movieList.addMovie("The Game","David","Fincher",14,06,1997);
	movieList.addMovie("Legends Of the Fall","Edward","Zwick",21,06,1994);
	
	movieList.showAllMovies();
	
	movieList.addMovie("Fight Club","David","Fincher",5,8,1999);
	movieList.showAllMovies();
	
	movieList.removeMovie("Next");
	movieList.showAllMovies();
	
	movieList.removeMovie("Looper");
	
	movieList.addActor("Fight Club","Meat","Loaf","Robert 'Bob' Paulson");
	movieList.addActor("Fight Club","Brad","Pitt","Tyler Durden");
	movieList.addActor("Fight Club","Helena Bonham","Carter","Marla Singer");
	movieList.addActor("Fight Club","Edward","Norton","The Narrator");
	movieList.showMovie("Fight Club");
	
	movieList.showMovie("Looper");
	
	movieList.addActor("Fight Club","Brad","Pitt","Tyler Durden");
	
	movieList.addActor("The Game","Michael", "Douglas","Nicholas Van Orton");
	movieList.addActor("The Game","Sean", "Penn","Conrad Van Orton");
	movieList.addActor("The Game","James", "Rebhorn","Jim Feingold");
	movieList.addActor("The Game","Deborah Kara", "Unger","Christine");
	movieList.showMovie("The Game");
	
	movieList.showActorRoles("Brad","Pitt");
	movieList.showActorRoles("Michael","Douglas");
	movieList.showMovies(2012);
	movieList.showMovies(2005);
	movieList.removeActor("Fight Club","Helena Bonham","Carter");
	movieList.removeActor("Fight Club","Brad","Pitt");
	movieList.showMovie("Fight Club");
}
