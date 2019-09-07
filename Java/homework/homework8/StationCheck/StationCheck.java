public class StationCheck {
	public static void main(String args[]) {
		Goods good1=new Goods(false);
		Goods good2=new Goods(true);
		Machine myMachine=new Machine();
		try {
			System.out.println("Chack good1...");
			myMachine.checkBag(good1);
			System.out.println("Chack good2...");
			myMachine.checkBag(good2);
		}
		catch(DangerException d){
			d.toShow();
		}
	}
}
class DangerException extends Exception {
	public void toShow() {
		System.out.println("This is a dangerous article!!!");
	}
}
class Goods{	
	boolean isDanger;
	Goods(boolean b){
		isDanger=b;
	}
}
class Machine{
	public void checkBag(Goods goods) throws DangerException{
		if(goods.isDanger==true) {
			throw new DangerException();
		}
		
	}
}