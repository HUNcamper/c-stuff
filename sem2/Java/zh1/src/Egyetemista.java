public class Egyetemista {
    protected String neptunkod;
    protected int erdemjegy;
    protected boolean kedv;

    public String getNeptunkod() {
        return neptunkod;
    }

    public int getErdemjegy() {
        return erdemjegy;
    }

    public boolean isKedv() {
        return kedv;
    }

    public Egyetemista() {
        this.neptunkod = "hallgato01";
        this.erdemjegy = 4;
        this.kedv = true;
    }

    public Egyetemista(String neptunkod, int erdemjegy, boolean kedv) {
        this.neptunkod = neptunkod;

        if (erdemjegy < 1) this.erdemjegy = 1;
        else if (erdemjegy > 5) this.erdemjegy = 5;
        else this.erdemjegy = erdemjegy;

        this.kedv = kedv;
    }

    public void puskazas() {
        if (this.erdemjegy < 5) this.erdemjegy++;
        this.kedv = false;
    }

    public boolean prog1(int jegy) {
        if (jegy > 3) return true;

        return false;
    }

    public int nemKeneBukni(double atlag) {
        if (Math.round(atlag) < 2) atlag += 0.21;

        return (int)Math.round(atlag);
    }

    @Override
    public String toString() {
        return "A " + (isKedv() ? "" : "nem ") + "tanulo hallgatonak: " + getNeptunkod() + " a neptunkodja, erdemjegye: " + getErdemjegy() + " es " + (isKedv() ? "a tanulasi kedve pedig magas." : "nem tanul.");
    }
}
