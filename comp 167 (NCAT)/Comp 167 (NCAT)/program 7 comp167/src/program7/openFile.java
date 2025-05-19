package program7;

import java.util.Scanner;
// imports input and output classes
import java.io.*;

public class openFile {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scnr = new Scanner(System.in);
		Scanner fileScan = null;
		FileInputStream fileIn = null;
		FileOutputStream fileOut = null;
	    PrintWriter outFS = null;
		String fileName1;
		String fileName2;
		
		try {
			System.out.println("What is the name of your  first file?");
			fileName1 = scnr.nextLine();
			System.out.println("What is the name of your second file?");
			fileName2 = scnr.nextLine();
			System.out.println("Now opening " + fileName1 + " and "+ fileName2);
			// while testing the files I made it couldn't open the files unless I put the path in not sure if its
			// a issue on my laptop or the program
			fileIn = new FileInputStream(fileName1);
			fileScan = new Scanner(fileIn);
			
			fileOut = new FileOutputStream(fileName2);
			outFS = new PrintWriter(fileOut);
			// goes through each line of first file and writes it in the second file with all contents uppercased
			while(fileScan.hasNext()) {
				outFS.println(fileScan.nextLine().toUpperCase());
			}
			fileScan.close();
			outFS.close();
		}
		//if the file can not be found
		catch (FileNotFoundException e) {
	      System.out.println("File not found either because it doesn't exist or you didn't enter the name correctly");
	      // shows exactly where the error occurred
	      
	    }
		
		scnr.close();
		System.out.println("End of program check your second second file to see the new text if you didn't receive an error.");

	}

}
