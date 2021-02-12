// megoldas

int main() {
    double egyikOldal = oldaltBeolvas();
    double masikOldal = oldaltBeolvas();

    double ker = kerulet(egyikOldal, masikOldal);
    double ter = terulet(egyikOldal, masikOldal);

    kiiras(ker, ter);

    return 0;
}