import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class Chatbot {
	
	private static final HashMap<String, String> Siri=new HashMap<>();
		static {
			 Siri.put("good evening", "good evening , Hope all is well!!");
			 Siri.put("hello", "Hello! I am a simple rule-based bot. How can I help you today?");
		     Siri.put("hi", "Hello there! Ask me about our operating hours or services.");
		     Siri.put("hours", "Our operating hours are Monday to Friday, 9:00 AM to 5:00 PM.");
		     Siri.put("service", "We offer customer support, technical assistance, and product demos.");
		     Siri.put("bye", "Goodbye! Have a great day.");
		     Siri.put("thank", "You're welcome! Feel free to ask anything else.");
		}
	private static String preprocessInput(String  In) {
		return In.toLowerCase().trim();
	}
	private static String getResponse(String Cli) {
		Set<String> key=Siri.keySet();
		for(String keys: key) {
			if(Cli.contains(keys)) {
				return Siri.get(keys);
			}
		}
		return "I'm sorry, I don't understand that. Could you please rephrase your question?";
	}
	public static void main(String[] args) {
		System.out.println("Siri Initialized");
		Scanner sc=new Scanner(System.in);
		String UsI;
		while(true) {
			System.out.print("You :  ");
			UsI = sc.nextLine();
			if(UsI.equalsIgnoreCase("bye")) {
				String farewell= getResponse(preprocessInput(UsI));
				System.out.println("Bot: "+ farewell);
				break;
			}
			String cleanedInput=preprocessInput(UsI);
			String botResponse=getResponse(cleanedInput);
			System.out.println("Bot: " + botResponse);
		}
		sc.close();
		System.out.println("Siri session ended.");
	}
}
