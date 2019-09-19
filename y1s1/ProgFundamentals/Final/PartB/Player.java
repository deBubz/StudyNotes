
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
    private int turn = 0;
    private int territories = 0;
    private  static int count = 0;
   // static 

   public int getTurn() { return turn;}
   public int getUnplacedArmies() {return unplacedArmies;}

    /** Constructor for objects of class Player
     */
    public Player()
    {
        System.out.print(String.format("Enter player %d\'s name: ", count+1));
        name = World.keyboard.next();
        count ++;
    }

    /** player toString
     * @return    player name
     */
    
    public String toString(){ return name; }
    
    public void giveArmies(){ 
        unplacedArmies += territories; 
        System.out.println(String.format("Giving %d new armies to %s", territories , toString()));
    }

    public void placeArmies(int placed){ unplacedArmies -= placed; }

    
    public void addTerritory() {territories += 1;}

    public void looseTerritory() {territories -= 1;}

    public void nextTurn() {turn += 1;}
}
