/**
 * The Selection Sort algorithm, on arrays of size 4.
 * 
 * SKELETON FOR LAB TEST: Students modify method "selSort04".
 * 
 * @author Raymond Lister 
 * @version April 2015
 */
public class SelSortSize04
{
    /**
     * Swaps the values stored at two POSITIONS of an array.
     * 
     * You MUST use this method in your solution to method
     * selSort04.
     * 
     * Do NOT change this method.
     * 
     * This method, or a method that performs the same
     * function, may be examinable in the final exam.
     * (But the debug "print" statements are NOT examinable.)
     *
     * @param   x           An array of integers
     * @param   position1   A valid position in the array "a"
     * @param   position2   A valid position in the array "a".
     */
    private static void swapPositions(int [] x, int position1, int position2)
    {
        // The next three lines are debug output; not examinable in final exam.
        System.out.print("swapPositions(");
        MinMax.printArray(x);
        System.out.print(", " + position1 + ", " + position2 + "); ");

        // If you have to write this method in the final exam,
        // you will only have to provide something equivalent
        // to the three lines of code below.  You will NOT have
        // to provide the debug output.

        int temp     = x[position1];
        x[position1] = x[position2];
        x[position2] = temp;

        // The next three lines are debug output; not examinable in final exam.
        System.out.print("array now ");
        MinMax.printArray(x);
        System.out.println();

    } // method swapPositions

    /**
     * Sorts an array of 4 integers using the Selection Sort Algorithm.
     *
     * The Selection Sort Algorithm is examinable in
     * the final exam.  However, if you are examined on
     * the Selection Sort Algorithm, it is likely to be on
     * the version of Selection Sort taught later in
     * semester, the version which uses loops, not this version.
     * 
     * @param   a   An array of 4 elements 
     */
    public static void selSort04(int [] a)
    {
        /* 
         * do NOT change any code ABOVE this comment
         */

        // Insert your code here.
        int[] numArr = a;
        MinMax minmax = new MinMax(); 
       
        
        for(int i = 1 ; i < 4; i++)
        {
                int minPos = minmax.minPosition(numArr, i-1, 3);
                swapPositions(a, i-1,minPos);
        }
        
        
        
        // Your solution MUST use the methods:
        // 1. "swapPositions" given above in this same class.
        // 2. "minPosition" in the class "MinMax".
        //
        // In this lab test, you can provide a solution using
        // EITHER constant subscripts OR variable subscripts.
        // However, using variable subscripts will prepare you
        // better for a later lab test. 
        // That later lab test will use loops.  If you already
        // know about loops you may use them in this lab
        // exercise.  PLATE is only checking the output from
        // your code.  It does not examine your code.

        /* 
         * do NOT change any code BELOW this comment
         */

        // Do NOT remove the following "debug" statement.
        // It is included to help you debug your code.
        // Also, plate expects to see this output.
        // If you have to write this method in the final exam, you
        // will NOT have to provide this "debug" statement.
        debug(a);

    } // method Selection Sort Skeleton For Lab Test

    /* This method generates output that is useful
     * when debugging selSort04.
     * 
     * Also, plate EXPECTS to see the output generated by this method.
     * 
     * Do NOT change this method.
     * 
     * At the time you complete this lab exerise on 
     * selSort04, you are NOT expected to understand the
     * code in this method.
     * 
     * This method is NOT examinable in the final exam.
     */
    private static void debug(int [] x)
    {   
        System.out.println();
        System.out.println("Final state of array is: ");
        MinMax.printArray(x);
        System.out.println();

        if ( MinMax.isSorted(x,0,x.length-1) == 1 )
        {
            System.out.println("The array is sorted!");
            System.out.println("But we haven't checked if the array contains the same numbers as it originally did.");
            System.out.println("Short of testing a piece of code on all legal inputs,");
            System.out.println("no amount of testing can PROVE that a piece of code is bug free.");
        }
        else
            System.out.println("The array is NOT sorted!");
            
    } // method debug
}
