package maze.fun;

class Area 
{
	private Location start;
	private Location end;
	public Area(Location start, Location end) {
		this.start = start;
		this.end = end;
	}
	public int getNumColumns() {
		return 1+end.getColumn()-start.getColumn();
	}
	public int getNumRows() {
		return 1+end.getRow()-start.getRow();
	}
	public Location getStart() {
		return start;
	}
	public Location getEnd() {
		return end;
	}
	public boolean contains(Location l) {
		return l.getRow()>=start.getRow() &&
		       l.getColumn()>=start.getColumn() &&
		       l.getRow()<=end.getRow() &&
		       l.getColumn()<=end.getColumn();
	}
}