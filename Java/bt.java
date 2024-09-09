import java.util.Scanner;

public class bt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int left = 0, right = n - 1;
        int find = 0;
        while(left <= right) {
            int mid = (right + left) / 2;
            if (x < a[mid]) {
                right = mid - 1;
            } else if (x > a[mid]) {
                left = mid + 1;
            } else {
                find = 1;
                break;
            }
        }
        if (find != 0) {
            System.out.print("YES");
        } else System.out.print("NO");
        sc.close();
    }
}