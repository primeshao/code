import java.util.*;
public class test5{
	public static void main(String args[]){
		int i,j;
		int N_1,N_2;
		Scanner reader=new Scanner(System.in);
		System.out.print("Plese enter the plaintext to be encrypted:");
		String temp_1=reader.nextLine();
		char plainText[]=temp_1.toCharArray();
		System.out.print("Plese input key:");
		String temp_2=reader.nextLine();
		char key[]=temp_2.toCharArray();
		N_1=plainText.length;
		N_2=key.length;
		char cipherText[]=new char[N_1];
		for(i=0;i<N_1;i++){
			j=i%N_2;
			cipherText[i]=(char)(plainText[i]^key[j]);
		}
		System.out.print("cipherText:");
		for(i=0;i<N_1;i++){
			System.out.print(cipherText[i]);
		}
		System.out.print("\nplainText:");
		for(i=0;i<N_1;i++){
			System.out.print(plainText[i]);
		}
		System.out.println();
	}
}
//Do not use capitals or lowercases in both plaintext and secret keys.It will meet Some mistakes!