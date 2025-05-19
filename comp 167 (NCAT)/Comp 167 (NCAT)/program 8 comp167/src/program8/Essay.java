package program8;

public class Essay extends GradedActivity {
	private double grammarScore;
	private double spellingScore;
	private double lengthScore;
	private double contentScore;
	
	
// all the scores to find a final essay grade
	public void setGrammarScore(double g) {
		grammarScore = g;
	}
	
	public void setSpellingScore(double s) {
		spellingScore = s;
	}
	
	public void setLengthScore(double l) {
		lengthScore = l;
	}
	
	public void setContentScore(double c) {
		contentScore = c;
	}
	//changing the getGrade() function for this class
	@Override
	 public char getGrade()
	   {
	      char letterGrade;
	      double score = grammarScore + spellingScore + lengthScore + contentScore;

	      if (score >= 90)
	         letterGrade = 'A';
	      else if (score >= 80)
	         letterGrade = 'B';
	      else if (score >= 70)
	         letterGrade = 'C';
	      else if (score >= 60)
	         letterGrade = 'D';
	      else
	         letterGrade = 'F';

	      return letterGrade;
	   }
	

}
