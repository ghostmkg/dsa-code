import java.util.Scanner;
public class Prime {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        int number = scanner.nextInt();
        boolean flag =true;
        for(int i=2;i<=number/2;i++){
            if(number%i==0){
                flag=false;
            }else{
                flag=true;
            }
        }
        if(flag==true){
            System.out.println(number + " is a prime number");
        }else{
              System.out.println(number + " is  not a prime number");
        }
    }
}
