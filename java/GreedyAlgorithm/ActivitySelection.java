import java.util.*;

public class ActivitySelection{
    public static void main(String args[]){

        int start[] = {0, 1, 3, 5, 5, 8};
        int end[] = {6, 2, 4, 7, 9, 9};

        System.out.println("MaxActivity code when end arr is sorted...");
        SortedEnd(start, end);
        System.out.println("MaxActivity code when end arr is not sorted...");
        UnSortedEnd(start, end);
    }   

    public static void SortedEnd(int start[], int end[]){
        // end time basis sorted arr

        int maxActivity = 0;
        ArrayList<Integer> ans = new ArrayList<>();

        // 1. always take the first activity (A0) bec it doesnt overlap with any other activity
        maxActivity = 1;
        ans.add(0);

        // initializing lastEnd with end of first activity
        int lastEnd = end[0];

        // taking a normal array for iteration bec start and end arrays are not ArrayList but arrays
        for(int i=1; i<end.length; i++){
            if(start[i] >= lastEnd){
                maxActivity++;
                ans.add(i);
                lastEnd = end[i];
            }
        }

        System.out.println("max activities... " + maxActivity);
        for(int i=0; i<ans.size(); i++){
            System.out.print("A" + ans.get(i) + " ");
        }
        System.out.println();
    }

    // creating an unsorted end arr function 
    public static void UnSortedEnd(int start[], int end[]){

        int activities[][] = new int[start.length][3];
        for(int i=0; i<start.length; i++){
            activities[i][0] = i;
            activities[i][1] = start[i];
            activities[i][2] = end[i];
        } 

        // lambda function -> shortform of a big function
        // in java, Comparator is an interface for sorting java objects
        Arrays.sort(activities, Comparator.comparingDouble(o -> o[2]));

        // end time basis sorted
        int maxActivity = 0;
        ArrayList<Integer> ans = new ArrayList<>();

        // 1st activity is already added
        maxActivity = 1;

        // adding that activity
        ans.add(activities[0][0]);
        int lastEnd = activities[0][2];
        for(int i=1; i<end.length; i++){
            if(activities[i][1] >= lastEnd){
                maxActivity++;
                ans.add(activities[i][0]);
                lastEnd = activities[i][2];
            }
        }

        System.out.println("max activities... " + maxActivity);
        for(int i=0; i<ans.size(); i++){
            System.out.print("A" + ans.get(i) + " ");
        }
        System.out.println();

    }

}