package maze.fun;

public class Grid implements IGrid
{
	int[][] grid;
	Area area;
	public Grid(int[][] grid) {
		this.grid = grid;
		int nrows = grid.length;
		if (grid.length==0)
			throw new RuntimeException("Empty grid");
		int ncols = grid[0].length;
		for (int[] row: grid)
			if (row.length!=ncols)
				throw new RuntimeException("Irregular grid");
		this.grid = grid;
		Location start = new Location(0, 0);
		Location end = new Location(nrows-1, ncols-1);
		area = new Area(start, end);
	}
	public Location getStart() {
		return area.getStart();
	}
	public Location getEnd() {
		return area.getEnd();
	}
	public Area getArea() {
		return area;
	}
	public boolean isFree(Location l) {
		return grid[l.getRow()][l.getColumn()]==1;
	}
}
