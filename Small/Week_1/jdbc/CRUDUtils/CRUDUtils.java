package Utils;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class CRUDUtils {
    private static DataSource dataSource=null;//连接池对象
    static{
        //初始化连接池对象
        Properties properties=new Properties();
        InputStream ips = CRUDUtils.class.getClassLoader().getResourceAsStream("druid.properties");
        try {
            properties.load(ips);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            dataSource= DruidDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    public static Connection getConnection() throws SQLException {
        return dataSource.getConnection();
    }
    public static void freeConnection(Connection connection) throws SQLException {
        connection.close();
    }
    public static void Insert(String tableName, String columns, String values) throws SQLException {
        Connection connection = getConnection();
        PreparedStatement preparedstatement = connection.prepareStatement("INSERT INTO " + tableName + " (" + columns + ") VALUES (" + values + ")");
        preparedstatement.executeUpdate();
    }
    public static ResultSet Read(String tableName,String condition) throws SQLException {
        ResultSet resultSet = null;
        PreparedStatement preparedStatement = null;
        Connection connection = null;
        try {
            connection = getConnection();
            preparedStatement = connection.prepareStatement("SELECT * FROM " + tableName + " WHERE " + condition);
            resultSet = preparedStatement.executeQuery();
            return resultSet;
        } finally {
            if (resultSet != null) {
                resultSet.close();
            }
            if (preparedStatement != null) {
                preparedStatement.close();
            }
            if (connection != null) {

                freeConnection(connection);
            }
        }
    }
    public static void Update(String tableName,String Values,String condition) throws SQLException {
        Connection connection=getConnection();
        PreparedStatement preparedStatement=connection.prepareStatement("UPDATE " + tableName + " SET " + Values + " WHERE " + condition);
        preparedStatement.executeUpdate();
    }
    public static void Delete(String tableName,String condition) throws SQLException {
        Connection connection=getConnection();
        PreparedStatement preparedStatement=connection.prepareStatement("DELETE FROM"+ tableName +"WHERE"+condition);
        preparedStatement.executeUpdate();
    }
}
