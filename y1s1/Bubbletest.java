public class Bubbletest
{
    public static void main(String[] args)
    {
        int[] Arr = new int[] {2,5,7,8,1,12,33,9,3,0};
        int temp, something , no , why;
        Boolean swap;


        for(int x = 0; x < Arr.length; x++)
        {
            swap = false;
            for( int i = 1; i < Arr.length; i++)
            {
                
                if(Arr[i-1] > Arr[i]) // first > 2nd
                { 
                    //swap
                    temp = Arr[i];
                    Arr[i] = Arr[i-1];
                    Arr[i-1] = temp;     
                }
                swap = true;
            }
            if(!swap) break; //break loop if no swapping occurs
        }

        // print out array to test
        for(int num : Arr) {
            System.out.print(num+ " ");
        }
    }
}
