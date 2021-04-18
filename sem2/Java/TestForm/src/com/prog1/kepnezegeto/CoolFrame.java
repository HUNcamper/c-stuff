package com.prog1.kepnezegeto;

import javax.swing.*;

public class CoolFrame {
    public static void main(String[] args) {
        JFrame frame = new JFrame("CoolFrame");
        frame.setContentPane(new CoolFrame().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    private JButton button1;
    private JPanel panel1;
}
