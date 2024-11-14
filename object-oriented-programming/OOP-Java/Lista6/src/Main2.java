// Yaryna Rachkevych
// PO Lista 6, Zadanie 2
// (Na bazie zadnia 1, listy 3 - implementacja klasy Lista<T> z odpowiednimi metodami)
// Medoty .remove, .removeAll oraz .retainAll nie są zaimplementowane w odpowiedni sposób

public class Main2 {
    public static void main(String[] args) throws Exception {
        Lista2<String> l1 = new Lista2<>();
        // Dodawanie elementow po kolei do listy
        l1.add("a");
        l1.add("c");
        l1.add("d");
        l1.add("e");

        Lista2<String> l2 = new Lista2<>();
        l2.add("y");
        l2.add("a");

        System.out.println("l1: "+l1.printList());
        System.out.println("l2: "+l2.printList());
        
        System.out.println("\nRozmiar j1 i l2: "+l1.size()+" "+l2.size());
        System.out.println("Czy l1 zawiera l2?: "+l1.containsAll(l2));
        System.out.println("Czy l1 zawiera 4?: "+l1.contains(4));

        l1.addAll(l2);
        System.out.println("\nl1 + l2: "+l1.printList());
        System.out.println("Czy teraz l1 zawiera l2?: "+l1.containsAll(l2));

        System.out.println("Interpretacja listy jako tablicy i wypisywanie jej elementow");
        for (var element : l1.toArray()) {
            System.out.println(element);
        }

        l2.clear();
        System.out.println("\nUsuwamy wszystko z l2");
        System.out.println("Czy teraz l2 jest pusta?: "+l2.isEmpty());
        System.out.println("Czy l1 jest pusta?: "+l1.isEmpty());

    }
}
