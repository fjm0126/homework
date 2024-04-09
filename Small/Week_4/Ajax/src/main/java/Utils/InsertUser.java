package Utils;
import User.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import ConnectionPool.*;
public class InsertUser {
    public static void insertUser(User user) throws SQLException {
        Connection conn = null;
        ComeTrueConnectionpool comeTrueConnectionpool=new ComeTrueConnectionpool();
        comeTrueConnectionpool.initialConnectionpool();
        conn=comeTrueConnectionpool.getconnection();
        String sql="insert into user(UserName,PhoneNumber,IdCard,BankNumber,Money,PassWord) values(?,?,?,?,?,?)";
        PreparedStatement preparedStatement= conn.prepareStatement(sql);
        preparedStatement.setObject(1,user.getUserName());
        preparedStatement.setObject(2,user.getPhoneNumber());
        preparedStatement.setObject(3,user.getIdCard());
        preparedStatement.setObject(4,user.getBankNumber());
        preparedStatement.setObject(5,user.getMoney());
        preparedStatement.setObject(6,user.getPassWord());
        preparedStatement.executeUpdate();
    }
}

