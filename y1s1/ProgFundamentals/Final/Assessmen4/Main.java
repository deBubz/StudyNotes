
/**
 * Write a description of class Main here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Main
{

    public static void main( String [] args )
    {
        World game = new World();
        
        game.armiesSetUp(game.getPlayer1());
        game.armiesSetUp(game.getPlayer2());
        
    }
}
