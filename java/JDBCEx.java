import java.sql.*;

public class JDBCEx {
    public static void main(String[] args) {
        try {
          
            // Load the driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish the connection
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/world", "root", "12345");

            // Create a statement
            Statement st = con.createStatement();

            // Execute a query
            String sql = "SELECT * FROM people";
            ResultSet rs = st.executeQuery(sql);

            // Process the results
            while (rs.next()) {
                System.out.println("Name: " + rs.getString("name") +
                                   ", Age: " + rs.getInt("age"));
            }

            // Close resources
            rs.close();
            st.close();
            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}