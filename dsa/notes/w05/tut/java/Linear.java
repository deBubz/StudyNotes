public class Linear {
    static boolean liner_search(int[] arr, int find, int index, boolean status) {
        if(status){     // not found
            if(arr[index] == find) return true;
            else if(index >= arr.length) {  // index passed the length of 
                return false;
            }
            else {
                return liner_search(arr, find, ++index, status); 
                // still false 
            }
        } return true;
    }

    static boolean liner_search(int[] arr, int find) {
        return liner_search(arr, find, 0, false);
    }

    public static void main(String[] args) {
        int[] arr = { 3, 4, 5, 6, 76 };

        if(liner_search(arr, 8))
        System.out.println("hey ");
        else System.out.println("ho ");
    }

}