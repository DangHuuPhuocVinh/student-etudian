import java.awt.*;
import java.net.*;
import java.awt.event.*;

public class Ex1_1752052 extends Frame { 
            TextField tf1; 
            TextField tf2; 
            Label l1; 
            Button b, b2, b3, b4, b5;
                    Ex1_1752052() { 
                          setTitle("Adder"); 
                          tf1 = new TextField("First number"); 
                          tf1.setBounds(100, 50, 95, 20);
                          tf2 = new TextField("Second number"); 
                          tf2.setBounds(100, 100, 95, 20); 
                          b = new Button("Add"); 
                          b.setBounds(11,190,60,40);
                          b2 = new Button("Subtract");
                          b2.setBounds(90,190, 60, 40);
                          b3 = new Button("Multi"); 
                          b3.setBounds(190,190,60,40);
                          b4 = new Button("Divide"); 
                          b4.setBounds(190,190,60,40);
                          b5 = new Button("Modulo"); 
                          b5.setBounds(190,190,60,40);
                          l1 = new Label(""); 
                          l1.setBounds(100, 120, 85, 20); 
                          add(b); 
                          add(b2);
                          add(b3);
                          add(b4);
                          add(tf1); 
                          add(tf2); 
                          add(l1); 
                          setSize(300,300); 
                          setVisible(true); 

        b.addActionListener(new ActionListener(){
               public void actionPerformed(ActionEvent e) { 
                    int a = Integer.parseInt(tf1.getText());
                    int b = Integer.parseInt(tf2.getText()); 
                    int c = a + b; 
                    int d = a - b;
                    int e1 = a * b;
                    int f = a / b;
                    int g = a % b;
                    l1.setText("Result is: " + String.valueOf(c));
                    l1.setText("Result is: " + String.valueOf(d));
                    l1.setText("Result is: " + String.valueOf(e1));
                    l1.setText("Result is: " + String.valueOf(f));
                    l1.setText("Result is: " + String.valueOf(g));
                    
                         }
                }); 
            } 
public static void main(String []args) { 
                   new Ex1_1752052();
          } 
}