import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ExtremeShopping {
    private Map<String, List<Product>> extremeList;

    public ExtremeShopping() {
        this.extremeList = new HashMap<String, List<Product>>();
    }

    public void addShoppingList(String shop, List<Product> termekLista) {
        this.extremeList.put(shop, termekLista);
    }

    public void printShoppingLists() {
        for (Map.Entry<String, List<Product>> entry : this.extremeList.entrySet()) {
            System.out.println(entry.getKey());

            String out = "";
            for (Product product : entry.getValue()) {
                out += product.getName() + " ";
            }

            System.out.println(out.substring(0, out.length()-1)); // utolsó szóköz eltávolítása
        }
    }
}
