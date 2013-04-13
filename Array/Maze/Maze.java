package maze.fun;

import java.util.ArrayList;

public class Maze 
{
	private IGrid grid;
	public void setGrid(IGrid grid) {
		this.grid = grid;
	}
	public ArrayList<Path> findPath() {
		return traverse(grid.getStart(), new Path());
	}
	private ArrayList<Path> traverse(Location l, Path p) {
		// TODO: fill in this part
	}
	public static void main(String[] args) {
		int[][] mdata = {{1,1,1,0,1,1,0,0,0,1,1,1,1},
	            	     {1,0,1,1,1,0,1,1,1,1,0,0,1},
		                 {0,0,0,0,1,0,1,0,1,0,1,0,0},
		                 {1,1,1,0,1,1,1,0,1,0,1,1,1},
		                 {1,0,1,0,0,0,0,1,1,1,0,0,1},
	                     {1,0,1,1,1,1,1,1,0,1,1,1,1},
	                     {1,0,1,0,0,0,0,0,0,1,1,0,0},
		                 {1,1,1,1,1,1,1,1,1,1,1,1,1}};
		IGrid grid = new Grid(mdata);
		Maze maze = new Maze();
		maze.setGrid(grid);
		ArrayList<Path> paths = maze.findPath();
		for (Path p: paths) 
			System.out.println(p);
	}
}









