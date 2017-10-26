// 練習問題 チャットクライアント
import java.net.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ChatClient extends JFrame implements ActionListener{
   InputPanel inP;  //入力域とボタンのパネル
   JTextArea talkArea;
   JMenuBar mbar;
   JMenu menu;
   JMenuItem saveM, exitM;

   Socket chatS = null;
   BufferedReader in = null;
   PrintStream out = null;

   String userName;

   public ChatClient(String title) {
      super(title);
      mbar = new JMenuBar();  //set menu
      setJMenuBar(mbar);
      menu = new JMenu("終了");
      exitM = new JMenuItem("終了");
      exitM.addActionListener(this);
      menu.add(exitM);
      mbar.add(menu);

      inP = new InputPanel();    
      talkArea = new JTextArea(10,40);
      talkArea.setEditable(false);
      JScrollPane scrollPane = new JScrollPane(talkArea);
      Container c = getContentPane();
      c.add(scrollPane, BorderLayout.CENTER);
      c.add(inP, BorderLayout.SOUTH);
   }

   public void actionPerformed(ActionEvent e){
      Object obj = e.getSource();
      if(obj == exitM){
         sendMessage(" 接続を切りました。");
         System.exit(0);
      }
   } 

   class InputPanel extends JPanel implements ActionListener{
      JTextField field;
      JButton goB;
      InputPanel(){
	 setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
         field = new JTextField(40);
         goB = new JButton("発言");
         goB.addActionListener(this);
         add(field);
         add(goB);
       }
       public void actionPerformed(ActionEvent e) {
         sendMessage(field.getText());
         field.setText("");
         goB.requestFocus();
       }
    }

    public void startChat() {
       sendMessage(" 接続しました。");
       String fromServer;
       try{
          while ((fromServer = in.readLine()) != null) {
             talkArea.append(fromServer + "\n");
          }
          end();
       }catch (IOException e){ 
          System.out.println("チャット中に問題が起こりました。");
          System.exit(1);
       }
    }
 
    public void sendMessage(String msg) {
       String s = userName + ":" + msg;
       out.println(s);
    }

    //network setup
    public void initNet(String serverName, int port, String uName) {
       userName = uName;
       // create Socket
       try {
	  chatS = new Socket(InetAddress.getByName(serverName), port);
          // ローカルホストでテストの場合は上の代わりに下の行を有効にする
          //chatS = new Socket(InetAddress.getLocalHost(), port);
          in = new BufferedReader(
                 new InputStreamReader(chatS.getInputStream()));
          out = new PrintStream(chatS.getOutputStream());
       } catch (UnknownHostException e) {
          System.out.println("ホストに接続できません。");
          System.exit(1);
       } catch (IOException e) {
          System.out.println("IOコネクションを得られません。");
          System.exit(1);
       }
    }

    public void end() {
       try {
          out.close();
          in.close();
          chatS.close();
       } catch (IOException e) { System.out.println("end:" + e); }
    }

    /**
     * java ChatClient サーバのIPアドレス ポート番号 ユーザ名
     * args[0] = serveraddress
     * args[1] = portnumber
     * args[2] = username
    */
    public static void main(String[] args) {
       if (args.length != 3 && args.length != 4) {
          System.out.println(
             "Usage: java ChatClient サーバのIPアドレス ポート番号 ユーザ名");
          System.out.println("例: java ChatClient 210.0.0.1 50002 ariga");
          System.exit(0);
        }
        // Getting argument.
        String sName = args[0];
        int portN = Integer.valueOf(args[1]).intValue();
        String uName = args[2];
        System.out.println("serverName = " + sName);
        System.out.println("portNumber = " + portN);
        System.out.println("userName = " + uName);

        // Setup and start.
        JFrame.setDefaultLookAndFeelDecorated(true);
	ChatClient chat = new ChatClient(uName + " -> " + sName);
        chat.initNet(sName, portN, uName);
        chat.pack();
        chat.setVisible(true);
        chat.startChat();
    }
}
