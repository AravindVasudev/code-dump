import requests
from bs4 import BeautifulSoup
import json

# Google Scholar URL
URL = 'https://scholar.google.co.in/citations'
contents = dict()

# get the user ID
id = input('Enter Scholar ID: ')

# send GET request to the URL with id as GET params
page = requests.get(URL, params={"user": id})

# create a Beautiful Soup instance for the page content
soup = BeautifulSoup(page.content, 'html.parser')

# Scrape into contents
contents['name'] = soup.find('div', id="gsc_prf_in").text # finds name div

contents['area_of_specialization'] = soup.find('a', attrs={"class": "gsc_prf_ila"}).text

# scrape citation table
citations_table = soup.find('div', id="gsc_rsb")
citations_rows  = citations_table.find_all('td', attrs={"class": "gsc_rsb_std"}) # citation rows
contents['citations_all'] = citations_rows[0].text # all citations
contents['citations_since_2012'] = citations_rows[1].text # citations since 2012

# scrape papers table
papers_table = soup.find('tbody', id="gsc_a_b")
papers_rows  = papers_table.find_all('tr', attrs={"class": "gsc_a_tr"})

contents['papers'] = list()
for row in papers_rows:
    iter_paper = dict()
    iter_paper['title'] = row.find('a', attrs={"class": "gsc_a_at"}).text
    iter_paper['year'] = row.find('span', attrs={"class": "gsc_a_h"}).text
    iter_paper['citations'] = row.find('a', attrs={"class": "gsc_a_ac"}).text
    iter_paper['authors'] = row.find('div', attrs={"class": "gs_gray"}).text

    contents['papers'].append(iter_paper)

with open('profile.json', 'w') as fp:
    json.dump(contents, fp)

print('Scraped data dumped into ./profile.json')
