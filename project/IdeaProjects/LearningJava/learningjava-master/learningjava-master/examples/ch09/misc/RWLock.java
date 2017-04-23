public class RWLock
{

	public static void main( String [] args )
	{
		ReadWriteLock rwlock = new ReentrantReadWriteLock();
		rwlock.readLock().lock();
		System.out.println("here1");
		rwlock.writeLock().lock();
		System.out.println("here2");
	}

}
