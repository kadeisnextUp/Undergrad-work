package program5;

public class Player {
	private String name; 
	private int score = 50; // player's default score is 50
	
	public Player() { // default constructor
		name = "noName";
	}
	
	//
	public void setName(String playerName) {
		name = playerName;
	}
	
	public String getName() {
		return name;
	}
	
	// returns the player's score
	public int getScore() {
		return score;
	}
	
	// will add to the players score depending on the condition
	public void setScore(int scoreAdd) {
		// if the current score minus the score being added is less than 1
		if ((score - scoreAdd)< 1) {
			score+= scoreAdd;
		}
		// otherwise the score being added is made negative and added to the player's total score
		else {
			scoreAdd = scoreAdd*-1;
			score += scoreAdd;
		}
		
	}

}
