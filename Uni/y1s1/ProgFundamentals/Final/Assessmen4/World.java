import java.util.Scanner;

/**
 * Write a description of class World here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class World
{
    // instance variables - replace the example below with your own
    private Player player1;
    private Player player2;
    
    private Territory territory1;
    private Territory territory2;
    private Territory territory3;
    private Territory territory4;
    
    public static final Scanner keyboard = new Scanner(System.in);

    public Player getPlayer1() {return player1;}
    public Player getPlayer2() {return player2;}
    
    public Territory getTerritory1() {return territory1;}
    public Territory getTerritory2() {return territory2;}
    public Territory getTerritory3() {return territory3;}
    public Territory getTerritory4() {return territory4;}
    
    /**
     * Constructor for objects of class World
     */
    public World()
    {
        territory1 = new Territory(0, 0);
        territory2 = new Territory(1, 0);
        territory3 = new Territory(0, 1);
        territory4 = new Territory(1, 1);
        
        player1 = new Player();
        player2 = new Player();
    }

    /**
     *  toString method
     *  
     *  @retn printout status of thegame  
     */
    public String toString()
    {
        //“[0,0]Joe(1) [1,0]null(0) [0,1]Sam(0) [1,1]null(0)” 
        // terr1 terr2 terr3 terr4
        return  territory1.toString() + " " +
                territory2.toString() + " " +
                territory3.toString() + " " +
                territory4.toString();
    }
    
    /**
     * use to place armies into territory
     *  
     *  @retn printout status of thegame  
     */
    
    public void placeArmies(Player player, Territory ter )
    {
        //placeArmiesPrompt(player);
        System.out.print("How many armies would you like to place on "+ter.toString()+"? ");
        int placedArmies = keyboard.nextInt();
        
        ter.placeArmies(player, placedArmies); // place armies in territory
        player.placeArmies(placedArmies); // reduce unsetarmies.
        System.out.println( this.toString() );
    }
    
    
    public void armiesSetUp(Player player)
    {
        System.out.println(player.toString() + ", please place your armies");
        System.out.println( this.toString() );
        
        Territory holder1 = territory1;
        Territory holder2 = territory2;
        if(player == player2)
        {    
            holder1 = territory3;
            holder2 = territory4;
        }

        
        placeArmies(player, holder1);
        placeArmies(player, holder2);
    }
}
