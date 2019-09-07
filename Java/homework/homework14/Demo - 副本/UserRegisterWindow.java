import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class UserRegisterWindow extends JFrame implements ActionListener,ItemListener,KeyListener,FocusListener {
	String userNo;
	String userName;
	String email;
	String password1;
	String password2;
	String userSex;
	Date birthday = null;
	User userTemp[];
	Box boxH_1,boxH_2,boxH_3;
	Box boxV_1,boxV_2,boxV_3;
	JButton button1 = new JButton("Register");
	JButton button2 = new JButton("Cancle");
	JButton button3 = new JButton("Users List");
	JButton loginButton = new JButton("User Login");
	JTextField text1 = new JTextField(10);
	JTextField text2 = new JTextField(10);
	JTextField text3 = new JTextField(10);
	JTextField text4 = new JPasswordField(10);
	JTextField text5 = new JPasswordField(10);
	JComboBox<String> comBox1 = new JComboBox<String>();
	JComboBox<String> comBox2 = new JComboBox<String>();
	JComboBox<String> comBox3 = new JComboBox<String>();
	JComboBox<String> comBox4 = new JComboBox<String>();
	public UserRegisterWindow() {
		setLayout(new FlowLayout());
		addListener();
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
	void addListener() {
		//add ActionListener
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
		loginButton.addActionListener(this);
		//add ItemListener
		comBox1.addItemListener(this);
		comBox2.addItemListener(this);
		comBox3.addItemListener(this);
		comBox4.addItemListener(this);
		//add KeyListener
		text1.addKeyListener(this);
		text2.addKeyListener(this);
		text3.addKeyListener(this);
		text4.addKeyListener(this);
		text5.addKeyListener(this);
		//add FocusListener
		text1.addFocusListener(this);
		text2.addFocusListener(this);
		text3.addFocusListener(this);
		text4.addFocusListener(this);
		text5.addFocusListener(this);
	}
	void init() {
		//Box Setting
		boxH_1 = Box.createHorizontalBox();
		boxH_2 = Box.createHorizontalBox();
		boxH_3 = Box.createHorizontalBox();
		boxV_1 = Box.createVerticalBox();
		boxV_2 = Box.createVerticalBox();
		boxV_3 = Box.createVerticalBox();
		//add to boxV_1
		boxV_1.add(Box.createVerticalStrut(3));
		boxV_1.add(new JLabel("User Number:"));
		boxV_1.add(Box.createVerticalStrut(11));
		boxV_1.add(new JLabel("User Name:"));
		boxV_1.add(Box.createVerticalStrut(11));
		boxV_1.add(new JLabel("User Sex:"));
		boxV_1.add(Box.createVerticalStrut(11));
		boxV_1.add(new JLabel("Birthday:"));
		boxV_1.add(Box.createVerticalStrut(11));
		boxV_1.add(new JLabel("Email:"));
		boxV_1.add(Box.createVerticalStrut(11));
		boxV_1.add(new JLabel("Password:"));
		boxV_1.add(Box.createVerticalStrut(11));
		boxV_1.add(new JLabel("Password(again):"));
		//add to boxV_2
		boxV_2.add(text1);
		boxV_2.add(Box.createVerticalStrut(5));
		boxV_2.add(text2);
		boxV_2.add(Box.createVerticalStrut(5));
		boxV_2.add(comBox1);
		boxV_2.add(Box.createVerticalStrut(5));
		boxV_2.add(boxH_1);
		boxV_2.add(Box.createVerticalStrut(5));
		boxV_2.add(text3);
		boxV_2.add(Box.createVerticalStrut(5));
		boxV_2.add(text4);
		boxV_2.add(Box.createVerticalStrut(5));
		boxV_2.add(text5);
		//add to boxV_3
		boxV_3.add(boxH_2);
		boxV_3.add(Box.createVerticalStrut(25));
		boxV_3.add(boxH_3);
		//add to boxH_1
		boxH_1.add(comBox2);
		boxH_1.add(new JLabel("Year"));
		boxH_1.add(comBox3);
		boxH_1.add(new JLabel("Mouth"));
		boxH_1.add(comBox4);
		boxH_1.add(new JLabel("Day"));
		//add to boxH_2
		boxH_2.add(boxV_1);
		boxH_2.add(Box.createHorizontalStrut(10));
		boxH_2.add(boxV_2);
		//add to boxH_3
		boxH_3.add(button1);
		boxH_3.add(Box.createHorizontalStrut(20));
		boxH_3.add(loginButton);
		boxH_3.add(Box.createHorizontalStrut(20));
		boxH_3.add(button3);
		boxH_3.add(Box.createHorizontalStrut(20));
		boxH_3.add(button2);
		
		//add to comBox
		comBox1.addItem("Male");
		comBox1.addItem("Female");
		for(int i = 1900;i<=2050;i++) {
			comBox2.addItem(String.valueOf(i));
		}
		for(int i = 1;i<=12;i++) {
			comBox3.addItem(String.valueOf(i));
		}
		for(int i = 1;i<=31;i++) {
			comBox4.addItem(String.valueOf(i));
		}
		//add
		add(boxV_3);
	}
	void tableWindow() {
		dispose();
		TableWindow tableWin = new TableWindow();
		tableWin.setBounds(150, 150, 640, 400);
		tableWin.setTitle("User browsing window");	
	}
	void loginWindow() {
		dispose();
		TableWindow.cellData = new Object[User.registerCount][5];
		for(int i = 0;i < User.registerCount;i++) {
			TableWindow.cellData[i] = Demo.user[i].getInfo();
		}
		TableWindow.infoWrite();
		LoginWindow win = new LoginWindow();
		win.setBounds(100, 100, 300, 175);
		win.setTitle("User Login");
	}
	void regist() {
		Calendar c = Calendar.getInstance();
		c.set(Integer.parseInt(comBox2.getSelectedItem().toString()),
				Integer.parseInt(comBox3.getSelectedItem().toString())-1,
				Integer.parseInt(comBox4.getSelectedItem().toString()));
		birthday = c.getTime();
		userNo = text1.getText();
		userName = text2.getText();
		email = text3.getText();
		password1 = text4.getText();
		password2 = text5.getText();
		if(!password1.equals("")&&password1.equals(password2)&&User.isUserNo(userNo)&&!userName.equals("")&&User.isEmail(email)) {
			userTemp = new User[User.registerCount+1];
			for(int i = 0;i < Demo.user.length;i++) {
				userTemp[i] = Demo.user[i];
			}
			Demo.user = userTemp;
			Demo.user[User.registerCount] = new User();
			Demo.user[User.registerCount].register(userNo, userName, password1, birthday, email, userSex);
			text2.setText(null);
			text3.setText(null);
			text4.setText(null);
			text5.setText(null);
			text1.requestFocus();
			JOptionPane.showMessageDialog(boxV_3, "Registration Successful!("+userName+":"+User.registerCount+")", "tip",JOptionPane.PLAIN_MESSAGE);
		}
		else {
			JOptionPane.showMessageDialog(boxV_3, "Registration Failed!("+userName+")", "tip",JOptionPane.PLAIN_MESSAGE);
			text4.requestFocus();
			text5.setText(null);
		}
	}
	//ActionListener
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == button1) {
			regist();
		}
		if(e.getSource() == loginButton) {
			loginWindow();
		}
		if(e.getSource() == button2) {
			dispose();
		}
		if(e.getSource() == button3) {
			tableWindow();
		}
	}
	//ItemListener
	public void itemStateChanged(ItemEvent e) {
		if(e.getSource() == comBox1) userSex = comBox1.getSelectedItem().toString();
		if(e.getSource() == comBox3) {
			comBox4.removeAllItems();
			int month_temp = Integer.parseInt(comBox3.getSelectedItem().toString());
			int day_temp = 31;
			if (month_temp == 4 || month_temp == 6 || month_temp == 9 || month_temp == 11) day_temp = 30;
			else if (month_temp == 2) {
				int year_temp = Integer.parseInt(comBox2.getSelectedItem().toString());
				if (year_temp % 400 == 0 || (year_temp % 4 == 0 && year_temp % 100 != 0)) day_temp = 29;
				else day_temp = 28;
				}
			for (int j = 0; j < day_temp; j++) {
				comBox4.addItem("" + (j + 1));
				}
			}
	}
	//KeyListener
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_ENTER) {
			if(e.getSource() == text1) {
				if(User.isUserNo(text1.getText())) text1.transferFocus();
				else {
					JOptionPane.showMessageDialog(boxV_3, "Account Format Error!", "Warning",JOptionPane.WARNING_MESSAGE);
					text1.setText(null);
				}
			}
			else if(e.getSource() == text3) {
				if(User.isEmail(text3.getText())) text3.transferFocus();
				else {
					JOptionPane.showMessageDialog(boxV_3, "Email Format Error!", "Warning",JOptionPane.WARNING_MESSAGE);
					text3.setText(null);
				}
			}
			else if(e.getSource() == text5) {
				regist();
			}
			else {
				JTextField t = (JTextField)e.getSource();
				t.transferFocus();
			}
		}
	}
	public void keyReleased(KeyEvent e) {}
	public void keyTyped(KeyEvent e) {}
	//FocusListener
	public void focusGained(FocusEvent e) {
		JTextField t = (JTextField)e.getSource();
		t.setText(null);
	}
	public void focusLost(FocusEvent e) {}
}