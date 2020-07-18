// Name: Seong Su Park and Ryan Hu
// Date: 11/16/2017
// Per: 1
// Computer Science Data Structures

import java.awt.Color;
import java.awt.Graphics;

public class Line {
	
	public int x1;
	public int y1;
	public int x2;
	public int y2;
	public Color color;
	
	public Line(int x1, int y1, int x2, int y2, Color color) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
		this.color = color;
	}
	
	public void draw( Graphics g ) {
		g.setColor( color);
		g.drawLine(x1, y1, x2, y2);
	}
	
	
	public void setX1(int x1) {
		this.x1 = x1;
	}
	public void setX2(int x2) {
		this.x2 = x2;
	}
	public void setY1(int y1) {
		this.y1 = y1;
	}
	public void setY2(int y2) {
		this.y2 = y2;
	}
	public void setColor(Color color) {
		this.color = color;
	}
	public Color getColor() {
		return color;
	}
}
