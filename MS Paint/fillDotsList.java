// Name: Seong Su Park and Ryan Hu
// Date: 11/16/2017
// Per: 1
// Computer Science Data Structures

import java.util.ArrayList;

public class fillDotsList {
	
	private ArrayList<Line> listLine = new ArrayList<Line>();
	
	public fillDotsList() {	
	}
	
	public void addDot( Line dot) {
		listLine.add(dot);
	}
	
	public ArrayList<Line> getListLine(){
		return listLine;
	}
}
