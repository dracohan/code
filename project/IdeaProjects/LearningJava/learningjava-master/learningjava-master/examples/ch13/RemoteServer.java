//file: RemoteServer.java
public interface RemoteServer extends Remote {
    Date getDate(  ) throws RemoteException;
    StringIterator getList() throws RemoteException;
    Object execute( WorkRequest work ) throws RemoteException;
    void asyncExecute( WorkRequest work, WorkListener listener ) 
		throws RemoteException;
}
