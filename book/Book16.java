
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
/**
 *
 * @author DIEGOCV
 */
public class Book16 {
 
    static class FastReader {
 
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    public static void main(String[] args) {
        FastReader s = new FastReader();
        int n, m, i, k, ai, bi;
        Long j, c, mi_k;
        n = s.nextInt();
        m = s.nextInt();        
        ArrayList<Long> h = new ArrayList();
        for (i = 0; i < n; i++) h.add(s.nextLong());
        h.sort(Long::compareTo);
        for (i = 0; i < m; i++) {
            j = s.nextLong();
            c = new Long(-1);
            n = h.size();
            k = n / 2;
            ai = 0;
            bi = n-1;
            while(ai <= bi){  
                mi_k = h.get(k); 
                if (mi_k == j) {
                    c = j;
                    h.remove(k);
                    break;
                } else if(ai == bi){
                    c = h.get(ai);
                    h.remove(ai);
                    break;
                } else if (mi_k < j) {
                    ai = k;                   
                } else if (mi_k > j) {                    
                    bi = k;                    
                }
                k = (ai + bi)/2;
                mi_k = h.get(k); 
                if(k == ai) {
                    if(h.get(bi) <= j ){
                        c = h.get(bi);
                        h.remove(bi);
                    }else if(mi_k <= j){
                        c = mi_k;
                        h.remove(ai);
                    }
                    break;
                }else if(k == bi) {
                    if(mi_k <= j ){
                        c = h.get(k);
                        h.remove(k);
                    }
                    break;
                }
            }
            System.out.println(c);
        }
    }
 
}
