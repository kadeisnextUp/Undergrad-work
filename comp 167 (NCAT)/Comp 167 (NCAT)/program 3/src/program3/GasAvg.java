package program3;

import java.io.File;
import java.io.FileNotFoundException; 
import java.util.Scanner;

public class GasAvg {
	public static double LowAvg(double[] temps) {
		double low = temps[0];
		for(int i = 0; i <temps.length;i++) {
			if(temps[i]<low) {
				low = temps[i];
			}
		}
		return low;
	}
	
	public static double higAvg(double[] temps) {
		double high = temps[0];
		for(int i = 0; i <temps.length;i++) {
			if(temps[i]>high) {
				high = temps[i];
			}
		}
		return high;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String gas;
		double realGas;
		try {
			File gasAvgs = new File("1994_Weekly_Gas_Averages.txt");
			Scanner reader = new Scanner(gasAvgs);
			while(reader.hasNext()) {
				
				
				double[] numAvgs = new double[52] ;
				
				for(int k =0; k < numAvgs.length;k++) {
					gas = reader.nextLine();
					realGas = 
					
					numAvgs[k] = gas;
				}
			}
		}
		
		
		

	}

}
