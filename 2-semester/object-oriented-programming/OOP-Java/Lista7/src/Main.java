//PO, Zadanie z Listy 7
//Yaryna Rachkevych
//Komendy do terminalu:
// 1) javac Main.java
// 2) java Main <nazwa_pliku> <nazwa_klasy>
//Np: java Main m1 Motocykl

import javax.swing.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        String nazwa_pl = args[0];
        String nazwa_kl = args[1];

        System.out.println(nazwa_kl);

        try{
            Object obj = null;
            File file = new File(nazwa_pl);

            if (file.exists()) {
                FileInputStream fis = new FileInputStream(file);
                ObjectInputStream ois = new ObjectInputStream(fis);
                obj = ois.readObject();
                ois.close();
            } else {

                if (nazwa_kl.equals("Motocykl")){
                    obj = new Motocykl("",0,0);
                }
                else if (nazwa_kl.equals("Tramwaj")){
                    obj = new Tramwaj("",0,0,0);
                }

            }

            if (obj instanceof Motocykl) {
                MotocyklSwing swing = new MotocyklSwing((Motocykl) obj);
                // wywołanie okienka swinga
                int result = JOptionPane.showConfirmDialog(null, swing, "Edycja motocylku", JOptionPane.OK_CANCEL_OPTION);
                if (result == JOptionPane.OK_OPTION) {
                    Motocykl motocykl = swing.getMotocykl();
                    FileOutputStream fos = new FileOutputStream(file);
                    ObjectOutputStream oos = new ObjectOutputStream(fos);
                    oos.writeObject(motocykl);
                    oos.close();
                    System.out.println("Zapisano obiekt: " + motocykl.toString());
                }
            } else if (obj instanceof Tramwaj) {
                TramwajSwing swing = new TramwajSwing((Tramwaj) obj);
                int result = JOptionPane.showConfirmDialog(null, swing, "Edycja tramwaju", JOptionPane.OK_CANCEL_OPTION);
                if (result == JOptionPane.OK_OPTION) {
                    Tramwaj tramwaj = swing.getTramwaj();
                    FileOutputStream fos = new FileOutputStream(file);
                    ObjectOutputStream oos = new ObjectOutputStream(fos);
                    oos.writeObject(tramwaj);
                    oos.close();
                    System.out.println("Zapisano obiekt: " + tramwaj.toString());
                }
            } else {
                // Jeżeli podano błędną nazwę klasy to informujemy
                // o tym użytkownika
                System.out.println("Nie znaleziono klasy: " + nazwa_kl);
                System.exit(1);
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}

