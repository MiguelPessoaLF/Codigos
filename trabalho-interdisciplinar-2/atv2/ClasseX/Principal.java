package com.ti2cc;

import java.util.Scanner;
import java.util.List;

public class Principal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DAO dao = new DAO();
        dao.conectar();

        int opcao = -1;

        while (opcao != 0) {
            System.out.println("\n=== MENU PRINCIPAL ===");
            System.out.println("1 - Inserir usuário");
            System.out.println("2 - Atualizar usuário");
            System.out.println("3 - Excluir usuário");
            System.out.println("4 - Listar usuários");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");
            opcao = sc.nextInt();
            sc.nextLine(); // consumir quebra de linha

            switch (opcao) {
                case 1: // INSERIR
                    System.out.print("Código: ");
                    int codigo = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Login: ");
                    String login = sc.nextLine();
                    System.out.print("Senha: ");
                    String senha = sc.nextLine();
                    System.out.print("Sexo (M/F): ");
                    char sexo = sc.nextLine().charAt(0);

                    Usuario u1 = new Usuario(codigo, login, senha, sexo);
                    if (dao.inserirUsuario(u1)) {
                        System.out.println("Usuário inserido com sucesso!");
                    } else {
                        System.out.println("Erro ao inserir usuário.");
                    }
                    break;

                case 2: // ATUALIZAR
                    System.out.print("Informe o código do usuário a atualizar: ");
                    int codUpdate = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Novo login: ");
                    String novoLogin = sc.nextLine();
                    System.out.print("Nova senha: ");
                    String novaSenha = sc.nextLine();
                    System.out.print("Novo sexo (M/F): ");
                    char novoSexo = sc.nextLine().charAt(0);

                    Usuario u2 = new Usuario(codUpdate, novoLogin, novaSenha, novoSexo);
                    if (dao.atualizarUsuario(u2)) {
                        System.out.println("Usuário atualizado com sucesso!");
                    } else {
                        System.out.println("Erro ao atualizar usuário.");
                    }
                    break;

                case 3: // EXCLUIR
                    System.out.print("Informe o código do usuário a excluir: ");
                    int codDelete = sc.nextInt();
                    sc.nextLine();

                    if (dao.excluirUsuario(codDelete)) {
                        System.out.println("Usuário excluído com sucesso!");
                    } else {
                        System.out.println("Erro ao excluir usuário.");
                    }
                    break;

                case 4: // LISTAR
                    List<Usuario> lista = dao.getUsuarios();
                    System.out.println("\n--- Usuários cadastrados ---");
                    for (Usuario u : lista) {
                        System.out.println(u.toString());
                    }
                    break;

                case 0:
                    System.out.println("Saindo...");
                    break;

                default:
                    System.out.println("Opção inválida.");
            }
        }

        dao.close();
        sc.close();
    }
}
