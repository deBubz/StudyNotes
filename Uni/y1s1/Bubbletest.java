public class Bubbletest
{
    public static void main(String[] args)
    {
        int[] Arr = new int[] {3,5,2,1,100,9,6};
        int temp;
        //boolean switch = false;
        for(int i =1; i < Arr.length+1; i++)
        {
            for( int x = 0; x < Arr.length; x++)
            {
                if(Arr[i] < Arr[i-1])
                { // swap if 2nd value smaller than 1st
                    temp = Arr[i];
                    Arr[i] = Arr[i-1];
                    Arr[i-1] = temp;
                }
            }
        } 


        // print out array to test
        for(int num = 0; num< Arr.length; num++) {
            System.out.println(Arr[num]);
        }
    }
}
