
/**
 * Write a description of class Player here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Player
{
    // Fields
    private String name;
    private int unplacedArmies = 3;
    private static int count = 0;
   // static 

   public int getUnplacedArmies() {return unplacedArmies;}
    /**
     * Constructor for objects of class Player
     */
    public Player()
    {
        System.out.print("Enter player " + (count + 1) + "'s name: ");
        name = World.keyboard.next();
        count ++;
    }

    /**
     * player toString
     * @return    player name
     */
    
    public String toString()
    {
        return name;
    }
    
    public void placeArmies(int placed)
    {
        unplacedArmies -= placed;
    }

}
