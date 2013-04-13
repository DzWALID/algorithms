import java.util.Scanner;

// CardGameTest: Test all classes
// author: Tugba Dogan
// date: 2012/6/25

public class CardGameTest
{
    public static void main( String[] args)
	{
    	Scanner scan = new Scanner( System.in);

    	System.out.println( "Start of CardGameTest\n");

		// CONSTANTS

		// VARIABLES
		Card		c;
		Cards		cards;
		ScoreCard	scores;
		Player		p;
		CardGame	game;

		// PROGRAM CODE

		// test Card class
/*		c = new Card( 1);
		System.out.println( c);
		System.out.println();

		// test Cards class
		cards = new Cards();
		cards.createFullPack();
		cards.shuffle();
		cards.testOnlyPrint();*/

		// test ScoreCard class
		scores = new ScoreCard( 4);
		scores.update( 3, 1);
		scores.update( 1, 2);
		System.out.println( "\n" + scores );

/*		// test Player class
		p = new Player("David");
		p.add(c);
		p.add(new Card(27));
		System.out.println(p.playCard());
		System.out.println(p.playCard());*/
		
		// test CardGame class
		Player[] players = new Player[4];
		players[0] = new Player("Cihad");
		players[1] = new Player("Tuðba");
		players[2] = new Player("Iþýl");
		players[3] = new Player("Zeynep");

		game = new CardGame(players);

		for(int a=0; a<13; a++)
		{
			for(int i = 0; i<4; i++)
			{
				game.playTurn(players[game.getTurnOfPlayerNo()], new Card(1));
			}
		//	for(int i = 0; i<4; i++)
		//	{
		//		System.out.println(game.getScore(i));
		//	}
		}

		//game.playTurn();

		// Once you have all the bits working, write a SimpleCardGame class
		// that provides a menu allowing any of the players to play their card,
		// an option to see the score card, and one to quit the game at any time.
		// When the game is over it should print out the winners.

		System.out.println( "\nEnd of CardGameTest\n" );
	}

} // end of class CardGameTest
