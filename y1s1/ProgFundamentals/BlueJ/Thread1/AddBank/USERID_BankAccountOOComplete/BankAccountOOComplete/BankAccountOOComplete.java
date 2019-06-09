/**
 * This Object-Oriented" version of the "BankAccount" class
 * is a simple introduction to Constructors / 
 * private data members / static vs. not static / and the
 * "toString" method. 
 * 
 * SKELETON FOR LAB TEST.
 * 
 * @author Raymond Lister
 * @version September 2015;
 */

public class BankAccountOOComplete
{
    private static double interestRate = 0.0;
    private final int accountNumber;
    private String accountName;
    private double balance;

    /**
     *   The constructors now follow
     */

    /**
     * @param    num  number for the account
     * @param    name name of the account
     */
    public BankAccountOOComplete(int num, String name)
    {
        this.balance = 0;
        this.accountNumber = num;
        this.accountName = name;
    } 

    /**
     * @param    num    number for the account
     * @param    name   name of the account
     * @param    bal    opening balance
     */
    public BankAccountOOComplete(int num, String name, double bal)
    {
        this.balance = bal;
        this.accountNumber = num;
        this.accountName = name;
    } 

    /**
     * @return     The account number 
     */
    public int getAccountNumber()       
    {
        return this.accountNumber;
    }

    /**
     * @return   The name for the account 
     */
    public String getAccountName()
    {
        return this.accountName;
    }

    /**
     * @param   newName The new name for the account 
     */
    public void setAccountName(String newN)
    {
        this.accountName = newN;
    }

    /**
     * @return     The account balance 
     */
    public double getBalance()
    {
        return this.balance;
    }

    /**
     * @param   amount  To be added to the balance
     */
    public void deposit(double amt)  
    {
        this.balance += amt;
    }

    /**
     * The withdrawal should be refused if the withdrawal
     * would result in a negative balance.
     * 
     * @param   amount  The amount to be withdrawn
     *
     * @return  new balance or -1.0 if withdrawal refused
     */
    public double withdraw(double amt)
    {  
        if(amt > this.balance)
        {
            return -1;
        }
        
        this.balance -= amt;
        
        return this.balance;
    }

    /**
     * @return   The interest rate 
     */ 
    public static double getInterestRate()
    {
        return interestRate;
    }

    /**
     * @param   newInterest    The new interest rate 
     */
    public static void setInterestRate(double newInterest)
    {
        interestRate = newInterest;
    }

    /**
     * It is common practise to supply a "toString" method 
     * in an object-oriented class.  In fact, if you don't 
     * explicitly supply such a method, Java produces an 
     * implicit, simplistic "toString" method which produces
     * a String like "BankAccountOO@1edd1f0". The word before 
     * the "@" is the name of the class. The hexadecimal 
     * number after the "@" is called the objects "hash code". 
     * 
     * See Nielsen, page  78,
     *          section "5.2.4 The toString Method"
     * See Nielsen, page 165,
     *          section "8.2.1 Overriding the toString Method"
     * 
     *@return   The state of this "instance of class BankAccount" or "object", the accountNumber, accountName and balance  
     */
    public String toString()
    {
        return "accountNumber = " + this.accountNumber + 
               " accountName = " + this.accountName +
               " balance = " + this.balance;
    }

} // class BankAccountOOComplete
