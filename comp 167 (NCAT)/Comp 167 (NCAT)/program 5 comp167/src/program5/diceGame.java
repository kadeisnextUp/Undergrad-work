package program5;

import java.util.Scanner;

public class diceGame {
	
		
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Player player1 = new Player();
		Player player2 = new Player();
		Scanner scnr = new Scanner(System.in);
		String input = "";
		boolean winner = false;
		System.out.println("Welcome to the 2-player dice game!");
		System.out.println("In this game there are two players who will take turns in \"throwing\" a dice and they both start out with 50 points.");
		System.out.println("The number the dice lands on is subtracted from the player's total after every \"throw\". ");
		System.out.println("If the number subtracted from a player's score is less than one it is added to the total instead");
		System.out.println("In order to win the player has to acheive a final score of 1\n");
		System.out.println("What is the first player's name?");
		input = scnr.nextLine();
		player1.setName(input);
		System.out.println("What is the second player's name?");
		input = scnr.nextLine();
		player2.setName(input);
		Die dice = new Die(6);
		System.out.println("\naeStarting the game simulation...");
		while (winner == false) {
			dice.roll();
			int score = dice.getValue();
			player1.setScore(score);
			System.out.println(player1.getName()+ "'s score is " + player1.getScore());
			if(player1.getScore() == 1) {
				winner = true;
				System.out.println(player1.getName()+ " won the game");
				System.out.println(player1.getName()+ "'s final score is " + player1.getScore());
				break;
			}
			dice.roll();
			score = dice.getValue();
			player2.setScore(score);
			System.out.println(player2.getName()+ "'s score is " + player2.getScore());
			if(player2.getScore() == 1) {
				winner = true;
				System.out.println(player2.getName()+ " won the game");
				System.out.println(player2.getName()+ "'s final score is " + player2.getScore());
			}
			
			
			
		}
		scnr.close();
		System.out.println("End of program");
		

	}

}
