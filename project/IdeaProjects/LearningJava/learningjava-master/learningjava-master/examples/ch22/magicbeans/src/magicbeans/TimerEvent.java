package magicbeans;

public class TimerEvent extends java.util.EventObject {
	int value;

	TimerEvent( Timer source ) {
		super( source );
	}
}
