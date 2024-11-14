//PO, Zadanie z Listy 7
//Yaryna Rachkevych
//Komendy do terminalu:
// 1) javac Main.java
// 2) java Main <nazwa_pliku> <nazwa_klasy>
//Np: java Main m1 Motocykl

public class Tramwaj extends Pojazd {
    public int dl_trasy;
    public Tramwaj(String model, int rok_pr, int max_pr, int dl_trasy){
        setModel(model);
        setRok_pr(rok_pr);
        setMax_pr(max_pr);
        setDl_trasy(dl_trasy);
    }

    public void setDl_trasy(int dl_trasy) {
        this.dl_trasy = dl_trasy;
    }

    public int getDl_trasy() {
        return dl_trasy;
    }

    @Override
    public String toString() {
        return "Model: " + getModel() + " Rok produkcji, maksymalna prędkość, długość trasy: "
                + getRok_pr() + ", " + getMax_pr() + ", " + getDl_trasy();
    }
}
