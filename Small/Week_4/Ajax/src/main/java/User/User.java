package User;

public class User {
    private String UserName;
    private String PhoneNumber;
    private String IdCard;  //身份证
    private String BankNumber; //银行卡号
    private double Money;
    private String PassWord; //密码

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String userName) {
        UserName = userName;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public String getIdCard() {
        return IdCard;
    }

    public void setIdCard(String idCard) {
        IdCard = idCard;
    }

    public String getBankNumber() {
        return BankNumber;
    }

    public void setBankNumber(String bankNumber) {
        BankNumber = bankNumber;
    }

    public double getMoney() {
        return Money;
    }

    public void setMoney(double money) {
        Money = money;
    }

    public User(String userName, String phoneNumber, String idCard, String bankNumber, double money, String passWord) {
        UserName = userName;
        PhoneNumber = phoneNumber;
        IdCard = idCard;
        BankNumber = bankNumber;
        Money = money;
        PassWord = passWord;
    }
    public User(){

    }
    public String getPassWord() {
        return PassWord;
    }

    public void setPassWord(String passWord) {
        PassWord = passWord;
    }

    public void setUsername(String UserName) {
        this.UserName=UserName;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.PhoneNumber=PhoneNumber;
    }
}

