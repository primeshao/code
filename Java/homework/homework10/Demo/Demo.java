import java.util.*;
public class Demo {
	public static void main(String args[]) {
		System.out.print("Input your birthday for the key(e.g.:20000101):");
		Scanner reader = new Scanner(System.in);
		long inputKey = reader.nextLong();
		System.out.print("Input the string which your want encrypt:");
		String inputString = reader.nextLine();
		inputString = reader.nextLine();
		String stringTemp = RandomApp.encrypt(inputString, inputKey);
		System.out.println("cipher text:"+stringTemp);
		stringTemp = RandomApp.encrypt(stringTemp, inputKey);
		System.out.println("proclaimed text:"+stringTemp);
		int a[] = new int[5];
		int b[] = new int[5];
		RandomApp.getRandomNumber(1, 10, a, b);
		System.out.print("a:");
		for(int i = 0;i<5;i++) {
			System.out.print(a[i]+" ");
		}
		System.out.print("\nb:");
		for(int i = 0;i<5;i++) {
			System.out.print(b[i]+" ");
		}
	}
}