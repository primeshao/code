import java.util.*;
public class ComplexDemo {
	public static void main(String args[]) {
		System.out.println("Test...");
		Complex c1=new Complex(0,0);
		System.out.println("set c1...");
		c1.set();
		System.out.print("c1=");
		c1.output();
		Complex c2=new Complex(0,0);
		System.out.println("set c2...");
		c2.set();
		System.out.print("c2=");
		c2.output();
		//new
		Complex c3=c1.add(c2);
		System.out.print("way1:c1+c2=");
		c3.output();
		c3=Complex.add(c1, c2);
		System.out.print("way2:c1+c2=");
		c3.output();
		//add
		c3=c1.cut(c2);
		System.out.print("way1:c1-c2=");
		c3.output();
		c3=Complex.cut(c1, c2);
		System.out.print("way2:c1-c2=");
		c3.output();
		//cut
		c3=c1.multi(c2);
		System.out.print("way1:c1*c2=");
		c3.output();
		c3=Complex.multi(c1, c2);
		System.out.print("way2:c1*c2=");
		c3.output();
		//multi
		c3=c1.devision(c2);
		System.out.print("way1:c1/c2=");
		c3.output();
		c3=Complex.devision(c1, c2);
		System.out.print("way2:c1/c2=");
		c3.output();
	}
}
class Complex {
	double realPart=0.0;
	double imaginaryPart=0.0;
	Complex(double temp1,double temp2){
		realPart=temp1;
		imaginaryPart=temp2;
	}
	Complex add(Complex c) {
		double temp1=realPart+c.realPart;
		double temp2=imaginaryPart+c.imaginaryPart;
		return new Complex(temp1,temp2);
	}
	static Complex add(Complex c1,Complex c2) {
		double temp1=c1.realPart+c2.realPart;
		double temp2=c1.imaginaryPart+c2.imaginaryPart;
		return new Complex(temp1,temp2);
		
	}
	//add
	Complex cut(Complex c) {
		double temp1=realPart-c.realPart;
		double temp2=imaginaryPart-c.imaginaryPart;
		return new Complex(temp1,temp2);
	}
	static Complex cut(Complex c1,Complex c2) {
		double temp1=c1.realPart-c2.realPart;
		double temp2=c1.imaginaryPart-c2.imaginaryPart;
		return new Complex(temp1,temp2);		
	}
	//cut
	Complex multi(Complex c) {
		double temp1=realPart*c.realPart-imaginaryPart*c.imaginaryPart;
		double temp2=imaginaryPart*c.realPart+realPart*c.imaginaryPart;
		return new Complex(temp1,temp2);
	}
	static Complex multi(Complex c1,Complex c2) {
		double temp1=c1.realPart*c2.realPart-c1.imaginaryPart*c2.imaginaryPart;
		double temp2=c1.imaginaryPart*c2.realPart+c1.realPart*c2.imaginaryPart;
		return new Complex(temp1,temp2);		
	}
	//multi
	Complex devision(Complex c) {
		double temp3=c.realPart*c.realPart+c.imaginaryPart*c.imaginaryPart;
		double temp1=(realPart*c.realPart+imaginaryPart*c.imaginaryPart)/temp3;
		double temp2=(imaginaryPart*c.realPart-realPart*c.imaginaryPart)/temp3;
		return new Complex(temp1,temp2);
	}
	static Complex devision(Complex c1,Complex c2) {
		double temp3=c2.realPart*c2.realPart+c2.imaginaryPart*c2.imaginaryPart;
		double temp1=(c1.realPart*c2.realPart+c1.imaginaryPart*c2.imaginaryPart)/temp3;
		double temp2=(c1.imaginaryPart*c2.realPart-c1.realPart*c2.imaginaryPart)/temp3;
		return new Complex(temp1,temp2);	
	}
	//devision
	void output() {
		if(imaginaryPart==0.0) System.out.println(realPart);
		else if(imaginaryPart<0.0) System.out.println(realPart+""+imaginaryPart+"i");
		else System.out.println(realPart+"+"+imaginaryPart+"i");
		
	}	
	void set() {
		Scanner reader=new Scanner(System.in);
		System.out.print("realPart:");
		realPart=reader.nextDouble();
		System.out.print("imaginaryPart:");
		imaginaryPart=reader.nextDouble();
	}


}