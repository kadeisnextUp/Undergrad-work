package mp1;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;
import java.io.*;
import java.util.InputMismatchException;


public class userInterface {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//variables for CollegeClass Object
		String name;
		String location;
		String teacher;
		int max = 0;
		String[] studentArray = new String[max];
		
		
		ArrayList<String> studentList =  new ArrayList<String>();
		ArrayList<String> copyList = new ArrayList<String>();
		ArrayList<Student> students = new ArrayList<Student>();
		CollegeClass test = new CollegeClass();
		
		boolean end = false;
		Scanner scnr = new Scanner(System.in);
		//for file input
		Scanner fileScan = null;
		FileInputStream fileIn = null;
		
		// create random numbers
		Random rand = new Random();
		
		while(end == false) {
			//get class info from user and add values to the class object
			System.out.println("This program intends to replacate a college class.");
			System.out.println("Please enter the class's name, location(building/hall), and the teacher's full name below in this fashion:");
			System.out.println("Example:");
			System.out.println("Class name \nLocation \nFirstName LastName");
			name = scnr.nextLine();
			test.setName(name);
			
			location = scnr.nextLine();
			test.setLocation(location);
			
			teacher = scnr.nextLine();
			test.setInstructor(teacher);
			// get max students
			System.out.println("What is the maximum number of students allowed in this class");
			
			try {
				max = scnr.nextInt();
				if (max <= 100 && max > 0) {
					test.setMax(max);
					studentArray = new String[max];
					end = true;
				}
				else {
					System.out.println("Enter a number greater than zero and less than 100");
				}
			}
			catch (InputMismatchException k) {
				System.out.println("Enter a valid number greater than 0");
				scnr.nextLine();
			}
			
		}
		
		
		// opening random student name list I created
		
		try {
			System.out.println("Gathering students for this class...");
			//male students
			fileIn = new FileInputStream("randomMales.txt");
			fileScan = new Scanner(fileIn);
			while(fileScan.hasNext()) {
				studentList.add(fileScan.nextLine());
			}
			
			//female students
			fileIn = new FileInputStream("randomFemales.txt");
			fileScan = new Scanner(fileIn);
			while(fileScan.hasNext()) {
				studentList.add(fileScan.nextLine());
			}
			
			
		}
		catch (FileNotFoundException e) {
			System.out.println("File cannot be found.");
		}
		
		
		// modifying the list to have the max number of students
		copyList = studentList;
		int total = 100;

		while(copyList.size() > max) {
			copyList.remove(rand.nextInt(total));
			total--;
			
			
		}
		//adding the students to the array in the CollegeClass object
		for(int i = 0; i < copyList.size(); i++) {
			studentArray[i] = copyList.get(i);
		}
		test.setList(studentArray);
		
		// assigning each student a numerical average and grade
		for(String k: copyList) {
			Student temp = new Student();
			temp.setName(k);
			double randAvg = rand.nextInt(101);
			temp.setAvg(randAvg);
			String grade;
			if(randAvg <= 59.0) {
				grade = "F";
			}
			else if(randAvg >=60 && randAvg <70 ) {
				grade = "D";
			}
			else if(randAvg >= 70 && randAvg <80) {
				grade = "C";
			}
			else if(randAvg >=80 && randAvg < 90) {
				grade = "B";
			}
			else {
				grade = "A";
			}
			temp.setGrade(grade);
			students.add(temp);
		}
	
	
	
		//printing all the information about the class and each student's information
		System.out.println();
		System.out.println();
		System.out.println("Displaying the class inforamtion:");
		test.printClassInfo();
		System.out.println("\n\nDisplaying all the students in this class and their final grade:");
		for(Student k: students) {
			System.out.println();
			k.printInfo();
		}
		
		System.out.println("\n\nEnd of program");
	}

}
