import java.util.Scanner;
public class MyTimeTest {
	public static void main(String args[]) {
		MyTime t1=new MyTime();
		MyTime t2=new MyTime();
		MyTime t3=new MyTime();
		System.out.print("c1:");
		t1.input(1);
		System.out.print("c2:");
		t2.input(0);
		t3=t1.add(t2);
		System.out.println(t2.output(0)+" after "+t1.output(1)+" is "+t3.output(1));
		t3=t1.reduce(t2);
		System.out.println(t2.output(0)+" before "+t1.output(1)+" is "+t3.output(1));
		t3=MyTime.Spacing(t1,t2);
		System.out.println("The time difference between "+t1.output(1)+" and "+t2.output(1)+" was "+t3.output(0));
	}
}
class MyTime {
	MyTime(){
		
	}
	MyTime(int h,int m,int s,int judge){
		TimeTransform(h,m,s,judge);
	}
	int hour=0;
	int minute=0;
	int second=0;
	void TimeTransform(int h,int m,int s,int judge) {
		if(s<0) {
			m-=(s/(-60)+1);
			s+=(60*(s/(-60)+1));
		}
		else if(s>=60) {
			m+=(s/60);
			s-=(60*(s/60));
		}
		if(m<0) {
			h-=(m/(-60)+1);
			m+=(60*(m/(-60)+1));
		}
		else if(m>=60) {
			h+=(m/60);
			m-=(60*(m/60));
		}
		if(judge==1) {
			{
				if(h<0) {
					h=((h%(-24))+24);
				}
				else {
					h=h%24;
				}
				
			}
			if(h==24) {
				h=0;
			}
			
		}
		hour=h;
		minute=m;
		second=s;
	}
	void input(int judge) {
		Scanner reader= new Scanner(System.in);
		System.out.println("Input the hour,mintue and second,seprated by enter:");
		TimeTransform(reader.nextInt(),reader.nextInt(),reader.nextInt(),judge);
	}
	String output(int judge) {
		if(judge==1) {
			return hour+":"+minute+":"+second;//e.g. 12:13:14
		}
		else return hour+"h"+minute+"m"+second+"s";//e.g. 12h13m14s
	}
	MyTime add(MyTime t) {
		return new MyTime(hour+t.hour,minute+t.minute,second+t.second,1);
	}
	MyTime reduce(MyTime t) {
		return new MyTime(hour-t.hour,minute-t.minute,second-t.second,1);
	}
	static MyTime Spacing(MyTime t1,MyTime t2) {
		t2.TimeTransform(t2.hour,t2.minute,t2.second,1);
		if(t1.hour>t2.hour) {
			return new MyTime(t1.hour-t2.hour,t1.minute-t2.minute,t1.second-t2.second,0);
		}
		else {
			return new MyTime(t2.hour-t1.hour,t2.minute-t1.minute,t2.second-t1.second,0);
		}
	}
}