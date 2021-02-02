# Data-Structures-Indexing-Websites
Binary search tree ADT and AVL Tree and make a comparıson between both data structures through complexıty analysis. Writing a program that creates an index of a given list of the top popular websites and their IP addresses.

# Requirements
In this program, given a text file that includes the list of the top popular websites and
their IP addresses. When you typically request a website from your browser by typing in a URL1,
that URL is converted to an IP address2 that is used to retrieve that page from the given URL.
In this prigram, it will process this external file with URLs and IP addresses, and then it will
create an index of those pages. The attached file includes the list of IP addresses as follows:
google.com > 216.58.219.206
youtube.com > 172.217.4.206
facebook.com > 31.13.69.228
baidu.com > 123.125.114.144
yahoo.com > 206.190.36.45
amazon.com > 54.239.17.6
wikipedia.org > 208.80.154.224
qq.com > 61.135.157.156
google.co.in > 216.58.219.195
As you can see here, the first page is the main Google page and the last page is the Google
page in Italy (because of the extension “co.in” in the IP address).
Programming task here is to process this file, and generate an AVL tree and a BST that indexes the list of
pages and their IP addresses. However, in this file, when it process the page URLs, it need to
consider that google.com and google.co.in are both belong to Google. For this, it need to just
retrieve the name of the page which is the one until the first dot in the URL. For example, once
you insert the 9 entries given above you should have the following AVL tree.
![alt text](https://i.imgur.com/Z9XUtWt.png)


# Functions
• read_ip_data: This function will mainly process the external file. As an input, it will take
the file name and it will return an AVL tree and simple BST.

• insert_page: This function will take an AVL tree and a simple BST, a page, and its IP
address, and then it will try to insert it to the AVL tree and BST seperately. If the page is
already in the tree, then it will update the existing node with the IP. You cannot again
make assumptions about the number of IP address here (i.e., you do not know how many
IP addresses a website has), so make sure that you use a dynamic list (you are
encouraged to use a linked list here). If the page is not in the AVL tree and BST, then the
functions will create a new node and add it to the tree.

• display_index: This function will mainly take an AVL tree and BST and display the index
of the pages in an alphabetical order.

• search_url: This function will mainly take an AVL tree , BST and a page, and will return
the list of IPs of that page.

• search_ip: This function will mainly take an AVL tree and an IP and BST and an IP, and
will return the page with that IP.

# Sample Output
1. Display the full index: This will display the full AVL tree constructed and Full BST. For example,
for the first 9 entries given above it will show the following.
amazon, IP addresses: 54.239.17.6
baidu, IP addresses: 123.125.114.144
facebook, IP addresses: 31.13.69.228
google, IP addresses: 216.58.219.206, 216.58.219.195
qq, IP addresses: 61.135.157.156
wikipedia, IP addresses: 208.80.154.224
yahoo, IP addresses: 206.190.36.45
youtube, IP addresses: 172.217.4.206
2. Search for a URL: This will allow the user to enter a page and then retrieve the list of all IPs for
that page. For example, for the first 9 entries given above, it will say:
Please enter the page: google
IP addresses for google: 216.58.219.206, 216.58.219.195
3. Search for an IP address: This will allow the user to enter an IP address and find the page that
it belongs to:
Page 3 of 6
Please enter the URL: 216.58.219.
IP has to be in this format xxx.xxx.xxx.xxx
Please enter the URL: 216.58.219.206
It belongs to google
