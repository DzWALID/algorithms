package maze.fun;

public class Location 
{
	private int r;
	private int c;
	public Location(int r, int c) {
		this.r = r;
		this.c = c;
	}
	public int getRow() {
		return r;
	}
	public int getColumn() {
		return c;
	}
	Location move(Direction dir) {
		return new Location(r+dir.getRowDelta(), c+dir.getColumnDelta());
	}
	public final boolean equals(Object o) {
		if (!(o instanceof Location))
			return false;
		Location l = (Location) o;
		return l.r==r && l.c==c;
	}
	public int hashCode() {
		int hash = 17;
		hash = 31 * hash + c;
		hash = 31 * hash + r;
		return hash;
	}
}