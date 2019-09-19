/**
 * Simple utility functions used by the Selection Sort code.
 *
 * NOTE: THIS IS A CUT DOWN VERSION OF THE ENTIRE MINMAX CLASS.
 *       IT ONLY CONTAINS THE METHODS REQUIRED FOR
 *       SELECTION SORT. SOME OTHER METHODS IN THE FULL MINMAX
 *       ARE IN THE UTILITY FUNCTIONS FOR BUBBLE SORT.
 *  
 * @author Raymond Lister 
 * @version April 2015
 */
public class MinMax
{      
    /**
     * Returns the position of the smallest element in the given portion of the array.
     * 
     * If there is more than one occurrence of the minimum element,
     * minPosition will return one of the positions,
     * but exactly which of those positions is not defined.
     * 
     * At the time you complete this lab exerise on 
     * selSort04, you are NOT expected to understand the
     * code in this method.
     * 
     * This method, or a method that performs the same
     * function, may be examinable in the final exam.
     * (But the debug "print" statements are NOT examinable.)
     * 
     * @param   a       An array of integers
     * @param   first   A valid position in the array "a"
     * @param   last    A valid position in the array "a", where first is less than or equal to last
     * 
     * @return  The POSITION of the minimum element in array "a" between positions "first and "last" (inclusive).
     */
    public static int minPosition(int [] a, int first, int last)
    {
        System.out.print("minPosition(");
        printArray(a);
        System.out.print(", " + first + ", " + last + ");");

        int minPositionSoFar = first;

        for (int i=first+1 ; i<=last ; ++i )
        {
            if ( a[i] < a[minPositionSoFar] )
                minPositionSoFar = i;
        }

        // The following line of debug output is not examinable in the final exam.
        System.out.println(" return minPositionSoFar = " + minPositionSoFar + "  ");

        // The line below may also be examinable in the final exam.
        return minPositionSoFar;

    } // method minPosition

    /** 
     * This methof checks if an array is sorted into ascending order. 
     * 
     * At the time you complete this lab exerise on 
     * selSort04, you are NOT expected to understand the
     * code in this method.
     * 
     * This method, or a method that performs the same
     * function, may be examinable in the final exam.
     * (But the debug "print" statements are NOT examinable.)
     * 
     * @param   a       An array of integers
     * @param   first   A valid position in the array "a"
     * @param   last    A valid position in the array "a", where first is less than or equal to last
     * 
     * @return  1 if the elements from "first" to "last" are sorted, otherwise return something else. 
     */
    public static int isSorted(int [] a, int first, int last)
    {
        //Print 
        System.out.print("isSorted(");
        printArray(a);
        System.out.print(", " + first + ", " + last + ");");

        for (int i=first+1 ; i<=last ; ++i )
        {
            if ( a[i-1] > a[i] )
            {
                System.out.println(" NOT sorted, return something other than 1");
                return -1;
            }
        }
        // Most of the code that is examinable in the final exam ends here.

        // The following line of debug output is not examinable in the final exam.
        System.out.println(" sorted, so return 1");

        // The line below may also be examinable in the final exam.
        return 1;

    } // method isSorted

    /**
     * Prints out an array, with opening and closing braces, and
     * comma separated elements. For example "{1,2,3,4}". 
     * 
     * This method, or a method that performs a similar 
     * function, may be examinable in the final exam. There is no
     * debug output in this method. It is all examinable.
     *
     * @param   a       An array of integers
     */
    public static void printArray(int [] a)
    {
        System.out.print("{" + a[0]);

        for (int i=1 ; i<a.length ; ++i )
            System.out.print("," + a[i]);

        System.out.print("}");

    } // method printArray
}
