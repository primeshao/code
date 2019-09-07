public class test3 {
	public static void main(String args[]){
		int i,sum=0;
		for(i=1;i<=8888;i++){
			sum+=i;
			if(sum>=8888){
				System.out.println("n="+(i-1));
				break;
			}

		}
	}
}