import java.util.ArrayList;
import java.util.List;

public class ShoppingList {
    private List<Product> items;

    public ShoppingList() {
        this.items = new ArrayList<Product>();
    }

    public void addProduct(Product product) {
        this.items.add(product);
    }

    public int countProducts() {
        return items.size();
    }

    public Product getProduct(int index) {
        if(index > countProducts()-1 || index < 0) return null;
        //return (Product)items.toArray()[index];

        int i = 0;
        for (Product product : this.items) {
            System.out.println(product.getName());
            if (index == i) return product;

            i++;
        }

        return null;
    }

    public void printProducts() {
        for (Product product : this.items) {
            System.out.println(product.getName());
        }
    }

    public void delete(Product toDelete) {
        items.remove(toDelete);
    }

    public int deleteUnimportant() {
        items.removeIf(product -> !product.isImportant());

        return countProducts();
    }
}
