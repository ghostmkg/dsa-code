package strings;

public class LongestWordFinder {

    public static void main(String[] args) {
        // Example input string
        String sentence = "I am learning Java programming language";

        // Call the method to find the longest word
        String longestWord = findLongestWord(sentence);

        // Output the longest word
        System.out.println("The longest word is: " + longestWord);
    }

    // Method to find the longest word in a sentence
    public static String findLongestWord(String sentence) {
        // Split the sentence into words
        String[] words = sentence.split(" ");

        // Initialize the longest word
        String longestWord = "";

        // Loop through the words to find the longest one
        for (String word : words) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }

        return longestWord;
    }
}