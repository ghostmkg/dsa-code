package Practice;

import java.util.HashMap;
import java.util.Map.Entry;

public class HashMapDemo {
    public static void main(String[] args) {
        HashMap<String, Integer> map = new HashMap<>();

        map.put("A",10);
        map.put("B",20);
        map.put("C",30);

        System.out.println("Size of map is: "+ map.size());
        System.out.println(map);

        if(map.containsKey("A")) {
            Integer A = map.get("A");
            System.out.println("Value for key A is: "+A);
        }

        for(String key : map.keySet()) {
            System.out.println("Key:"+key+", Value:"+map.get(key));
        }

        //alternative way
        for(Entry<String, Integer> entry : map.entrySet()) {
            System.out.println("Key:"+entry.getKey()+", Value:"+entry.getValue());
        }
    }
}
