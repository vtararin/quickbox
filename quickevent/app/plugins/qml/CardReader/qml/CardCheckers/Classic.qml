import QtQml 2.0
import qf.core 1.0
import qf.qmlwidgets 1.0
import CardReader 1.0

CardChecker 
{
	id: root
	caption: "Clasic"
	
	function checkCard(card, run_id)
	{
		Log.info("checking card:", JSON.stringify(card, null, 2));
	}
}