import java.net.*;

public class SR implements Runnable {
	InetAddress adress;
	DatagramSocket postman;
	DatagramPacket sentPack;
	DatagramPacket receivePack;
	public SR() {
		try{
			postman = new DatagramSocket();
			adress = InetAddress.getByName(Demo.IP);
		}
		catch(Exception e) {}
		String mess = Demo.messageSent;
		byte[] buffer = mess.getBytes();
		sentPack = new DatagramPacket(buffer,buffer.length,adress,Demo.port);
		sentPack.setData(buffer);
		buffer = new byte[8192];
		receivePack = new DatagramPacket(buffer,buffer.length);
	}
	public void run() {
		String name = Thread.currentThread().getName();
		if(name.equalsIgnoreCase("Sent")) {
			try{
				postman.send(sentPack);
			}
			catch(Exception e) {}
		}
		if(name.equalsIgnoreCase("Receive")) {
			try {
				postman.receive(receivePack);
				Demo.messageReceive = new String(receivePack.getData(),0,receivePack.getLength());
				Demo.receiveArea.append(Demo.messageReceive+"\n");
			}
			catch(Exception e) {}
		}
	}
}