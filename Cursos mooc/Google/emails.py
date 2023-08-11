#!/usr/bin/env python3

import os.path
import mimetypes
import smtplib
import getpass
from email.message import EmailMessage

#variables for email content
sender = "me@example.com"
recipient = "you@example.com"
body = """Hey there!

I'm learning to send emails using Python!"""

#variables for email attached file
attachment_path = "tmp/example.png"
attachment_filename = os.path.basename(attachment_path)
mime_type, _ = mimetypes.guess_type(attachment_path)
mime_type, mime_subtype = mime_type.split('/', 1)

#variables for email server
"""
mail_server = smtplib.SMTP_SSL('smtp.example.com')
mail_pass = getpass.getpass('Pasword? ')
"""

#create a message
message = EmailMessage()

#set the message values
message['From'] = sender
message['To'] = recipient
message['Subject'] = 'Greetings from {} to {}!'.format(sender, recipient)
message.set_content(body)

with open(attachment_path, 'rb') as ap:
	message.add_attachment(ap.read(), maintype = mime_type, subtype = mime_subtype, filename = attachment_filename)

print(message)

#enter the server
"""
mail_server.login(sender, mail_pass)
mail_server.send_massage(message)
mail_server.quit()
"""


























