//PO, Zadanie z Listy 7
//Yaryna Rachkevych
//Komendy do terminalu:
// 1) javac Main.java
// 2) java Main <nazwa_pliku> <nazwa_klasy>
//Np: java Main m1 Motocykl

public class Motocykl extends Pojazd {
    public Motocykl(String model, int rok_pr, int max_pr){
        setModel(model);
        setRok_pr(rok_pr);
        setMax_pr(max_pr);
    }

    @Override
    public String toString() {
        return "Model: " + getModel() + " Rok produkcji, maksymalna prędkość: "
                + getRok_pr() + ", " + getMax_pr();
    }
}
