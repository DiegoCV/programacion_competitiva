/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;


import java.util.TreeSet;
import java.util.Iterator;
import java.util.Scanner;

/**
 *
 * @author DIEGOCV
 */
public class Main {
    
    public static void main(String args[]){
        int t, n;
        String aux_string;
        String[] aux_vector;
        TreeSet<String> diccionario = new TreeSet<>();
        Scanner sc = new Scanner(System.in); 
        t = sc.nextInt();        
        while(t > 0){
            n = sc.nextInt();
            sc.skip("\n");
            aux_string = sc.nextLine();
            while(!aux_string.equals("FIN")){
                aux_vector = aux_string.split(" ");
                for(int i = 0; i < aux_vector.length; i = i + 1){
                    aux_vector[i] = aux_vector[i].replace(",","");
                    aux_vector[i] = aux_vector[i].replace(".","");
                    aux_vector[i] = aux_vector[i].replace("?","");
                    aux_vector[i] = aux_vector[i].replace("!","");                            
                    diccionario.add(aux_vector[i]);
                }
                aux_string = sc.nextLine();
            }
            Iterator ite = diccionario.iterator();
            while(ite.hasNext()){
                System.out.println(ite.next());
            }
            System.out.println("-");
            diccionario.clear();
            t = t - 1;
        }
    }           
}
