public class Permutations {
    public static void permute(String str, String ans) {
        if (str.length() == 0) {
            System.out.println(ans);
            return;
        }
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            String rest = str.substring(0, i) + str.substring(i + 1);
            permute(rest, ans + ch);
        }
    }

    public static void main(String[] args) {
        permute("ABC", "");
    }
}
