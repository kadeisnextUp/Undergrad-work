package mp1;

public class Classroom {
	private String className;
	private String classLocation;
	private String classInstructor;
	
	// constructors
	public Classroom() {
		className = "none";
		classLocation = "none";
		classInstructor = "none";
	}
	
	public Classroom(String name, String loc, String teacher) {
		className = name;
		classLocation = loc;
		classInstructor = teacher;
	}
	
	// setters
	public void setName(String name) {
		className = name;
	}
	
	public void setLocation(String loc) {
		classLocation = loc;
	}
	
	public void setInstructor(String teacher) {
		classInstructor = teacher;
	}
	
	
	//getters
	public String getName() {
		return className;
	}
	
	public String getLocation() {
		return classLocation;
	}
	
	public String getInstructor() {
		return classInstructor;
	}
	
	// other methods
	public void printClassInfo() {
		System.out.println("This is " + className + " class");
		System.out.println(className + " is located at " + classLocation);
		System.out.println("The teacher for this class is " + classInstructor);
		
	}
	
	
	

}
