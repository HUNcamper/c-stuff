package com.company;



public class Main {

    public static void main(String[] args) {
        System.out.println("1. feladat:");
        lustalkodas(true, true);
        lustalkodas(true, false);

        System.out.println("2. feladat:");
        System.out.println(utolsoSzamjegyEgyenloseg(10, 20).toString());
        System.out.println(utolsoSzamjegyEgyenloseg(15, 20).toString());

        System.out.println("3. feladat:");
        System.out.println(utolsoSzamjegyEgyenlosegN(432542, 111542, 3).toString());
        System.out.println(utolsoSzamjegyEgyenlosegN(432542, 563123, 3).toString());

        System.out.println("4. feladat");
        System.out.println(honap(6));
        System.out.println(honap(12));
        System.out.println(honap(0));

        System.out.println("5. feladat");
    }

    // 1. feladat
    public static void lustalkodas(Boolean hetkoznap, Boolean vakacio) {
        System.out.println((!hetkoznap || vakacio) ? "Lustálkodhatunk" : "Nem lustálkodhatunk");
    }

    // 2. feladat
    public static Boolean utolsoSzamjegyEgyenloseg(Integer szam1, Integer szam2) {
        String szam1_s = szam1.toString();
        String szam2_s = szam2.toString();

        Integer szam1_len = szam1_s.length();
        Integer szam2_len = szam2_s.length();

        return szam1_s.charAt(szam1_len-1) == szam2_s.charAt(szam2_len-1);
    }

    // 3. feladat
    public static Boolean utolsoSzamjegyEgyenlosegN(Integer szam1, Integer szam2, Integer n) {
        String szam1_s = szam1.toString();
        String szam2_s = szam2.toString();

        Integer szam1_len = szam1_s.length();
        Integer szam2_len = szam2_s.length();

        String temp1 = "";
        String temp2 = "";

        for (int i = szam1_len-n; i < szam1_len; i++) {
            temp1 += szam1_s.charAt(i);
        }

        for (int i = szam2_len-n; i < szam2_len; i++) {
            temp2 += szam2_s.charAt(i);
        }

        return (temp1.equals(temp2));
    }

    // 4. feladat
    public static String honap(Integer ho) {
        String szoveg = "";

        switch(ho) {
            case 1:
                szoveg = "Januar";
                break;
            case 2:
                szoveg = "Februar";
                break;
            case 3:
                szoveg = "Marcius";
                break;
            case 4:
                szoveg = "Aprilis";
                break;
            case 5:
                szoveg = "Majus";
                break;
            case 6:
                szoveg = "Junius";
                break;
            case 7:
                szoveg = "Julius";
                break;
            case 8:
                szoveg = "Augusztus";
                break;
            case 9:
                szoveg = "Szeptember";
                break;
            case 10:
                szoveg = "Oktober";
                break;
            case 11:
                szoveg = "November";
                break;
            case 12:
                szoveg = "December";
                break;
            default:
                szoveg = "Nem ismert";
        }

        return szoveg;
    }

    // 5. feladat
    public static Integer primek(Integer n) {
        int[] numbers = new int[n];

        for (int i = 0; i < n; i++) {

        }
    }
}
