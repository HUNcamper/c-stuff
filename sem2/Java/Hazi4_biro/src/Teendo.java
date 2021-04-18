public class Teendo {
    private String nev;
    private String ido;
    private int prioritas;
    private boolean teljesitettuk;

    public void setNev(String nev) {
        this.nev = nev;
    }

    public void setIdo(String ido) {
        this.ido = ido;
    }

    public void setPrioritas(int prioritas) {
        if(prioritas >= 1 && prioritas <= 5) this.prioritas = prioritas;
        else {
            this.prioritas = 5;
            System.err.println("Hibás prioritás! 5 alapértékre állítva.");
        }
    }

    public String getNev() {
        return nev;
    }

    public String getIdo() {
        return ido;
    }

    public int getPrioritas() {
        return prioritas;
    }

    public boolean isTeljesitettuk() {
        return teljesitettuk;
    }

    public void atvalt() {
        this.teljesitettuk = !this.teljesitettuk;
    }

    public Teendo() {
        this.nev = "DefaultNév";
        this.ido = "DefaultIdő";
        this.prioritas = 1;
        this.teljesitettuk = false;
    }

    public Teendo(String nev, String ido, int prioritas) {
        setNev(nev);
        setIdo(ido);
        setPrioritas(prioritas);
        this.teljesitettuk = false;
    }

    public static Teendo legfontosabb(Teendo[] teendok) {
        if(teendok.length == 0) return null;

        int legfontosabb_i = 0;
        for (int i = 0; i < teendok.length; i++) {
            if(teendok[i].prioritas < teendok[legfontosabb_i].prioritas) {
                legfontosabb_i = i;
            }
        }

        return teendok[legfontosabb_i];
    }

    @Override
    public String toString() {
        return "Teendo neve: " + getNev() + ", ideje: " + getIdo() + ", prioritasa: " + getPrioritas() + ", teljesitettuk: " + (isTeljesitettuk() ? "igen" : "nem");
    }
}
