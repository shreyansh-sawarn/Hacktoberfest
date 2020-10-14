'''
Script to scrap the headlines of BBC News website
and gives the headlines with Links
'''

'''
Program uses requests module to get web data from URL and BeautifulSoup module to parse the web data
as HTML using html parser.
Install requests and BeautifulSoup module before executing!
'''
import requests
from bs4 import BeautifulSoup
import pprint # prints the Final output in pretty manner which is inbuilt module in Python

response = requests.get("https://www.bbc.com/") 

parsed_html = BeautifulSoup(response.text,'html.parser')  #parsing the received web data by html parser

headlines_links = parsed_html.select('.media__link') #All links of Headlines news are included in class "media__link"

def bbcHeadlines(headlines_links):
    news = []
    for links in headlines_links:
        headlines = links.get_text('\n',strip=True)
        if links.get('href').startswith('https'):
            link = links.get('href')
            news.append({'HeadLines ':headlines, 'Link': link})
        else:
            link = links.get('href')
            news.append({'HeadLines ': headlines, 'Link': 'https://www.bbc.com'+link})

    return news

pprint.pprint(bbcHeadlines(headlines_links))
