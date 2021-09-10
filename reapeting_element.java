import java.io.*;

public class reapeting_element{
    public static void main(String[] args) throws IOException {
        int[] array = {6,6,6,6,6};
        int ret = 0;
        for (int i = 0; i < array.length - 1; i++) {
            ret = ret ^ (i + 1) ^ array[i];
        }
        ret = ret ^ array[array.length - 1];
        System.out.println(ret);
    }
}