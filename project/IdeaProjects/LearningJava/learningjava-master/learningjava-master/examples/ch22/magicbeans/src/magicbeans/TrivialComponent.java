package magicbeans;

public class TrivialComponent extends JComponent {

	public void paintComponent( Graphics g ) { 
		g.setColor( getBackground() );
		g.fillRect( 0, 0, getSize().width, getSize().height );
	}

}
