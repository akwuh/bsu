package util;

import java.awt.*;
import java.awt.event.*;
import java.util.regex.*;
import java.util.*;
import java.io.*;
import javax.swing.*;

public class Settings {

	private int width = 600;
	private int height = 600;
	private int gridWidth = 1;
	private int gridHeight = 1;
	private String name = "Default";
	private String menuName = null;
	private ActionListener listener = null;

	public Settings setWidth(int x){width = x; return this;}
	public Settings setHeight(int x){height = x; return this;}
	public Settings setGridWidth(int x){gridWidth = x; return this;}
	public Settings setGridHeight(int x){gridHeight = x; return this;}
	public Settings setName(String x){name = x; return this;}
	public Settings setMenuName(String x){menuName = x; return this;}
	public Settings setListener(ActionListener x){listener = x; return this;}
	
	public int getWidth(){return width;}
	public int getHeight(){return height;}
	public int getGridHeight(){return gridHeight;}
	public int getGridWidth(){return gridWidth;}
	public String getName(){return name;}
	public String getMenuName(){return menuName;}
	public ActionListener getListener(){return listener;}

}
