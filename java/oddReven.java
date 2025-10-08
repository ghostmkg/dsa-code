
import java.util.Scanner;

public class oddReven{
    public static void main(String[] args) {
        
    Scanner sc=new Scanner(System.in);
    System.out.println("enter the number");
    int n=sc.nextInt();
    for(int i=1;i<=n;i++){
        if(n%2==0){
              System.out.println(n + "is even number");
        }else{
             System.out.println(n + "is odd number");
        }
        }
    }
    }