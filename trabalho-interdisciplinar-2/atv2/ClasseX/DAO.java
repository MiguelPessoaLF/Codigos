package com.ti2cc;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DAO {
    private Connection conexao;

    public DAO() {
        conexao = null;
    }

    public boolean conectar() {
        String driverName = "org.postgresql.Driver";
        String serverName = "localhost";
        String mydatabase = "teste";
        int porta = 5432;
        String url = "jdbc:postgresql://" + serverName + ":" + porta + "/" + mydatabase;
        String username = "ti2cc";
        String password = "ti@cc";
        boolean status = false;

        try {
            Class.forName(driverName);
            conexao = DriverManager.getConnection(url, username, password);
            status = (conexao != null);
            System.out.println("Conexão efetuada com o postgres!");
        } catch (ClassNotFoundException e) {
            System.err.println("Conexão NÃO efetuada com o postgres -- Driver não encontrado -- " + e.getMessage());
        } catch (SQLException e) {
            System.err.println("Conexão NÃO efetuada com o postgres -- " + e.getMessage());
        }

        return status;
    }

    public boolean close() {
        boolean status = false;

        try {
            if (conexao != null) {
                conexao.close();
            }
            status = true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return status;
    }

    public boolean inserirUsuario(Usuario usuario) {
        boolean status = false;
        try {
            Statement st = conexao.createStatement();
            st.executeUpdate("INSERT INTO usuario (codigo, login, senha, sexo) "
                    + "VALUES (" + usuario.getCodigo() + ", '" + usuario.getLogin() + "', '"
                    + usuario.getSenha() + "', '" + usuario.getSexo() + "');");
            st.close();
            status = true;
        } catch (SQLException u) {
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean atualizarUsuario(Usuario usuario) {
        boolean status = false;
        try {
            Statement st = conexao.createStatement();
            String sql = "UPDATE usuario SET login = '" + usuario.getLogin()
                       + "', senha = '" + usuario.getSenha()
                       + "', sexo = '" + usuario.getSexo()
                       + "' WHERE codigo = " + usuario.getCodigo();
            st.executeUpdate(sql);
            st.close();
            status = true;
        } catch (SQLException u) {
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean excluirUsuario(int codigo) {
        boolean status = false;
        try {
            Statement st = conexao.createStatement();
            st.executeUpdate("DELETE FROM usuario WHERE codigo = " + codigo);
            st.close();
            status = true;
        } catch (SQLException u) {
            throw new RuntimeException(u);
        }
        return status;
    }

    // listar todos os usuários usando List<Usuario>
    public List<Usuario> getUsuarios() {
        List<Usuario> usuarios = new ArrayList<>();

        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM usuario");

            while (rs.next()) {
                Usuario u = new Usuario(
                        rs.getInt("codigo"),
                        rs.getString("login"),
                        rs.getString("senha"),
                        rs.getString("sexo").charAt(0)
                );
                usuarios.add(u);
            }

            st.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

        return usuarios;
    }
}
