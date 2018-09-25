/**
 * The Selection Sort algorithm, on arrays of size N.
 * 
 * SKELETON FOR LAB TEST: Students modify method "selSortN".
 * 
 * @author Raymond Lister 
 * @version April 2015
 */

public class SelSortSizeN
{
    /**
     * Sorts an array of N integers using the Selection Sort Algorithm.
     *
     * This version of Selection Sort Algorithm may be examinable in
     * the final exam.
     * 
     * @param   a   An array of N elements
     */
    public static void selSortN(int [] a)
    {   
        /*
         * This solution uses loops.
         */
        int minPos;

        for (int i = 1 ; i < a.length; i++)
        {
            // You *MUST* use methods minPosition and
            // swapPositions in your solution. These two
            // methods are located immediately after
            // this method, so look at the javadoc comments
            // of hose methods for a description of those
            // methods' parameters.
            minPos = minPosition(a, i-1, (a.length-1));
            swapPositions(a, i-1,minPos);
            
        }

        // all elements should now now sorted into increasing order

        // The following line of debug output is not examinable in the final exam.
        debug(a);

    } // method selSortN

    /**
     * Returns the position of the smallest element in the given 
     * portion of the array.
     * 
     * If there is more than one occurrence of the minimum element,
     * minPosition will return one of the positions,
     * but exactly which of those positions is not defined.
     * 
     * At the time you complete this lab exerise on 
     * selSortN, you are NOT expected to understand the
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
    private static int minPosition(int [] a, int first, int last)
    {
        // The following three lines of debug output are not examinable in the final exam.
        System.out.print("minPosition(");
        printArray(a);
        System.out.print(", " + first + ", " + last + ");");

        // The code that is examinable in the final exam starts here.
        int minPositionSoFar = first;

        for (int i=first+1 ; i<=last ; ++i )
        {
            if ( a[i] < a[minPositionSoFar] )
                minPositionSoFar = i;
        }
        // Most of the code that is examinable in the final exam ends here.

        // The following line of debug output is not examinable in the final exam.
        System.out.println(" return " + minPositionSoFar + "  ");

        // The line below may also be examinable in the final exam.
        return minPositionSoFar;

    } // method minPosition

    /**
     * Swaps the values stored at two POSITIONS of an array.
     * 
     * You MUST use this method in your solution to method
     * bubSortN.
     * 
     * Do NOT change this method.
     * 
     * This method, or a method that performs the same
     * function, may be examinable in the final exam.
     * (But the debug "print" statements are NOT examinable.)
     * 
     * @param   x           An array of integers
     * @param   pos1   A valid position in the array "a"
     * @param   pos2   A valid position in the array "a".
     */
    private static void swapPositions(int [] x, int pos1, int pos2)
    {
        // The next three lines of Java are debug output, which
        // are not examinable in final exam.
        System.out.print("swapPositions(");
        printArray(x);
        System.out.print(", " + pos1 + ", " + pos2 + "); ");

        // If you have to write this method in the final exam,
        // you will only have to provide something equivalent
        // to the three lines of code below.  You will NOT have
        // to provide the debug output.

        int temp     = x[pos1];
        x[pos1] = x[pos2];
        x[pos2] = temp;

        // The next four lines of Java are debug output, which
        // are not examinable in final exam.
        System.out.print("array now ");
        printArray(x);
        System.out.println();
        System.out.println();

    } // method swapPositions

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
    private static void printArray(int [] a)
    {
        System.out.print("{" + a[0]);

        for (int i=1 ; i<a.length ; ++i )
            System.out.print("," + a[i]);

        System.out.print("}");

    } // method printArray

    /** 
     * This method checks if an array is sorted into
     * ascending order. 
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
    private static int isSorted(int [] a, int first, int last)
    {
        // The next three lines of Java are debug output, which
        // are not examinable in final exam.
        System.out.print("isSorted(");
        printArray(a);
        System.out.print(", " + first + ", " + last + ");");

        // The code that may be examinable in the final
        // exam starts here.

        for (int i=first+1 ; i<=last ; ++i )
        {
            if ( a[i-1] > a[i] )
            {
                System.out.println(" NOT sorted");
                return -1;
            }
        }

        // Most of the code that may be examinable in the final
        // exam ends here.

        // The following line of debug output is not
        // examinable in the final exam.
        System.out.println(" sorted");

        // The following return statement may be examinable
        // in the final exam.

        return 1;

    } // method isSorted    

    /* This method generates output that is useful
     * when debugging selSortN.
     * 
     * Also, plate EXPECTS to see the output generated by this method.
     * 
     * Do NOT change this method.
     * 
     * At the time you complete this lab exerise on 
     * selSortN, you are NOT expected to understand the
     * code in this method.
     * 
     * This method is NOT examinable in the final exam.
     */
    private static void debug(int [] x)
    {   
        System.out.println();
        System.out.println("Final state of array is: ");
        printArray(x);
        System.out.println();

        if ( isSorted(x,0,x.length-1) == 1 )
        {
            System.out.println("The array is sorted!");
            System.out.println("But we haven't checked if the array contains the same ");
            System.out.println("numbers as it originally did.");
            System.out.println("Short of testing a piece of code on all legal inputs,");
            System.out.println("no amount of testing can PROVE that a piece of code "); 
            System.out.println("is bug free.");
        }
        else
            System.out.println("The array is NOT sorted!");

    } // method debug
}
