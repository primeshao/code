import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class TableWindow extends JFrame implements ActionListener{
	static boolean selector = true;
	Box boxV,boxH_1,boxH_2;
	JButton button1 = new JButton("Refresh");
	JButton button2 = new JButton("Save");
	JButton registerButton = new JButton("Register");
	JButton button3 = new JButton("Cancle");
	static Object cellData[][] = {{"null","null","null","null","null","null","null"}};
	static Object headers[] = {"User Number","User Name","Sex","Birthday","Email","Password"};
	JTable table = new JTable(cellData,headers);
	public TableWindow(){
		setLayout(new FlowLayout());
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
	void addListener() {
		button1.addActionListener(this);
		button2.addActionListener(this);
		registerButton.addActionListener(this);
		button3.addActionListener(this);
	}
	void wirte() {
		infoWrite();
		if(selector) JOptionPane.showMessageDialog(boxV, "Save Successful!","tip",JOptionPane.PLAIN_MESSAGE);
		else JOptionPane.showMessageDialog(boxV, "Save failed, please refresh and try again!", "Warning",JOptionPane.WARNING_MESSAGE);	
	}
	static void infoWrite() {
		try {
			FileWriter tofile;
			BufferedWriter out;
			File desktopDir = javax.swing.filechooser.FileSystemView.getFileSystemView().getHomeDirectory();
	        String desktopPath = desktopDir.getAbsolutePath();
	        File userFile = new File(desktopPath,"userInfo.txt");
			tofile = new FileWriter(userFile);
			out = new BufferedWriter(tofile);
			out.write("User Number\tUser Name\tSex\tBirthday\t\tEmail\t\t\tPassword\t\n");
			for(int i = 0;i < User.registerCount;i++) {
				for(int j = 0;j < 6;j++) {
					out.write((String)cellData[i][j]+"\t");
					if(j == 1) out.write("\t");
					if(j == 4) {
						char temp[] = cellData[i][j].toString().toCharArray();
						if(temp.length <= 7) {
							out.write("\t\t");
						}
						if(8 <= temp.length&&temp.length <= 15) {
							out.write("\t");
						}			
					}
				}
				out.write("\n");
			}
			out.close();
			tofile.close();
			selector = true;
		}
		catch(Exception e) {
			selector = false;
		}
	}
	void init() {
		setLayout(new FlowLayout());
		setVisible(true);
		addListener();
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		boxV = Box.createVerticalBox();
		boxH_1 = Box.createHorizontalBox();
		boxH_2 = Box.createHorizontalBox();
		add(boxV);
		boxV.add(boxH_1);
		boxV.add(boxH_2);
		setColumnWidth(table,headers);
		boxH_1.add(new JScrollPane(table) {  
			   public Dimension getPreferredSize() {return new Dimension(585, 300);}
			   }
		);
		boxH_2.add(button1);
		boxH_2.add(Box.createHorizontalStrut(5));
		boxH_2.add(button2);
		boxH_2.add(Box.createHorizontalStrut(5));
		boxH_2.add(registerButton);
		boxH_2.add(Box.createHorizontalStrut(5));
		boxH_2.add(button3);
		
	}
	void setColumnWidth(JTable t ,Object h[]) {
		t.getColumn(h[0]).setPreferredWidth(90);
		t.getColumn(h[1]).setPreferredWidth(90);
		t.getColumn(h[2]).setPreferredWidth(45);
		t.getColumn(h[3]).setPreferredWidth(90);
		t.getColumn(h[4]).setPreferredWidth(180);	
		t.getColumn(h[5]).setPreferredWidth(90);
	}
	void register() {
		dispose();
		UserRegisterWindow win = new UserRegisterWindow();
		win.setBounds(100, 100, 450, 350);
		win.setTitle("UserRegister");
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == button1) {
			cellData = new Object[User.registerCount][5];
			for(int i = 0;i < User.registerCount;i++) {
				cellData[i] = Demo.user[i].getInfo();
			}
			table = new JTable(cellData,headers);
			boxH_1.removeAll();
			setColumnWidth(table,headers);
			boxH_1.add(new JScrollPane(table) {  
				   public Dimension getPreferredSize() {return new Dimension(585, 300);}
				   }
			);
			revalidate();
		}
		if(e.getSource() == button2) {
			wirte();
		}
		if(e.getSource() == registerButton) {
			register();
		}
		if(e.getSource() == button3) {
			dispose();
		}	
	}
}