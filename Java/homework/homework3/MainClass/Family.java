import java.util.Scanner;
public class Family {
	TV homeTV;
	Scanner reader=new Scanner(System.in);
	void buyTV(TV tv) {
		homeTV=tv;		
	}
	void remoteControlTV(int s) {
		homeTV.setChannel(s);
		
	}
	void seeTV() {
		System.out.println("Opening...");
		homeTV.showProgram();
		System.out.print("Now,we watch TV,choose channel:");
		remoteControlTV(reader.nextInt());
		homeTV.showProgram();
	}
}
