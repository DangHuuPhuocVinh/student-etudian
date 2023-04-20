package W03_Ex4_1752052;

public class Palindrome {
	static boolean isPalindrome(String sentence) {
        boolean flag = true;
        int temp = sentence.length() - 1;
        
        for (int i = 0; i < (sentence.length() / 2.0); i++) {
            if (sentence.charAt(i) != sentence.charAt(temp))
                flag = false;
            temp--;
        }
        return flag;
}
}
