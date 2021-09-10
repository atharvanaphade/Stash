import java.io.*;
import java.util.*;

public class A_Odd_Set {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc --> 0) {
            int n = sc.nextInt(), o = 0, e = 0;
            for (int i = 0; i < 2 * n; i++) {
                int temp = sc.nextInt();
                if (temp % 2 == 0) e++;
                if (temp % 2 == 1) o++;
            }
            if (o != e) System.out.println("No");
            else System.out.println("Yes");
        }
    }
}`