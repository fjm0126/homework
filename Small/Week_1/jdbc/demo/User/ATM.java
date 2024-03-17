package User;

import jdk.jshell.spi.SPIResolutionException;

import java.io.File;
import java.io.PrintWriter;
import java.sql.*;
import java.util.*;
import java.util.stream.Collectors;

public class ATM {
    private Scanner sc=new Scanner(System.in);
    //菜单页面
    public void Menu() throws SQLException {

        while (true) {
            System.out.println("===欢迎使用ATM系统===");
            System.out.println("请选择操作：");
            System.out.println("1、登录账户");
            System.out.println("2、创建账户");
            int choice = sc.nextInt();
            switch(choice){
                case 1:
                    //用户登录
                    enterAccount();
                    break;
                case 2:
                    //创建账户
                    createAccount();
                    break;
                default:
                    System.out.println("无效操作，请重新输入");
            }
        }
    }
    /* 完成用户登录操作 */
    private void enterAccount() throws SQLException {
        UserInformation user=new UserInformation();
        Database check=new Database();
        Connection connection= check.connectDatabase();
        Statement statement= connection.createStatement();
        while (true) {
            System.out.println("请输入您的银行卡号：");
            String banknumber=sc.next();
            boolean checknumber=check(banknumber);
            if(checknumber==true){
                System.out.println("无此账户，请重新输入：");
                continue;
            }
            user.setBankNumber(banknumber);
            System.out.println("请输入您的密码：");
            String password=sc.next();
            String sql="select * from user";
            ResultSet resultSet=statement.executeQuery(sql);
            boolean flag=false;
            while(resultSet.next()){
                if (Objects.equals(resultSet.getNString("PassWord"),password)){
                    flag=true;
                    System.out.println("账户登录成功，请选择下一步操作");
                    userOperate(user);
                    break;
                }
            }
            if (flag){
                break;
            }else{
                System.out.println("密码错误，请重新输入。");
            }
        }
    }
    private void userOperate(UserInformation user) throws SQLException {
        System.out.println("1、存款");
        System.out.println("2、取款");
        System.out.println("3、转账");
        System.out.println("4、查询余额");
        System.out.println("5、退出账户");
        int choice=sc.nextInt();
        switch (choice){
            case 1:
                //存款
                intoMoney(user);
                break;
            case 2:
                getMoney(user);
                //取款
                break;
            case 3:
                //转账
                Transfer(user);
                userOperate(user);
                break;
            case 4:
                double money=checkmoney(user);
                System.out.println("您的余额为："+money);
                userOperate(user);
                break;
            case 5:
                Menu();
                break;
            default:
                System.out.println("无效操作，请重新输入");
        }
    }
    /* 存款操作 */
    private void intoMoney(UserInformation user) throws SQLException {
        Database getmoney=new Database();
        Connection connection= getmoney.connectDatabase();
        System.out.println("请输入要存款的金额：");
        double money=sc.nextDouble();
        double currentMoney=checkmoney(user);
        double nowMoney=money+currentMoney;
        String sql="update user set Money=? where BankNumber=?";
        PreparedStatement preparedStatement= connection.prepareStatement(sql);
        preparedStatement.setObject(1,nowMoney);
        preparedStatement.setObject(2,user.getBankNumber());
        int i=preparedStatement.executeUpdate();
        if(i>0){
            System.out.println("存款成功");
        }else {
            System.out.println("存款失败");
        }
        System.out.println("请按0打印流水账单。");
        int a=sc.nextInt();
        if(a==0){
            printBill("存款",user,money,connection);}
        preparedStatement.close();
        connection.close();
        userOperate(user);
    }
    /* 取款操作 */
    private void getMoney(UserInformation user) throws SQLException {
        double currentMoney;
        double money;
        while (true) {
            System.out.println("请输入要取款的金额：");
            money = sc.nextDouble();
            currentMoney = checkmoney(user);
            if (money > currentMoney) {
                System.out.println("余额不足，请重新输入。");
                System.out.println("您的当前余额为：" + currentMoney);
            } else {
                break;
            }
        }
        Database getmoney = new Database();
        Connection connection = getmoney.connectDatabase();
        double nowMoney = currentMoney - money;
        String sql = "update user set Money=? where BankNumber=?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setObject(1, nowMoney);
        preparedStatement.setObject(2, user.getBankNumber());
        int i = preparedStatement.executeUpdate();
        if (i > 0) {
            System.out.println("取款成功");
        } else {
            System.out.println("取款失败");
        }
        System.out.println("请按0打印流水账单。");
        int a=sc.nextInt();
        if(a==0){
        printBill("取款",user,money,connection);}
        connection.close();
        preparedStatement.close();
        userOperate(user);
    }
    private void Transfer(UserInformation user) throws SQLException {
        double money;
        System.out.println("请输入转账银行卡号：");
        String banknumber=sc.next();
        double currentmoney=checkmoney(user);
        while (true) {
            System.out.println("请输入转账金额：");
            money=sc.nextDouble();
            if (money>currentmoney){
                System.out.println("余额不足，请重新输入。");
            }else{
                break;
            }
        }
        Database trans=new Database();
        Connection connection= trans.connectDatabase();
        try{
            connection.setAutoCommit(false);
            subMoney(user,money,connection);
            addMoney(banknumber,money,connection);
            connection.commit();
            connection.close();
        }catch(Exception e){
            connection.rollback();
        }finally {
            System.out.println("转账成功！");
        }
        System.out.println("请按0打印流水账单。");
        int a=sc.nextInt();
        if(a==0){
            printBill("转账",user,money,connection);}
    }
    private void subMoney(UserInformation user,double money,Connection connection) throws SQLException {
        String sql="update user set Money=Money-? where BankNumber=?;";
        PreparedStatement preparedStatement= connection.prepareStatement(sql);
        preparedStatement.setObject(1,money);
        preparedStatement.setObject(2,user.getBankNumber());
        preparedStatement.executeUpdate();
        preparedStatement.close();
    }
    private void addMoney(String Banknumber,double money,Connection connection) throws SQLException {
        String sql="update user set Money=Money+? where BankNumber=?;";
        PreparedStatement preparedStatement= connection.prepareStatement(sql);
        preparedStatement.setObject(1,money);
        preparedStatement.setObject(2,Banknumber);
        preparedStatement.executeUpdate();
        preparedStatement.close();
    }
    private void printBill(String operate,UserInformation user,double money,Connection connection) throws SQLException {
        String name=getName(user,connection);
        String idcard=getIdcard(user,connection);
        String phonenumber=getPhonenumber(user,connection);
        String banknumber=user.getBankNumber();
        List<UserInformation> information=new ArrayList<>();
        information.add(new UserInformation(name,idcard,phonenumber,banknumber,operate,money));
        String billReport=information.stream().map(UserInformation::toString).collect(Collectors.joining());
        String filePath="bill report.txt";
        try(PrintWriter out=new PrintWriter(new File(filePath))){
            out.println(billReport);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
    //完成创建账户操作
    private void createAccount() throws SQLException {
        UserInformation user=new UserInformation();
        System.out.println("请输入您的姓名：");
        String name=sc.next();
        user.setUserName(name);
        System.out.println("请输入您的手机号：");
        String phone=sc.next();
        user.setPhoneNumber(phone);
        System.out.println("请输入您的身份证号：");
        String id=sc.next();
        user.setIdCard(id);
        while (true) {
            System.out.println("请输入您的密码(6位纯数字)：");
            String password=sc.next();
            boolean flag=password.matches("\\d{6}");//正则表达式判断是否为6位纯数字
            if(flag){
                System.out.println("请再次输入确认您的密码：");
                String passwordCheck=sc.next();
                if(passwordCheck.equals(password)){
                    System.out.println("密码设置成功。");
                    user.setPassWord(passwordCheck);
                    break;
                }else{
                    System.out.println("两次输入密码不一致，请重新输入。");
                }
            }else{
                System.out.println("密码必须为6位纯数字，请重新输入。");
            }
        }
        //系统随机生成唯一的银行卡号
        String banknumber=createBanknumber();
        user.setBankNumber(banknumber);
        System.out.println("恭喜您创建账户成功，您的卡号是："+banknumber);
        //创建账户时默认余额为0
        user.setMoney(0);
        //存储到数据库中
        Database insert=new Database();
        try {
            insert.insertUser(user);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    /* 生成卡号 */
    private String createBanknumber() throws SQLException {
        String banknumber;
        while (true) {
            banknumber="";
            Random r = new Random();
            //产生十次随机数
            for (int i = 0; i < 10; i++) {
                int data = r.nextInt(10);
                banknumber+=data;
            }
            //判断是否唯一
            if(check(banknumber)){
                break;
            }
        }
        return banknumber;
    }
    /* 查询数据库，判断卡号是否唯一 */
    private boolean check(String banknumber) throws SQLException {
        Database checkNumber=new Database();
        Connection connection= checkNumber.connectDatabase();
        Statement statement= connection.createStatement();
        String sql="select * from user";
        ResultSet resultSet=statement.executeQuery(sql);
        boolean flag=true;
        while(resultSet.next()){
            if (Objects.equals(resultSet.getNString("BankNUmber"), banknumber)){
                flag=Boolean.FALSE;
                break;
            }
        }
        resultSet.close();
        statement.close();
        connection.close();
        return flag;
    }
     private double checkmoney(UserInformation user) throws SQLException {

         Database checkNumber=new Database();
         Connection connection= checkNumber.connectDatabase();
         String sql="select * from user where BankNumber=?";
         PreparedStatement preparedStatement=connection.prepareStatement(sql);
         preparedStatement.setObject(1,user.getBankNumber());
         ResultSet resultSet=preparedStatement.executeQuery();
         if(resultSet.next()){
             return resultSet.getDouble("Money");
         }
         return 0;
     }
     private String getName(UserInformation user,Connection connection) throws SQLException {
         String sql = "select * from user where BankNumber=?";
         PreparedStatement preparedStatement = connection.prepareStatement(sql);
         preparedStatement.setObject(1, user.getBankNumber());
         ResultSet resultSet = preparedStatement.executeQuery();
         String name = null;
         if (resultSet.next()) {
             name = resultSet.getString("UserName");
         }
         return name;
     }
    private String getPhonenumber(UserInformation user,Connection  connection) throws SQLException {
        String sql = "select * from user where BankNumber=?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setObject(1, user.getBankNumber());
        ResultSet resultSet = preparedStatement.executeQuery();
        String Phonenumber = null;
        if (resultSet.next()) {
            Phonenumber = resultSet.getString("PhoneNumber");
        }
        return Phonenumber;
    }
    private String getIdcard(UserInformation user,Connection connection) throws SQLException {
        String sql = "select * from user where BankNumber=?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setObject(1, user.getBankNumber());
        ResultSet resultSet = preparedStatement.executeQuery();
        String Idcard = null;
        if (resultSet.next()) {
            Idcard = resultSet.getString("IdCard");
        }
        return Idcard;
    }
}
