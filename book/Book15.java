/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.TreeSet; 
import java.util.NavigableSet;
import java.util.Iterator;
 
class Book15 {
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
	public static void main (String[] args) {
		FastReader s=new FastReader(); 
		int n = s.nextInt();
		int m = s.nextInt();
		int k = s.nextInt();
		int h[] = new int[n];
		TreeSet<Integer> tset = new TreeSet<Integer>(); 		
		Integer ai = 0;
		for(int j = 0; j < n; j++){
			h[j] = s.nextInt();
		}
		while(m > 0){			
			tset.add(s.nextInt());					
			m = m - 1;
		}
		m = 0;
		for(int i = 0; i < n; i = i + 1){
			if(tset.contains(h[i])){
				m = m + 1;
				tset.remove(h[i]);
			}else{		
				NavigableSet<Integer> ns = tset.subSet(h[i] - k, true, h[i] + k, true);
				if(!ns.isEmpty()){		
					ai = ns.floor(h[i]);
                                        if(ai != null){
                                            m = m + 1;					
                                            tset.remove(ai);
                                        }                                        					
				}
			}
		}
		
		System.out.print(n);
	}
}






