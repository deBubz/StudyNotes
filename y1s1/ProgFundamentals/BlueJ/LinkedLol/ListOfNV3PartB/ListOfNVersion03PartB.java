/**
 * This class maintains an arbitrary length list of integers.
 * 
 * In this version:
 * 1. The size of the list is *VARIABLE* after the object is created.
 * 2. The code assumes there is at least one element in the list.
 * 
 * This class introduces the use of structural recursion.
 * 
 * @author Raymond Lister 
 * @version May 2016
 * 
 */
public class ListOfNVersion03PartB
{   
    private int thisNumber;              // the number stored in this node
    private ListOfNVersion03PartB next;  // forms a linked list of objects
    
    private final int nodeID;            // a unique ID for each object in the list
    
    private static int nodeCount = 0;    // the number of list objects that have been created

    /**
     * This constructor initializes the list to the same values
     * as in the parameter.
     *
     * @param  element   the initial elements for the list
     */
    public ListOfNVersion03PartB(int num)
    {
        thisNumber = num;
        next = null;
        
        ++nodeCount;
        nodeID = nodeCount;

    } // constructor(int num)

    /**
     * @param  num   the multiple values to be stored in the list, in that order
     */
    public ListOfNVersion03PartB(int [] num)
    {
        this(num[0]);  // in this context, "this" invokes the other constructor

        for (int i=1 ; i<num.length ; ++i)
            insertLast(num[i]);

    } // constructor(int [] num)

    /**
     * @return     the first element in the list 
     */
    public int getFirst()
    {
        return thisNumber; // delete this line and add your lab test solution

    } // method getFirst
    
    /**
     * prints this object
     */
    public void printNode()
    {
        System.out.print("[" + nodeID + "," + thisNumber + "]->");

    } // method printListNode

    /**
     * stringifies this object
     */
    public String toStringNode()
    {
        return "[" + nodeID + "," + thisNumber + "]->";

    } // method toStringNode


    /**
     * form a string from the tail of a list
     */
    private String toStringTail()
    {
        String s = toStringNode();

        if ( next != null )
            s = s + next.toStringTail();

        return s;

    } // method toStringTail

    /**
     * @return     A summary of the contents of the whole list.
     */
    public String toString()
    {
        String s = toStringNode();

        if ( next != null )
            s = s + next.toStringTail();

        return s;

    } // method toString

    /**
     * @return     the sum of the elements of the array
     */
    public int sum()
    {
        if(next == null) 
            {return thisNumber; }
        else return thisNumber + next.sum(); // delete this line and add your lab test solution

    } // method sum 

    /**
     * @return     the number of times the replacement was made (i.e. 0 or 1)
     * 
     * @param  replaceThis   the element to be replaced
     * @param  withThis      the replacement
     */
    public int replaceOnce(int replaceThis, int withThis)
    {    

        if(replaceThis == thisNumber)
        {
            thisNumber = withThis;
            return 1;
        }
        
        if (next != null) {
            return next.replaceOnce(replaceThis, withThis);
        }
        else return 0;
    }

    /**
     * @return     the value of the smallest element in the list
     */
    public int minVal()
    {
       return 99; // delete this line and add your lab test solution

    } // method minVal

    /**
     * Inserts an element in the first position. The elements already in the
     * list are pushed up one place.
     * 
     * @param  newElement   the element to be inserted
     */
    public void insertFirst(int newElement)
    {  
       // add your lab test solution

    } // method insertFirst

    /**
     * Inserts an element in the last position. The pre-existing elements in the
     * list are unaffected.
     * 
     * @param  newElement   the element to be inserted
     */
    public void insertLast(int newElement)
    { 
        // add and/or modify code to complete the method

        if ( next == null )
            next = new ListOfNVersion03PartB(newElement);
        else
            next.insertLast(newElement);

    } // method insertLast

    /**
     * No change if there is only one element in the list. Otherwise, it moves up one place all
     * elements in the list, by overwriting each "thisNumber" with "next.thisNumber", thus
     * removing the first value in the list. The last node in the list is removed.
     */
    public void shuffleUp()
    {
        System.out.println("This method is NOT part of the lab test");
        System.out.println("It will probbaly be part of the assignment");

        // insert some code here

    } // method shuffleUp

    /*
     * @return     the number of deletions made (i.e. 0 or 1)
     * 
     * @param  element       the element to be deleted
     * @param  predecessor   a reference to the previous node in the linked list
     *                       i.e. the node where "next" points to this node
     */
    private int delete2(int element, ListOfNVersion03PartB predecessor)
    {  
        System.out.println("This method is NOT part of the lab test");
        System.out.println("It will probbaly be part of the assignment");
        return 99; // delete this line and complete the method for the assignment

    } // method delete2

    /**
     * @return     the number of deletions made (i.e. 0 or 1)
     * 
     * @param  element   the element to be deleted
     */
    public int delete(int element)
    {  
        if ( (thisNumber == element) && (next == null) )
        {
            System.out.println("Error when attempting to delete '" + element + "'. The list must contain at least one element");
            return 0;
        }

        if ( thisNumber == element )
        {
            // if thisNumber == element is true then the first "if" statement implies that next != null
            thisNumber = next.thisNumber;
            next = next.next;
            return 1;
        }

        if ( next == null )
        {
            // if next == null is true then the first "if" statement implies that thisNumber != element
            return 0;
        }

        return next.delete2(element, this);

    } // method delete

} // class ListOfNVersion03PartB
