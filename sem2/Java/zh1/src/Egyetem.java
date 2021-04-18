public class Egyetem {
    private OkosDiak[] hallgatok;
    private final String kepzettseg;
    private int felev;

    public String getKepzettseg() {
        return kepzettseg;
    }

    public int getFelev() {
        return felev;
    }

    public void setFelev(int felev) {
        if (felev > 7) {
            System.err.println("Rutinos Egyetemisták vagyunk.");
        } else {
            this.felev = felev;
        }
    }

    public Egyetem(int hallgatokMaximalisSzama, String kepzettseg, int felev) {
        this.kepzettseg = kepzettseg;
        this.felev = felev;
        this.hallgatok = new OkosDiak[hallgatokMaximalisSzama];
    }

    public boolean zhIras(OkosDiak diak) {
        for (int i = 0; i < this.hallgatok.length; i++) {
            if(hallgatok[i] == null) {
                hallgatok[i] = diak;
                return true;
            }
        }

        return false;
    }

    public int egyetemiHallgatoOsszeg() {
        int db = 0;

        for (int i = 0; i < this.hallgatok.length; i++) {
            if(hallgatok[i] != null) db++;
        }

        return db;
    }
}
