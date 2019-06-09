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
public class ListOfNVersion03PartA
{   
    private int thisNumber;              // the number stored in this node
    private ListOfNVersion03PartA next;  // forms a linked list of objects

    private final int nodeID;            // a unique ID for each object in the list

    private static int nodeCount = 0;    // the number of list objects that have been created

    /**
     * @param  num   the value to be stored in this object
     */
    public ListOfNVersion03PartA(int num)
    {
        thisNumber = num;
        next = null;

        ++nodeCount;
        nodeID = nodeCount;

    } // constructor(int num)

    /**
     * @param  num   the multiple values to be stored in the list, in that order
     */
    public ListOfNVersion03PartA(int [] num)
    {
        this(num[0]);  // in this context, "this" invokes the other constructor        

        for (int i=1 ; i<num.length ; ++i)
            insertLast(num[i]);

    } // constructor(int [] num)

    /**
     * @return     the number of elements stored in this list 
     */
    public int getListSize()
    {
        return nodeCount; // delete this line and add your lab test solution

    } // method getListSize

    /**
     * @return     the last element in the list
     */
    public int getLast()
    {
        if(next != null)return thisNumber;
        
        return 0;
    } // method getLast

    /**
     * prints this object
     */
    public void printNode()
    {
        System.out.print("[" + nodeID + "," + thisNumber + "]->");

    } // method printListNode

    /**
     * prints the tail of a list
     */
    private void printListTail()
    {
        printNode();

        if ( next != null )
            next.printListTail();

    } // method printListTail

    /**
     * prints the contents of the list, in order from first to last
     */
    public void printList()
    {
        printNode();

        if ( next != null )
            next.printListTail();

    } // method printList

    /**
     * This method is NOT examinable in this test.
     * 
     * prints the contents of the list, in order from first to last, and
     * then moves the cursor to the next line
     */
    public void printlnList()
    {
        printList();
        System.out.println();

    } // method printlnList

    /**
     * @return     the number of times the element occurs in the list
     * 
     * @param  element   the element to be counted
     */
    public int countElement(int element)
    {
        
        int counter = 0;
        
        while(next != null)
        {
            if(next.thisNumber == element) counter++;
        }
        
        
        return counter; // delete this line and add your lab test solution

    } // method countElement 

    /**
     * @return     the number of times the replacement was made
     * 
     * @param  replaceThis   the element to be replaced
     * @param  withThis      the replacement
     */
    public int replaceAll(int replaceThis, int withThis)
    {
        int counter = 0;
        if(next.thisNumber == replaceThis)
        {
             thisNumber = withThis;
             counter++;
        }
        
        return counter; // delete this line and add your lab test solution

    } // method replaceAll

    /**
     * @return a reference to the first object in the list that contains the parameter value, or null if it is not found
     * 
     * @param  findThis   the value to be found
     */
    public ListOfNVersion03PartA findUnSorted(int findThis)
    {  
        if(next.thisNumber == findThis)
        {
            return next;
        }
        return null; // delete this line and add your lab test solution

    } // method findUnSorted 

    /**
     * @return     the reference to the object containing the smallest element in the list
     */
    public ListOfNVersion03PartA minRef()
    {
        return this; // delete this line and add your lab test solution

    } // method minRef

    /**
     * Inserts an element in the last position. The pre-existing elements in the
     * list are unaffected.
     * 
     * @param  newElement   the element to be inserted
     */
    public void insertLast(int newElement)
    { 
        if ( next == null )
            next = new ListOfNVersion03PartA(newElement);
        else
            next.insertLast(newElement);

    } // method insertLast

    /**
     * Inserts an element into a sorted list. NOTE: The pre-existing elements in the
     * list are sorted and the list remains sorted (ascending order).
     * 
     * @param  newElement   the element to be inserted
     */
    public void insertSorted(int newElement)
    { 
        System.out.println("This method is NOT part of the lab test");
        System.out.println("It will probbaly be part of the assignment");

        if ( next == null )
        {
            next = new ListOfNVersion03PartA(newElement);
        }
        else
        {
            next.insertLast(newElement);
        }

    } // method insertLast

} // class ListOfNVersion03PartA
