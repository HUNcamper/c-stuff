import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BestPriceFinder {
    private Map<String, String> bestBuys;

    public BestPriceFinder() {
        this.bestBuys = new HashMap<String, String>();
    }

    public void addProduct(Product product, String shop) {
        this.bestBuys.put(product.getName(), shop);
    }

    public String getShopFor(String product) {
        if (!this.bestBuys.containsKey(product)) return null;
        return this.bestBuys.get(product);
    }

    public void printBestBuys() {
        for (Map.Entry<String, String> entry : this.bestBuys.entrySet()) {
            System.out.println("Buy " + entry.getKey() + " at " + entry.getValue() + ".");
        }
    }

    public int deleteShop(String shopToDelete) {
        List<String> toDelete = new ArrayList<String>();
        int db = 0;
        for (Map.Entry<String, String> entry : this.bestBuys.entrySet()) {
            if (entry.getValue().equals(shopToDelete)) {
                toDelete.add(entry.getKey());
                db++;
            }
        }

        for (String key : toDelete) {
            this.bestBuys.remove(key);
        }

        return db;
    }
}
