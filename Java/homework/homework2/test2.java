public class test2 {
	public static void main(String args[]) {
		int i;
		long sum=0,temp=0;
		for(i=1;i<=10;i++){
			temp*=10;
			temp+=8;
			sum+=temp;
			}
		System.out.println("sum="+sum);
		}
	}