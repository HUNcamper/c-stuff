public class Megbeszeles extends Teendo {
    private String kivel;
    private String hol;
    public static int MEGBESZELES_DARAB = 0;

    public String getKivel() {
        return kivel;
    }

    public String getHol() {
        return hol;
    }

    public void setKivel(String kivel) {
        this.kivel = kivel;
    }

    public void setHol(String hol) {
        this.hol = hol;
    }

    public Megbeszeles(String ideje, String kivel, String hol) {
        super("Megbeszeles", ideje, 1);
        MEGBESZELES_DARAB++;

        setKivel(kivel);
        setHol(hol);
    }

    @Override
    public void setPrioritas(int prioritas) {
        super.setPrioritas(1);
    }

    @Override
    public String toString() {
        return "Megbeszeles, partner: " + getKivel() + ". Idopont: " + getIdo() + ". Helyszin: " + getHol();
    }
}
