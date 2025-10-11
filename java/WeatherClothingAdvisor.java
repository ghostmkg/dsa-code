import java.util.Scanner;

public class WeatherClothingAdvisor {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the temperature (°C): ");
        int temperature = sc.nextInt();
        sc.nextLine(); // consume newline

        System.out.print("Enter weather condition (sunny, rainy, cloudy, windy): ");
        String condition = sc.nextLine().toLowerCase();

        System.out.println("\n👕 Clothing Advice:");
        suggestClothing(temperature, condition);

        sc.close();
    }

    public static void suggestClothing(int temp, String condition) {
        if (temp < 10) {
            System.out.println("It's quite cold! Wear a heavy jacket or coat.");
        } else if (temp >= 10 && temp <= 20) {
            System.out.println("Wear a light sweater or hoodie.");
        } else if (temp > 20 && temp <= 30) {
            System.out.println("It's warm. T-shirt and jeans would be fine.");
        } else {
            System.out.println("It's hot outside! Wear light cotton clothes.");
        }

        switch (condition) {
            case "rainy":
                System.out.println("Don't forget to carry an umbrella ☔");
                break;
            case "sunny":
                System.out.println("Wear sunglasses and use sunscreen 😎");
                break;
            case "windy":
                System.out.println("Consider wearing a windbreaker 🧥");
                break;
            case "cloudy":
                System.out.println("Might be cool later, take a light jacket.");
                break;
            default:
                System.out.println("Enjoy your day!");
        }
    }
}
