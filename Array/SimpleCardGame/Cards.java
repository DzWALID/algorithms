import java.util.*;
// Cards - Maintains a collection of zero or more playing cards.
//		   Provides facilities to create a full pack of 52 cards
//		   and to shuffle the cards.
// author: Tugba Dogan
// date: 2012/6/25

public class Cards
{
	final int NOOFCARDSINFULLPACK = 52;

	// properties
	Card[]	cards;
	int		valid;

	// constructors
	public Cards()
	{
		cards = new Card[ NOOFCARDSINFULLPACK ];
		valid = 0;
	}

	// methods

	// removes and returns the top card from the array
	public Card getTopCard()
	{
		if ( valid <= 0)
			return null;
		else
		{
			Card tmp;
			valid--;
			tmp = cards[valid];
			cards[valid] = null;
			return tmp;
		}
	}

	// add given cards to top
	public boolean addTopCard( Card c)
	{
		if ( valid < cards.length)
		{
			cards[valid] = c;	// should this be cloned?
			valid++;
			return true;
		}
		return false;
	}
	// create a full pack cards
	public void createFullPack()
	{
		for(int i=0; i<52; i++)
		{
			addTopCard( new Card(i) );
		}
	}

	// Shufle cards in array
	public void shuffle()
	{
		Collections.shuffle(Arrays.asList(cards));
	}
}