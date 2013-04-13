// ScoreCard - Maintains one integer score per player, for any number of players
//
// author: Tugba Dogan
// date: 2012/6/25

public class ScoreCard
{
	// properties
	int[] scores;

	// constructors
	public ScoreCard( int noOfPlayers)
	{
		scores = new int[noOfPlayers];

		// init all scores to zero
		for ( int i = 0; i < scores.length; i++)
			scores[i] = 0;
	}

	// methods
	public int getScore( int playerNo)
	{
		return scores[ playerNo];
	}

	// Update given player's score
	public void update( int playerNo, int amount)
	{
		scores[playerNo] += amount;
	}

	// return all players' scores
	public String toString()
	{
		String s;
		s = "\n"
			+ "_____________\n"
			+ "\nPlayer\tScore\n"
			+ "_____________\n";

		for ( int playerNo = 0; playerNo < scores.length; playerNo++)
		{
			s = s + playerNo + "\t" + scores[playerNo] + "\n";
		}

		s += "_____________\n";
		return s;
	}

}