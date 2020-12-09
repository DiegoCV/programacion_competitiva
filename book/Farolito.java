

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Farolito {

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

    static class Farol {

        public int left, center, rigth;

        public Farol(int left, int center, int rigth) {
            this.left = left;
            this.center = center;
            this.rigth = rigth;
        }

        public int mayor() {
            if (this.left > this.rigth) {
                return this.left;
            }
            return this.rigth;
        }
    }

    public static void main(String[] args) {
        FastReader s = new FastReader();
        int x, n, pi, aux, mayor = 0, nn;
        boolean flag;
        x = s.nextInt();
        n = s.nextInt();
        LinkedList<Farol> p = new LinkedList<>();
        Farol it, it_2;
        pi = s.nextInt();
        p.add(new Farol(pi, pi, x - pi));
        mayor = p.get(0).mayor();
        System.out.print(mayor + " ");
        n = n - 1;
        while (n > 0) {
            pi = s.nextInt();     
            flag = false;
            nn = p.size();
            for (int i = 0; i < nn ; i++) {
                it = p.get(i);
                if (pi > it.center) {      
                    aux = pi - it.center;
                    if(it.rigth == mayor) mayor = aux;                    
                    it.rigth = aux;
                    if(i == nn - 1 ){
                        Farol f = new Farol(it.rigth, pi, x-pi); 
                        p.add(f);                        
                        if(f.mayor() > mayor) mayor = f.mayor();
                    }else{
                        it_2 = p.get(i + 1);
                        it_2.left = it_2.center - pi;   
                        if(it_2.left == mayor) mayor = it_2.left;  
                        it.rigth = pi - it.rigth;
                        if(it.rigth == mayor) mayor = it.rigth;  
                        Farol f = new Farol(it.rigth, pi, it_2.left); 
                        p.add(i+1, f);                        
                        if(f.mayor() > mayor) mayor = f.mayor();                                                                       
                    }                                         
                    flag = true;
                    System.out.print(mayor+" ");
                    break;
                }             
                n = n - 1;
            }
            if(!flag){
                it = p.get(0);
                it.left = it.center - pi;   
                if(it.left == mayor) mayor = it.left;    
                Farol f = new Farol(pi, pi, it.left); 
                p.add(f);                        
                if(f.mayor() > mayor) mayor = f.mayor();                                               
                System.out.println(mayor+" ");
            }
        }

    }
}
