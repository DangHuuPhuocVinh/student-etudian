import java.awt.event.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;
//I'm sorry teacher but i was try too many ways but cannot use many screens, 
//i just can use one screen to load the file, modify, delete and save it.

public class W06_1752052 extends JFrame implements ActionListener{  
		JTextArea text, textResult;  
		JButton submit, delete;  
		JLabel result;
		
		W06_1752052() {  
			// set frame and button work with file
			JMenuBar menubar = new JMenuBar();
	        JMenu file = new JMenu("File");
	        file.setMnemonic(KeyEvent.VK_F);
	        
	        JMenuItem jmiLoad = new JMenuItem("Load", KeyEvent.VK_O);
	        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	        
	        jmiLoad.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					JFileChooser jfc = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
					
					
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

	        menubar.add(file);
	        
	        jmiLoad.addActionListener(this);
	        jmiSave.addActionListener(this);
	        jmiClose.addActionListener(this);
	        
	        setJMenuBar(menubar);
			
	        text = new JTextArea();  
			text.setBounds(0,0,450,250);
			
			textResult = new JTextArea();  
			textResult.setBounds(50,260,400,100);
	      
			delete = new JButton("Delete");  
			delete.setBounds(150,380,120,40); 
	      
			result = new JLabel("Result: ");
			result.setBounds(5,295,50,25);
		
			delete.addActionListener(this); 
			
			add(delete);
			add(text);
			add(result);
			add(textResult);
			
			setSize(450, 500);
			setLayout(null);  
			setTitle("Bank compte");
	        setLocationRelativeTo(null);
			setVisible(true);  
		}
	
		public void actionPerformed(ActionEvent ae){  
			String string = ae.getActionCommand();
			if (string.equals("Load")) 
				textResult.setText("File loaded. Now you can modify the file");
			if(string.equals("Save"))
				textResult.setText("Saved");
			if(ae.getSource() == delete){  
				text.setText("");
				textResult.setText("Deleted");
			}
		}    

		public static void main(String[] args) {
			// TODO Auto-generated method stub
	        SwingUtilities.invokeLater(new Runnable() {
	 
	            public void run() {
	            	W06_1752052 w06 = new W06_1752052();
	                w06.setVisible(true);
	            }
	        });
	    }
}  

