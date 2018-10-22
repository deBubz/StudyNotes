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
    private Player player1, player2;
    
    private Territory territory1, territory2, territory3, territory4;
    
    public static final Scanner keyboard = new Scanner(System.in);

    public Player getPlayer1() {return player1;}
    public Player getPlayer2() {return player2;}
    
    public Territory getTerritory1() {return territory1;}
    public Territory getTerritory2() {return territory2;}
    public Territory getTerritory3() {return territory3;}
    public Territory getTerritory4() {return territory4;}
    
    /** Constructor for objects of class World
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

    public String toString()
    {
        //“[0,0]Joe(1) [1,0]null(0) [0,1]Sam(0) [1,1]null(0)” 
        // terr1 terr2 terr3 terr4
        return  String.format("%1$s %2$s %3$s %4$s", territory1.toString(), territory2.toString(), territory3.toString(), territory4.toString());
    }
    
    public void prompt(String message) { System.out.println(message);}
    public void list() { prompt(toString());}
    public void fullPrompt(String message) {
        prompt(message); 
        list();
    }
    public void rmArmies(Territory ter){ ter.removeArmies(); }

    //---------------------------------------B A S E ----------------------------------------------
    /** Game start   
     *  @retn printout status of thegame  
     */
    
    public void placeArmies(Player player)
    {   
        fullPrompt(String.format("You have %d armies to place.", player.getUnplacedArmies()));
        while(player.getUnplacedArmies() != 0)
        {
            Territory territory = territoryPrompt();
            
            if(territory.owner == player || territory.owner == null)
            {
                if(territory.owner == null) player.addTerritory();
                territory.placeArmies(player, 1);
                player.placeArmies(1);
            }
            
            list();
        }
    }
    
    /** return territory from coordinate values
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
    
    /**promt to ENTER TERRITORY COODRINATES
     * @return territory
     * return null if -1 is entered
     *  */
    public Territory territoryPrompt()  
    {
        int column, row; 
        System.out.print("Select a territory: ");

        column = keyboard.nextInt();    // first input
        if(column == -1) return null;   // return null if input is -1; 
        row = keyboard.nextInt();       // 2nd input

        return this.checkTerritory(column, row);    // found territory
    }


    // --------------------------------------------------------------------------------------------------
    public void transfer(Player player) 
    {
        boolean switcher = true;
        fullPrompt("Select source/target territories for a transfer.");
        while (switcher) {
            switcher = transferTask(player);
        }
    }    // TASK 2
    
    public boolean transferTask(Player player)
    {
        Territory select = territoryPrompt(); //select 
        if(select == null) return false; // if input is -1
        if(select.owner != player ) return true; // if 
        Territory transfer = territoryPrompt(); // transfer to
        rmArmies(select);
        transfer.placeArmies(player,1);
        list();
        return true;
    }
    // -----------------------------------------------------------------------------------------------------
    public boolean selectTask(Player player)
    {
        Territory select = territoryPrompt(); //select 
        if(select == null) return false; // stop if input is -1
        if(select.owner != player ) return true; //  repeat if you didnt select your own
        // transfer to
        return true;
    }

    public void attack(Player player)
    {
        fullPrompt("Select source/target territories for an attack.");
        
        Territory select = territoryPrompt();

        attacking(select);
    }

    public void attacking(Territory ter){
        boolean selectSwitch = true;
        Territory select = ter;
        while(selectSwitch){
            selectSwitch = attackTarget(select);
            if(selectSwitch){
                selectSwitch = attackTarget(select);
                if(select == null) return;
            }
            else return;
        } 
    }
    
    public void attackTest(boolean selectSwitch, Territory select){
        if(selectSwitch){
            selectSwitch = attackTarget(select);
        }
        else return;
    }

    public boolean attackTarget(Territory attacker)
    {   
        Territory target = territoryPrompt();
        if(target == null) { return false; }
        
        // attacking 
        rmArmies(attacker);
        rmArmies(target);
        list();
        return true;
    }

    // ----------------------------------------------------------------
    public void turn(Player player)
    {
        if(player.getTurn() == 0)
        {
            prompt(String.format("%s\'s turn.", player));
            placeArmies(player);
            player.nextTurn();
        }
        else
        {
            prompt(String.format("%s\'s turn.", player));
            player.giveArmies();
            placeArmies(player);
            attack(player);
        }
        
    }
}
