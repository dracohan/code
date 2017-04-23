import org.xml.sax.InputSource;

import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

public class PrintDOM {
	public static void main( String [] args ) throws Exception 
	{
		DocumentBuilder parser =  DocumentBuilderFactory.newInstance().newDocumentBuilder();
		Document document = parser.parse( new InputSource("zooinventory.xml") );
		Transformer transformer =  TransformerFactory.newInstance().newTransformer();
		Source source = new DOMSource( document );
		Result output = new StreamResult( System.out );
		transformer.transform( source, output );
	}
}
