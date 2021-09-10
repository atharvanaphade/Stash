package NCC;
/////////package random_practiceQuestions;


import java.io.*;
import java.util.*;

public class pavel_and_triangles {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { return Integer.parseInt(next()); } // reads in the next int
        public long nextLong() { return Long.parseLong(next()); } // reads in the next long
        public double nextDouble() { return Double.parseDouble(next()); } // reads in the next double
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args){
        int a=r.nextInt();
        int[] arr=new int[a];
        for (int i=0;i<a;i++){
            arr[i]=r.nextInt();
        }


        long ans=0;

        int ex=0;
        for (int i:arr){
            if (ex>0){
                int x=Math.min(i/2,ex);
                ans=ans+x;

                ex=ex-x;
                i=i-2*x;
            }
            ans=ans+i/3;

            ex=ex+i%3;
        }



        pw.println(ans);
        pw.close();
    }
}
