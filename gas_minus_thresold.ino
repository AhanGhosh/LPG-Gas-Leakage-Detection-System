#include <WiFi.h>
#include <ESP32Servo.h>
#include <ESP_Mail_Client.h>

// WiFi credentials
#define WIFI_SSID "POCOM2"
#define WIFI_PASSWORD "12345678"

// SMTP server settings for Gmail
#define SMTP_server "smtp.gmail.com"
#define SMTP_Port 465
#define sender_email "ahanghosh2004@gmail.com"
#define sender_password "bsthlcolpiirktaw"
#define Recipient_email "ahanbabua07@gmail.com"
#define Recipient_name "AHAN"

// Pin definitions
#define MQ6_PIN 34
#define BUZZER_PIN 25
#define FAN_PIN 26
#define SERVO_PIN 27

// Threshold value for LPG gas detection
#define THRESHOLD_VALUE 350

// Servo motor
Servo servo;

// SMTPSession object
SMTPSession smtp;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  Serial.print("Connecting...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.println();
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  // Debug mode for SMTP
  smtp.debug(1);

  // Initialize the servo motor
  servo.attach(SERVO_PIN);

  // Initialize pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(FAN_PIN, LOW);
}

void loop() {
  int gasValue = analogRead(MQ6_PIN);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Check if gas value exceeds the threshold
  if (gasValue > THRESHOLD_VALUE) {
    int gasLeakageAmount = gasValue - THRESHOLD_VALUE;

    // Send alert email to owner with the gas leakage amount
    sendEmail(gasLeakageAmount);

    // Trigger the buzzer
    digitalWrite(BUZZER_PIN, HIGH);

    // Turn on the exhaust fan
    digitalWrite(FAN_PIN, HIGH);

    // Rotate the servo motor to close the gas valve
    servo.write(120);  // Adjust this value as per your servo configuration

  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(FAN_PIN, LOW);
    servo.write(0);  // Adjust this value as per your servo configuration
  }

  delay(5000);  // Delay for 10 seconds before next read
}

void sendEmail(int gasLeakageAmount) {
  ESP_Mail_Session session;

  session.server.host_name = SMTP_server;
  session.server.port = SMTP_Port;
  session.login.email = sender_email;
  session.login.password = sender_password;
  session.login.user_domain = "";

  // Declare the message class
  SMTP_Message message;

  message.sender.name = "ESP32";
  message.sender.email = sender_email;
  message.subject = "LPG Gas Leakage Alert";
  message.addRecipient(Recipient_name, Recipient_email);

  // Create the message body with the gas leakage amount
  String textMsg = "Gas leakage detected! The gas leakage amount is " + String(gasLeakageAmount) + ". Take action immediately.";
  message.text.content = textMsg.c_str();
  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  if (!smtp.connect(&session))
    return;

  if (!MailClient.sendMail(&smtp, &message))
    Serial.println("Error sending Email, " + smtp.errorReason());
  else
    Serial.println("Email sent successfully");
}
