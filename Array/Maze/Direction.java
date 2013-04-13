package maze.fun;

public class Direction 
{
	public final static Direction right = new Direction(0, 1);
	public final static Direction left = new Direction(0, -1);
	public final static Direction down = new Direction(1, 0);
	public final static Direction up = new Direction(-1, 0);
	public final static Direction[] all = {right, left, down, up};
	private int dr;
	private int dc;
	private Direction(int dr, int dc) {
		this.dr = dr;
		this.dc = dc;
	}
	public int getRowDelta() {
		return dr;
	}
	public int getColumnDelta() {
		return dc;
	}
}