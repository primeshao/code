import java.util.*;
public class User {
	String userNo;
	String userName;
	String password;
	Date birthday;
	short age = 0;
	String email;
	String userSex;
	static int registerCount = 0;
	void register(String userNo,String userName,String password,Date birthday,String email,String userSex) {
		this.userNo = userNo;
		this.userName = userName;
		this.password = password;
		this.birthday = birthday;
		this.email = email;
		this.userSex = userSex;
		computeAge();
		registerCount++;
	}
	Object[] getInfo() {
		Object temp[] = {userNo,userName,userSex,String.format("%tF", birthday),email,password};
		return temp;
	}
	void computeAge() {
		Calendar cal = Calendar.getInstance();
		Calendar ca2 = Calendar.getInstance();
		cal.setTime(new Date());
		ca2.setTime(birthday);
		age=(short)(cal.get(Calendar.YEAR)-ca2.get(Calendar.YEAR));
	}
	static boolean isUserNo(String userNo) {
		char no[] = userNo.toCharArray();
		if(no.length == 11) return true;
		else return false;
	}
	static boolean isEmail(String email) {
		int count=0;
		for (int i = 0; i < email.length(); i++) {
			char chat = email.charAt(i);
			if (chat=='@') {
				count++;
				}
			if (count>1) {
				return false;
				}
			}
		int pointIndex=email.lastIndexOf(".");
		int aindex=email.indexOf("@");  
		if (pointIndex<aindex) {
			return false;
			}
		if (aindex+1>=pointIndex) {
			return false;
			}
		if (aindex==0) {
			return false;
			}      
		return true;
		}
	}