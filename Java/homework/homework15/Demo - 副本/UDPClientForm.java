import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class UDPClientForm extends JFrame implements ActionListener{
	GridBagLayout gridBagLayout=new GridBagLayout();
	GridBagConstraints gridBagConstraints=new GridBagConstraints();//Layout management
	//component 1
	JLabel IPLabel = new JLabel("Server IP");
	//component 2
	JTextField IPText = new JTextField(10);
	//component 3
	JLabel portLabel = new JLabel("Server Port");
	//component 4
	JTextField portText = new JTextField(5);
	//component 5
	JLabel receiveLabel = new JLabel("Receive data");
	//component 6
	JTextArea receiveArea = new JTextArea(5,10);
	JScrollPane scrollpane=new JScrollPane();
	//component 7
	JLabel sentLabel = new JLabel("Data to be sent");
	//component 8
	JTextField sentText = new JTextField(15);
	//component 9
	JButton sentButton = new JButton("Sent");
	//component 10
	JButton cancleButton = new JButton("Cancle");
	public UDPClientForm(){
	    setLayout(gridBagLayout);
	    gridBagConstraints.fill=GridBagConstraints.BOTH;
        setSize(450,300);
        setLocationRelativeTo(null);
        init();
        setVisible(true);
        setResizable(false);
        setTitle("UDP Communication Client");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);	
	}
	void init() {
		scrollpane.setViewportView(receiveArea);
		receiveLabel.setForeground(Color.BLUE);
		sentLabel.setForeground(Color.BLUE);
		IPText.setText("127.0.0.1");
		portText.setText("50000");
		constraintsSetting(0,0,1,1);
		gridBagLayout.setConstraints(IPLabel, gridBagConstraints);
		constraintsSetting(1,0,2,1);
		gridBagLayout.setConstraints(IPText, gridBagConstraints);
		constraintsSetting(3,0,1,1);
		gridBagLayout.setConstraints(portLabel, gridBagConstraints);
		constraintsSetting(4,0,1,1);
		gridBagLayout.setConstraints(portText, gridBagConstraints);
		constraintsSetting(0,1,5,1);
		gridBagLayout.setConstraints(receiveLabel, gridBagConstraints);
		constraintsSetting(0,2,5,5);
		gridBagLayout.setConstraints(scrollpane, gridBagConstraints);
		constraintsSetting(0,7,5,1);
		gridBagLayout.setConstraints(sentLabel, gridBagConstraints);
		constraintsSetting(0,8,5,1);
		gridBagLayout.setConstraints(sentText, gridBagConstraints);
		constraintsSetting(1,9,1,1);
		gridBagLayout.setConstraints(sentButton, gridBagConstraints);
		constraintsSetting(3,9,1,1);
		gridBagLayout.setConstraints(cancleButton, gridBagConstraints);
		add(IPLabel);
		add(IPText);
		add(portLabel);
		add(portText);
		add(receiveLabel);
		add(scrollpane);
		add(sentLabel);
		add(sentText);
		add(sentButton);
		add(cancleButton);
		sentButton.addActionListener(this);
		cancleButton.addActionListener(this);
	}
	void constraintsSetting(int x, int y, int width, int height){
		gridBagConstraints.gridx=x;
        gridBagConstraints.gridy=y;
        gridBagConstraints.gridwidth=width;                                             
        gridBagConstraints.gridheight=height; 	
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == sentButton) {
			openSR();
		}
		if(e.getSource() == cancleButton) {
			dispose();
		}
	}
	void openSR() {
		Demo.receiveArea = receiveArea;
		Demo.IP = IPText.getText();
		Demo.port = Integer.parseInt(portText.getText());
		Demo.messageSent = sentText.getText();
		sentText.setText(null);
		Demo.toSR();
	}
}
