package AppliedMath;

import java.util.Scanner;

public class W01_solution {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		//01
		trig();
		
		//02
		voltage();
		}	
	
	public static void printTriangle() {
//		System.out.print(" *");
		System.out.println();
		final int H = 7;
		String sym = "";
		for (int i = 0; i<H; i++) {
			sym += ".~*";
			for (int j = H; j > i; j--) {
				System.out.print("   ");
				
			}
			System.out.print(sym.substring(0,sym.length()-1)+"|");
			System.out.println();
//			System.out.print(" *");
		}
	}
	
	public static void trig() {
		printTriangle();
		System.out.print("Enter distance to tower: ");
		double dist = sc.nextDouble();

		System.out.print("Enter angle of elevation: ");
		double deg = sc.nextDouble();
		trigCalc(dist, deg);

	}
	public static double trigCalc(double dist, double deg) {
		deg = Math.toRadians(deg);


		double height = (Math.sin(deg)/Math.cos(deg)) * dist;
		
		height = Math.round(height * 100)/100.0;
		System.out.println("Height of tower is " +height+" M");
		return height;
	}

}




/*
 *                              .~|
 *                           .~*.~|
 *                        .~*.~*.~|
 *                     .~*.~*.~*.~|
 *                  .~*.~*.~*.~*.~|
 *               .~*.~*.~*.~*.~*.~|
 *            .~*.~*.~*.~*.~*.~*.~|
 *         .~*.~*.~*.~*.~*.~*.~*.~|
 *
 */
