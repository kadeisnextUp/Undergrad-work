package program1;

import java.util.Scanner;



public class retail {
	// This method takes in a double (cost of item) and a int 
	// (markup percentage) and returns the new retail price
	public static double calculateRetail(double cost, int percent) {
		double percentage;
		double markupPrice;
		percentage = (double)(percent / 100.0);
		markupPrice = cost + (percentage*cost);
		return markupPrice;
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double cost;
		int percent;
		String input;
		double result;
		Scanner scnr = new Scanner(System.in);
		input = " ";
		
		// this loop is for the user input
		while(input.equals("stop")== false) {
			System.out.println("Enter the item's wholesale cost");
			cost = scnr.nextDouble();
			System.out.println("Enter the item's markup percent");
			percent = scnr.nextInt();
			result = calculateRetail(cost, percent);
			System.out.print("The item's retail price is $");
			System.out.printf("%.2f\n",result);
			System.out.println("Enter anything to continue the program or \"stop\" to end the program");
			input = scnr.next();
			
		}
			
		
		scnr.close();
		System.out.println("End of the program");

	}

}
