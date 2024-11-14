//PO, Zadanie z Listy 7
//Yaryna Rachkevych
//Komendy do terminalu:
// 1) javac Main.java
// 2) java Main <nazwa_pliku> <nazwa_klasy>
//Np: java Main m1 Motocykl

import javax.swing.*;
import java.awt.*;


public class MotocyklSwing extends JComponent {
    private JTextField modelTextField;
    private JTextField rokPrTextField;
    private JTextField maxPrTextField;

    public MotocyklSwing(Motocykl motocykl) {
        setLayout(new GridLayout(4, 2));
        JLabel modelLabel = new JLabel("Model:");
        modelTextField = new JTextField();
        JLabel rokPrLabel = new JLabel("Rok produkcji:");
        rokPrTextField = new JTextField();
        JLabel maxPrLabel = new JLabel("Maksymalna prędkość:");
        maxPrTextField = new JTextField();

        add(modelLabel);
        add(modelTextField);
        add(rokPrLabel);
        add(rokPrTextField);
        add(maxPrLabel);
        add(maxPrTextField);
    }

    public Motocykl getMotocykl(){
        String model = getModel();
        int rok = getRokProdukcji();
        int max = getMaksymalnaPredkosc();
        return new Motocykl(model, rok, max);
    }

    public String getModel() {
        return modelTextField.getText();
    }

    public int getRokProdukcji() {
        String rokPrString = rokPrTextField.getText();
        return Integer.parseInt(rokPrString);
    }

    public int getMaksymalnaPredkosc() {
        String maxPrString = maxPrTextField.getText();
        return Integer.parseInt(maxPrString);
    }
}
