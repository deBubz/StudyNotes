import java.text.*;
/**
 * CashRegister
 */
public class CashRegister {
    private double cash;

    public CashRegister(){
        this.cash = 0;
    }

    //methods 
    public void sold(double payment) {
        this.cash += payment;
    }

    @Override
    public String toString() {
        if(cash != 0) return "Cash register: $" + format(cash);
        else return "Cash register: empty";
    }
    
    private String format(double d) {
        return new DecimalFormat("###,##0.00").format(d);
    }
}