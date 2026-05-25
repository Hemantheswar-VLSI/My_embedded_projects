/* Smart agriculture project code */


//Bylink app templates details
#define BLYNK_TEMPLATE_ID "Template id "
#define BLYNK_TEMPLATE_NAME "Template name"
#define BLYNK_AUTH_TOKEN "Authentification token"


//Nodemcu ibraries for mail and bylink app
#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>
#include <BlynkSimpleEsp8266.h>


// WiFi credentials
#define auth "Authentification token"
#define WIFI_SSID "Hotspot name"
#define WIFI_PASSWORD "Hotspot password"

// Gmail SMTP server
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

// Gmail login (use App Password)
#define AUTHOR_EMAIL "Sender_mail_id"
#define AUTHOR_PASSWORD "mydcqwzwghdypato"

// Recipient email
#define RECIPIENT_EMAIL "receivers_mail_id"

SMTPSession smtp;   // Object that handles SMTP connection

//pins to control the motor 
#define m1p1 D0
#define m1p2 D1
int value;


void setup() {
  pinMode(m1p1,OUTPUT);
  pinMode(m1p2,OUTPUT);
  Serial.begin(9600);
  // Connect WiFi
  Blynk.begin(auth,WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }
  Serial.println("\nWiFi connected!");
}
  
  BLYNK_WRITE(V1){
  int value=param.asInt();
  Serial.println(value);
  
  //Used some default moisture values for my project
  
  if(value<=310){
    low_range_mail(value);
    Serial.println("low range mail : ");
  }
  else if(value>310 && value<=510){
    low_range_prefered_mail(value);
    Serial.println("Low range prefered mail to turn on the motor : ");
  }
  else if(value>510 && value<=820){
    normal_range_mail(value);
    Serial.println("normal range mail ,giving choict to farmer to turn on or off : ");
  }
  else if(value>820 && value<=910){
    high_range_prefered_mail(value);
    Serial.println("High range prefered mail to turn off the motor  : ");
  }

  else if(value>=920){
    high_range_mail(value);
    Serial.println("high range mail : ");
  }

}




  BLYNK_WRITE(V0) {
   value = param.asInt(); 
  Serial.println(value);
  if(value==HIGH){
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2,LOW);
  }
  else if (value==LOW){ 

    digitalWrite(m1p1,LOW);
    digitalWrite(m1p2,LOW);

  }
}


  

void loop() {

  Blynk.run();
}

//moisture level is very less mail
void low_range_mail(int value){
  //turning on motors
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,LOW);

  // SMTP session configuration
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.time.ntp_server = "pool.ntp.org";  // For timestamp in emails

  // Build the email message
  SMTP_Message message;
  message.sender.name = "LOW RANGE ALERT MAIL";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = String(" << WARNING >> moisture : ")+ value;
  message.addRecipient("Friend", RECIPIENT_EMAIL);
  message.html.content =
  "<html><body>"
  "<p>Water level is too low so automatically motor is turn on and releasing water  </p>"
  
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



//Moisture level is just above the low range mail
void low_range_prefered_mail(int value){
  // SMTP session configuration
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.time.ntp_server = "pool.ntp.org";  // For timestamp in emails

  // Build the email message
  SMTP_Message message;
  message.sender.name = "LOW RANGE PREFERED  MAIL";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = String(" prefered to on motor ; moisture : ")+ value;
  message.addRecipient("Friend", RECIPIENT_EMAIL);
  message.html.content =
  "<html><body>"
  "<p>Water level is  low, so it is prefered to turn on the motor to release water for crop  </p>"
  "<p>To turn on the motor </p>"
  "<p>click the below link</p>"
  "<p><a href=\"Use your blynk app  template link here \">Open Blynk Dashboard</a></p>"
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



//moisture level is in normal mode 
void normal_range_mail(int value){
  // SMTP session configuration
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.time.ntp_server = "pool.ntp.org";  // For timestamp in emails

  // Build the email message
  SMTP_Message message;
  message.sender.name = "NORMAL RANGE MAIL";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = String("Hello from FIELD ; moisture : ")+ value;
  message.addRecipient("Friend", RECIPIENT_EMAIL);
  message.html.content =
  "<html><body>"
  "<p>  Water level is in normal condition , If you want to on the motor to release the water </p>"
  "<p> Click here to turn on motor : </p>"
  "<p><a href=\"Use your blynk app  template link here \">Open Blynk Dashboard</a></p>"
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



//Moisture level is just above the low range mail
void high_range_prefered_mail(int value){
  // SMTP session configuration
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.time.ntp_server = "pool.ntp.org";  // For timestamp in emails

  // Build the email message
  SMTP_Message message;
  message.sender.name = "LOW RANGE PREFERED  MAIL";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = String("PREFERED TO TURN OFF THE MOTOR ;Moisture :  ")+value;
  message.addRecipient("Friend", RECIPIENT_EMAIL);
  message.html.content =
  "<html><body>"
  "<p>Water level is  high so it is prefered to turn off the motor to stop water for crop  </p>"
  "<p>To turn off the motor </p>"
  "<p>click the below link</p>"
  "<p><a href=\"Use your blynk app  template link here  \">Open Blynk Dashboard</a></p>"
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



//moisture level is too high
void high_range_mail(int value){
  //turn offing the motors
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);

  // SMTP session configuration
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.time.ntp_server = "pool.ntp.org";  // For timestamp in emails

  // Build the email message
  SMTP_Message message;
  message.sender.name = "HIGH RANGE ALERT MAIL";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = String(" << HIGH ALERT WARNING >> ; moisture : ")+ value;
  message.addRecipient("Friend", RECIPIENT_EMAIL);
  message.html.content =
  "<html><body>"
  "<p>  Water level is  too high automatically turn offing the motor </p>"
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























