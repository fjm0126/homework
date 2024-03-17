package User;

public class UserInformation {
    private String UserName;
    private String PhoneNumber;
    private String IdCard;  //身份证
    private String BankNumber; //银行卡号
    private double Money;
    private String PassWord; //密码
    private String operate; //用户操作
    public UserInformation() {
    }

    public UserInformation(String UserName, String PhoneNumber, String IdCard, String BankNumber, double Money, String PassWord) {
        this.UserName = UserName;
        this.PhoneNumber = PhoneNumber;
        this.IdCard = IdCard;
        this.BankNumber = BankNumber;
        this.Money = Money;
        this.PassWord = PassWord;
    }
public UserInformation(String UserName, String PhoneNumber, String IdCard, String BankNumber,String operate,double Money) {
    this.UserName = UserName;
    this.PhoneNumber = PhoneNumber;
    this.IdCard = IdCard;
    this.BankNumber = BankNumber;
    this.operate=operate;
    this.Money=Money;
}

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String UserName) {
        this.UserName = UserName;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public void setPhoneNumber(String PhoneNumber) {
        this.PhoneNumber = PhoneNumber;
    }

    public String getIdCard() {
        return IdCard;
    }

    public void setIdCard(String IdCard) {
        this.IdCard = IdCard;
    }


    public String getBankNumber() {
        return BankNumber;
    }

    public void setBankNumber(String BankNumber) {
        this.BankNumber = BankNumber;
    }

    public double getMoney() {
        return Money;
    }
    public void setMoney(double Money) {
        this.Money = Money;
    }
    public String getPassWord() {
        return PassWord;
    }
    public void setPassWord(String PassWord) {
        this.PassWord = PassWord;
    }

    public String toString() {
        return "Account{UserName = " + UserName + ", PhoneNumber = " + PhoneNumber + ", IdCard = " + IdCard + ", BankNumber = " + BankNumber + ", Operate = " + operate + ", Money = " + Money + "}";
    }

    public String getOperate() {
        return operate;
    }

    public void setOperate(String operate) {
        this.operate = operate;
    }
}
