import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String host = "localhost";
        int port = 12345;

        try (Socket socket = new Socket(host, port);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))) {

            System.out.print("Enter message to send: ");
            String userInput = stdIn.readLine();
            out.println(userInput);

            String response = in.readLine();
            System.out.println("Server response: " + response);
        } catch (IOException e) {
            System.out.println("Client exception: " + e.getMessage());
        }
    }
}
