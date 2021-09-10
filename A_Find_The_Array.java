import java.io.*;
import java.util.*;

public class A_Find_The_Array {
    public static void main (String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc --> 0) {
            int s = sc.nextInt();
            int ret = 0;
            int val = 1;
            while (s > 0) {
                s -= val;
                val += 2;
                ret++;
            }
            System.out.println(ret);
        }
        sc.close();
    }
}