/**
 * Customer
 */
public class Customer {
    public static void main(String[] args) { //main
        new Customer().use();
    }

    // fields
    private Account savingsAcc;
    private Account loansAcc;

    // constructor
    public Customer(){
        savingsAcc = new Account("Savings");    
        loansAcc = new Account("Loans");
    }

    //use
    public void use() {
        char choice;

        while((choice = readChoice()) != 'x') {
            switch (choice) {
                case 'd': deposite(); break;
                case 'w': withdraw(); break;
                case 't': transfer(); break;
                case 's': show(); break;
            
                default: help(); break;
            }
        }

    }

    public char readChoice() {
        System.out.println("Customer menu (d/w/t/s/x): ");
        return In.nextChar();
    }

    //methods]
    public void deposite() {
        savingsAcc.deposite(readAmt("deposite"));
    }

    public void withdraw() {
        double amt = readAmt("withdraw");
        if(savingsAcc.has(amt)) savingsAcc.withdraw(amt);
        else System.out.println("insufficient funds");
    }

    public void transfer() {
        double amt = readAmt("transfer");
        if(savingsAcc.has(amt)) savingsAcc.transfer(loansAcc,amt);
        else System.out.println("insufficient funds");
    }

    public double readAmt(String act) {
        System.out.print("Amount to " + act + ": $");
        return In.nextDouble();
    }

    public void show() {
        System.out.println(savingsAcc);
        System.out.println(loansAcc);
    }

    public void help() {
        System.out.println("Menu Options:");
        System.out.println("Deposite");
        System.out.println("Withdraw");
        System.out.println("Transfer");
        System.out.println("View");
        System.out.println("Exit");
    }

}