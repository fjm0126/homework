package controller;
import ConnectionPool.*;
import User.User;
import Utils.InsertUser;
import Utils.createBanknumber;
import com.google.gson.Gson;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;
@WebServlet("/Jquery-Ajax")
public class ActionServlet extends BaseServlet {
    public void login(HttpServletRequest request, HttpServletResponse response) throws  IOException {
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        String userName = request.getParameter("userName");
        String password = request.getParameter("password");

        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        Map<String, Object> resultMap = new HashMap<>();

        try {
           ComeTrueConnectionpool comeTrueConnectionpool=new ComeTrueConnectionpool();
           comeTrueConnectionpool.initialConnectionpool();
           conn=comeTrueConnectionpool.getconnection();
            String sql = "SELECT * FROM user WHERE UserName = ? AND PassWord = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, userName);
            stmt.setString(2, password);
            rs = stmt.executeQuery();
            if (rs.next()) {
                User user = new User();
                user.setUsername(rs.getString("UserName"));
                user.setPhoneNumber(rs.getString("PhoneNumber"));
                resultMap.put("status", 200);
                resultMap.put("data", user);
                resultMap.put("msg", "用户登录成功");
            } else {
                resultMap.put("status", 400);
                resultMap.put("data", null);
                resultMap.put("msg", "用户名或密码错误，登录失败");
            }
            String jsonResponse = new Gson().toJson(resultMap);
            out.println(jsonResponse);
        } catch (SQLException e) {
            e.printStackTrace();
            resultMap.put("status", 500);
            resultMap.put("data", null);
            resultMap.put("msg", "服务器错误");
            out.println(new Gson().toJson(resultMap));
        } finally {
            try {
                if (rs!= null) rs.close();
                if (stmt!= null) stmt.close();
                if (conn!= null) conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    public void register(HttpServletRequest request, HttpServletResponse response) throws IOException, SQLException {
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        Map<String, Object> resultMap = new HashMap<>();
        String name = request.getParameter("name");
        String PhoneNumber = request.getParameter("phoneNumber");
        String IdCard=request.getParameter("IdCard");
        String password1=request.getParameter("password1");
        String checkPassword=request.getParameter("checkPassword");
        boolean flag=password1.matches("\\d{6}");
        if(Objects.equals(name, "") || Objects.equals(PhoneNumber, "") || Objects.equals(IdCard, "") || Objects.equals(checkPassword, "")|| password1.isEmpty())
        {
            resultMap.put("msg","请输入全部信息，不能为空！");
            out.println(new Gson().toJson(resultMap));
            return;
        }
        if(!flag)
        {
            resultMap.put("msg","注册失败，请输入6位纯数字密码！");
            out.println(new Gson().toJson(resultMap));
            return;
        }
        if(!password1.equals(checkPassword))
        {
            resultMap.put("msg","两次输入密码不一致，请重新输入！");
            out.println(new Gson().toJson(resultMap));
            return;
        }
        String Banknumber= createBanknumber.createBanknumber();
        double money=0;
        User user=new User(name,PhoneNumber,IdCard,Banknumber,money,password1);
        InsertUser.insertUser(user);
        resultMap.put("msg", "注册成功");
        out.println(new Gson().toJson(resultMap));
    }

    public void GetPassWord(HttpServletRequest request, HttpServletResponse response) throws IOException, SQLException {
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        Map<String, Object> resultMap = new HashMap<>();
        String name1=request.getParameter("name1");
        String IdCard1=request.getParameter("IdCard1");
        if(Objects.equals(name1, "") || Objects.equals(IdCard1, ""))
        {
            resultMap.put("msg","信息不能为空！");
            out.println(new Gson().toJson(resultMap));
            return;
        }
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        ComeTrueConnectionpool comeTrueConnectionpool=new ComeTrueConnectionpool();
        comeTrueConnectionpool.initialConnectionpool();
        conn=comeTrueConnectionpool.getconnection();
        String sql = "SELECT * FROM user WHERE UserName = ? AND IdCard = ?";
        stmt = conn.prepareStatement(sql);
        stmt.setString(1, name1);
        stmt.setString(2, IdCard1);
        rs = stmt.executeQuery();
        if(rs.next())
        {
            String password=rs.getString("PassWord");
            resultMap.put("msg","找回密码成功，密码是："+password);
            out.println(new Gson().toJson(resultMap));
        }
        else{
            resultMap.put("msg","此用户不存在！");
            out.println(new Gson().toJson(resultMap));
        }
    }
}

