package Appendix; /**
 * @project: ThinkingInJava
 * @filename: Appendix.ShowMsgBox.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 5:28 PM 9/7/15
 * @comment: Test Purpose
 * @result:
 */

class ShowMsgBox {
    public static void main(String[] args) {
        ShowMsgBox app = new ShowMsgBox();
        //app.ShowMessage("Generated with JNI");
    }

    private native void ShowMessage(String msg);

    static {
        //System.loadLibrary("MsgImpl");
    }
}
class foo{

}
