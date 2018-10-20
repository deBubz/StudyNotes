
/**
 * Write a description of class Territory here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Territory
{
    // instance variables - replace the example below with your own
    private Player owner = null;
    private int row;
    private int column;
    private int armies = 0;
    
    public Player getOwner() { return owner;}

    /**
     * Constructor for objects of class Territory
     */
    public Territory(int c, int r)
    {
        column = c;
        row = r;
    }

    /**
     * territory tostring
     * 
     * @return    the sum of x and y
     */
    
    public String toString()
    {   //"[0,1]null(0)"  
        return "["+column+","+row+"]"+owner+"("+armies+")";
    }
    
     /**
     * innitial territory place army
     * 
     * @return    the sum of x and y
     */
    
    public void placeArmies(Player player, int placedArmies)
    {
        owner = player;
        placeArmies(placedArmies);
    }
    
    public void placeArmies(int army) { armies += army; }
    
    public void placeArmies() { armies+=1; }
    

    public void removeArmies() 
    { 
        armies -= 1;
        if(armies == 0) owner = null;
    }
    
    
    
    
}
