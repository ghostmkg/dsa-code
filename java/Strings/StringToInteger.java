public class StringToInteger {
    public static int myAtoi(String s) {
        if (s == null || s.isEmpty()) return 0;
        
        int i = 0, n = s.length();
        int sign = 1;
        long result = 0;

        
        while (i < n && s.charAt(i) == ' ') i++;

        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }

        
        while (i < n && Character.isDigit(s.charAt(i))) {
            result = result * 10 + (s.charAt(i) - '0');

            
            if (result * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (result * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            
            i++;
        }

        return (int)(result * sign);
    }

    public static void main(String[] args) {
        System.out.println(myAtoi("42"));             
        System.out.println(myAtoi("   -42"));         
        System.out.println(myAtoi("4193 with words"));
        System.out.println(myAtoi("words 987"));      
        System.out.println(myAtoi("-91283472332"));   
    }
}
