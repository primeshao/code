public class Test {
	public static void main(String args[]) {
		CPU cpu=new CPU();
		cpu.setSpeed(2200);
		HardDisk disk=new HardDisk();
		disk.setAmount(200);
		PC pc=new PC();
		pc.setCPU(cpu);
		pc.setHardDisk(disk);
		pc.show();
	}
	
}class PC {
	CPU cpu;
	HardDisk HD;
	void setCPU(CPU c) {
		cpu=c;
	}
	void setHardDisk(HardDisk h){
		HD=h;
	}
	void show() {
		System.out.println("CPU speed:"+cpu.getSpeed());
		System.out.println("HardDisk amount:"+HD.getAmount());
	}

}
class CPU {
	int speed;
	void setSpeed(int s) {
		speed=s;
	}
	int getSpeed(){
		return speed;
	}
}
class HardDisk {
	int mount;
	void setAmount(int m) {
		mount=m;
	}
	int getAmount(){
		return mount;
	}
}
	

