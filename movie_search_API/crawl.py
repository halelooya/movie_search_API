from bs4 import BeautifulSoup
import requests
import re

f= open("raw_data.txt","w+")

def split_keywords(s):
	words = s.replace(',',' ').replace(':',' ').replace('\n',' ').replace('\'',' ').replace('.',' ').split();
	for word in words:
		f.write(word.lower().encode("utf-8")+" ")

for page in range(1,21):
	url = "https://www.imdb.com/search/title?groups=top_1000&sort=user_rating&view=simple&page="+str(page)+"&ref_=adv_nxt"

	# Getting the webpage, creating a Response object.
	response = requests.get(url)

	# Extracting the source code of the page.
	data = response.text

	# Passing the source code to BeautifulSoup to create a BeautifulSoup object for it.
	soup = BeautifulSoup(data, 'lxml')
	 
	# Extracting all the <a> tags into a list.
	tags = soup.find_all(href=re.compile("adv_li_tt"))
	 
	# Extracting URLs from the attribute href in the <a> tags.
	for tag in tags:
		page_url = "https://www.imdb.com"+str(tag.get('href'))
		response = requests.get(page_url)
		data = response.text
		soup = BeautifulSoup(data, 'lxml')

		#movie name
		name = soup.h1.contents[0]
		f.write(name.encode("utf-8")+'\n')
		split_keywords(name)

		#director
		directors = soup.find_all(href=re.compile("tt_ov_dr$"))
		for director in directors:
			split_keywords(director.contents[0])

		#writers
		writers = soup.find_all(href=re.compile("tt_ov_wr$"))
		for writer in writers:
			split_keywords(writer.contents[0])

		#stars
		stars = soup.find("table","cast_list").find_all(href=re.compile("tt_cl_t"))
		for star in stars:
			href = str(star.get('href'))
			if "name" in href:
				split_keywords(star.contents[0])

		#genre
		genre = soup.find_all(href=re.compile("tt_stry_gnr$"))
		for g in genre:
			split_keywords(g.contents[0])

		#release year
		year = soup.find(id = "titleYear").contents[1].contents[0]
		split_keywords(year)

		#country
		countrys = soup.find_all(href=re.compile("country_of_origin"))
		for country in countrys:
			split_keywords(country.contents[0])

		#language
		languages = soup.find_all(href=re.compile("primary_language"))
		for language in languages:
			split_keywords(language.contents[0])

		f.write('\n')
		
f.close()

	    
