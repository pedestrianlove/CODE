from bs4 import BeautifulSoup
import requests

# fetch the web source
url = "http://www.tcgs.tc.edu.tw:1218/ShowUserStatistic?account=s08351050"
req = requests.get (url)
soup = BeautifulSoup (req.text, "html.parser")



# fetch the data from the soup object
grade = 0
percentage = ''
for AC in soup.find_all ('a'):
	if (str (AC.get ('href'))[25:34] == 's08351050'):
		grade = int (str (AC.text))
		percentage = str (AC.next_sibling).strip ().split ()[1]
		break


# output
print ("TCGS Judge: {:d} AC".format (grade, percentage) + percentage)
