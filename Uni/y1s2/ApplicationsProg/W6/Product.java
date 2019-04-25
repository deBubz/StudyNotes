import java.text.*;

public class Product {
    private String name;
    private int stock;
    private double price;

    public Product(String name, int stock, double price) {
        this.name  = name;
        this.stock = stock;
        this.price = price;
    }

    public String getName() {
        return this.name;
    }

    public boolean isEmpty() {
        return stock == 0;
    }

    /**
     * Return true iff this product has at least n stock
     */
    public boolean has(int n) {
        return this.stock >= n;
    }

    /**
     * Sell n stock of this product (decrease stock by n)
     * and return the amount of money earned (price * n)
     */
    public double sell(int n) {
        this.stock -= n;
        return (double)price*n;
    }

    /**
     * Increase stock by n.
     */
    public void restock(int n) {
        this.stock += n;
    }

    @Override
    public String toString() {
        return name + " - " + stock + " at $" + formatted(price); 
    }

    private String formatted(double money) {
        return new DecimalFormat("###,##0.00").format(money);
    }
}
