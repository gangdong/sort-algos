import java.util.Arrays;
import java.util.Scanner;

public final class sortAlgorithm {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        while (true) {

            int[] data = new int[] { 17, 6, 19, 45, 1, 2, 23, 5, 4, 11, 3 };
            System.out.println("initial data:" + Arrays.toString(data));
            System.out.println(
                    "options: 1.[bubble sort] 2.[selection sort] 3.[insert sort] 4.[quick sort] 5.[shell sort]");
            String cmd = sc.nextLine();
            switch (cmd) {
                case "1":
                    System.out.println("start bubble sorting:");
                    sort_bubble(data, data.length);
                    break;
                case "2":
                    System.out.println("start selection sorting:");
                    sort_selection(data, data.length);
                    break;
                case "3":
                    System.out.println("start insert sorting:");
                    break;
                case "4":
                    System.out.println("start quick sorting:");
                    break;
                case "5":
                    System.out.println("start shell sorting:");
                    break;
                default:
                    System.out.println("execute none:\n");
                    break;

            }
            System.out.println("after sort, the data:" + Arrays.toString(data));
        }

    }

    private static void swap(int[] a, int i, int j) {

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

	/* bubble sort*/
    private static void sort_bubble(int[] a, int len) {

        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - 1 - i; j++) {

                if (a[j] > a[j + 1]) {
                    swap(a, j, j + 1);
                }

            }
            System.out.println("search done:" + Arrays.toString(a));
        }

    }

    private static void sort_selection(int[] a, int len) {

        for (int i = 0; i < len-1; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (a[j] < a[min]) {
                    min = j;
                }
            }
            swap(a, i, min);
            System.out.println("search done:" + Arrays.toString(a));
        }
    }

}