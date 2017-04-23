//file: StringIterator.java
public interface StringIterator extends Remote {
    public boolean hasNext(  ) throws RemoteException;
    public String next(  ) throws RemoteException;
}
