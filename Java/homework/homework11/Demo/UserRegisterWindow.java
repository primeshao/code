import java.awt.event.*;
import java.util.*;
import javax.swing.*;
public class UserRegisterWindow extends JFrame implements ActionListener{
	User user[] = new User[1];
	User userTemp[];
	Box boxH;
	Box boxVOne,boxVTwo;
	JButton button1 = new JButton("Regist");
	JButton button2 = new JButton("Quit");
	JTextField jtest1 = new JTextField(10);
	JTextField jtest2 = new JTextField(10);
	JTextField jtest3 = new JTextField(10);
	JTextField jtest4 = new JTextField(10);
	JTextField jtest5 = new JTextField(10);
	JTextField jtest6 = new JTextField(10);
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == button1) {
			String userNo = jtest1.getText();
			String userName = jtest2.getText();
			String birthday = jtest3.getText();
			String email = jtest4.getText();
			String password1 = jtest5.getText();
			String password2 = jtest6.getText();
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
			if(password1.equals(password2)) {
				userTemp = new User[User.registerCount+1];
				for(int i = 0;i < user.length;i++) {
					userTemp[i] = user[i];
				}
				user = userTemp;
				user[User.registerCount] = new User();
				user[User.registerCount].register(userNo, userName, password1, date, email);
				JOptionPane.showMessageDialog(boxH, "Registration Successful!("+userName+":"+User.registerCount+")", "tip",JOptionPane.PLAIN_MESSAGE);
				}
			else JOptionPane.showMessageDialog(boxH, "Registration Failed!("+userName+")", "tip",JOptionPane.PLAIN_MESSAGE);
			}
		}
		if(e.getSource() == button2) {
			dispose();
		}
	}
	public UserRegisterWindow() {
		button1.addActionListener(this);
		button2.addActionListener(this);
		setLayout(new java.awt.FlowLayout());
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
	void init() {
		boxH = Box.createHorizontalBox();
		boxVOne = Box.createVerticalBox();
		boxVTwo = Box.createVerticalBox();
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(new JLabel("User number:"));
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(new JLabel("User name:"));
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(new JLabel("Birthday:"));
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(new JLabel("Email:"));
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(new JLabel("Password:"));
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(new JLabel("Password(again):"));
		boxVOne.add(Box.createVerticalStrut(5));
		boxVOne.add(button1);
		boxVTwo.add(jtest1);
		boxVTwo.add(jtest2);
		boxVTwo.add(jtest3);
		boxVTwo.add(jtest4);
		boxVTwo.add(jtest5);
		boxVTwo.add(jtest6);
		boxVTwo.add(Box.createVerticalStrut(5));
		boxVTwo.add(button2);
		boxH.add(boxVOne);
		boxH.add(Box.createHorizontalStrut(10));
		boxH.add(boxVTwo);
		add(boxH);	
	}
}
