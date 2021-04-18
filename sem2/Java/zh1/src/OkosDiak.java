public class OkosDiak extends Egyetemista {
    private String helyszin;
    private double tanulmanyiatlag;

    public String getHelyszin() {
        return helyszin;
    }

    public double getTanulmanyiatlag() {
        return tanulmanyiatlag;
    }

    public OkosDiak(int erdemjegy, boolean kedv, String helyszin, double tanulmanyiatlag) {
        super("TTIK-INF", erdemjegy, kedv);

        if (!helyszin.equals("Otthon")) {
            helyszin = "Ha nem tanulsz, akkor megbuksz.";
            tanulmanyiatlag = 1.5;
        }

        this.helyszin = helyszin;
        this.tanulmanyiatlag = tanulmanyiatlag;
    }

    public boolean ingyenOtos(boolean felveheto) {
        if (felveheto) {
            if (this.tanulmanyiatlag + 1.0 > 5.0) {
                return false;
            }

            this.tanulmanyiatlag += 1.0;
        }

        return true;
    }

    @Override
    public void puskazas() {
        if (!this.helyszin.contains("Otthon") && !this.neptunkod.contains("lusta diak")) {
            this.neptunkod = "lusta diak " + this.neptunkod;
        }

        super.puskazas();
    }

    @Override
    public String toString() {
        return "O egy okos diak. NEM KELL PUSKAZNUNK!!!";
    }
}
