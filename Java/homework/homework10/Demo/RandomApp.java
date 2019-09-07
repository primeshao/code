import java.util.*;
public class RandomApp {
	public static String encrypt(String inputString,long key) {
		int N = inputString.length();
		Random random = new Random(key);
		short L[] = new short[N];
		char s[] = inputString.toCharArray();
		for(int i = 0;i<N;i++) {
			L[i] = (short)random.nextInt();
		}
		for(int i = 0;i<N;i++) {
			s[i] = (char) (s[i]^L[i]);
		}
		return new String(s);
	}
	public static void getRandomNumber(int min,int max,int a[],int b[]) {
		Random random = new Random();
		int c[] = new int[10];
		boolean[]  bool = new boolean[11];
		int randInt = 0;
        for(int i = 0; i < 10 ; i++) {
             do {
          	   randInt = random.nextInt(max)+min;
             }while(bool[randInt]);
            bool[randInt] = true;
            c[i] = randInt;
       }
        for(int i = 0;i<5;i++) {
        	a[i] = c[i];
        }
        for(int i = 0;i<5;i++) {
        	b[i] = c[i+5];
        }
	}		
}
