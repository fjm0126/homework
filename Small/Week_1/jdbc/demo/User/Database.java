package User;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Database {
    public Connection connectDatabase(){
        Connection connection;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection= DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/ATM","root","20050126");
        } catch (ClassNotFoundException | SQLException e) {
            throw new RuntimeException(e);
        }
        return connection;
    }
    public void insertUser(UserInformation user) throws SQLException {
        Connection connection=connectDatabase();
        String sql="insert into user(UserName,PhoneNumber,IdCard,BankNumber,Money,PassWord) values(?,?,?,?,?,?)";
        PreparedStatement preparedStatement= connection.prepareStatement(sql);
        preparedStatement.setObject(1,user.getUserName());
        preparedStatement.setObject(2,user.getPhoneNumber());
        preparedStatement.setObject(3,user.getIdCard());
        preparedStatement.setObject(4,user.getBankNumber());
        preparedStatement.setObject(5,user.getMoney());
        preparedStatement.setObject(6,user.getPassWord());
        int rows=preparedStatement.executeUpdate();
        if(rows>0){
            System.out.println("数据存储成功");
        }else{
            System.out.println("数据存储失败");
        }
        preparedStatement.close();
        connection.close();
    }
}
