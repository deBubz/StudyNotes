import java.util.*;

public class Store {
    private CashRegister cashRegister;
    private LinkedList<Product> products = new LinkedList<Product>();

    public Store() {
        use();
    }
    // (s/r/v/c/p/x)
    private void use() {
        char ch;
        while((ch = readChoice()) != 'x') {
            switch (ch) {
                case 's':   sell();     break;
                case 'r':   restock();  break;
                case 'v':   viewStock();break;
                case 'c':   viewCash(); break;
                case 'p':   pruneProducts();    break;
                default:    help();     break;
            }
        }
    }

    private char readChoice() {
        System.out.print("Choice (s/r/v/c/p/x):");
        return In.nextChar();
    }

    private void sell() {
    }

    private void restock() {
    }

    private void viewStock() {
    }

    private void viewCash() {
    }

    private void pruneProducts() {
    }

    private String readName() {
        return "No Name";
    }

    private double readPrice() {
        return 0.0;
    }

    private int readNumber() {
        return 0;
    }

    private void help() {
        System.out.println("Menu options");
        System.out.println("s = sell");
        System.out.println("r = restock");
        System.out.println("v = view stock");
        System.out.println("c = view cash");
        System.out.println("p = prune products");
        System.out.println("x = exit");
    }
}
