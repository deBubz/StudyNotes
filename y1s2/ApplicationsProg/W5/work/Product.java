import java.text.*;
/**
 * Product
 */
public class Product {
    private String name;
    private int stock;
    private double price;

    //const
    public Product(String n, int s, double p){
        this.name = n;
        this.stock = s;
        this.price = p;
    }
    
    // methods

    // sell 
    // return total
    public double sell(int qnt) {
        stock -= qnt;
        return qnt * price;
    }

    public boolean has (int qnt) {
        if(stock >= qnt) return true;
        else return false;
    }

    // add more stock
    public void restock(int amt) {
        this.stock += amt;
    }

    @Override
    public String toString() {
        return stock + " " + name + " at $" + format(price);
    }

    private String format(double d) {
        return new DecimalFormat("###,##0.00").format(d);
    }

}