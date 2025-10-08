import java.util.* ;

public class setBit {

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in) ;

        System.out.println("Enter the number :");

        int num = sc.nextInt();

        System.out.println("Enter the positon of the bit to set :");

        int pos = sc.nextInt();

        int bitMask = 1<<pos;

        int newNumber = bitMask | num ;

        System.out.println("Number after succesfully bit setting : " + newNumber );

        sc.close();
    }
    
}
