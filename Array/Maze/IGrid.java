package maze.fun;

interface IGrid 
{
	public Location getStart();
	public Location getEnd();
	public Area getArea();
	public boolean isFree(Location l);
}