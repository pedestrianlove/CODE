from bs4 import BeautifulSoup
import requests

# fetch the web source
url = "http://140.128.102.136/Ranking"
req = requests.get (url)
soup = BeautifulSoup (req.text, "html.parser")



# fetch the data from the soup object
grade = 0
for AC in soup.find_all ('a'):
	if (str (AC.get ('href'))[20:29] == 's08351050'):
		grade = int (str (AC.text))
		break


# output
print ("THU CPE: {:d} AC(s)".format (grade))
