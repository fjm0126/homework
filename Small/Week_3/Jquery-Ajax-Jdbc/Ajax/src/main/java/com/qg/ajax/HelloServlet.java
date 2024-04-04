package com.qg.ajax;
import com.google.gson.Gson;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/Jquery-Ajax")
public class HelloServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws  IOException {
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        String userName = request.getParameter("userName");
        String password = request.getParameter("password");

        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        Map<String, Object> resultMap = new HashMap<>();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/ATM", "root", "20050126");
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
                resultMap.put("msg", "用户登录失败");
            }
            String jsonResponse = new Gson().toJson(resultMap);
            out.println(jsonResponse);
        } catch (SQLException e) {
            e.printStackTrace();
            resultMap.put("status", 500);
            resultMap.put("data", null);
            resultMap.put("msg", "服务器错误");
            out.println(new Gson().toJson(resultMap));
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
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
}

