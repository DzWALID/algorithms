package maze.fun;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

public class Path implements Iterable<Location>
{
	HashSet<Location> locSet = new HashSet<Location>();
	LinkedList<Location> locList = new LinkedList<Location>();
	public Path() {}
	public Path append(Location l) {
		if (locSet.contains(l))
			throw new RuntimeException("Loop in a path!");
		locSet.add(l);
		locList.add(l);
		return this;
	}
	public Path prepend(Location l) {
		if (locSet.contains(l))
			throw new RuntimeException("Loop in a path!");
		locSet.add(l);
		locList.add(0, l);
		return this;
	}
	public Path removeLast() {	
		Location l = locList.removeLast();
		locSet.remove(l);
		return this;
	}
	public Iterator<Location> iterator() {
		return new PathIterator(this);
	} 
	public int size() {
		return locList.size();
	}
	public boolean contains(Location l) {
		return locSet.contains(l);
	}
	public String toString() {
		StringBuilder s = new StringBuilder();
		s.append("s");
		for (Location l : locList) 
			s.append("->(" + l.getRow() + "," + l.getColumn() + ")");
		s.append("->e");
		return s.toString();
	}
}

class PathIterator implements Iterator<Location> 
{
	private Path p;
	private Location l;
	private Iterator<Location> it;
	public PathIterator(Path p) {
		this.p = p;
		it = p.locList.iterator();
	}
	public boolean hasNext() {
		return it.hasNext();
	}
	public Location next() {
		l =  it.next();
		return l;
	}
	public void remove() {
		it.remove();
		p.locSet.remove(l);
	}
}