import java.text.DecimalFormat;

/**
 * Account
 */
public class Account {
    // fieds
    private double balance;
    private String type;

    // constructor
    public Account(String type) {
        this.type = type;
        System.out.print("Initial "+ type +" Balance: ");
        this.balance = In.nextDouble();
    }
    
    //methods
    public void deposite(double dep) {
        balance += dep;
    }

    public void withdraw(double dep) {
        balance -= dep;
    }

    public void transfer(Account to, double amt) {
        balance -= amt;
        to.balance += amt;
    }

    public void show() {
        System.out.println(this);
    }

    public boolean has(double amt) {
        return balance > amt;
    }

    //override
    @Override
    public String toString() {
        return type + " Account has $" + format(balance);
    }

    private String format(double amt) {
        return new DecimalFormat("###,##0.00").format(amt);
    }
}