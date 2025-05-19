package mp1;

public class Student {
	private String name;
	private double numAvg;
	private String letterGrade;
	
	//constructors
	public Student() {
		name = "no name";
		numAvg = 0.0;
		letterGrade = "n/a";
		
	}
	
	public Student(String stuName, double stuAvg, String stuGrade ) {
		name = stuName;
		numAvg = stuAvg;
		letterGrade = stuGrade; 
		
	}
	
	//setters
	public void setName(String stuName) {
		name = stuName;
	}
	
	public void setAvg(double stuAvg) {
		numAvg = stuAvg;
	}
	
	public void setGrade(String grade) {
		letterGrade = grade;
	}

	
	// getters
	public String getName() {
		return name;
	}
	
	public double getAvg() {
		return numAvg;
	}
	
	public String getGrade() {
		return letterGrade;
	}
	
	//other methods
	
	public void printInfo() {
		System.out.println(name);
		System.out.println("Final numeric average: " + numAvg);
		System.out.println("Final letter grade: " + letterGrade);
	}
}
