/**
 * A demonstration of the BubbleSort algorithm,
 * on arrays of size 4, using the "ifSwap" method.
 * 
 * SKELETON FOR LAB TEST.
 * 
 * @author Raymond Lister 
 * @version April 2018
 */
class Bub04IfSwapV1
{      
    /**
     * Compares two elements of an array and swaps them
     * if the two elements are out of order.
     */
    private static void ifSwap(int [] a, int i, int j)
    {
        System.out.print("ifSwap(a," + i + "," + j + ") ");
        
        if ( a[i] <= a[j] )
        {
            System.out.println("no swap");
        }
        else
        {  
            Other.swap(a, i, j);
        }
        
    } // method ifSwap
    
    
    /**
     * Sorts an array of 4 integers with the Bubble Sort
     * algorithm, using the "ifSwap" method.
     *  
     * @param   a   An array of 4 elements
     */
    public static void bubSort04(int [] a)
    {       
        System.out.println();
        System.out.print("              Array to be sorted ");
        Other.printArray(a);
        System.out.println();

        /* 
         * Do NOT change any code ABOVE this comment
         * Your solution MUST use the method "ifSwap"
         */
        
        // The following ifSwaps make the FIRST pass through the array
        // Insert one or more calls to the "ifSwap" method below here.

        // Do NOT remove the next two lines of Java code.
        Other.debug("Is largest in place?", a, 3);
        System.out.println();

        // The following ifSwaps make the SECOND pass through the array
        // Insert one or more calls to the "ifSwap" method below here.

        // Do NOT remove the next two lines of Java code.
        Other.debug("Is 2nd largest in place?", a, 2);         
        System.out.println();
        
        // The following ifSwaps make the THIRD pass through the array
        // Insert one or more calls to the "ifSwap" method below here.

        /* 
         * Do NOT change any code BELOW this comment
         */

        Other.debug("Is array now sorted?", a, 1);
        System.out.println("----------------------------------------------");

    } // method bubSort04
    
} // class
