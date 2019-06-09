/**
 * This class maintains a list of 4 integers.
 * 
 * This list is simple and unusual in it always contains exactly the
 * same number of elements.  Later, when we know more Java, we will
 * study classes where the number of elements may vary. 
 * 
 * In this version 2, we use variables in the subscripts.
 * 
 * @author Raymond Lister 
 * @version August 2014
 * 
 */
public class ListOf4V2PartA
{
    private static final int listSize = 4;
    
    private int[] list = {0, 1, 2, 3};

    
    /**
     * A constructor for objects of class ListOf4, which takes four parameters
     * 
     * @param  one   an initial element for the list, the first element.
     * @param  two   an initial element for the list
     * @param  three an initial element for the list
     * @param  four  an initial element for the list, the last element.
     */
    public ListOf4V2PartA(int one, int two, int three, int four)
    {
        list[0] = one;
        list[1] = two;
        list[2] = three;
        list[3] = four;
    } // constructor ListOf4(int one, int two, int three, int four)
    
    /**
     * @return     the number of elements stored in this list 
     */
    public int getListSize()
    {
        return list.length;
        
    } // method getListSize
    
    /**
     * @return     the last element in the list
     */
    public int getLast()
    {
        return list[list.length - 1];
    } // method getLast
      
    
    /**
     * prints the contents of the list, in order from first to last
     */
    public void printList()
    {
      // with variable subscripts ... 
      System.out.print("{");
      
      for(int i = 0; i < list.length; i++)
      {
          if(i == 3)
          {
              System.out.print(list[i] + "}");
          }
          else
          {
              System.out.print(list[i] + ", ");
          }
      }
    } // method printList
            
    
    /**
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
    public int countElement(int countThis)
    {
       int count = 0; // role: stepper
        
       // with variable subscripts ...
       for(int i : list)
       {
           if(i == countThis)
           {
               count++;
           }
       }
      
       return count;
        
    } // method countElement 
                    
    /**
     * @return     the number of times the replacement was made
     * 
     * @param  replaceThis   the element to be replaced
     * @param  withThis      the replacement
     */
    public int replaceAll(int replaceThis, int withThis)
    {
        int count = 0; // role: stepper; number of replacements made

        for(int i = 0; i < list.length; i++)
        {
            if(list[i] == replaceThis)
            {
                list[i] = withThis;
                count++;
            }
        }
        return count;
        
    } // method replaceAll          
    
    /**
     * @return     the first position in list occupied by the parameter value, or -1 if it is not found
     * 
     * @param  findThis   the value to be found
     */
    public int findUnSorted(int findThis)
    {  
        int count = 0;
  
        for(int i : list)
        {
            if(i == findThis)
            {
                return count;
            }
            count++;
        }
        
        return -1;
    } // method findUnSorted
    
    
    /**
     * @return     the position of the smallest element in the array
     */
    public int minPos()
    {
        int position =0;

        for(int i = 1; i < list.length; i++)
        {
            if(list[i] < list[i-1])
            {
                position =i;
            }
        }

        return position;
        
    } // method minPos
     
       
    /**
     *  Swaps two elements in the list
     *  
     * @param  i   the position of one of the elements to be swapped
     * @param  j   the position of one of the elements to be swapped
     */
    public void swap(int i, int j)
    {
        int temp; // role: temporary
        
           temp = list[i];
        list[i] = list[j];
        list[j] = temp;
        
    } // method swap
       
    /**
     * Orders the elements of the list, with the first element smallest and the 
     * last element largest.  Does this using the bubblesort algorithm.
     */
    public void sortBubble()
    {
        for(int x = 0; x < list.length; x++)
        {
            for(int i = 1; i < list.length; i++)
            {
                if(list[i-1] > list[i])
                {
                    swap(i-1, i);
                }
            }
        }
    } // method sortBubble

} // class ListOf4V2