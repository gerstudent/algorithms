import java.util.Scanner;

class insertionSort{
    void sort(int[] arr){
        int n = arr.length;
        int temp, j;
        for (int i = 1; i < n; ++i){
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > temp){
                arr[j + 1] = arr[j];
                j -= 1;
            }
            arr[j + 1] = temp;
        }
    }

    static void printarr(int[] arr){
        int n = arr.length;
        for (int j : arr) {
            System.out.print(j + " ");
        }
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i){
            arr[i] = input.nextInt();
        }
        insertionSort res = new insertionSort();
        res.sort(arr);
        printarr(arr);
    }
}