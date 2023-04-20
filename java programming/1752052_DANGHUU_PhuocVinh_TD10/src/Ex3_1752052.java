import java.awt.*;
import java.net.*;
import java.awt.event.*;

public class Ex3_1752052 extends Frame { 
          TextArea ta; 
          Label label1; 
          Label label2; 
          Button button; 

          Ex3_1752052() {
             setTitle("Word Count"); 
             
             ta = new TextArea(); 
             ta.setBounds(100, 100, 400, 400); 
             button = new Button("Count"); 
             button.setBounds(270,500,60,40); 
             label1 = new Label(""); 
             label1.setBounds(100, 50, 100, 30); 
             label2 = new Label(""); 
             label2.setBounds(250,50,100,30);
             
             add(button);
             add(ta);
             add(label1);
             add(label2);
             setLayout(null);
             setSize(600, 600);
             setVisible(true);

             button.addActionListener(new ActionListener(){
             public void actionPerformed(ActionEvent e) {
                  int w = ta.getText().split("\\s+").length;
                  int c = ta.getText().length();
                  
                  label1.setText("Words " + w);
                  label2.setText("Characters " + c);
               }
         });
  }
public static void main(String []args) {
     new Ex3_1752052();
   }
}