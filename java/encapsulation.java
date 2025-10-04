class Account {
    private String a_name;
    private int a_no;

    public String geta_name()
    {
            return a_name;
        }
    public void seta_name(String a_name)
        {
            this.a_name = a_name;
        }

        public int geta_no()
        {
                return a_no;
            }
    public void seta_no(int a_no)
            {
                this.a_no = a_no;
            }
        }

        public class encapsulation {
            public static void main(String[] args) {
                Account acc = new Account();
                acc.seta_name("sid");
                acc.seta_no(1324);
                System.out.println(acc.geta_name() + "\n" + acc.geta_no());
            }
}
