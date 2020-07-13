
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
        int t, n, bi;  
        int MAX = 600 + 1;
        int menor = MAX;
        int mayor = -MAX;
        Hashtable<Integer, Integer> minutos = new Hashtable<>();
        Scanner sc = new Scanner(System.in); 
        t = sc.nextInt();
        while(t > 0){
            n = sc.nextInt();
            menor = MAX;
            mayor = -MAX;
            for(int i = 0; i < n; i = i + 1){
                bi = sc.nextInt();
                if(minutos.containsKey(bi)){
                    minutos.put(bi, minutos.get(bi) + 1);
                }else{
                    minutos.put(bi,1);
                }
                if(bi < menor) menor = bi;
                if(bi > mayor) mayor = bi;
            }
            System.out.println("Horas diferentes: "+minutos.size());
            System.out.println("Temprano: "+menor/60+":"+menor%60);
            System.out.println("Tarde: "+mayor/60+":"+mayor%60);
            minutos.clear();
            t = t - 1;
        }
      
    }
    
}