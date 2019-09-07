import java.util.*;
public class User {
	String userNo;
	String userName;
	String password;
	Date birthday;
	short age = 0;
	String email;
	static int registerCount = 0;
	void register(String userNo,String userName,String password,Date birthday,String email) {
		this.userNo = userNo;
		this.userName = userName;
		this.password = password;
		this.birthday = birthday;
		this.email = email;
		computeAge();
		registerCount++;
	}
	void computeAge() {
		Calendar cal = Calendar.getInstance();
		Calendar ca2 = Calendar.getInstance();
		cal.setTime(new Date());
		ca2.setTime(birthday);
		age=(short)(cal.get(Calendar.YEAR)-ca2.get(Calendar.YEAR));
	}
}
