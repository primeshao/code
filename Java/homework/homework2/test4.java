import java.util.*;
public class test4{
	public static void main(String args[]){
		int N,i,j,count=0;
		Scanner reader=new Scanner(System.in);
		String temp=reader.nextLine();
		char userInput[]=temp.toCharArray();
		N=userInput.length;
		for(i='a';i<='z';i++){
			for(j=0;j<N;j++){
				if(userInput[j]==i){
					count++;
				}
			}
			if(count!=0){
				System.out.print((char)i+":"+count+"; ");
			}
			count=0;
		}
	}
}
//you can not use "#"