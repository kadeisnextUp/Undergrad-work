package mp1;

import java.util.Arrays;

public class CollegeClass extends Classroom {
	private int maxStudents;
	private String[] classList;

	//constructors
	public CollegeClass() {
		// TODO Auto-generated constructor stub
		maxStudents = 0;
		classList = null;
	}

	public CollegeClass(String name, String loc, String teacher, int max , String[] stuList) {
		super(name, loc, teacher);
		// TODO Auto-generated constructor stub
		maxStudents = max;
		classList = stuList;
	}
	
	//setter
	public void setMax(int max) {
		maxStudents = max;
	}
	
	public void setList(String[] stuList) {
		classList = stuList;
	}
	
	//getters
	public int getMax() {
		return maxStudents;
	}
	
	public String[] getList() {
		return classList;
	}
	
	//other methods
	@Override
	public void printClassInfo(){
		super.printClassInfo();
		System.out.println("The max students in this class is " + maxStudents);
		System.out.println("The students in this class are: ");
		System.out.println(Arrays.toString(classList));
	}
	
	

}
