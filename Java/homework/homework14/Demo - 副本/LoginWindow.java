import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class LoginWindow extends JFrame implements ActionListener,FocusListener,KeyListener {
	int infoCount = 0;
	String infoStr[] = new String[1];
	JButton loginButton = new JButton("login");
	JButton registerButton = new JButton("Register");
	JButton cancleButton = new JButton("Cancle");
	Box boxH_1,boxH_2;
	Box boxV_1,boxV_2,boxV_3;
	JTextField userNoText = new JTextField(10);
	JTextField passwordText = new JTextField(10);
	public LoginWindow() {
		setLayout(new FlowLayout());
		addListener();
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		infoGet();
		User.registerCount = 0;
		if(infoCount != 0) {
			Demo.user = new User[infoCount];
			for(int i = 0;i < infoCount;i++) {
				Demo.user[i] = infoCut(infoStr[i]);
			}
		}
	}
	void addListener() {
		loginButton.addActionListener(this);
		registerButton.addActionListener(this);
		cancleButton.addActionListener(this);
		userNoText.addFocusListener(this);
		passwordText.addFocusListener(this);
		userNoText.addKeyListener(this);
		passwordText.addKeyListener(this);
	}
	void init() {
		//Box Setting
		boxH_1 = Box.createHorizontalBox();
		boxH_2 = Box.createHorizontalBox();
		boxV_1 = Box.createVerticalBox();
		boxV_2 = Box.createVerticalBox();
		boxV_3 = Box.createVerticalBox();
		////Box Add
		boxV_1.add(new JLabel("User Number:"));
		boxV_1.add(Box.createVerticalStrut(15));
		boxV_1.add(new JLabel("Password:"));
		boxV_2.add(userNoText);
		boxV_2.add(Box.createVerticalStrut(10));
		boxV_2.add(passwordText);
		boxH_1.add(boxV_1);
		boxH_1.add(Box.createHorizontalStrut(20));
		boxH_1.add(boxV_2);
		boxH_2.add(loginButton);
		boxH_2.add(Box.createHorizontalStrut(5));
		boxH_2.add(registerButton);
		boxH_2.add(Box.createHorizontalStrut(5));
		boxH_2.add(cancleButton);
		boxV_3.add(boxH_1);
		boxV_3.add(Box.createVerticalStrut(25));
		boxV_3.add(boxH_2);
		add(boxV_3);
	}
	void login() {
		boolean selector = true;
		String userNo = userNoText.getText();
		String password = passwordText.getText();
		if(User.isUserNo(userNoText.getText())) {
			for(int i = 0;i < User.registerCount;i++) {
				if(Demo.user[i].userNo.equals(userNo)&&Demo.user[i].password.equals(password)) {
					selector = true;
					break;
				}
				else selector = false;	
			}
			if(selector) tableWindow();
			else {
				JOptionPane.showMessageDialog(boxV_3, "User does not exist or password error!", "Warning",JOptionPane.WARNING_MESSAGE);
				passwordText.requestFocus();
			}
		}
		else {
			JOptionPane.showMessageDialog(boxV_3, "User number is 11 digits!", "Warning",JOptionPane.WARNING_MESSAGE);
			userNoText.requestFocus();
		}
	}
	void registerWindow() {
		dispose();
		UserRegisterWindow win = new UserRegisterWindow();
		win.setBounds(100, 100, 450, 350);
		win.setTitle("UserRegister");
	}
	void tableWindow() {
		dispose();
		TableWindow tableWin = new TableWindow();
		tableWin.setBounds(150, 150, 640, 400);
		tableWin.setTitle("User browsing window");	
	}
	User infoCut(String s) {
		StringTokenizer analyzer = new StringTokenizer(s);
		String userNo = analyzer.nextToken();
		String userName = analyzer.nextToken();
		String userSex = analyzer.nextToken();
		String date = analyzer.nextToken();
		String email = analyzer.nextToken();
		String password = analyzer.nextToken();
		Date birthday = null;
		String[] dateDivide=date.split("-");
		if(dateDivide.length==3){
			int year = Integer.parseInt(dateDivide [0].trim());
			int month = Integer.parseInt(dateDivide [1].trim());
			int day = Integer.parseInt(dateDivide [2].trim());
			Calendar c = Calendar.getInstance();
			c.set(year, month-1, day);
			birthday = c.getTime();
		}
		User temp = new User();
		temp.register(userNo, userName, password, birthday, email, userSex);
		return temp;
	}
	void infoGet() {
		String s;
		String strTemp[];
		try {
			File desktopDir = javax.swing.filechooser.FileSystemView.getFileSystemView().getHomeDirectory();
			String desktopPath = desktopDir.getAbsolutePath();
			File fRead = new File(desktopPath,"userInfo.txt");
			FileReader in = new FileReader(fRead);
			BufferedReader reader = new BufferedReader(in);
			if((s = reader.readLine())!=null) {
				for(infoCount = 0;(s = reader.readLine())!=null;infoCount++) {
					strTemp = new String[infoCount+1];
					for(int i = 0;i < infoStr.length;i++) {
						strTemp[i] = infoStr[i];
					}
					infoStr = strTemp;
					infoStr[infoCount] = s;
				}
			}
			reader.close();
			in.close();
		}
		catch(Exception e){}
	}
	//ActionListener
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == loginButton) {
			login();
		}
		if(e.getSource() == registerButton) {
			registerWindow();
		}
		if(e.getSource() == cancleButton) {
			dispose();
		}
	}
	//FocusListener
	public void focusGained(FocusEvent e) {
		JTextField t = (JTextField)e.getSource();
		t.setText(null);
		}
	public void focusLost(FocusEvent e) {}
	//KeyListener
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_ENTER) {
			if(e.getSource() == userNoText) {
				if(User.isUserNo(userNoText.getText())) userNoText.transferFocus();
				else {
					JOptionPane.showMessageDialog(boxV_3, "Account Format Error!", "Warning",JOptionPane.WARNING_MESSAGE);
					userNoText.setText(null);
				}
			}
			else {
				login();
			}
		}
	}
	public void keyReleased(KeyEvent e) {}
	public void keyTyped(KeyEvent e) {}
}