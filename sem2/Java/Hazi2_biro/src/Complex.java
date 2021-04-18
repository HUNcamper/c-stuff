public class Complex {
    private final double real;
    private final double imag;

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    @Override
    public String toString() {
        return this.real + "+" + this.imag + "i";
    }

    public Complex add(Complex num) {
        // (a,b) + (c,d) = (a+c, b+d)
        double a = this.real;
        double b = this.imag;
        double c = num.real;
        double d = num.imag;
        return new Complex(this.real+num.real, this.imag+num.imag);
    }

    public Complex mul(Complex num) {
        // (a,b) * (c,d) = (ac-bd, bc+ad)
        return new Complex( this.real*num.real - this.imag*num.imag, this.imag*num.real + this.real*num.imag);
    }
}
