import java.util.* ;
public class updateBit {
    public static void main (String args[]){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number :");

        int num = sc.nextInt();

        System.out.println("Enter the bit position to update : ");

        int pos = sc.nextInt();

        System.out.print("Enter the new bit value (0 or 1): ");

        int newBit = sc.nextInt();

        int bitMask = 1 << pos;

        if(newBit == 0){

            int newbitMask = ~bitMask ;
            int result = num & newbitMask;
            System.out.println("Number after clearing bit at position " + pos + " is: " + result);

        } else{
            int result = num | bitMask;
            System.out.println("Number after setting bit at position " + pos + " is: " + result);
        }
        sc.close();
    }
}
