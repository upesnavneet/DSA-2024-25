
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        scanner.close();

        if (word.equals(word.toUpperCase()) || 
            (word.length() > 1 && word.substring(1).equals(word.substring(1).toUpperCase()) && Character.isLowerCase(word.charAt(0)))) {
            StringBuilder flipped = new StringBuilder();
            for (char c : word.toCharArray()) {
                if (Character.isUpperCase(c)) {
                    flipped.append(Character.toLowerCase(c));
                } else {
                    flipped.append(Character.toUpperCase(c));
                }
            }
            System.out.println(flipped.toString());
        } else {
            System.out.println(word);
        }
    }
}
