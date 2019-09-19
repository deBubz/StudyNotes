import java.util.*;
    /**
 * Store
 */
public class Store {

    // main method 
    public static void main(String[] args) {
        new Store().use();
    }

    /// 2fields]
    private CashRegister cashRegister;
    private Product product;

    //const
    public Store(){
        cashRegister = new CashRegister();
        product = new Product("Sticky tape", 200, 2.99);
    }

    // menu methods
    public void use() {
        char sel;
        while((sel = charSelect()) != 'x'){
            switch (sel) {
                case 's': sell(); break;
                case 'r': restock(); break;
                case 'v': viewStock(); break;
                case 'c': viewCash(); break;
                default: help(); break;
            }
        }
    }

    public char charSelect() {
        System.out.print("Choice (s/r/v/c/x): ");
        return In.nextChar();
    }

    // normal methods
    public void sell() {
        int amt = readNum();
        if(product.has(amt)){
            cashRegister.sold(product.sell(amt));
        }
        else System.out.println("Not enough stock");
    }

    public void restock() {
        product.restock(readNum());
    }

    public void viewStock() {
        System.out.println(product);
    }

    public void viewCash() {
        System.out.println(cashRegister.toString());
    }

    public int readNum(){
        System.out.print("Number: ");
        return In.nextInt();
    }

    public void help(){
        System.out.println("Menu Options"); 
        System.out.println("s = sell"); 
        System.out.println("r = restock");
        System.out.println("v = view stock");
        System.out.println("c = view cash");
        System.out.println("x = exit");
    }
}