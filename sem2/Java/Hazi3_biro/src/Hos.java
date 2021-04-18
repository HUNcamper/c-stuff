public class Hos extends Ember {
    private int tamadas;
    private int sikerSzam;

    public int getTamadas() {
        return this.tamadas;
    }

    public int getSikerSzam() {
        return this.sikerSzam;
    }

    public void setSikerSzam(int sikerSzam) {
        if(this.sikerSzam <= sikerSzam) {
            this.sikerSzam = sikerSzam;
        }
    }

    public Hos(String nev, int eletEro, int tamadas, int sikerSzam) {
        super(nev, eletEro);

        this.tamadas =      tamadas < 0 ? 0 : tamadas;
        this.sikerSzam =    sikerSzam < 0 ? 0 : sikerSzam;
    }

    public void edzes() {
        if (vajonElMeg()) {
            this.tamadas++;
        }
    }

    @Override
    public void gyogyul(int mennyit) {
        this.eletEro += mennyit;
    }

    @Override
    public String toString() {
        String allapot = getAllapot();

        return "Emberunk neve " + this.nev + ", es jelenleg " + allapot + ". Ez az ember egy sarkanyolo hos, tamadasa " + this.tamadas + ", es eddig " + this.sikerSzam + " darab sarkanyt olt meg.";
    }
}
