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
    
    public void prompt(String message)
    {
        System.out.println(message);
        System.out.println(toString());
    }
    
    /**
     * use to place armies into territory
     *  
     *  @retn printout status of thegame  
     */
    
    public void placeArmies(Player player)
    {   
        prompt("You have "+ player.getUnplacedArmies() +" armies to place.");
        
        while(player.getUnplacedArmies() != 0)
        {
            Territory territory = territoryPrompt();
            
            if(territory.getOwner() == player || territory.getOwner() == null)
            {
                territory.placeArmies(player, 1);
                player.placeArmies(1);
            }
            
            System.out.println(this.toString());
            //System.out.println("=== " + player.getUnplacedArmies());
        }
    }
    
    /**
     * return territory from coordinate values
     *  */
    public Territory checkTerritory(int col, int row) 
    {
        if(col == 0)
        {
            if(row == 0) return territory1;
            else return territory3;
        }
        else
        {
            if(row == 0) return territory2;
            else return territory4;
        }
    }
    
    /**
     * promt to ENTER TERRITORY COODRINATES
     * if enter -1 null is returned
     * @return Found territory
     * 
     *  */
    public Territory territoryPrompt()  
    {
        int column, row;
            
        System.out.print("Select a territory: ");
        column = keyboard.nextInt();
        if(column == -1) return null; // return null if input is -1; 
        row = keyboard.nextInt();

        return this.checkTerritory(column, row);
    }
    
    public void transfer(Player player)
    {
        boolean switcher = true;
        prompt("Select source/target territories for a transfer.");
        while (switcher) {
            switcher = transferTask(player);
        }
        //if(select.getOwner() == player) System.out.print("FOUNDHIM");
        //else System.out.print("FALSE ALARM");
    }
    
    public boolean transferTask(Player player)
    {
        Territory select = territoryPrompt(); //select 
        if(select == null) return false; // if input is -1
        if(select.getOwner() != player ) return true; // if 
        Territory transfer = territoryPrompt(); // transfer to
        select.removeArmies();
        transfer.placeArmies(player,1);
        System.out.println(toString());
        return true;
    }
}
