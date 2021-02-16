package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");

        System.out.print("Ez egy szoveg");
        System.out.println("Ez egy szoveg!");
        System.out.printf("Ez %d C-bol ismeros kiiratas\n", 1);
        System.out.format("Ez %d C-bol ismeros kiiratas\n", 1);

        // Platformfüggetlenség: \n és \r\n elhagyása
        System.out.printf("Ez %d C-bol ismeros kiiratas"+System.lineSeparator(), 1);

        System.out.println("Most hibaüzenet következik:");
        System.err.println("Ez a hibaüzenet.");

        // Shortcut: "sout" + Enter & "serr" + Enter

        Scanner sc = new Scanner(System.in);
        System.out.println("Hello! Hogy hívnak?");
        String nev = sc.nextLine();
        System.out.println("Hello " + nev + "! Hany éves vagy?");
        int kor = sc.nextInt();
        System.out.println("Hello " + nev + ", aki " + kor + " éves.");
    }
}
