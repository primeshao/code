public class test2 {
	public static void main(String args[]) {
		int i,j,time=0,num=0;
		for(i=2;i<=100;i++){
			for(j=2;j<i/2;j++)
				if(i%j==0) time++;
			if(time==0){
				System.out.print(i+" ");
				num++;
				if(num%6==0)System.out.print("\n");
			}
			else time=0;
		}	
	}
}
