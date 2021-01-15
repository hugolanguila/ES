import java.io.DataInputStream;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class PruebaSocket {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
       System.out.print("IP: " + args[1] + " - " + " PUERTO: " + args[0] + "\n\nRespuesta: \n");

       int puerto = Integer.parseInt(args[0]);
       String dir = args[1];
       String msj;
       
       Socket cs;
    
        try {
            cs = new Socket(dir, puerto);
            DataInputStream is = new DataInputStream(cs.getInputStream());
            
            byte b[] = new byte[100];
            is.read(b);
            System.out.println(new String(b, StandardCharsets.UTF_8));
            
            is.close();
            cs.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }    
}
