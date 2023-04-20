import java.awt.event.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;

public class Ex2 extends JFrame implements ActionListener{  
		JTextArea text, textRes;  
		JButton submit, clear;  
		JLabel result;
		
		Ex2() {  
			// set frame and button work with file
			JMenuBar menubar = new JMenuBar();
	        JMenu file = new JMenu("File");
	        file.setMnemonic(KeyEvent.VK_F);
	        
	        JMenuItem jmiLoad = new JMenuItem("Load", KeyEvent.VK_O);
	        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	        
	        jmiLoad.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					JFileChooser jfc = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
					
					jfc.setDialogTitle("Select a text file");
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
					jfc.setDialogTitle("Select a directory");
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
			setTitle("Find words and lines in the text");
	        setLocationRelativeTo(null);
			setVisible(true);  
		}
		// count words, charactersr and lines
		public void actionPerformed(ActionEvent e){  
			String str = e.getActionCommand();
			if (str.equals("Close")) 
				System.exit(0);
			
			setTitle(str + " Selected");
			
			String txt = text.getText();
			if(e.getSource() == submit){  
				String words[] = txt.split("\\s");  
				String result = String.valueOf("Number of words:  " + words.length + " words" + "\nNumber of characters:  " + txt.length() + " characters" + "\nNumber of lines: " + text.getLineCount() + " lines");
				textRes.setText(result);
			}  
			
			if(e.getSource() == clear){  
				text.setText("");
			}
		}    

		public static void main(String[] args) {
			// TODO Auto-generated method stub
	        SwingUtilities.invokeLater(new Runnable() {
	 
	            public void run() {
	            	Ex2 ex2 = new Ex2();
	                ex2.setVisible(true);
	            }
	        });
	    }
}  

