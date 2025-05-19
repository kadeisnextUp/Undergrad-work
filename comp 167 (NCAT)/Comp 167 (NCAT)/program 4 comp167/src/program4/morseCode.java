package program4;

import java.util.Scanner;

public class morseCode {
	// this method takes a string as input and uses a array of chars that represented every possible character
	// in morse code and a array of the corresponding actual morse code as strings
	// the nested for loop will look at each string index in the input and find the corresponding morse code
	public static String stringToMorse(String change) {
		String morseCode = "";
		// length of both arrays is 40
		char[] characters = {'A', 'B' ,'C' ,'D' ,'E', 'F' ,'G', 'H', 'I', 'J', 'K' ,
				'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z',
				'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'0' ,',' ,'.', '?',' '};
		String [] morse = {".-" ,"-...","-.-.","-..",".","..-.","--.","....","..",".---",
				"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
				".--","-..-","-.--","--..",".----","..---","...--","....-",".....",
				"-....","--...","---..","----.","-----", "--..--",".-.-.-","..-.."," "};
		
		String upChange = change.toUpperCase();
		for(int k  = 0; k < upChange.length();k++) {
			for (int i = 0; i < characters.length;i++) {
				if(upChange.charAt(k) == characters[i]) {
					morseCode = morseCode + morse[i];
					
				}
			}
			
		}
		
		return morseCode;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.?";
		Scanner scnr = new Scanner(System.in);
		String message = "";
		String input = "";
		String fault = "";
		while(input.equals("stop")== false) {
			System.out.println("Enter a message to change into morse code");
			message = scnr.nextLine();
			System.out.println("You entered "+ message);
			String morse = stringToMorse(message);
			if(morse == "") {
				for(int k = 0; k < message.length(); k++) {
					if(characters.indexOf(message.charAt(k),0) == -1) {
						fault = fault + message.substring(k,k+1);
					}
				}
				
				
			}
			else {
				System.out.println("The morse code is " + morse);
			}
			
			System.out.println("Enter \"stop\" to stop this program or anything else to continue");
			input = scnr.next();
			
			
		}
		scnr.close();
		
		System.out.println("End of program");

	}

}
