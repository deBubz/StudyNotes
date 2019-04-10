public class StretchWith2Vowels {
    public static void main(String[] args) {   // main 
        String sent = readSentence();
        
        while(!sent.contains("*")){
            System.out.println("Matching words = " + countWord(sent));
            sent = readSentence();
        }
    }

    //------------------------------------------------------
         
        // count the words that match in this sentence
    public static int countWord(String sent){ //count total LV2
        int count = 0;
        sent = sent.toLowerCase();
        for(String word: sent.split(" +")){
           if (wordZCheck(word)) count++ ; 
        }
        return count;
    }
    
    // does this word have a z bloc
    public static boolean wordZCheck(String word){  // CHECK PATTERN
        if (word.contains("z")) {
            return subStringCheck(word);
        }
        else return contain2Vowels(word);
    }

    public static boolean subStringCheck(String word) {

        // ------------------
        int charCount = 0;
        int zstart = 0;

        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'z') {
                if(charCount < 2) {
                    charCount = 0;
                    zstart = i+1;
                }
                else {
                    //if (zstart != 0) zstart++;  zstart!=0? zstart ++: zstart
                    //zstart = i;
                    //String testWord = word.substring(zstart, zstart+charCount);
                    if( contain2Vowels(word.substring(zstart, zstart+charCount))) return true;
                    else charCount = 0;
                }
            }
            else charCount++;
        }

        if (charCount >= 2) {
            return contain2Vowels(word.substring(zstart));
        }
        else return false;
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
