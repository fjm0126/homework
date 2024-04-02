package com.qg.ajax;

import java.io.*;
import java.sql.*;

import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;


@WebServlet("/Jquery-Ajax")
public class HelloServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        Connection connection;
        PrintWriter out = response.getWriter();
        out.println("用户姓名如下：");
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/ATM", "root", "20050126");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        String sql = "select * from user";
        PreparedStatement preparedStatement;
        try {
            preparedStatement = connection.prepareStatement(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        ResultSet resultSet;
        try {
            resultSet = preparedStatement.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
            try {
                while (resultSet.next()) {
                    out.println(resultSet.getString("UserName"));
                }
            } catch (SQLException h) {
                throw new RuntimeException(h);
            }
            try {
                connection.close();
                preparedStatement.close();
                resultSet.close();
            } catch (SQLException h) {
                throw new RuntimeException(h);
            }
        }
    }


