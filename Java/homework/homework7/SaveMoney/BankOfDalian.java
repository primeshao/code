public class BankOfDalian extends Bank {
	double year;
	public double computerInterest() {
		super.year=(int)year;
		double r=year-(int)year;
		int day=(int)(r*1000);
		double yearInterest=super.computerInterest();
		double dayInterest=day*0.00012*savedMoney;
		interest=yearInterest+dayInterest;
		System.out.printf("The intetest of %d yuan in Bank of Dalian for %d years and %d days:%f yuan\n",savedMoney,super.year,day,interest);
		return interest;
	}
}