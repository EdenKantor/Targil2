package serverGui;
import java.net.InetAddress;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;
import server.BiteMeServer;
import server.ServerUI;

public class ServerDisplayController implements Initializable{

    @FXML
    private Button connectBtn = null;

    @FXML
    private Button disconnectBtn = null;

    @FXML
    private Button closeBtn = null;
    
    @FXML
    private TextField port;

    @FXML
    private TextField DBname;

    @FXML
    private TextField DBuser;

    @FXML
    private TextField DBpassword;
    
    @FXML
    private Label Server_Configuration;

    @FXML
    private Label ip_label;

    @FXML
    private Label port_label;

    @FXML
    private Label DB_label;

    @FXML
    private Label DBuser_label;

    @FXML
    private Label DBpassword_label;

    @FXML
    private Label serverStatusLabel;
    
    @FXML
    private Label server_ipLabel;
    
    @FXML
    private Label ClientDetailsLabel;
    
    @FXML
    private Label HostNameLabel;
    
    @FXML
    private Label IPAddLabel;
    
    @FXML
    private Label ClientHostNameLabel;
    
    @FXML
    private Label ClientIPAddLabel;

    private BiteMeServer server;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        // Initialize method for Initializable interface, if you are implementing it
        port.setText("5555");
        DBname.setText("order");
        DBuser.setText("root");
        DBpassword.setText("Aa123456");
        
        // Get the local IP address
        try {
            String ipAddress = InetAddress.getLocalHost().getHostAddress();
            server_ipLabel.setText(ipAddress);
        } catch (Exception e) {
            server_ipLabel.setText("Unable to get IP address");
        }
    }
    
    public void start(Stage primaryStage) throws Exception {	
		Parent root = FXMLLoader.load(getClass().getResource("/ServerGui/ServerDisplay.fxml"));
				
		Scene scene = new Scene(root);
		primaryStage.setTitle("Server menu");
		primaryStage.setScene(scene);
		
		primaryStage.show();
		
	}
    
    @FXML
    public void connect(ActionEvent event) {
        String dbName = DBname.getText();
        String dbUser = DBuser.getText();
        String dbPassword = DBpassword.getText();
    	
        int portNumber;
        try {
            portNumber = Integer.parseInt(port.getText());
        } catch (NumberFormatException e) {
            serverStatusLabel.setText("Invalid port number");
            serverStatusLabel.setTextFill(Color.RED);
            serverStatusLabel.setVisible(true);
            return;
        }
        
        // Create a new BiteMeServer instance with database credentials
        BiteMeServer serverInstance = new BiteMeServer(portNumber, dbName, dbUser, dbPassword);
        
     // Sets the callback function for the server instance to the updateClientDetails method of this controller.
     // This ensures that when a client connects to the server, the updateClientDetails method is called with the client's
     // hostname and IP address.
        serverInstance.setClientDetailsCallback(this::updateClientDetails);

        
        // Pass the server instance to ServerUI.runServer
        ServerUI.runServer(portNumber, serverInstance);
        serverStatusLabel.setText("Server is listening for connections on port " + portNumber);
        serverStatusLabel.setTextFill(Color.GREEN);
        serverStatusLabel.setVisible(true);

        disableButton(connectBtn, true);
        disableButton(disconnectBtn, false);
    }

    @FXML
    public void disconnect(ActionEvent event) {
        ServerUI.stopServer();
        serverStatusLabel.setText("Server disconnected");
        serverStatusLabel.setTextFill(Color.RED);
        serverStatusLabel.setVisible(true);
        
        disableButton(connectBtn, false);
        disableButton(disconnectBtn, true);
    }
    
    @FXML
    public void getcloseBtn(ActionEvent event) throws Exception {
    	System.out.println("exit");
    	System.exit(0);
    }

    private void disableButton(Button button, boolean disable) {
        button.setDisable(disable);
        button.setOpacity(disable ? 0.5 : 1.0);
    }
    
    // Updates the client details on the GUI by setting the client host name and IP address labels.
    public void updateClientDetails(String clientHostName, String clientIpAddress) {
        Platform.runLater(() -> { // // Ensure the GUI update runs on the JavaFX Application Thread
            ClientHostNameLabel.setText(clientHostName);
            ClientIPAddLabel.setText(clientIpAddress);
            System.out.println("Updated GUI with client details: " + clientHostName + " (" + clientIpAddress + ")");
        });

    }

}
