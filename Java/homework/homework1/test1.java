public class test1 {
	public static void main(String args[]) {
		int i,j,sum=0,temp=1;
		for(i=1;i<=10;i++){
			for(j=1;j<=i;j++)
				temp*=j;
			sum+=temp;
			temp=1;
		}
		System.out.println("sum="+sum);
	}

}
