import java.util.*;
public class Demo {
	public static void main(String args[]) {
		UserInformation user[]=new UserInformation[10];
		Scanner reader=new Scanner(System.in);
		System.out.println("Enter the user registration string to end with End:");
		String information=reader.nextLine();
		while(true) {
			user[UserInformation.registerCount]=new UserInformation();
			splitInformatin(user[UserInformation.registerCount],information);
			information=reader.nextLine();
			if(information.equals("End")) break;
			}
		user[0].computeAge();
		System.out.println("Login account1:\nUser1 number:");
		String tempUser=reader.nextLine();
		System.out.println("password:");
		if(user[0].login(tempUser, reader.nextLine())) user[0].loginState=true;
		System.out.println("Login account2:\nUser2 number:");
		tempUser=reader.nextLine();
		System.out.println("password:");
		if(user[1].login(tempUser, reader.nextLine())) user[1].loginState=true;
		System.out.print("Update password for user1:");
		System.out.println("(Input as 17111205005,ABC,123456)");
		StringTokenizer analyze=new StringTokenizer(reader.nextLine(),",");
		tempUser=analyze.nextToken();
		String tempPassword1=analyze.nextToken();
		String tempPassword2=analyze.nextToken();
		if(user[0].updatePassword(tempUser, tempPassword1, tempPassword2)) user[0].password=tempPassword2;
		System.out.println("Input user number to logout account1:");
		user[0].logout(reader.nextLine());
		System.out.println("User status information table:");
		System.out.println("User\t\tName\tBirthday\tage\tEmail\t\tLogin state\t");
		for(int i=0;i<=UserInformation.registerCount;i++) {
			System.out.print(user[i].userNo+"\t");
			System.out.print(user[i].userName+"\t");
			System.out.print(String.format("%tY-%<tm-%<td",user[i].birthday)+"\t");
			System.out.print(user[i].age+"\t");
			System.out.print(user[i].email+"\t");
			if(user[i].loginState) System.out.println("Online");
			else System.out.println("Offline");
		}
}
static void splitInformatin(UserInformation users,String information) {
	StringTokenizer analyze=new StringTokenizer(information,",");
	String userNo=analyze.nextToken();
	String userName=analyze.nextToken();
	String birthday=analyze.nextToken();
	String password=analyze.nextToken();
	String email=analyze.nextToken();
	if(emailTest(email)) {
		Date date=null;
		String dateStr=birthday;
		String[] dateDivide=dateStr.split("-");
		if(dateDivide.length==3){
		int year = Integer.parseInt(dateDivide [0].trim());
		int month = Integer.parseInt(dateDivide [1].trim());
		int day = Integer.parseInt(dateDivide [2].trim());
		Calendar c = Calendar.getInstance();
		c.set(year, month-1, day);
		date = c.getTime();
		users.register(userNo, userName, password, date, email);	
		UserInformation.registerCount++;
		}
	}
}
static boolean emailTest(String email) {
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
