public class test1 {
	public static void main(String args[]){
		int i,j,sum;
		for(i=2;i<1000;i++){
			sum=0;
			for(j=1;j<i;j++){
				if(i % j==0){
					sum += j;
				}
			}
			if(sum==i){
				System.out.print(i+" ");
			}
		}
	}
}