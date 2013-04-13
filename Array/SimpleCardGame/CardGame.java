import java.util.*;
// Cardgame A Class which provides options and methods for CardGame
// author: Tugba Dogan
// date: 2012/6/25
public class CardGame
{
	// properties
	Cards				fullPack;
	ArrayList<Player>	players;
	ScoreCard			scoreCard;
	Card[]				cardsOnTable;
	int					roundNo;
	int					turnOfPlayer;

	// constructors
	public CardGame(Player[] players)
	{
		this.players = new ArrayList<Player>();

		for(int i=0; i<players.length; i++)
		{
			this.players.add(players[i]);
		}

		// create a full pack and use its methods to play
		fullPack = new Cards();
		fullPack.createFullPack();
		fullPack.shuffle();

		// Create scoreCard object to keep players's scores
		scoreCard = new ScoreCard(players.length);
		roundNo = 0;
		turnOfPlayer = 0;

		cardsOnTable = new Card[players.length];

		for(int i=0; i<52; i++)
		{
			this.players.get(turnOfPlayer).add(fullPack.getTopCard());
			turnOfPlayer++;
			if(turnOfPlayer == players.length)
				turnOfPlayer = 0;
		}
		turnOfPlayer = 0;
	}

	// methods

	// Play a round
	public boolean playTurn( Player p, Card c)
	{
		if(!isTurnOf(p) || isGameOver())
			return false;

		cardsOnTable[turnOfPlayer] = p.playCard();
		turnOfPlayer++;
		Player[] winner;
		int n;
		String s;
		if(turnOfPlayer == players.size())
		{
			winner = getWinners();
			n = 0;
			for(int i=0; i<winner.length; i++)
			{
				s = winner[i].getName();
				for(int a=0; a<players.size(); a++)
				{
					if(s.equals(players.get(a).getName()))
						n = a;
				}
				scoreCard.update(n,1);
			}
			roundNo++;
			if(!isGameOver())
			{
				turnOfPlayer = 0;
			}
		}
		return true;
	}

	// Control that whether tne next palyer exists or not
	public boolean isTurnOf( Player p)
	{
		if(p.getName().equals(players.get(turnOfPlayer).getName()))
			return true;
		return false;
	}

	// COntrol that whether game is over or not
	public boolean isGameOver()
	{
		if(roundNo == 52/players.size())
		{
			System.out.println(scoreCard);
			return true;
		}
		return false;
	}

	// Return given player's score
	public int getScore( int playerNumber)
	{
		if(playerNumber<players.size())
			return scoreCard.getScore(playerNumber);
		return -1;
	}

	// return given players' name
	public String getName( int playerNumber)
	{
		if(playerNumber<players.size())
			return players.get(playerNumber).getName();
		return "Player is not found";
	}

	public int getRoundNo()
	{
		return roundNo;
	}

	// return next Player's number
	public int getTurnOfPlayerNo()
	{
		return turnOfPlayer;
	}

	// return winners
	public Player[] getWinners()
	{
		int index= 0;
		Card[] cards = new Card[cardsOnTable.length];
		for(int i=0; i<cardsOnTable.length; i++)
		{
			cards[i] = cardsOnTable[i];
		//	System.out.println(cards[i]);
		}
		Player[] players = new Player[1];
		Arrays.sort(cardsOnTable);

		for(int i=0; i<cardsOnTable.length; i++)
		{
			if(cards[i].equals(cardsOnTable[0]))
				index = i;
		}
		players[0] = this.players.get(index);
		return players;
	}

}