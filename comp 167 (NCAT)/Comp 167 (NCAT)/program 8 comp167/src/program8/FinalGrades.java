package program8;
import java.util.Random;

public class FinalGrades {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// random class to create random numbers
		Random rand = new Random();
		System.out.println("Creating a essay object...");
		Essay testEssay = new Essay();
		
		
		System.out.println("\nGenerating random grammar score for essay...");
		double grammar = rand.nextInt(31);
		System.out.println("Grammar score is: " + grammar);
		
		System.out.println("\nGenerating random spelling score for essay...");
		double spelling = rand.nextInt(21);
		System.out.println("Spelling score is: " + spelling);
		
		System.out.println("\nGenerating random length score for essay...");
		double length = rand.nextInt(21);
		System.out.println("Length score is: " + length);

		System.out.println("\nGenerating random content score for essay...");
		double content = rand.nextInt(31);
		System.out.println("Content score is: " + content);
		
		System.out.println("Adding the scores to the essay object...");
		testEssay.setGrammarScore(grammar);
		testEssay.setSpellingScore(spelling);
		testEssay.setLengthScore(length);
		testEssay.setContentScore(content);
		
		System.out.println("\nCalling the getGrade() function...");
		System.out.println("The final score for this essay is a " + testEssay.getGrade());
		

		
		
		
		

		

	}

}
