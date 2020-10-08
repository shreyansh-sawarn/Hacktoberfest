import java.util.ArrayList;
import java.util.Scanner;

public class PhoneNumberCombinations {
    private static final String[] COMBO = { "0", "1", "ABC", "DEF", "GHI",
            "JKL", "MNO", "PQRS", "TUV", "WXYZ"
    };

    public static void main(String[] args) {
        ArrayList<String> result = null;
        Scanner in = new Scanner(System.in);
        System.out.println("Input Phone Number (No hyphens):");
        String num = in.next();
        result = getLetterCombinations(num, "", 0);
        System.out.print("Combinations: ");
        System.out.println(result);
    }

    /**
     * Recursive function to get the letter combinations of a number.
     * @param number the numbers to get the letter combinations for
     * @param current the current string of letter combination
     * @param index the index to be looked at
     * @return the letter combinations of a number
     */
    public static ArrayList<String> getLetterCombinations(String number, String current, int index) {
        ArrayList<String> result = new ArrayList<String>();

        if (index == number.length()) {
            result.add(current);
            return result;
        }
        else {
            String letters = COMBO[number.charAt(index) - '0'];

            for (int i = 0; i < letters.length(); i++) {
                //PROC -- This allows us to get each possible result.
                ArrayList<String> possibleResults = getLetterCombinations(number, current + letters.charAt(i), index+1);
                for (String s: possibleResults) {
                    result.add(s);
                }
            }
        }
        return result;
    }
}