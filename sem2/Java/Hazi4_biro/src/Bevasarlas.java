public class Bevasarlas extends Teendo {
    private String miket;
    private int maxOsszeg;

    public String getMiket() {
        return miket;
    }

    public int getMaxOsszeg() {
        return maxOsszeg;
    }

    public void setMiket(String miket) {
        this.miket = miket;
    }

    public void setMaxOsszeg(int maxOsszeg) {
        this.maxOsszeg = maxOsszeg;
    }

    public Bevasarlas(String ideje, String miket, int maxOsszeg) {
        super("Bevasarlas", ideje, 3);

        setMiket(miket);
        setMaxOsszeg(maxOsszeg);
    }

    public void frissit(String termek) {
        if (termek == "<torol>") {
            this.miket = "";
            this.maxOsszeg = 0;
        } else {
            this.miket += ", " + termek ;
            this.maxOsszeg += 1000;
        }
    }

    @Override
    public void setPrioritas(int prioritas) {
        super.setPrioritas(3);
    }

    @Override
    public String toString() {
        return "Bevasarlas. Termekek: " + getMiket() + ", tervezett osszeg: " + getMaxOsszeg() + " Ft";
    }
}
