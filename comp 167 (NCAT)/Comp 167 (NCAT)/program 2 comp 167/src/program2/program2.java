package program2;

import java.util.Scanner;
import java.util.InputMismatchException;

public class program2 {
	
	// this method takes a array of ints and a int as input and outputs the ints in the array that are greater 
	// than the input int
	public static int[] greaterThan(int[] numbers, int n) {
		int count = 0;
		int greater =0;
		
		while(count != numbers.length-1) {
			if (numbers[count] > n) {
				greater++;
				count++;
			}
			else {
				count++;
			}
			
		}
		
		int[] result = new int[greater];
		count =0;
		for (int i =0; i < numbers.length-1; i++) {
			if (numbers[i] > n) {
				result[count] = numbers[i];
				count++;
				
			}
		}
		
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int num;
		int testLength;
		Scanner scnr = new Scanner(System.in);
		String input = "";
		
		while(input.equals("stop")== false) {
			try {
				System.out.println("Enter the length of the array of ints");
				testLength = scnr.nextInt();
				int[] test = new int[testLength];
				for(int i = 0; i < test.length; i++) {
					System.out.println("Enter each number for the array");
					try {
						test[i] = scnr.nextInt();
					}
					 catch (InputMismatchException k) {
						System.out.println("Please enter a valid integer");
						scnr.nextLine();
					}
					
					
				}
				
			}
			catch (InputMismatchException k) {
				System.out.println("Enter a valid integer");
			}
			
			
			
			
			
			System.out.print("All numbers have been entered for the array.");
			System.out.print("Enter a number to compare to the array");
			num = scnr.nextInt();
			
			System.out.println("Using the greaterThan() method...");
			int[] result = greaterThan(test,num);
			if(result.length > 0) {
				System.out.println("These numbers were greater than " + num);
				for(int k = 0; k < result.length; k++ ) {
					System.out.print(result[k] + " ");
				}
				
			}
			else {
				System.out.println("There were no numbers greater than the given value.");
				
			}
			
			System.out.println("Enter any character to continue or enter \"stop\" to end the program");
			input = scnr.next();
			
		}
		
		System.out.println("End of program");

	}

}
