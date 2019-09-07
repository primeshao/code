import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class NewWindow extends JFrame implements ActionListener{
	File userFile;
	FileWriter tofile;
	BufferedWriter out;
	Box boxV,boxH_1,boxH_2;
	JButton button1 = new JButton("Refresh");
	JButton button2 = new JButton("Save");
	JButton button3 = new JButton("Cancle");
	Object cellData[][] = {{"null","null","null","null","null","null"}};
	Object headers[] = {"User Number","User Name","Sex","Birthday","Email"};
	JTable table = new JTable(cellData,headers);
	public NewWindow(){
		setLayout(new FlowLayout());
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
	void addListener() {
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
	}
	void wirte() {
		try {
			File desktopDir = javax.swing.filechooser.FileSystemView.getFileSystemView().getHomeDirectory();
	        String desktopPath = desktopDir.getAbsolutePath();
	        userFile = new File(desktopPath,"userInfo.txt");
			tofile = new FileWriter(userFile);
			out = new BufferedWriter(tofile);
			out.write("User Number\tUser Name\tSex\tBirthday\t\tEmail\t\n");
			for(int i = 0;i < User.registerCount;i++) {
				for(int j = 0;j < 5;j++) {
					out.write((String)cellData[i][j]+"\t");
					if(j == 1) out.write("\t");
				}
				out.write("\n");
			}
			out.close();
			tofile.close();
			JOptionPane.showMessageDialog(boxV, "Save Successful!","tip",JOptionPane.PLAIN_MESSAGE);
		}
		catch(IOException e) {
			JOptionPane.showMessageDialog(boxV, "Error!", "Warning",JOptionPane.WARNING_MESSAGE);
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
			   public Dimension getPreferredSize() {return new Dimension(495, 300);}
			   }
		);
		boxH_2.add(button1);
		boxH_2.add(button2);
		boxH_2.add(button3);
		
	}
	void setColumnWidth(JTable t ,Object h[]) {
		t.getColumn(h[0]).setPreferredWidth(90);
		t.getColumn(h[1]).setPreferredWidth(90);
		t.getColumn(h[2]).setPreferredWidth(45);
		t.getColumn(h[3]).setPreferredWidth(90);
		t.getColumn(h[4]).setPreferredWidth(180);	
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
				   public Dimension getPreferredSize() {return new Dimension(495, 300);}
				   }
			);
			revalidate();
		}
		if(e.getSource() == button2) {
			wirte();
		}
		if(e.getSource() == button3) {
			dispose();
		}
	}
}