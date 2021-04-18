public class Ember {
    protected String nev;
    protected int eletEro;

    public void setEletEro(int eletEro) {
        this.eletEro = eletEro < 0 ? 0 : eletEro;
    }

    public int getEletEro() {
        return this.eletEro;
    }

    public String getNev() {
        return this.nev;
    }

    public Ember() {
        this.nev = "ismeretlen";
        this.eletEro = 10;
    }

    public Ember(String nev, int eletEro) {
        this.nev = nev;
        this.eletEro = Math.abs(eletEro);
    }

    public boolean vajonElMeg() {
        return this.eletEro == 0 ? false : true;
    }

    public void gyogyul(int mennyit) {
        if(this.eletEro == 0) System.err.println("sajnalom, elkestetek");
        else {
            this.eletEro += mennyit;
        }
    }

    protected String getAllapot() {
        String allapot = "majd kicsattan az egeszsegtol";

        if(this.eletEro <= 10 && this.eletEro >= 1) allapot = "atlagos az allapota";
        else if(this.eletEro == 0)                  allapot = "halott";

        return allapot;
    }

    @Override
    public String toString() {
        String allapot = getAllapot();

        return "Emberunk neve " + this.nev + ", es jelenleg " + allapot + ".";
    }
}
