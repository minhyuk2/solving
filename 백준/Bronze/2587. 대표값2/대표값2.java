import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		List<Integer> lists = new ArrayList<>();

		for(int i=0;i<5;i++){
			int num = s.nextInt();
			lists.add(num);
		}
		Collections.sort(lists);
		int counts  = 0;
		for(int i=0;i<5;i++){
			counts += lists.get(i);
		}

		System.out.print(counts/5 + " ");
		System.out.println(lists.get(2));

	}
}
