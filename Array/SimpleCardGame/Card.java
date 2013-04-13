/**
 * Card - a single playing card
 * @author Tugba Dogan
 * @version 1.00 2012/2/15
 */
public class Card implements Comparable
{
	final String[] SUITS = { "Hearts", "Diamonds", "Spades", "Clubs"};
	final String[] FACES = { "A", "2", "3", "4", "5",
							 "6", "7", "8", "9", "10",
							 "J", "Q", "K"};
	// properties
	int		cardNo;

	// constructors
	public Card( int faceValue, int	suit )
	{
		cardNo = faceValue + suit * 13;
	}

	public Card( int cardNumber)
	{
		cardNo = cardNumber;
	}
	
	// getter methods
	public int getFaceValue()
	{
		return cardNo % 13;
	}

	public int getSuit()
	{
		return cardNo / 13;
	}
	
	// return selected card information
	public String toString()
	{
		return FACES[ getFaceValue() ] + " of " + SUITS[ getSuit() ];
	}
	// Compare card objects' suits and face values
	public int compareTo(Object o)
	{
		Card c = (Card) o;
		if(this.getFaceValue() == c.getFaceValue())
		{
			if(this.getSuit() == c.getSuit())
				return 0;
			if(this.getSuit() < c.getSuit())
				return 1;
			return -1;
		}
		if(this.getFaceValue()<c.getFaceValue())
			return 1;
		return -1;
	}
}