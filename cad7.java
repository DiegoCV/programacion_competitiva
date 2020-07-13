

import java.util.Scanner;
import java.util.Hashtable;

/**
 *
 * @author DIEGOCV
 */
public class Main {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int t, k, l, total;
        String aux_string;
        Hashtable<String, Integer> productos = new Hashtable<>();
        Scanner sc = new Scanner(System.in); 
        t = sc.nextInt();
        while(t > 0){
            total = 0;
            k = sc.nextInt();
            sc.skip("\n");
            for(int i = 1; i <= k; i = i + 1){             
               aux_string = sc.nextLine();
               productos.put(aux_string.split(" ")[0], Integer.parseInt(aux_string.split(" ")[1]));
            }
            l = sc.nextInt();
            sc.skip("\n");
            for(int i = 1; i <= l; i = i + 1){
               aux_string = sc.nextLine();
               total = total + (productos.get(aux_string.split(" ")[0])*Integer.parseInt(aux_string.split(" ")[1]));               
            }
            System.out.println(total);
            productos.clear();
            t = t - 1;
        }
      
    }
    
}