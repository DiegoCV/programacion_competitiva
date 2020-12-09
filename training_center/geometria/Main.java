import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static class Point implements Comparable<Point> {
		double x, y;
		
		Point eje;
		
		Point(double x, double y, Point eje){
			this.x = x;
			this.y = y;
			this.eje = eje;
		}
		
		double euclidean_distance(Point q) {
			double dx = (this.x-q.x) * (this.x-q.x);
			double dy = (this.y-q.y) * (this.y-q.y);
			return Math.sqrt(dx+dy);
		}
		
		double euclidean_distance_with_respect_to_eje() {
			double dx = (this.x-eje.x) * (this.x-eje.x);
			double dy = (this.y-eje.y) * (this.y-eje.y);
			return Math.sqrt(dx+dy);
		}
		

		@Override
		public int compareTo(Point arg) {
			if(this.euclidean_distance_with_respect_to_eje() > arg.euclidean_distance_with_respect_to_eje()) {
				return 1;
			}else if(this.euclidean_distance_with_respect_to_eje() < arg.euclidean_distance_with_respect_to_eje()) {
				return -1;
			}else {
				if(this.x < arg.x) { return -1;}
				else if(this.x > arg.x){ return 1;}
				
				if(this.y < arg.y) { return -1;}
				else { return 1;}
				
			}		
		}
		
	}
	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n, x0, y0;
		n=s.nextInt();
		x0 = s.nextInt();
		y0 = s.nextInt();
		Point eje = new Point(x0, y0, null);
		ArrayList<Point> points = new ArrayList<Point>();
		while(n > 0) {
			points.add(new Point(s.nextInt(), s.nextInt(), eje));
			n--;
		}
		Collections.sort(points);
		for (Point point : points) {
			System.out.println((int)point.x+" "+(int)point.y);
		}
		//s.close();
	}
}
