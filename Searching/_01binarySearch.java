package Searching;
import java.util.Scanner;
public class _01binarySearch{

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int size=in.nextInt();
        in.nextLine();
        int[] arr = new int[size];
        for(int i=0;i<size;i++){
            System.out.print("Enter element "+(i+1)+": ");;
            arr[i]=Integer.parseInt(in.nextLine());
        }
        System.out.print("Enter element to be found in your array: ");
        int elem=Integer.parseInt(in.nextLine());
        System.out.println("The index of you element is: "+binarySearch(arr, elem));
        in.close();
    }
    public static int binarySearch(int[] arr,int target){
        int start=0;
        int end=arr.length-1;
        if(start>end){
            return -1;
        }
        while(start<=end){
            int middle=start+(end-start)/2; //represents the middle index of our given array
            if(arr[middle]>target){         //Checks if if middle element is greater than target
                end=middle-1;               //is middle is greater makes our end to middle-1 index to now check in that index range
            }
            else if(arr[middle]<target){
                start=middle+1;
            }
            else{
                return middle;
            }
        }
        return -1;
    }
}
