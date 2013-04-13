import java.util.Scanner;
// SimpleCardgame.java Test class for Simple Card Game
// author: Tugba Dogan
// date: 2012/6/25

public class SimpleCardGame {

	public static void main(String[] args) {

		Scanner scan = new Scanner( System.in);

		//VARIABLES
		int number,option,playerNumber,a=0;
		String name;
		boolean cik = true;
		CardGame game;
		ScoreCard scores;

		while(cik)
		{
			// Print menu for user to start game or quit
			System.out.println("1) Start Game");
			System.out.println("2) Quit");

			System.out.print("Enter Number: ");
			number = scan.nextInt();

			// Start game
			if(number == 1)
			{
				// Get how many users will play
				System.out.print("Enter the number of player: ");
				playerNumber = scan.nextInt();

				// Create Player array to keep players
				Player[] players = new Player[playerNumber];

				// Get users' names and add them to array
				for(int i=0; i<playerNumber; i++)
				{
					System.out.print("Enter player's names: ");
					name = scan.next();
					players[i] = new Player(name);
				}

				game = new CardGame(players);

				// Print menu while enough cards exist for all players
				while(a<(52/playerNumber))
				{
					// Print menu to play a round or show score or quit
					System.out.println("1) Play a round");
					System.out.println("2) Scores");
					System.out.println("3) Quit");

					System.out.print("Enter Number: ");
					option = scan.nextInt();

					// Play a round
					if(option == 1)
					{
						for(int i = 0; i<playerNumber; i++)
						{
							game.playTurn(players[game.getTurnOfPlayerNo()], new Card(1));
						}
						a++;
					}

					// Show all players' scores
					else if(option == 2)
					{
						for(int i = 0; i<playerNumber; i++)
						{
							System.out.println(game.getScore(i));
						}
					}

					// Quit game
					else if(option == 3)
					{
						a = (52/playerNumber)+1;
					}
				}
			}
			// Quit game
			if(number == 2)
			{
				cik = false;
			}
		}

	}
}
