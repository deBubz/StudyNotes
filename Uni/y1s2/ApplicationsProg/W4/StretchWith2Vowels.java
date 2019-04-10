public class StretchWith2Vowels {
    public static void main(String[] args) {   // main 
        String sent = readSentence();
        
        while(!sent.contains("*")){
            System.out.println("Matching words = " + countPattern(sent));
            sent = readSentence();
        }
    }

    //------------------------------------------------------
         
        // count the words that match in this sentence
    public static int countPattern(String sent){ //count total LV2
        int count = 0;
        for(String word: sent.split(" +")){
           if (wordZCheck(word)) count++ ; 
        }
        return count;
    }
    
    // does this word have a z bloc
    public static boolean wordZCheck(String word){  // CHECK PATTERN
        if (word.contains("z")) {
            return subStringCheck(word.substring(word.indesOf('z')+1 ,word.length()));
        }
        else return contain2Vowels(word);
    }

    public static boolean subStringCheck(String word) {
        charCount = 0;
    
        if (word.contains("z")) {
            for (int i = 0; i < word.length(); i++) {
            
            }
            return false;
        }
        else return contain2Vowels(word);
    }
    
    //---------------------------------------------------------------

    // does this word have 2 vowels OK
    public static boolean contain2Vowels(String part) { // lv 4
        int count = 0;
        for(int i = 0; i < part.length() ; i++) {
            if(isVowel(part.charAt(i))) count++;
        }
        return count == 2;
    }
    
    // is this char a vowel OK
    public static boolean isVowel(char c){ //  lvl 5
        return "aeiou".contains(c + "");
    }
    
    // READ LOOP
    public static String readSentence(){
        System.out.print("Sentence: ");
        return In.nextLine();
    }
}
