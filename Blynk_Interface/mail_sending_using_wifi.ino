/* Sending messages via mails using Nodemcu  */

#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>

// WiFi credentials
#define WIFI_SSID "Hotspot name"
#define WIFI_PASSWORD "Hotspot password"

// Gmail SMTP server
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

// Gmail login (use App Password)
#define AUTHOR_EMAIL "Sender_email_id"
#define AUTHOR_PASSWORD "mydcqwzwghdypato"

// Recipient email
#define RECIPIENT_EMAIL "receiver_email_id"

SMTPSession smtp;   // Object that handles SMTP connection
   
void setup() {
  Serial.begin(9600);

  // Connect WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // SMTP session configuration
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.time.ntp_server = "pool.ntp.org";  // For timestamp in emails

  // Build the email message
  SMTP_Message message;
  message.sender.name = "NodeMCU ESP8266";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = "Hello from NodeMCU!";
  message.addRecipient("Friend", RECIPIENT_EMAIL);
 message.html.content =
  "<html><body>"
  "<p>This mail is for testing Arduino code </p>"
  
  "</body></html>";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;


  // Connect to SMTP server
  if (!smtp.connect(&session)) {
    Serial.println("Connection to SMTP server failed!");
    return;
  }

  // Send the email
  if (!MailClient.sendMail(&smtp, &message)) {
    Serial.print("Error sending email: ");
    Serial.println(smtp.errorReason());
  } else {
    Serial.println("Email sent successfully!");
  }
}

void loop() {
        //Mail sent only once when program is executed because mail code is written in setup function
}
