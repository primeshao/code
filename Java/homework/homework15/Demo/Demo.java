import javax.swing.JTextArea;
public class Demo {
	static JTextArea receiveArea;
	static String messageSent,messageReceive,IP;
	static int port;
	public static void main(String args[]) {
		UDPClientForm win = new UDPClientForm();
	}
	public static void toSR() {
		SR sr = new SR();
		Thread sent,receive;
		sent = new Thread(sr);
		receive = new Thread(sr);
		sent.setName("Sent");
		receive.setName("Receive");
		sent.start();
		receive.start();
	}
}
