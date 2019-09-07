public class TestDemo {
	public static void main(String args[]) {
		Student Jack=new Student();
		Jack.setName("Jack");
		Jack.setSex('M');
		Jack.setHeight(1.85);
		Jack.setAge(19);
		Jack.setStudentNumber(1234567);
		Jack.setMajor("computer");
		Jack.setTotalCredits(2.5);
		Teacher Alice=new Teacher();
		Alice.setName("Alice");
		Alice.setSex('F');
		Alice.setHeight(1.65);
		Alice.setAge(29);
		Alice.setJobNumber(7654321);
		Alice.setCollege("college of computer");
		TestDemo.talk(Jack);
		System.out.println();
		TestDemo.talk(Alice);
	}
	static void talk(Student s) {
		System.out.println(s.getName()+" "+s.getSex()+" "+s.getHeight()+" "+s.getAge());
		System.out.println(s.getStudentNumber()+" "+s.getMajor());
		System.out.println("ToltalCredits:"+s.getToltalCredits());
		s.walk();
		s.speak();
		s.study();
		s.test();
	}
	static void talk(Teacher t) {
		System.out.println(t.getName()+" "+t.getSex()+" "+t.getHeight()+" "+t.getAge());
		System.out.println(t.getJobNumber()+" "+t.getCollege());
		t.walk();
		t.speak();
		t.teach();
		t.test();
	}
}
class People{
	String name;
	char sex;
	double height;
	int age;
	void setName(String n) {
		name=n;
	}
	void setSex(char s) {
		sex=s;
	}
	void setHeight(double h) {
		height=h;
	}
	void setAge(int a) {
		age=a;
	}
	String getName() {
		return name;
	}
	char getSex() {
		return sex;
	}
	double getHeight() {
		return height;
	}
	int getAge() {
		return age;
	}
	void walk() {
		System.out.println("walk as people");
	}
	void speak() {
		System.out.println("la la la la la la...");
	}
}
class Student extends People{
	long studentNumber;
	String major;
	double totalCredits;
	void setStudentNumber(long number) {
		studentNumber=number;
	}
	void setMajor(String m) {
		major=m;
	}
	void setTotalCredits(double c) {
		totalCredits=c;
	}
	long getStudentNumber() {
		return studentNumber;
	}
	String getMajor() {
		return major;
	}
	double getToltalCredits() {
		return totalCredits;
	}
	void walk() {
		System.out.println("walk as students");
	}
	void speak() {
		System.out.println("Hi,I am a student.");
	}
	void study() {
		System.out.println("I love study.");
	}	
	void test() {
		System.out.println("I'm going to test.");
	}
}
class Teacher extends People{
	long jobNumber;
	String college;
	void setJobNumber(long number) {
		jobNumber=number;
	}
	void setCollege(String c) {
		college=c;
	}
	long getJobNumber() {
		return jobNumber;
	}
	String getCollege() {
		return college;
	}
	void walk() {
		System.out.println("walk as teachers");
	}
	void speak() {
		System.out.println("Hello,I am a teachar.");
	}	
	void teach() {
		System.out.println("I like teach students.");
	}
	void test() {
		System.out.println("I'm writing out my examination paper.");
	}
}