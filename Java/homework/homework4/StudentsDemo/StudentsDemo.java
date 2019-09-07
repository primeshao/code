import java.util.Scanner;
import java.lang.Object;
public class StudentsDemo {
	public static void main(String args[]) {
		int i;
		Students.count=1;
		Scanner reader = new Scanner(System.in);
		System.out.print("How many students do you want?->");
		int N=reader.nextInt();
		Students stu[]=new Students[N];
		for(i=0;i<N;i++) {
			System.out.println("Student"+(i+1));
			stu[i]=new Students();
			stu[i].newStudent();
		}//new student
		System.out.print("Searching by name:");
		String name_temp=reader.nextLine();//get /n
		name_temp=reader.nextLine();
		int count=0;
		for(i=0;i<N;i++) {
			if(stu[i].name.equals(name_temp)) {
				stu[i].outPutStudent();
				count++;
			}
		}
		if(count==0) {
			System.out.println("NOT FOUND!");
		}//Searching by name
		System.out.print("Searching by student number:");
		long studentNumber_temp=reader.nextLong();
		count=0;
		for(i=0;i<N;i++) {
			if(stu[i].studentNumber==studentNumber_temp) {
				stu[i].outPutStudent();
				count++;
			}
		}
		if(count==0) {
			System.out.println("NOT FOUND!");
		}//Searching by student number
		System.out.println("The best students in math£º");
		double mathMax=stu[0].math;
		for(i=1;i<N;i++) {
			if(stu[i].math>mathMax) {
				mathMax=stu[i].math;	
			}
		}
		for(i=0;i<N;i++) {
			if(stu[i].math==mathMax) {
				stu[i].outPutStudent();
			}
		}//math max
		System.out.println("The best students in total£º");
		double totalMax=stu[0].getTotalScore();
		for(i=1;i<N;i++) {
			if(stu[i].getTotalScore()>totalMax) {
				totalMax=stu[i].getTotalScore();	
			}
		}
		for(i=0;i<N;i++) {
			if(stu[i].getTotalScore()==totalMax) {
				stu[i].outPutStudent();
			}
		}//total Max
		System.out.println("The worst students in total£º");
		double totalMin=stu[0].getTotalScore();
		for(i=1;i<N;i++) {
			if(stu[i].getTotalScore()<totalMin) {
				totalMin=stu[i].getTotalScore();	
			}
		}
		for(i=0;i<N;i++) {
			if(stu[i].getTotalScore()==totalMin) {
				stu[i].outPutStudent();
			}
		}//total Min
		System.out.println("The stuent whose total score is higher than the average scores of all students, but at least one class fails:");
		double Score=0;
		for(i=0;i<N;i++) {
			Score+=stu[i].getTotalScore();
		}
		Score/=N;
		count=0;
		for(i=0;i<N;i++) {
			if(stu[i].getTotalScore()>Score) {
				if(stu[i].getMath()<60.0) {
					stu[i].outPutStudent();
					count++;
				}
				else if(stu[i].getEnglish()<60.0) {
					stu[i].outPutStudent();
					count++;
				}
				else if(stu[i].getComputer()<60.0) {
					stu[i].outPutStudent();
					count++;
				}
			}
		}
		if(count==0) {
			System.out.println("NOT FOUND!");		
		}//Biased undergraduates		
	}

}
class Students {
	Scanner reader = new Scanner(System.in);
	static int count;
	int serialNumber;
	long studentNumber;
	String name;
	String sex;
	String major;
	double math;
	double computer;
	double english;
	Students(){
		serialNumber=count++;
	}
	void setName() {
		name=reader.nextLine();
	}
	void setStudentNumber() {
		studentNumber=reader.nextLong();
	}
	void setSex(){
		sex=reader.nextLine();
	}
	void setMajor() {
		major=reader.nextLine();
	}
	void setMath() {
		math=reader.nextDouble();
	}
	void setComputer() {
		computer=reader.nextDouble();
	}
	void setEnglish(){
		english=reader.nextDouble();
	}
	int getSerialNumber() {
		return serialNumber;
	}
	String getName() {
		return name;
	}
	long getStudentNumber() {
		return studentNumber;
	}
	String getSex() {
		return sex;
	}
	String getMajor() {
		return major;
	}
	double getMath() {
		return math;
	}
	double getComputer() {
		return computer;
	}
	double getEnglish() {
		return english;
	}
	double getTotalScore() {
		return math+computer+english;
	}
	double getAverageScore() {
		return (math+computer+english)/3.0;
	}
	void newStudent() {
		System.out.print("name:");
		setName();
		System.out.print("sex:(M/F):");
		setSex();
		System.out.print("major:");
		setMajor();
		System.out.print("student number:");
		setStudentNumber();
		System.out.print("math scores:");
		setMath();
		System.out.print("computer scores:");
		setComputer();
		System.out.print("english scores:");
		setEnglish();	
	}
	void outPutStudent() {
		System.out.println("serial number:"+getSerialNumber());
		System.out.println("student number:"+getStudentNumber());
		System.out.println("name:"+getName());
		System.out.println("sex:"+getSex());
		System.out.println("major:"+getMajor());
		System.out.println("math scores:"+getMath());
		System.out.println("computer scores:"+getComputer());
		System.out.println("english scores:"+getEnglish());
		System.out.println("average score:"+getAverageScore());
		System.out.println("total score:"+getTotalScore());
	}
}