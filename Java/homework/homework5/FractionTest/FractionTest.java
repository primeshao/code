import java.util.*;
public class FractionTest {
	public static void main(String args[]) {
		Scanner reader = new Scanner(System.in);
		System.out.print("numerator1:");
		int temp=reader.nextInt();
		System.out.print("denominator1:");
		Fraction f1=new Fraction(temp,reader.nextInt());
		System.out.print("numerator2:");
		temp=reader.nextInt();
		System.out.print("denominator2:");
		Fraction f2=new Fraction(temp,reader.nextInt());
		Fraction f3=new Fraction();
		System.out.print("f1=");
		f1.print_double();
		System.out.print("f2=");
		f2.print_double();
		f3=f1.add(f2);
		System.out.print(f1.a+"/"+f1.b+" + "+f2.a+"/"+f2.b+"=");
		f3.print();
		f3=f1.plus(f2);
		System.out.print(f1.a+"/"+f1.b+" - "+f2.a+"/"+f2.b+"=");
		f3.print();
		f3=f1.multiply(f2);
		System.out.print("("+f1.a+"/"+f1.b+")"+" * "+"("+f2.a+"/"+f2.b+")"+"=");
		f3.print();
		f3=f1.divide(f2);
		System.out.print("("+f1.a+"/"+f1.b+")"+" / "+"("+f2.a+"/"+f2.b+")"+"=");
		f3.print();
	}
}
class Fraction {
	int a;
	int b;
	Fraction(){
		a=0;
		b=0;
	}
	Fraction(int a, int b){
		int i=a;
		int j=b;
		if(i!=0&&j!=0){
			if(i<j) {
				int c=i;
				i=j;
				j=c;
			}
			int r=i%j;
			while(r!=0) {
				i=j;
				j=r;
				r=i%j;
			}
			i=a/j;
			j=b/j;
			if(j<=0) {
				i=-i;
				j=-j;
			}
		}
		this.a=i;
		this.b=j;
	}
	double toDouble() {
		return (a*1.0/b);
	}
	Fraction add(Fraction r) {
		if(b==0||r.b==0){
			return new Fraction(0,0); 
		}
		else{
			return new Fraction(a*r.b+r.a*b,b*r.b); 
		}
	}
	Fraction plus(Fraction r) {
		if(b==0||r.b==0){
			return new Fraction(0,0); 
		}
		else{
			return new Fraction(a*r.b-r.a*b,b*r.b);
		}
	}
	Fraction multiply(Fraction r) {
		if(b==0||r.b==0){
			return new Fraction(0,0); 
		}
		else{
			return new Fraction(a*r.a,b*r.b);
		}	
	}
	Fraction divide(Fraction r) {
		if(b==0||r.b==0){
			return new Fraction(0,0); 
		}
		else{
			return new Fraction(a*r.b,b*r.a);
		}	
	}
	
	void print() {
		if(this.b==0) {
			System.out.println("error");		
		}
		else if(this.a==0) {
			System.out.println("0");

		}
		else {
			System.out.println(this.a+"/"+this.b);
		}
	}
	void print_double() {
		if(b==0) {
			System.out.println("error");
		}
		else {
			System.out.println(toDouble());
		}

	}
}
