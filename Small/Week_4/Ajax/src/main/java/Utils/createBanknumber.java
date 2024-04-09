package Utils;

import java.sql.SQLException;
import java.util.Random;

public class createBanknumber {
    public static String createBanknumber(){
        String banknumber;
            banknumber="";
            Random r = new Random();
            //产生十次随机数
            for (int i = 0; i < 10; i++) {
                int data = r.nextInt(10);
                banknumber+=data;
            }
        return banknumber;
    }
}
