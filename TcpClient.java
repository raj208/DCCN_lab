import java.io.*;
import java.net.*;

public class TcpClient {
    private static final String SERVER_ADDRESS = "localhost"; // or the server's IP address
    private static final int SERVER_PORT = 12345;

    public static void main(String[] args) {
        try (Socket socket = new Socket(SERVER_ADDRESS, SERVER_PORT);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in))) {
             
            System.out.println("Connected to server on port: " + socket.getPort());
            
            String userInputLine;
            System.out.println("Type messages to send to the server (type 'exit' to quit):");
            while ((userInputLine = userInput.readLine()) != null) {
                if ("exit".equalsIgnoreCase(userInputLine)) {
                    break;
                }
                out.println(userInputLine);
                System.out.println("Server response: " + in.readLine());
            }
        } catch (IOException e) {
            System.err.println("Error in client: " + e.getMessage());
        }
    }
}
