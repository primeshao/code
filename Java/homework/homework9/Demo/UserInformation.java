import java.util.*;
public class UserInformation {
	String userNo;
	String userName;
	String password;
	Date birthday=null;
	short age;
	boolean loginState=false;
	String email;
	static int registerCount=0;
	void register(String userNo,String userName,String password,Date birthday,String email) {
		this.userNo=userNo;
		this.userName=userName;
		this.password=password;
		this.birthday=birthday;
		this.email=email;
		computeAge();
	}
	boolean login(String userNo,String password) {
		if(this.userNo.equals(userNo)&&this.password.equals(password)) {
			System.out.println("Login succeed!");
			return true;
		}
		else{
			System.out.println("Login failed!");
			return false;
		}
	}
	void logout(String userNo) {
		if(this.userNo.equals(userNo)) {
			System.out.println("Logout succeed!");
			loginState=false;
		}
		else System.out.println("Logout failed!");
	}
	boolean updatePassword(String userNo,String passwordOld,String passwordNew) {
		if(this.userNo==userNo&&this.password==passwordOld) {
			System.out.println("Update succeed!");
			return true;
		}
		else {
			System.out.println("Update failed!");
			return false;
		}
	}
	void computeAge() {
		Calendar cal = Calendar.getInstance();
		Calendar ca2 = Calendar.getInstance();
		cal.setTime(new Date());
		ca2.setTime(birthday);
		age=(short)(cal.get(Calendar.YEAR)-ca2.get(Calendar.YEAR));
	}
}