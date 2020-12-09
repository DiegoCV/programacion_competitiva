
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 *
 * @author DIEGOCV
 */
public class Concert_Tickets {

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
        int n, m, i, j, k, c;
        n = s.nextInt();
        m = s.nextInt();
        ArrayList<Integer> h = new ArrayList();
        for (i = 0; i < n; i++) h.add(s.nextInt());
        h.sort(Integer::compareTo);
        for (i = 0; i < m; i++) {
            j = s.nextInt();
            c = -1;
            n = h.size();
            for (k = 0; k < n; k++) {
                if (h.get(k) == j) {
                    c = j;
                    h.remove(k);
                    break;
                } else if (h.get(k) < j) {
                    c = h.get(k);
                    if (k == n - 1) h.remove(k);                    
                } else {                    
                    break;
                }
            }
            System.out.println(c);
        }
    }

}
