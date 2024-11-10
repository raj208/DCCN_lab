import java.io.*;
import java.net.*;

class Server{
    private ServerSocket serverSocket;

    public Server(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        System.out.println("Server listening on port " + port);
    }

    public void acceptConnection() {
        try (Socket clientSocket = serverSocket.accept()) {
            System.out.println("Connection accepted from " + clientSocket.getInetAddress());
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            String message = in.readLine();
            System.out.println("Received message: " + message);
            out.println("Message received");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public void close() throws IOException {
        serverSocket.close();
    }

    public static void main(String[] args) {
        int port = 12345;
        try {
            Server server = new Server(port);
            while (true) {
                server.acceptConnection();
            }
        } catch (IOException e) {
            System.out.println("Server exception: " + e.getMessage());
        }
    }
}
