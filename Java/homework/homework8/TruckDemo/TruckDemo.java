import java.util.*;
public class TruckDemo {
	public static void main(String args[]) {
		Truck dongfeng=new Truck();
		dongfeng.setGoods();
		System.out.println("The total weight for the foods set on Dongfeng is "+dongfeng.getTotalWeight()+" kg.");
		
		
	}

}
interface ComputerWeight{
	double computrWeight();
}
class Television implements ComputerWeight{
	public double computrWeight() {
		return 10.0;
	}
}
class Computer implements ComputerWeight{
	public double computrWeight() {
		return 15.5;
	}
}
class WashMachine implements ComputerWeight{
	public double computrWeight() {
		return 25.5;
	}
}
class Truck {
	ComputerWeight goods[];
	int amount=0;
	void setGoods() {
		Scanner reader=new Scanner(System.in);
		System.out.print("How many goods do you want to express?");
		amount=reader.nextInt();
		goods=new ComputerWeight[amount];
		for(int i=0;i<goods.length;i++) {
			if(i%3==0) {
				goods[i]=new Television();
			}
			else if(i%3==1) {
				goods[i]=new Computer();
			}
			else {
				goods[i]=new WashMachine();
			}
		}
	}
	double getTotalWeight() {
		double totalWeight=0.0;
		for(int i=0;i<amount;i++) {
			totalWeight+=goods[i].computrWeight();
		}
		return totalWeight;
	}
}