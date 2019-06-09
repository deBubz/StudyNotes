import java.util.*;

public class Store {
    private CashRegister cashRegister;
    private LinkedList<Product> products = new LinkedList<Product>();

    public static void main(String[] args) {
        new Store().use();
    }

    public Store() {
        cashRegister = new CashRegister();
        products.add(new Product("Whiteboard Marker", 85, 1.50f));
        products.add(new Product("Whiteboard Eraser", 45, 5.00f));
        products.add(new Product("Black Pen", 100, 1.50f));
        products.add(new Product("Red Pen", 100, 1.50f));
        products.add(new Product("Blue Pen", 100, 1.50f));
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
        System.out.print("Choice (s/r/v/c/p/x): ");
        return In.nextChar();
    }

    private void sell() {
        //does it exist loop
        Product product = product(readName());
        if (product != null) {
            System.out.println("Selling " + product.getName());
            int stock = readNumber();
            if(product.has(stock))
                cashRegister.add(product.sell(stock));
            else System.out.println("Not enough stock");
        }
        else System.out.println("No such product");
    }

    private void restock() {
        Product product = product(readName());
        if (product != null) {
            System.out.println("Restocking " + product.getName());
            product.restock(readNumber());
        }
    }

    private void viewStock() {
        for(Product prod : products) {
            System.out.println(prod.toString());
        }
    }

    private void viewCash() {
        System.out.println(cashRegister.toString());
    }

    private void pruneProducts() {
        LinkedList<Product> emptyProd = new LinkedList<Product>();
        for(Product prod : products) {
            if(prod.isEmpty()) {
                emptyProd.add(prod);
            }
        }
        if(emptyProd.size() != 0){
            for(Product prod : emptyProd) {
                products.remove(prod);
            }
        }
    }

    private String readName() {
        System.out.print("Name: ");
        return In.nextLine();
    }

    private double readPrice() {
        System.out.print("Price: $");
        return In.nextDouble();
    }

    private int readNumber() {
        System.out.print("Number: ");
        return In.nextInt();
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

    private LinkedList<Product> product(String name) {
        for( Product prod : products) {
            if(prod.getName().toLowerCase().equals(name.toLowerCase())) {
                return prod;
            }
        }
        return null;
    }

    // private Product product(String name) {
    //     for( Product prod : products) {
    //         if(prod.getName().toLowerCase().equals(name.toLowerCase())) {
    //             return prod;
    //         }
    //     }
    //     return null;
    // }
}
