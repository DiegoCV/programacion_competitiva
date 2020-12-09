/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;

import java.util.Scanner;

/**
 *
 * @author DIEGOCV
 */
public class Main {

    public static void main(String args[]) {
        
// Java Program to show segment tree operations like construction, 
// query and update 
class SegmentTree {

    int st_pair[]; // The array that stores segment tree nodes 
    int st_odd[];

    /* Constructor to construct segment tree from given array. This 
	constructor allocates memory for segment tree and calls 
	constructSTUtil() to fill the allocated memory */
    SegmentTree(int arr[], int n) {
        // Allocate memory for segment tree 
        //Height of segment tree 
        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));

        //Maximum size of segment tree 
        int max_size = 2 * (int) Math.pow(2, x) - 1;

        st_pair = new int[max_size]; // Memory allocation 
        st_odd = new int[max_size]; // Memory allocation 
        constructSTUtil(arr, 0, n - 1, 0);
    }

    // A utility function to get the middle index from corner indexes. 
    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }

    /* A recursive function to get the sum of values in given range 
		of the array. The following are parameters for this function. 

	st --> Pointer to segment tree 
	si --> Index of current node in the segment tree. Initially 
				0 is passed as root is always at index 0 
	ss & se --> Starting and ending indexes of the segment represented 
					by current node, i.e., st[si] 
	qs & qe --> Starting and ending indexes of query range */
    int getSumUtil(int ss, int se, int qs, int qe, int si, boolean flag) {
        // If segment of this node is a part of given range, then return 
        // the sum of the segment 
        if (qs <= ss && qe >= se) {
            if (flag) {
                return st_pair[si];
            } else {
                return st_odd[si];
            }
        }

        // If segment of this node is outside the given range 
        if (se < qs || ss > qe) {
            return 0;
        }

        // If a part of this segment overlaps with the given range 
        int mid = getMid(ss, se);
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1, flag)
                + getSumUtil(mid + 1, se, qs, qe, 2 * si + 2, flag);
    }

    /* A recursive function to update the nodes which have the given 
	index in their range. The following are parameters 
		st, si, ss and se are same as getSumUtil() 
		i --> index of the element to be updated. This index is in 
				input array. 
	diff --> Value to be added to all nodes which have i in range */
    void updateValueUtil(int ss, int se, int i, int diff_pair, int diff_odd, int si) {
        // Base Case: If the input index lies outside the range of 
        // this segment 
        if (i < ss || i > se) {
            return;
        }

        // If the input index is in range of this node, then update the 
        // value of the node and its children 
        st_pair[si] = st_pair[si] + diff_pair;
        st_odd[si] = st_odd[si] + diff_odd;

        if (se != ss) {
            int mid = getMid(ss, se);
            updateValueUtil(ss, mid, i, diff_pair,diff_odd, 2 * si + 1);
            updateValueUtil(mid + 1, se, i, diff_pair,diff_odd, 2 * si + 2);
        }
    }

    // The function to update a value in input array and segment tree. 
// It uses updateValueUtil() to update the value in segment tree 
    void updateValue(int arr[], int n, int i, int new_val) {
        // Check for erroneous input index 
        if (i < 0 || i > n - 1) {
            System.out.println("Invalid Input");
            return;
        }
        int indice = new_val;
        new_val = arr[indice];
        // Get the difference between new value and old value 
        int diff_pair = 0;
        int diff_odd = 0;

        if (arr[i] % 2 == 0) {
            if (new_val % 2 != 0) {
                diff_pair = -1;
                diff_odd = 1;
            }
        } else {
            if (new_val % 2 == 0) {
                diff_pair = 1;
                diff_odd = -1;
            }
        }
            // Update the value in array 
            arr[i] = arr[indice];

            updateValueUtil(0, n - 1, i, diff_pair, diff_odd, 0);

            // Update the values of nodes in segment tree    
        }

        // Return sum of elements in range from index qs (quey start) to 
// qe (query end). It mainly uses getSumUtil() 
        int getSum
        (int n, int qs, int qe, boolean flag
        
        
            ) {
        // Check for erroneous input values 
        if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }
            return getSumUtil(0, n - 1, qs, qe, 0, flag);
        }

        // A recursive function that constructs Segment Tree for array[ss..se]. 
        // si is index of current node in segment tree st 
        String constructSTUtil
        (int arr[], int ss, int se, int si
        
        
            ) {
        // If there is one element in array, store it in current node of 
        // segment tree and return 
        if (ss == se) {
                st_pair[si] = isPair(arr[ss]);
                st_odd[si] = isOdd(arr[ss]);
                return st_pair[si] + "-" + st_odd[si];
            }

            // If there are more than one elements, then recur for left and 
            // right subtrees and store the sum of values in this node 
            int mid = getMid(ss, se);
            String m1 = constructSTUtil(arr, ss, mid, si * 2 + 1);
            String m2 = constructSTUtil(arr, mid + 1, se, si * 2 + 2);
            st_pair[si] = Integer.parseInt(m1.split("-")[0]) + Integer.parseInt(m2.split("-")[0]);
            st_odd[si] = Integer.parseInt(m1.split("-")[1]) + Integer.parseInt(m2.split("-")[1]);
            return st_pair[si] + "-" + st_odd[si];
        }

        int isPair
        (int num
        
        
            ) {
        if (num % 2 == 0) {
                return 1;
            }
            return 0;
        }

        int isOdd
        (int num
        
        
            ) {
        if (num % 2 != 0) {
                return 1;
            }
            return 0;
        }
        //    // Driver program to test above functions 
//    public static void main(String args[]) {
//        int arr[] = {1, 2, 3, 4, 5, 6};
//        int n = arr.length;
//        SegmentTree1 tree = new SegmentTree1(arr, n);
//
//        tree.updateValue(arr, n, 0, 5);
//        System.out.println("" + tree.getSum(n, 0, 5, true));
//        System.out.println("" + tree.getSum(n, 0, 5, false));
//        // Update: set arr[1] = 10 and update corresponding segment 
//        // tree nodes 
////        tree.updateValue(arr, n, 2, 7, false);
////         tree.updateValue(arr, n, 0, 7, false);
////         tree.updateValue(arr, n, 5, 7, false);
////         tree.updateValue(arr, n, 1, 7, false);
////        tree.r();
////        System.out.println("");
//        for(int i = 0; i < arr.length; i++){
//          System.out.print(arr[i]+"-");
//        } 
////         System.out.println("");
//        // Find sum after the value is updated 
//
//    }
} 
        int n, q, aux, aux1, aux2;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i = i + 1) {
            arr[i] = sc.nextInt();
        }
        SegmentTree st = new SegmentTree(arr, arr.length);
        q = sc.nextInt();
        for (int i = 0; i < q; i = i + 1) {
            aux = sc.nextInt();
            aux1 = sc.nextInt();
            aux2 = sc.nextInt();
            switch (aux) {
                case 0:
                    if (!(arr[aux1 - 1] % 2 == 0 && arr[aux2 - 1] % 2 == 0) || !(arr[aux1 - 1] % 2 != 0 && arr[aux2 - 1] % 2 != 0)) {                   
                        st.updateValue(arr, arr.length, aux1 - 1, aux2 - 1);
                    }
                    break;
                case 1:
                    aux = st.getSum(arr.length, aux1 - 1, aux2 - 1, true);
                    System.out.println(aux);
                    break;
                default:
                    aux = st.getSum(arr.length, aux1 - 1, aux2 - 1, false);
                    System.out.println(aux);
            }
        }
    }
}
