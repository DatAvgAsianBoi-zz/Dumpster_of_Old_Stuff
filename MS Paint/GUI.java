// Name: Seong Su Park and Ryan Hu
// Date: 11/16/2017
// Per: 1
// Computer Science Data Structures

// run, run configuaratoins, arguments, vm arguements --> -Xss2000m

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class GUI extends JFrame {
//	public static ControlPanel c;
	
	public ArrayList<Line> lineArray;
	public Line currentLine;
	
	public boolean isFull;
	public int colorPoint;
	public int xPoint, yPoint;
	
	private DrawCanvas paintCanvas;
	
	private BufferedImage bimage;

	
	private JPanel topBox;
	private JButton clearButton;
	private JButton undoButton;
	private JButton fillButton;
	private JComboBox<String> colorDropBox;
	
	///private List<fillDotsList> fillDots;

	private List<fillDotsList> listDots;
	private fillDotsList currentDotsList;
	
	private Stack<Integer> undoStack;
	
	private boolean [][] pixelBool;

	
	public GUI() {
		this.getContentPane().setLayout(new BoxLayout(this.getContentPane(), BoxLayout.X_AXIS));
		this.setResizable(false);
		listDots = new ArrayList<fillDotsList>();
		currentDotsList = new fillDotsList();
		
		undoStack = new Stack<Integer>(); // 1 is line 2 is fillDots
		
		lineArray = new ArrayList<Line>();
		currentLine = null;
		
		isFull = false;
		
		paintCanvas = new DrawCanvas();
		paintCanvas.setBackground(Color.WHITE);
		paintCanvas.setSize(600,500);
		
		paintCanvas.setPreferredSize(new Dimension(600,500));
		
		pixelBool = new boolean[paintCanvas.getWidth()][paintCanvas.getHeight()];
		setPixelBool();
		
		paintCanvas.addMouseListener( new MouseAdapter(){
	         @Override
	         public void mousePressed(MouseEvent evt){
	            // New Line Object        	       
	        	
	        	if ( isFull == false ) {
		        	currentLine = new Line ( evt.getX(), evt.getY(), evt.getX(), evt.getY(), getColor() );		   
	        	}
	        	else {
	        		xPoint = evt.getX();
		        	yPoint = evt.getY();
		        	repaint();
	                bimage = createImage(paintCanvas);  
	                colorPoint = bimage.getRGB(xPoint, yPoint); 
	              //fillImage(paintCanvas, evt.getX(), evt.getY());  
	        	}
	         }
	      });
		
		paintCanvas.addMouseMotionListener(new MouseMotionAdapter() {
	         @Override
	         public void mouseDragged(MouseEvent evt) {
	        	 if (isFull==false && currentLine!=null) {

	        		 currentLine.setX2( evt.getX() );
	        		 currentLine.setY2( evt.getY() );

	        		 repaint(); 
	        	 }
	        	           
	         }
	      });
		
		paintCanvas.addMouseListener( new MouseAdapter() {
	         @Override
	         public void mouseReleased(MouseEvent evt){
	        	 
	        	 if (isFull==false && currentLine != null) {
	        		 
	        		 undoStack.push(1);
	        		 
	        		 currentLine.setX2( evt.getX() );
		        	 currentLine.setY2( evt.getY() );
		        	 
	        		 lineArray.add(currentLine);
	        		 
		        	 currentLine = null;
		        	 
	        		 repaint(); 
	        	 }
	        	 else {
	        		
	        		undoStack.push(2);
	        		 
	        		fillImage(paintCanvas, xPoint, yPoint);  
	        		listDots.add(currentDotsList);
	        		currentDotsList = new fillDotsList();
	        		repaint();
	        		setPixelBool();
	        		
	        	 }
	        	
	          
	         }
	      });
		
		
		setTopBox();
		this.add(paintCanvas);
		this.setTitle("MS Paint");
		this.setSize(700,500);
		this.pack();
		this.setResizable(false);
		//this.pack();
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
	
	public void setTopBox() {
		topBox = new JPanel();
	
		clearButton = new JButton("Clear");
		clearButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent event) {
				currentLine = null;
				lineArray = new ArrayList<Line>();
				
				currentDotsList = new fillDotsList();
				listDots = new ArrayList<fillDotsList>();
				
				undoStack = new Stack<Integer>();
				repaint();			
			}
		});
		
		
		undoButton = new JButton("Undo");
		undoButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent event) {
				if (undoStack.size()!=0) {
					if(undoStack.peek()==1) {
						lineArray.remove(lineArray.size()-1);
						if(lineArray.size()==0) {
							lineArray = new ArrayList<Line>();
						}
					}
					else {
						listDots.remove(listDots.size()-1);
						if(listDots.size()==0) {
							listDots = new ArrayList<fillDotsList>();
						}
						
					}
					undoStack.pop();
					repaint();
				}
				/*
				if (lineArray.size()!=0) {
					lineArray.remove(lineArray.size()-1);
					repaint();
				
				}
				*/
			}
		});

		
		fillButton = new JButton("Fill");
		fillButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent event) {
				
				isFull = !isFull;
				
			}
		});
		
		String[] colorList = {"RED","ORANGE","YELLOW","GREEN","BLUE","PINK","GRAY","BLACK","WHITE"};
		colorDropBox = new JComboBox<String>(colorList);
		
		topBox.setSize(100,100);
		
		topBox.add(clearButton);
		topBox.add(undoButton);
		topBox.add(fillButton);
		topBox.add(colorDropBox);
		topBox.validate();
		add(topBox, BorderLayout.NORTH);
		
	}
	
	
	
	public void setPixelBool() {
		   for( int x=0; x<paintCanvas.getWidth(); x++) {
			   for(int y=0; y<paintCanvas.getHeight();y++) {
				   pixelBool[x][y] = false;
			   }
		   }
	}
	
	public boolean equalColor(int a) {
		   if (colorPoint == a) {
				   return true;
		   }
		   return false;
	}
	
	public void fillImage(JPanel panel, int x, int y) {
		/*
	    System.out.println("wutface");
	    System.out.println(x);
	    System.out.println(y);
	    System.out.println(pixelBool.length);
	   // System.out.print(pixelBool[0].length);
	   System.out.print(pixelBool[x][y]);
	    */
		



		if (x>=0 && y>=0 && x<pixelBool.length && y<pixelBool[0].length &&
	  		pixelBool[x][y]==false &&    		
	  		equalColor(bimage.getRGB(x,y))) {
			
		    System.out.print("Kappa");

			pixelBool[x][y] = true;

			currentDotsList.addDot(new Line(x,y,x,y,getColor()));
			
			/*
		    BufferedImage bi = new BufferedImage(panel.getWidth(), panel.getHeight(), BufferedImage.TYPE_INT_RGB);	  
		    bi.setRGB(x, y, getColor().getRGB());
		    Graphics2D g = bi.createGraphics();
		    panel.paint(g);
		    */
		    
		    fillImage(panel, x-1, y);
		    fillImage(panel, x+1, y);
		    fillImage(panel, x, y+1);
		    fillImage(panel, x , y-1);	   
		}
	}
	
	public Color getColor() {
		String x = (String)colorDropBox.getSelectedItem();
		switch(x) {
			case "RED": return Color.RED;
			case "BLUE": return Color.BLUE;
			case "GREEN": return Color.GREEN;
			case "YELLOW": return Color.YELLOW;
			case "BLACK": return Color.BLACK;
			case "GRAY": return Color.GRAY;		
			case "PINK": return Color.PINK;			
			default: return Color.ORANGE;	
		}	
	}
	
	
	 public BufferedImage createImage(JPanel panel) {		   
		  int w = panel.getWidth();
		  int h = panel.getHeight();
		  BufferedImage bi = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);	 
		  Graphics2D g = bi.createGraphics();
		  panel.paint(g);
		  return bi;	    
	    
	}
	
	 private class DrawCanvas extends JPanel {
	      @Override
	      protected void paintComponent(Graphics g) { // called back via repaint()
	         super.paintComponent(g);      
	         for(fillDotsList d: listDots) {
	        	 for (Line h: d.getListLine()) {
	        		 g.setColor(h.getColor());
	        		 h.draw(g);
	        	 }
	         }
	         for (Line line: lineArray) {
	        	g.setColor(line.getColor());
	            line.draw(g);       
	         }
	         
	         // if statement here ifFill
	         //
	       //  bimage = createImage(canvas);
	         
	      }
	   }
	
	 public static void main(String[] args) {
		 GUI gui = new GUI();
	 }
}
