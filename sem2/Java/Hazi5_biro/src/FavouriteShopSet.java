import java.util.Set;
import java.util.TreeSet;

public class FavouriteShopSet {
    Set<String> shops;

    public FavouriteShopSet() {
        this.shops = new TreeSet<String>();
    }

    public void addShop(String shop) {
        this.shops.add(shop);
    }

    public int countShops() {
        return this.shops.size();
    }

    public boolean isFavourite(String shop) {
        return this.shops.contains(shop);
    }

    public void printShops() {
        for (String shop : this.shops) {
            System.out.println(shop);
        }
    }

    public void delete(String shop) {
        this.shops.remove(shop);
    }
}
