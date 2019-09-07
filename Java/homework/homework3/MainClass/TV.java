public class TV {
	int channel=1;
	void setChannel(int c) {
		channel=c;		
	}
	int getChannel() {
		return channel;
	}
	void showProgram() {
		System.out.println("channel: "+getChannel());
		System.out.print("TVprogram: ");
		switch(getChannel()) {
			case 1 :System.out.println("Synthetical channel");break;
			case 2 :System.out.println("economical channel");break;
			case 3 :System.out.println("synthesis skill channel");break;
			case 4 :System.out.println("Chinese international channel");break;
			case 5 :System.out.println("sports channel");break;
			case 6 :System.out.println("movie channel");break;
			case 7 :System.out.println("soap opera channel");break;
			case 8 :System.out.println("English international channel");break;
			case 9 :System.out.println("drama channel");break;
			case 10 :System.out.println("society and law channel");break;
		}	
	}

}