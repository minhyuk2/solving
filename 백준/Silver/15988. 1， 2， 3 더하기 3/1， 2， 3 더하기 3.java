
import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args){
	//이건 그냥 백덤블링해서 봐도 DP문제다
		List<Integer> list = new ArrayList<>();
		int[] dp = new int[1000005];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		dp[4] = 7;
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		for(int t=4;t<=1000004;t++){
			dp[t] = ((dp[t-1]%1000000009 + dp[t-2]%1000000009)%1000000009 + dp[t-3]%1000000009)%1000000009;
		}


		for(int i=0;i<N;i++){
			int num = sc.nextInt();
			System.out.println(dp[num]);
		}
	}
}
