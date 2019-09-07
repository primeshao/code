abstract class Employee{
	public abstract double earnings();
}
class YearWorker extends Employee{
	public double earnings() {
		return 12000;
	}
}
class MonthWorker extends Employee{
	public double earnings() {
		return 12*2300;
	}
}
class WeekWorker extends Employee{
	public double earnings() {
		return 52*780;
	}
}
class Company{
	Employee employee[];
	double Salaries=0;
	Company(Employee employee[]){
		this.employee=employee;
	}
	public double salariesPay() {
		double salaries=0;
		for(int i=0;i<employee.length;i++) {
			salaries+=employee[i].earnings();
		}
		return salaries; 
	}
}
public class CompanySalary {
	public static void main(String args[]) {
		Employee employee[]=new Employee[29];
		for(int i=0;i<employee.length;i++) {
			if(i%3==0)
				employee[i]=new WeekWorker();
			else if(i%3==1)
				employee[i]=new MonthWorker();
			else if(i%3==2)
				employee[i]=new YearWorker();
		}
		Company company=new Company(employee);
		System.out.println("Company payrool:"+company.salariesPay()+" yuan");
	}

}