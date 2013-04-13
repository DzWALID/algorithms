// Player - Simple card game player with name and hand of cards
// author: Tugba Dogan
// date: 2012/6/25
public class Player
{
	// properties
	String	name;
	Cards	hand;

	// constructors
	public Player( String name)
	{
		this.name = name;
		hand = new Cards();
	}

	// methods
	public String getName()
	{
		return name;
	}
	
	// Add card to players' hands
	public void add( Card c)
	{
		hand.addTopCard(c);
	}
	
	// removes and returns the top card from the players hand
	public Card playCard()
	{
		return hand.getTopCard();
	}

}