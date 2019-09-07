public class CarDemo {
	public static void main(String args[]) {
		//Car testing...
		System.out.println("Car testing...");
		MyCar benz=new MyCar(2,3);
		benz.setBrand("benz");
		benz.showBrand();
		benz.setSpeed(110);
		benz.showSpeed();
		benz.speedUp();
		benz.showSpeed();
		benz.speedDown();
		benz.showSpeed();
		System.out.println("coordinates:"+benz.getCoordinates());
		benz.goForward(5);
		benz.turnLeft();
		benz.goForward(2);
		benz.turnRight();
		benz.goBack(6);
		benz.turnRight();
		benz.goForward(3);
		//Truck testing...
		System.out.println("Truck testing...");
		Truck yiqi=new Truck(4,7);
		yiqi.setBrand("yiqi");
		yiqi.showBrand();
		yiqi.setWeight(12000.5);
		yiqi.showWeight();
		yiqi.setSpeed(50);
		yiqi.showSpeed();
		yiqi.speedUp();
		yiqi.showSpeed();
		yiqi.speedDown();
		yiqi.showSpeed();
		System.out.println("coordinates:"+yiqi.getCoordinates());
		yiqi.goBack(3);
		yiqi.turnLeft();
		yiqi.goForward(2);
		yiqi.turnRight();
		yiqi.goForward(1);
		yiqi.turnLeft();
		yiqi.goForward(1);
		}
}
class Car{
	private int x;
	private int y;
	Car(int x,int y){
		this.x=x;
		this.y=y;
	}
	private int controller=0;
	private String brand;
	double speed;
	void turnRight() {
		System.out.println("turn right");
		controller--;
		if(controller<0) {
			controller+=4;
		}
		controller%=4;
	}
	void turnLeft() {
		System.out.println("turn left");
		controller++;
		controller%=4;
	}
	void goForward(int i) {
		switch(controller) {
		case 0: y+=i;break;
		case 1: x-=i;break;
		case 2: y-=i;break;
		case 3: x+=i;break;	
		}
		System.out.println("Forward:"+i+" coordinates:"+getCoordinates());
	}
	void goBack(int i) {
		switch(controller) {
		case 0: y-=i;break;
		case 1: x+=i;break;
		case 2: y+=i;break;
		case 3: x-=i;break;	
		}
		System.out.println("Back:"+i+" coordinates:"+getCoordinates());
	}
	void setBrand(String b) {
		brand=b;
	}
	void showBrand() {
		System.out.println(getBrand()+" car");
	}
	void setSpeed(double s) {
		speed=s;
	}
	void speedUp() {
		speed++;
	}
	void speedDown() {
		speed--;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	String getBrand() {
		return brand;
	}
	double getSpeed() {
		return speed;
	}
	void showSpeed() {
		System.out.println("Now speed:"+getSpeed());
	}
	String getCoordinates() {
		return "("+getX()+","+getY()+")";
	}
}
class MyCar extends Car{
	MyCar(int x,int y){
		super(x,y);
	}
	void speedUp() {
		System.out.print("speed up! ");
		speed+=5;
	}
	void speedDown() {
		System.out.print("speed down! ");
		speed-=5;
	}
}
class Truck extends Car{
	Truck(int x,int y){
		super(x,y);
	}
	double weight;
	void setWeight(double w) {
		weight=w;
	}
	double getWeight() {
		return weight;
	}
	void showWeight() {
		System.out.println("Weight:"+getWeight());
	}
	void speedUp() {
		System.out.print("speed up! ");
		speed+=0.5;
	}
	void speedDown() {
		System.out.print("speed down! ");
		speed-=0.5;
	}
	void showBrand() {
		System.out.println(getBrand()+" truck");
	}
}