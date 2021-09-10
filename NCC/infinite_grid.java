package NCC;

import java.io.*;
import java.util.*;

public class infinite_grid {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        int[] sieve = new int[10000001];
        sieve[0] = 1;
        for (int i = 0; i < 10000001; i++) {
            sieve[i] = i;
        }
        for (int i = 4; i < 10000001; i += 2) {
            sieve[i] = 2;
        }
        for (int i = 3; i * i < 10000001; i++) {
            if (sieve[i] == i) {
                for (int j = i * i; j < 10000001; j += 1) {
                    if (sieve[j] == j) {
                        sieve[j] = i;
                    }
                }
            }
        }
        for (int i = 0; i < tc; i++) {
            int n = sc.nextInt();
            long 
        }
    }
}
