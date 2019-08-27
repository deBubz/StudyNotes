public class Account  {

    private double bal;

    public Account() {
        bal = readBal();
    }

    private double readBal(){
        System.out.print("Balance: ");
        return 0;
    }
    
    private double readAmount() {
        System.out.print("Amount: ");
        return 0;
    }

    public void deposite() {
        bal += readAmount();
    }

    public void withdraw() {
        
    }

    public void show() {
        
    }

    
}