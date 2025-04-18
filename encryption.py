import smtplib

def send_unencrypted_email(sender_email, recipient_email, sender_password):
    # SMTP server configuration (example using a generic SMTP server)
    smtp_server = 'smtp.office365.com'
    smtp_port = 587  # Common port for unencrypted SMTP

    # Email content
    subject = "Confidential Financial Details"
    body = "Here are the confidential financial details..."
    email_text = f"""\
From: {sender_email}
To: {recipient_email}
Subject: {subject}

{body}
"""

    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.ehlo()  # Identify yourself to the server
        server.starttls()  # Upgrade the connection to secure
        server.ehlo()  # Re-identify yourself over the secure connection
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, recipient_email, email_text)
        print("Email sent successfully.")
    except Exception as e:
        print(f"Failed to send email: {e}")
    finally:
        server.quit()

# Example usage (credentials and server details are placeholders)
sender_email = "manas.biswas@students.iiit.ac.in"
recipient_email = "niraj.gupta@students.iiit.ac.in"
sender_password = "Man@Bis@1234"
send_unencrypted_email(sender_email, recipient_email, sender_password)
