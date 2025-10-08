import java.util.* ;
public class clearBit {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number : ");
        
        int num = sc.nextInt();

        System.out.print("Enter the bit position to clear (0-indexed): ");

        int pos = sc.nextInt();

        int bitMask = 1 << pos ;

        int nbitMask = ~bitMask ;

        int result = num & nbitMask;

        System.out.println("Number after clearing bit at position " + pos + " is: " + result);

        sc.close();
    }
}
