import java.awt.event.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;

public class Ex1 extends JFrame implements ActionListener{ 
		
		JTextArea text, textRes;  
		JButton submit, clear;  
		JLabel result;
		
		Ex1() {  
			// set frame and button work with file
			JMenuBar menubar = new JMenuBar();
	        JMenu file = new JMenu("File");
	        file.setMnemonic(KeyEvent.VK_F);
	        
	        JMenuItem jmiLoad = new JMenuItem("Load", KeyEvent.VK_O);
	        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	        
	        jmiLoad.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					JFileChooser jfc = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
					jfc.setDialogTitle("Please select your text file");
					jfc.setAcceptAllFileFilterUsed(false);
					
					FileNameExtensionFilter filter = new FileNameExtensionFilter("Text file (*.txt)", "txt");
					jfc.addChoosableFileFilter(filter);
					
					int returnValue = jfc.showOpenDialog(null);

					if (returnValue == JFileChooser.APPROVE_OPTION) {
						File selectedFile = jfc.getSelectedFile();
						String str = "";
						try (Scanner frame = new Scanner(selectedFile)){
							while(frame.hasNext())
								str += frame.nextLine() + "\n";
						} catch (FileNotFoundException exc1) {
							exc1.printStackTrace();
						}
						
						text.setText(str.substring(0, str.length()-1));
					}
				}
			});
	        
	        jmiLoad.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, InputEvent.CTRL_DOWN_MASK));
	        
	        JMenuItem jmiSave = new JMenuItem("Save", KeyEvent.VK_S);
	        jmiSave.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					
					JFileChooser jfc = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
					jfc.setDialogTitle("Please select your directory");
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					
					int returnValue = jfc.showSaveDialog(null);
					
					if (returnValue == JFileChooser.APPROVE_OPTION) {
						File selectedFile = jfc.getSelectedFile();
							
						try(BufferedWriter bw = new BufferedWriter(new FileWriter(selectedFile))) {
							bw.write(text.getText());
							
							System.out.println("Saved");
							
						} catch (Exception exc2) {
							System.out.println(exc2);
						}
					}
				}
			});
	        
	        // action 
	        jmiSave.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_DOWN_MASK));
	        		
	        JMenuItem jmiClose = new JMenuItem("Close", KeyEvent.VK_Q);
	        jmiClose.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q, InputEvent.CTRL_DOWN_MASK));

	        file.add(jmiLoad);
	        file.add(jmiSave);
	        file.addSeparator();
	        file.add(jmiClose);

	        menubar.add(file);
	        
	        jmiLoad.addActionListener(this);
	        jmiSave.addActionListener(this);
	        jmiClose.addActionListener(this);
	        
	        setJMenuBar(menubar);
			
			text = new JTextArea();  
			text.setBounds(0,0,450,250);
			
			textRes = new JTextArea();  
			textRes.setBounds(50,260,400,100);
      
			submit = new JButton("Submit");  
			submit.setBounds(60,380,120,40);  
	      
			clear = new JButton("Clear");  
			clear.setBounds(250,380,120,40);  
	      
			submit.addActionListener(this);  
			clear.addActionListener(this);  
			
			result = new JLabel("Result: ");
			result.setBounds(5,295,50,25);
			
			add(submit);
			add(clear);
			add(text);
			add(result);
			add(textRes);
			
			setSize(450, 500);
			setLayout(null);  
			setTitle("Find the largest and second largest number of the text");
	        setLocationRelativeTo(null);
			setVisible(true);  
		}
	
		public void actionPerformed(ActionEvent e){  
			
			String str = e.getActionCommand();
			
			if (str.equals("Close"))
				System.exit(0);
			
			setTitle(str + " Selected");
			
			//find largest and second largest number
			int number[] = new int[5000];
			int largestNumber = number[0];
			int secondLargest = number[0];
			
			String array1 = text.getText();
			String array2[] = array1.split("\n");
			
			for(int j = 0; j < array2.length; j++)
			{
				number[j] = Integer.parseInt(array2[j]); 
			}
			
			if(e.getSource() == submit){  
				for (int i = 0; i < number.length; i++)
				{
					if (number[i] > largestNumber)
					{
						secondLargest = largestNumber;
						largestNumber = number[i];
					}
					else if (number[i] > secondLargest)
					{
						secondLargest = number[i];
					}
				} 
			}
			else if(e.getSource() == clear){  
				text.setText("");
		    }
			
			String result = String.valueOf("The largest number is : " + largestNumber + "\nThe second largest number is : "+ secondLargest);  
		    textRes.setText(result); 
		}    

		public static void main(String[] args) {
			// TODO Auto-generated method stub
	        SwingUtilities.invokeLater(new Runnable() {
	 
	            public void run() {
	            	Ex1 ex1 = new Ex1();
	                ex1.setVisible(true);
	            }
	        });
	    }
}  