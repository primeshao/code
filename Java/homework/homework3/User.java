import java.util.*;
public class User {
	public static void main(String args[]) {
		Scanner reader=new Scanner(System.in);
		Vehicle car=new Vehicle();
		System.out.println("speed_now:"+car.getSpeed());
		System.out.print("setpower:");
		car.setPower(reader.nextInt());
		System.out.println("power_now:"+car.getPower());
		System.out.print("speed up:");
		car.speedUp(reader.nextInt());
		System.out.println("speed_now:"+car.getSpeed());
		System.out.print("speed down:");
		car.speedDown(reader.nextInt());
		System.out.println("speed_now:"+car.getSpeed());
		System.out.println("\n\nEND:\nspeed_now:"+car.getSpeed()+"\npower_now:"+car.getPower());
	}

}
class Vehicle{
	double speed=50;
	int power=0;
	void speedUp(int s) {
		speed+=s;
	}
	void speedDown(int s) {
		speed-=s;	
	}
	void setPower(int s) {
		power=s;
		
	}
	int getPower() {
		return power;
	}
	double getSpeed() {
		return speed;
	}
}
