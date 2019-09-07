public class ConstructionBank extends Bank {
	double year;
	public double computerInterest() {
		super.year=(int)year;
		double r=year-(int)year;
		int day=(int)(r*1000);
		double yearInterest=super.computerInterest();
		double dayInterest=day*0.0001*savedMoney;
		interest=yearInterest+dayInterest;
		System.out.printf("The intetest of %d yuan in Construction Bank for %d years and %d days:%f yuan\n",savedMoney,super.year,day,interest);
		return interest;
	}
}