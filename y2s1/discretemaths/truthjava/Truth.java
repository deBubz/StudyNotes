/**
 * Truth
 */
public class Truth {
    public static void main(String[] args) {
        Boolean question;        
        // Edit your question here
        question = NOT(true);
        // ignore below
    
        System.out.println(question.toString());
    }

    private Boolean AND(Boolean p, Boolean q){
        return p && q;
    }

    private static Boolean OR(int p, int q){
        return false;
    }

    private static Boolean NOT(Boolean a) {
        return !a;
    }


}