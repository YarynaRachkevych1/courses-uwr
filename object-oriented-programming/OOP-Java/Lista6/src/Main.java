// Yaryna Rachkevych
// PO Lista 6, Zadanie 1
// (Na bazie zadnia 1, listy 3 - implementacja klasy Lista<T> z odpowiednimi metodami)

import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception {
        Lista<String> l1 = new Lista<>();
        l1.pushFront("c");
        l1.pushFront("b");
        l1.pushFront("a");
        l1.pushBack("d");

        // Zapisywanie l1 do pliku:
        // Utworzenie pliku dla przechowywania l1
        try (FileOutputStream fos = new FileOutputStream("lista1.ser");
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {

            // zapisanie obiektu do pliku
            oos.writeObject(l1);
        }

        // Wczytywanie l1 z pliku i zapisywaniedo l2:
        Lista<String> l2;
        // Utworzenie pliku dla wczytania l1
        try (FileInputStream fis = new FileInputStream("lista1.ser");
             ObjectInputStream ois = new ObjectInputStream(fis)) {

            // Wczytywanie l1 do l2
            l2 = (Lista<String>) ois.readObject();
        }

        System.out.println("Stara lista l1: " + l1.printList());
        System.out.println("Nowa lista l2: "+l2.printList());
    }
}

