import requests
import sys

name = sys.argv[1]
address = sys.argv[2]
contact  = sys.argv[3]
return_value = sys.argv[4]
if return_value == "user_detail":
    data = f'<i>New user added</i>\n\nName      : <b>{name}</b>\nAddress  : <b>{address}</b>\nContact  : <b>{contact}</b>'
elif return_value == "contact_detail":
    data = f'<i>Contact Router</i>\n\nName      : <b>{name}</b>\nAddress  : <b>{address}</b>\nContact  : <b>{contact}</b>'
chat_id = -190475332
token = '9269173042:FCRRFAAAXMvYkqYkqre2XlEslV3yuNmAAAo'
url = f'https://api.telegram.org/bot{token}/sendMessage'
data = {'chat_id': {chat_id}, 'text': {data}, 'parse_mode' : 'html'}
requests.post(url, data).json()