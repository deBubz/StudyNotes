/**
 * This Object-Oriented" version of the "BankAccount" class
 * is a simple introduction to Constructors / 
 * private data members / static vs. not static / and the
 * "toString" method. 
 * 
 * SKELETON FOR LAB TEST.
 * 
 * @author Raymond Lister
 * @version April 2015;
 */

public class BankAccountOO
{
    private static double interestRate = 0.0;
    // Note: the interest rate is "static". That is, all
    //       bank accounts have the same interest rate.
    // See Parsons page 117, 
    //             section "6.8 Static Fields and Methods"
    // See https://docs.oracle.com/javase/tutorial/java/ ... 
    //           ... javaOO/classvars.html
    // Or google java tutorial static fields

    /*
     * The instance variables follow (i.e. not static). These
     * are also called "fields? or ?private data members?.
     */

    private final int accountNumber;
    // The "final" reserved word indicates that the first 
    // value that this variable receives will be its final 
    // value; it cannot change. See http:// ...
    // en.wikipedia.org/wiki/Final_(Java)#Final_variables
    // NOTE: "final" is NOT the same thing as "static".  
    //       "final" means "constant across time"
    //       "static" means "constant across objects" 

    private String accountName;

    private double balance; // e.g. 1.27 means $1.27

    /**
     *   The constructors now follow
     */

    /**
     * @param    num  number for the account
     * @param    name name of the account
     */
    public BankAccountOO(int num, String name)
    {
        //add whatever code is required in the constructor body
        this.accountName = name;
        this.accountNumber = num;
    } 

    /**
     * @param    num    number for the account
     * @param    name   name of the account
     * @param    bal    opening balance
     */
    public BankAccountOO(int num, String name, double bal)
    {
        this.accountName = name;
        this.accountNumber = num;
        this.balance = bal;
    } 

    /*
     * A number of the methods from the "static" version 
     * have been left out of this object-oriented version.  
     * That's because Raymond did not wish to test you on 
     * those methods a second time, having already tested 
     * your knowledge of those methods in the "static"
     * version.
     * 
     * The method setAccountNumber() would definitely NOT 
     * be copied across from the static version to this 
     * object-oriented version. That's because each object 
     * represents a unique bank account.
     * The account number set up by the 
     * constructor should never change again.
     * 
     * The method setAccountName() MIGHT be copied across.  
     * That's a business decision.  Some banks might allow 
     * a customer to change their name.  Other banks might 
     * only allow a name change by creating a new account.  
     * If the account name cannot be changed, then the 
     * declaration of private data member "accountName" 
     * should have the reserved word "final" added.
     * 
     * The method withdraw() has been copied across 
     * because:
     * (1) it was provided in its entirety in the
     *     "static" version of the class,
     * (2) to provide an example that "static" is dropped 
     *     from the header,
     * (3) to provide a hint as to what changes might be 
     *     needed for the other, incomplete methods.
     */

    /**
     * The withdrawal should be refused if the withdrawal
     * would result in a negative balance.
     * 
     * @param   amount  The amount to be withdrawn
     *
     * @return  new balance or -1.0 if withdrawal refused
     */
    public double withdraw(double amount)
    {  
        if ( balance >= amount )
        {
            balance = balance - amount;
            return balance;
        }
        else
            return -1.0;
    }

    /**
     * Note that this is a static method. So a change to the
     * interest rate changes the interest rate for all objects 
     * of this class.
     *
     * @param   newInterest    The new interest rate 
     */
    public static void setInterestRate(double newRate)
    {
        interestRate = newRate;
    }

    /**
     * Note that this is a static method. 
     * 
     * @return   The interest rate 
     */ 
    public static double getInterestRate()
    {
        return interestRate;
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
     * Note: Method "toString" method is NOT "static". It 
     * can't be static, since the values in the data members 
     * may vary between objects of this class.
     * 
     * See Nielsen, page  78,
     *          section "5.2.4 The toString Method"
     * See Nielsen, page 165,
     *          section "8.2.1 Overriding the toString Method"
     * 
     *@return   The state of this "class instance" or "object"  
     */


    public String toString()
    {
        return "accountNumber = "  + accountNumber +
               " accountName = "   + accountName   +
               " balance = "       + balance;
    }

} // class BankAccountOO
