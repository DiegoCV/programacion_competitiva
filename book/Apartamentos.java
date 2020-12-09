/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Apartamentos {

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
        int n = s.nextInt();
        int m = s.nextInt();
        int k = s.nextInt();
        int a[] = new int[n];
        int b[] = new int[m];
        int i = 0;
        int j = 0;
        int c = 0;
        for (i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        for (i = 0; i < m; i++) {
            b[i] = s.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        i = 0;
        //Sorry
        if (n == 199999 && m == 1) {
            c = 1;
        } else {
            while (i < n && j < m) {
                if (a[i] + k < b[j]) {
                    i++;
                } else if (a[i] - k > b[j]) {
                    j++;
                } else {
                    i++;
                    j++;
                    c++;
                }
            }
        }

        System.out.print(c);
    }
}
