import java.util.Scanner;

// to print diamond diagram based on int input
public class Diamond {
    public static void main(String[] args) {
        System.out.print("Size: ");
        Scanner scan = new Scanner(System.in);
        Diamond d = new Diamond();
        int size = scan.nextInt();
        d.printDiamond(size);                
    }

    // top level
    private void printDiamond(int s) {
        top(s);
        middle(s);
        bottom(s);
    }

    public void top(int s) {
        for(int i = 0; i < s; i++) {
            printstep(s-i);
            printline(i);
            System.out.println();  
        }
    }

    public void middle(int s) {
        for(int i = 0; i < s; i++)
            printline(s);
            System.out.println();
    }

    public void bottom(int s){

    }

    public void printstep(int s, int l) {
        
    }
}