import java.util.ArrayList;

// something raw types


/**
 * Test
 */
public class Test {
    public static void main(String[] args) {
        ArrayList <Integer> v = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            v.add(i);
        }

        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.get(i));
        }
        }

}