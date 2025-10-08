import java.util.*;
public class getBit {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number :");

        int num = sc.nextInt();

        System.out.println("Enter the position of the bit to be checked :");

        int pos = sc.nextInt();

        int bitMask = 1<<pos ;

        if((num & bitMask) == 0){
            System.out.println("The required bit is zero .");
        } else {
            System.out.println("The required bit is one .");
        }

        sc.close();
    }
    
}
