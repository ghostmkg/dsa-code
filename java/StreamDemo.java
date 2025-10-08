import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class StreamDemo {
    public static void main(String[] args) {
        ArrayList<Integer> arrayList = new ArrayList<>();

        arrayList.add(10);
        arrayList.add(20);
        arrayList.add(30);
        arrayList.add(40);

        //ArrayList<Integer> squareList = new ArrayList<>();

        //for(Integer i : arrayList) {
        //    squareList.add(i*i);
        //}

        //single line code for above same task
        List<Integer> squareList = arrayList.stream().map(x -> x*x).collect(Collectors.toList());

        System.out.println("The list of square numbers: "+squareList);

        //
        //List to squared set(Hashset)

        //normal approach
        //HashSet<Integer> squareSet = new HashSet<>();
        //for(Integer i : arrayList) {
        //    squareSet.add(i*i);
        //}

        Set<Integer> squareSet = arrayList.stream().map(x -> x*x).collect(Collectors.toSet());

        System.out.println("Square HashSet Is:"+squareSet);

        //Filtering
        List<String> languages = new ArrayList<>();


        languages.add("Scala");
        languages.add("Java");
        languages.add("Python");
        languages.add("Basic");
        

        //List<String> filterResult = new ArrayList<>();
        //for(String s : languages) {
        //    if(s.startsWith("P")) {
        //        filterResult.add(s);
        //    }
        //}
        
        List<String> filterResult = languages.stream().filter(s -> s.startsWith("P")).collect(Collectors.toList());
        
        System.out.println(filterResult);

        //
        //
        List<String> sortedList = languages.stream().sorted().collect(Collectors.toList());
        System.out.println(sortedList);

        //printing one by one
        languages.stream().forEach(y -> System.out.println("Element is " + y));
    }
}
