package orderpack;

public class Produs {
    private String denumire;
    private int pret;
    private int cantitate;
    public Produs(String denumire, int pret, int cantitate)
    {
        this.denumire = denumire;
        this.pret = pret;
        this.cantitate = cantitate;
    }
    public String getDenumire() {
        return denumire;
    }
    public void setDenumire(String denumire) {
        this.denumire = denumire;
    }
    public int getPret() {
        return pret;
    }
    public void setPret(int pret) {
        this.pret = pret;
    }
    public int getCantitate() {
        return cantitate;
    }
    public void setCantitate(int cantitate) {
        this.cantitate = cantitate;
    }

}
